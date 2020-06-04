
////////////////////////////////////////////////////////////////////////////////
// 0. directives préprocesseur


#include "libgraphique.h"


////////////////////////////////////////////////////////////////////////////////
// 0. variables globales et macros

SDL_Window *sdlScreen;                 // creation de l'écran
SDL_Renderer *sdlRenderer;          //création du renderer
SDL_Texture *sdlTexture;            //création de la texture d'affichage
SDL_Surface *sdlSurface;
SDL_Event lastevent ;                      // utilisé pour gestion événements
Trace_evts trace_evts ;                    // idem
Point dernier_clic = {-1,-1};
int LARGEUR = -1 ;                         // largeur de l'écran en pixels
int HAUTEUR = -1 ;
unsigned int *myPixels;
// hauteur de l'écran en pixels
std::string NOM_POLICE = "verdana.ttf" ;
#define octets_par_pixel ecran->format->BytesPerPixel
#define largeur_ecran (ecran->pitch / 4)


////////////////////////////////////////////////////////////////////////////////
// 1. Ouvrir et fermer une fenêtre

// ouvrir une fenêtre de taille largeur (x), hauteur (y)
void ouvrir_fenetre(int largeur, int hauteur){
    SDL_Init(SDL_INIT_VIDEO);
    sdlScreen = SDL_CreateWindow
            (
                "Yams", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                largeur,
                hauteur,
                SDL_WINDOW_SHOWN
            );
    sdlRenderer = SDL_CreateRenderer(sdlScreen, -1, SDL_RENDERER_ACCELERATED);
    sdlTexture = SDL_CreateTexture(sdlRenderer,
                                   SDL_PIXELFORMAT_ARGB8888,
                                   SDL_TEXTUREACCESS_STREAMING,
                                   largeur, hauteur);
    //initialisation des variables globales
    LARGEUR = largeur ;
    HAUTEUR = hauteur ;
    //printf("LARGEUR %d HAUTEUR %d\n",LARGEUR,HAUTEUR);

    // pour permettre les répétitions de touche si elles restent enfoncées
    //SDL_EnableKeyRepeat(5, 5);

    //initialisation du hasard
    srand(time(NULL));
}


// terminer le programme
void fermer_fenetre(){
    SDL_DestroyTexture(sdlTexture);
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlScreen);
    SDL_FreeSurface(sdlSurface);
    SDL_Quit();
}

// teste si la fin du programme a été demandée et le termine si nécessaire
void _test_arret() {
    if ((lastevent.type == SDL_QUIT) ||
            ( (lastevent.type == SDL_KEYDOWN )
              && (lastevent.key.keysym.sym == SDLK_ESCAPE))
       )
        fermer_fenetre() ;
}


///////////////////////////////////////////////////////////////////////////////
// 2. Fonctions de dessin

// actualise l'affichage des modifications graphiques
// sans appel à cet fonction les modifications sont non apparentes
void actualiser(){
    SDL_PollEvent(&lastevent) ;
    _test_arret();
    SDL_UpdateTexture(sdlTexture, NULL, myPixels, LARGEUR * sizeof (unsigned int));
    SDL_RenderClear(sdlRenderer);
    SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
    SDL_RenderPresent(sdlRenderer);
}


// affiche l'image sous forme .bmp (bitmap), contenue dans le même dossier
// nom est une chaine de caracteres qui est le nom (complet) du fichier image
// coin est le coin haut, gauche voulu pour l'image à afficher dans l'ecran
void afficher_image(std::string nom, Point coin){
    sdlSurface = SDL_LoadBMP(nom.c_str()); ;
    SDL_Rect position;
    position.x = coin.x;
    position.y=  coin.y;
    sdlTexture = SDL_CreateTextureFromSurface(sdlRenderer, sdlSurface);
    SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, &position);
    SDL_RenderPresent(sdlRenderer);
    SDL_FreeSurface(sdlSurface);
}


////////////////////////////////////////////////////////////////////////////////
// 3. Gestion des événements

// renvoie le code SDLK de la prochaine touche pressée
// fonction bloquante
int attendre_touche(void){
    do {
        SDL_WaitEvent(&lastevent) ;
        _test_arret() ;
    }
    while (lastevent.type != SDL_KEYDOWN ) ;
    return lastevent.key.keysym.sym;
}

