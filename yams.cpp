#include "libgraphique.h"

int main(int argc, char **argv)
    {
    srand(time(NULL));
    Point p={250,200};
    ouvrir_fenetre(800,600);
    afficher_texte("YAM's!",100,p,sdlRed);
    actualiser();
    attente(5000);
    Point afficheimage={0, 0};
    afficher_image("./files/image/fondyams.bmp",afficheimage);
    actualiser();
    attente(5000);
    fermer_fenetre();
    return(0);
    }






