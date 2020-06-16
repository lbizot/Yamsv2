
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
    srand(time(NULL));
}


// terminer le programme
void fermer_fenetre(){
    SDL_DestroyTexture(sdlTexture);
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlScreen);
    SDL_FreeSurface(sdlSurface);
    SDL_Quit();
    exit(0);
}

// teste si la fin du programme a été demandée et le termine si nécessaire
void _test_arret() {
    if ((lastevent.type == SDL_QUIT) || ( (lastevent.type == SDL_KEYDOWN ) && (lastevent.key.keysym.sym == SDLK_ESCAPE)))
        fermer_fenetre();
}


///////////////////////////////////////////////////////////////////////////////
// 2. Fonctions de dessin

// actualise l'affichage des modifications graphiques
// sans appel à cet fonction les modifications sont non apparentes
void actualiser(){
    SDL_PollEvent(&lastevent) ;
    _test_arret();
    //SDL_UpdateTexture(sdlTexture, NULL, myPixels, LARGEUR * sizeof (unsigned int));
    //SDL_RenderClear(sdlRenderer);
   // SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
    //SDL_RenderPresent(sdlRenderer);
}


// affiche l'image sous forme .bmp (bitmap), contenue dans le même dossier
// nom est une chaine de caracteres qui est le nom (complet) du fichier image
// coin est le coin haut, gauche voulu pour l'image à afficher dans l'ecran
void afficher_image(std::string nom, Point coin){
    sdlSurface = SDL_LoadBMP(nom.c_str());
    SDL_Rect position;
    position.x = coin.x;
    position.y = coin.y;
    position.w = sdlSurface->w;
    position.h = sdlSurface->h;
    sdlTexture = SDL_CreateTextureFromSurface(sdlRenderer, sdlSurface);
    SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, &position);
    SDL_RenderPresent(sdlRenderer);
    SDL_FreeSurface(sdlSurface);
}


void dessiner_rectangle(Point coin, int largeur, int hauteur, SDL_Color couleur) {
    SDL_Rect rect;
   	rect.x = coin.x;
    rect.y = coin.y;
    rect.w = largeur;
    rect.h = hauteur;
    SDL_SetRenderDrawColor(sdlRenderer, couleur.r, couleur.g, couleur.b, couleur.a);
    SDL_RenderFillRect(sdlRenderer,&rect);
    SDL_RenderPresent(sdlRenderer);
}

////////////////////////////////////////////////////////////////////////////////
// 3. Gestion des événements

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


////////////////////////////////////////////////////////////////////////////////
// 4. Affichage de texte
// pour fonctionner, la police doit se trouver dans le dossier lib
// (la police peut être changée en changeant la variable globale NOM_POLICE )



//affiche du texte de taille de police donnée ; coin est le coin haut gauche du texte
void afficher_texte(std::string texte, int taille, Point coin, SDL_Color couleur)
{
	TTF_Init();
    if (texte[0] != '\0')
    {
        //sdlSurface= TTF_RenderText_Blended(TTF_OpenFont("./files/verdana.ttf", taille), texte.c_str(), couleur);
        SDL_Surface* sdlSurface= TTF_RenderText_Blended(TTF_OpenFont("./files/verdana.ttf", taille), texte.c_str(), couleur);
		SDL_Texture* texture=SDL_CreateTextureFromSurface(sdlRenderer,sdlSurface);

        SDL_Rect position;
        position.x = coin.x;
        position.y=  coin.y;
        //sdlTexture = SDL_CreateTextureFromSurface(sdlRenderer, sdlSurface);
        //SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, &position);
        //SDL_RenderPresent(sdlRenderer);
        //SDL_FreeSurface(sdlSurface);
        SDL_QueryTexture(texture,nullptr,nullptr,&position.w,&position.h);
		SDL_FreeSurface(sdlSurface);
		SDL_RenderCopy(sdlRenderer,texture,nullptr,&position);
		SDL_RenderPresent(sdlRenderer); 
		SDL_DestroyTexture(texture);
    }
}

////////////////////////////////////////////////////////////////////////////////

// pause le programme pour une duree en millisecondes
void attente(int duree_ms)
{
    SDL_Delay(duree_ms);
}