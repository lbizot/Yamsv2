/*******************************************************************************
 * libraphique.c                                                               *
 * Quelques fonctions C basées sur la SDl pour réaliser des opérations         *
 * graphiques simples                                                          *
 *                                                                             *
 * Pour compiler en ligne de commande :                                        *
 * gcc ../lib/libgraphique.c prog.c -o resultat                                *
 *           `sdl-config --libs --cflags` -lm -lSDL                            *
 *                                                                             *
 * où                                                                          *
 *             prog.c : votre code source                                      *
 *             resultat    : nom de l'exécutable                               *
 *******************************************************************************
*/

///////////////////////////////////////////////////////////////////////////////
//0. Directive préprocesseur
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>

#include <QCoreApplication>


///////////////////////////////////////////////////////////////////////////////
//1. Déclaration des types "maison"
typedef unsigned int Couleur;
typedef SDL_Color Couleursdl;
typedef struct {int x,y;} Point;
typedef struct {
    int touches[SDL_NUM_SCANCODES] ;
    int sourisx ;
    int sourisy ;
    int boutong ;
    int boutond ;
} Trace_evts ;

////////////////////////////////////////////////////////////////////////////////
// Déclaration des fonctions
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// 1. Ouvrir et fermer une fenêtre

// ouvrir une fenêtre de taille largeur (x), hauteur (y)
void ouvrir_fenetre(int largeur, int hauteur);

// terminer le programme
void fermer_fenetre();

// teste si la fin du programme a été demandée et le termine si nécessaire
// ne pas utiliser directement
void _test_arret() ;

////////////////////////////////////////////////////////////////////////////////
// 2. Fonctions de dessin

// actualise l'affichage des modifications graphiques
// sans appel à cet fonction les modifications sont non apparentes
void actualiser();


// affiche l'image sous forme .bmp (bitmap), contenue dans le même dossier
// nom est une chaine de caracteres qui est le nom (complet) du fichier image
// coin est le coin haut, gauche voulu pour l'image à afficher dans l'ecran
void afficher_image(std:: string nom, Point coin);

////////////////////////////////////////////////////////////////////////////////
// 3. Gestion des événements

// renvoie le code SDLK de la prochaine touche pressée
// fonction bloquante
int attendre_touche(void);

// renvoie le code SDLK de la prochaine touche pressée avant une durée donnée
// en milisecondes, fonction bloquante durant un certain temps.
// Renvoie 0 si aucune touche n'a été pressée.
int attendre_touche_duree(int);

// renvoie les coordonnees du prochain clic (gauche ou droite) de souris
// fonction bloquante
Point attendre_clic() ;

//comme la fonction attendre clic, mais on ajoute un signe
//négatif devant les coordonnées du point si c'est un clic droit
Point attendre_clic_gauche_droite() ;


////////////////////////////////////////////////////////////////////////////////
// 3 bis : fonctions optionnelles pour les événements, non bloquantes

//reinitialise la mémoire des événements à 0
void reinitialiser_evenements(void);

// memorise les evenements ayant eu lieu depuis la derniere
// reinitialisation
void traiter_evenements(void);

// indique si la touche de code SDL en question a été pressée
// entre la derniere reinitialisation et le dernier traitement
int touche_a_ete_pressee(int);

//renvoie les coordonnees du dernier clic obtenu
// entre la derniere reinitialisation et le dernier traitement
// Point (-1,-1) si pas de clic
Point clic_a_eu_lieu();

// renvoie un point de coordonnées relatives souris obtenu
// entre la derniere reinitialisation et le dernier traitement
// (0,0) au lancement, dernière position reçue si sortie de fenêtre
Point deplacement_souris_a_eu_lieu();

////////////////////////////////////////////////////////////////////////////////
// 4. Affichage de texte
// pour fonctionner, la police doit se trouver dans le dossier lib
// (la police peut être changée en changeant la variable globale NOM_POLICE )

//affiche du texte de taille de police donnée ; coin est le coin haut gauche du texte
void afficher_texte(std::string texte, int taille, Point coin, SDL_Color couleur);


////////////////////////////////////////////////////////////////////////////////


// pause le programme pour une duree en millisecondes
void attente(int duree_ms);





//CouleurS ///////////////////////
// 16 couleurs de base en francais

#define sdlRed     {255, 0, 0, 0}
#define sdlBlue    {0, 0, 255, 0}
#define sdlWhite   {255, 255, 255, 0}
#define sdlGris    {128, 128, 128, 0}

#define argent     0xC0C0C0
#define blanc      0xFFFFFF
#define bleu       0x0000FF
#define bleumarine 0x000080
#define citronvert 0x00FF00
#define cyan       0x00FFFF
#define magenta    0xFF00FF
#define gris       0x808080
#define jaune      0xFFFF00
#define marron     0x800000
#define noir       0x000000
#define rouge      0xFF0000
#define sarcelle   0x008080
#define vert       0x00FF00
#define vertclair  0x008000
#define vertolive  0x808000
#define violet     0x800080
