#include "libgraphique.h"


// ouvrir une fenêtre de taille largeur (x), hauteur (y)
void Libgraphique::ouvrir_fenetre(int largeur, int hauteur){
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
    sdlTexture = SDL_CreateTexture(sdlRenderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING,largeur, hauteur);
    srand(time(NULL));
}


// terminer le programme
void Libgraphique::fermer_fenetre(){
    SDL_DestroyTexture(sdlTexture);
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlScreen);
    SDL_FreeSurface(sdlSurface);
    SDL_Quit();
    exit(0);
}

// teste si la fin du programme a été demandée et le termine si nécessaire
void Libgraphique::_test_arret() {
    if ((lastevent.type == SDL_QUIT) || ( (lastevent.type == SDL_KEYDOWN ) && (lastevent.key.keysym.sym == SDLK_ESCAPE)))
        fermer_fenetre();
}

// affiche l'image sous forme .bmp (bitmap), contenue dans le même dossier
// nom est une chaine de caracteres qui est le nom (complet) du fichier image
// coin est le coin haut, gauche voulu pour l'image à afficher dans l'ecran
void Libgraphique::afficher_image(std::string nom, Point coin){
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


void Libgraphique::dessiner_rectangle(Point coin, int largeur, int hauteur, SDL_Color couleur) {
    SDL_Rect rect;
   	rect.x = coin.x;
    rect.y = coin.y;
    rect.w = largeur;
    rect.h = hauteur;
    SDL_SetRenderDrawColor(sdlRenderer, couleur.r, couleur.g, couleur.b, couleur.a);
    SDL_RenderFillRect(sdlRenderer,&rect);
    SDL_RenderPresent(sdlRenderer);
}

// renvoie les coordonnees du prochain clic (gauche ou droite) de souris
// fonction bloquante
Point Libgraphique::attendre_clic() {
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

//affiche du texte de taille de police donnée ; coin est le coin haut gauche du texte
void Libgraphique::afficher_texte(std::string texte, int taille, Point coin, SDL_Color couleur)
{
	TTF_Init();
    if (texte[0] != '\0')
    {
        SDL_Surface* sdlSurface= TTF_RenderText_Blended(TTF_OpenFont("./files/verdana.ttf", taille), texte.c_str(), couleur);
		SDL_Texture* texture=SDL_CreateTextureFromSurface(sdlRenderer,sdlSurface);

        SDL_Rect position;
        position.x = coin.x;
        position.y=  coin.y;
        SDL_QueryTexture(texture,nullptr,nullptr,&position.w,&position.h);
		SDL_FreeSurface(sdlSurface);
		SDL_RenderCopy(sdlRenderer,texture,nullptr,&position);
		SDL_RenderPresent(sdlRenderer); 
		SDL_DestroyTexture(texture);
    }
}

// pause le programme pour une duree en millisecondes
void Libgraphique::attente(int duree_ms)
{
    SDL_Delay(duree_ms);
}