#ifndef LIBGRAPHIQUE_H
#define LIBGRAPHIQUE_H



#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>

#define sdlRed     {255, 0, 0, 0}
#define sdlBlue    {0, 0, 255, 0}
#define sdlWhite   {255, 255, 255, 0}
#define sdlGris    {128, 128, 128, 0}
#define plateau    {117, 49, 61, 0}
#define totaux 	   {255, 51, 51,0}
#define background {81, 120, 77,0}

typedef struct {int x,y;} Point;



class Libgraphique{
public:
	//ouvre une fenêtre
	void ouvrir_fenetre(int largeur, int hauteur);

	// terminer le programme
	void fermer_fenetre();

	// affiche l'image sous forme .bmp (bitmap), contenue dans le même dossier
	// nom est une chaine de caracteres qui est le nom (complet) du fichier image
	// coin est le coin haut, gauche voulu pour l'image à afficher dans l'ecran
	void afficher_image(std:: string nom, Point coin);

	//dessine un rectangle aux coordonnés coin avec les dimensions largeur hauteur ainsi que la SDL_Color couleur
	void dessiner_rectangle(Point coin, int largeur, int hauteur, SDL_Color couleur);

	// renvoie les coordonnees du prochain clic (gauche ou droite) de souris
	// fonction bloquante
	Point attendre_clic() ;

	//affiche du texte de taille de police donnée ; coin est le coin haut gauche du texte
	void afficher_texte(std::string texte, int taille, Point coin, SDL_Color couleur);

	// pause le programme pour une duree en millisecondes
	void attente(int duree_ms);


private:
	// teste si la fin du programme a été demandée et le termine si nécessaire
	// ne pas utiliser directement
	void _test_arret();

	SDL_Window *sdlScreen;              // creation de l'écran
	SDL_Renderer *sdlRenderer;          //création du renderer
	SDL_Texture *sdlTexture;            //création de la texture d'affichage
	SDL_Surface *sdlSurface;
	SDL_Event lastevent ;               // utilisé pour gestion événements

};

#endif