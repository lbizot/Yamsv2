#ifndef YAMS_H
#define YAMS_H

#include "libgraphique.h"

#define RESH 800
#define RESV 600

typedef struct des {
    int valeurDes;
    int stat;
}Des;

typedef struct main {
    int tab[5];
    int nbDesParValeur[7];
    Point cordnum[16];
    int total_graph[16];
}Main;

class Yams
{
public:
	Yams();
	void runGame();
private:
	Des initDes(Des );

	Des afficherDes_console(Des );

	void afficheDes_graph(int , Point);

	int RenouvelerDes(Point );

	Main compte_combi(Main );

	Main combi(Main );

	Des unlock(Des );

	void effaceDesLock_graph(Point );

	Point RenouvellementDes1(Des ,Point );
	Point RenouvellementDes2(Des ,Point );
	Point RenouvellementDes3(Des ,Point );
	Point RenouvellementDes4(Des ,Point );
	Point RenouvellementDes5(Des ,Point );

	void cleanScore_tmp();

	void cleanScore_jeu(Point );

	void cleanScore_jeu2(Point );

	int DecisionJoueur(Point );

	int DecisionJoueur2(Point );

	Libgraphique lb;
	Point total_jeu;
	Des d1;
    Des d2;
    Des d3;
    Des d4;
    Des d5;
    Main m1;

    Point psauvegarde; // 1
    Point psauvegarde2;// 2
    Point psauvegarde3;// 3
    Point psauvegarde4;// 4
    Point psauvegarde5;// 5
    Point psauvegarde6;// 6
    Point psauvegarde7;// BONUS
    Point psauvegarde8;// TOTAL 1
    Point psauvegarde9;// BRELAN
    Point psauvegarde10;// CARRE
    Point psauvegarde11;// FULL 
    Point psauvegarde12;// PETITE SUITE
    Point psauvegarde13;// GRANDE SUITE 
    Point psauvegarde14;// YAMS 
    Point psauvegarde15;// CHANCE TOTAL
    Point psauvegarde16;// TOTAL 2.1
    Point psauvegarde17;// TOTAL 2

    Point p1;
    Point p2;
    Point p3;
    Point p4;
    Point p5;

    int score_jeu_i2, score_jeu_intermediaire, score_jeu_total;//joueur 1
    int case1_1, case2_1, case3_1, case4_1, case5_1, case6_1, case7_1, case8_1, case9_1, case12_1, case10_1, case11_1, case15_1;//case quand on clic dessus, le temps qu'on a pas cliqué sur toute les cases on continu le jeu. JOUEUR 1.
    int t_case1_1, t_case2_1, t_case3_1, t_case4_1, t_case5_1, t_case6_1, t_case7_1, t_case8_1,t_case9_1,t_case12_1,t_case10_1, t_case11_1,t_case15_1;//JOUEUR 1

// ************** VARIABLES CONCERNANT JOUEUR 2 *****************
    
    int score_jeu_intermediaire_2, score_jeu_i2_2, score_jeu_total_2;//variables joueur 2
    
    int case1_2, case2_2, case3_2, case4_2, case5_2, case6_2, case7_2, case8_2,case9_2, case10_2, case11_2, case15_2,case12_2;// JOUEUR 2.
    int t_case1_2, t_case2_2, t_case3_2, t_case4_2, t_case5_2, t_case6_2, t_case7_2, t_case8_2, t_case9_2,t_case10_2, t_case11_2,t_case12_2, t_case15_2;//JOUEUR 2

    Point o1;
    Point affiche_joueur;
    int sauv[3]; // TABLEAU PERMETTANT DE NE PAS POUVOIR DESELECTIONNER UN Dé AU PROCHAIN LANCER
    Point clic;
    int i,k;
    int tour_joueur;
    int deja_clique;
    int score_final;
    Point choix_score;
    int lastscore;
    char score_graph[3];    
    char scorejeu_graph[3];
    int bonus;

    FILE* fichier;
};
#endif