// renvoie le code SDLK de la première touche pressée pendant
// la durée duree_ms (en millisecondes)
// (bloque le jeu en attente pendant cette duree)
// renvoie 0 si aucune touche n'a été pressée
int attendre_touche_duree(int duree_ms)
{

    unsigned int depart = SDL_GetTicks();
    unsigned int courant = SDL_GetTicks();
    int code = 0;
    SDL_Event e;
    while(SDL_PollEvent(&e))
        _test_arret() ;
    while(code==0 && int(courant - depart) < duree_ms)
    {
        courant = SDL_GetTicks();
        SDL_PollEvent(&e) ;
        if(e.type == SDL_KEYDOWN)

            code = e.key.keysym.sym;
        _test_arret() ;
    }
    while(int(courant - depart) < duree_ms )
    {
        courant = SDL_GetTicks();
        _test_arret() ;
    }
    return code;
}

// renvoie les coordonnees du prochain clic (gauche ou droite) de souris
// fonction bloquante
Point attendre_clic() {
    do {
        SDL_WaitEvent(&lastevent) ;
        _test_arret();
    }
    while (lastevent.type != SDL_MOUSEBUTTONDOWN) ;
    Point p ;
    p.x = lastevent.button.x ;
    p.y = lastevent.button.y ;

    return p;
}

//comme la fonction attendre clic, mais on ajoute un signe
//négatif devant les coordonnées du point si c'est un clic droit
Point attendre_clic_gauche_droite() {
    do {
        SDL_WaitEvent(&lastevent) ;
        _test_arret();
    }
    while (lastevent.type != SDL_MOUSEBUTTONDOWN) ;
    Point p ;
    if (lastevent.button.button==SDL_BUTTON_RIGHT)
    {
        p.x = - lastevent.button.x ;
        p.y = - lastevent.button.y ;
    }
    else
    {
        p.x = lastevent.button.x ;
        p.y = lastevent.button.y ;
    }

    return p;
}


////////////////////////////////////////////////////////////////////////////////
// 3 bis : fonctions optionnelles pour les événements, non bloquantes


//reinitialise la mémoire des événements à 0
void reinitialiser_evenements(void)
{
    memset(trace_evts.touches, 0, sizeof(trace_evts.touches)) ;
    dernier_clic.x = -1;
    dernier_clic.y = -1;
}

// memorise les evenements ayant eu lieu depuis la derniere
// reinitialisation
void traiter_evenements(void)
{

    while(SDL_PollEvent(&lastevent))
    {
        switch(lastevent.type)
        {
            case SDL_MOUSEMOTION:
                trace_evts.sourisx = lastevent.motion.x;
                trace_evts.sourisy = lastevent.motion.y;
                break;
            case SDL_KEYDOWN:
                trace_evts.touches[lastevent.key.keysym.sym]=1 ;
                break ;
            case SDL_MOUSEBUTTONDOWN:
                dernier_clic.x = lastevent.motion.x ;
                dernier_clic.y = lastevent.motion.y ;
        }

    }

}

// indique si la touche de code SDL en question a été pressée
// entre la derniere reinitialisation et le dernier traitement
int touche_a_ete_pressee(int code)
{
    return trace_evts.touches[code] ;
}

//renvoie les coordonnees du dernier clic entre la
// entre la derniere reinitialisation et le dernier traitement
// Point (-1,-1) si pas de clic
Point clic_a_eu_lieu()
{
    Point res = dernier_clic ;
    dernier_clic.x = -1;
    dernier_clic.y = -1 ;
    return res;
}

// renvoie un point de coordonnées relatives souris obtenu
// entre la derniere reinitialisation et le dernier traitement
// (0,0) au lancement, dernière position reçue si sortie de fenêtre
Point deplacement_souris_a_eu_lieu()
{
    Point res;
    res.x = trace_evts.sourisx;
    res.y = trace_evts.sourisy;
    return res;
}

////////////////////////////////////////////////////////////////////////////////
// 4. Affichage de texte
// pour fonctionner, la police doit se trouver dans le dossier lib
// (la police peut être changée en changeant la variable globale NOM_POLICE )



//affiche du texte de taille de police donnée ; coin est le coin haut gauche du texte
void afficher_texte(std::string texte, int taille, Point coin, SDL_Color couleur)
{
    if (texte[0] != '\0' && !TTF_Init())
    {
        sdlSurface= TTF_RenderText_Blended(TTF_OpenFont("./files/verdana.ttf", taille), texte.c_str(), couleur);
        SDL_Rect position;
        position.x = coin.x;
        position.y=  coin.y;
        sdlTexture = SDL_CreateTextureFromSurface(sdlRenderer, sdlSurface);
        SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, &position);
        SDL_RenderPresent(sdlRenderer);
        SDL_FreeSurface(sdlSurface);
    }
}

////////////////////////////////////////////////////////////////////////////////

// pause le programme pour une duree en millisecondes
void attente(int duree_ms)
{
    SDL_Delay(duree_ms);
}

