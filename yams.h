/******************************************************************************/
/* YAMS_H                                                                     */
/******************************************************************************/

#include "libgraphique.h"


/******************************************************************************/
/* DEFINE                                                                     */
/******************************************************************************/
#define RESH 800
#define RESV 600
#define plateau 0x75313d
#define totaux 0xff3333
#define background 0x51784d

/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/

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


/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/


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






// *************************************************************************
// **************************** FONCTIONS **********************************
// *************************************************************************


int DecisionJoueur(Point p1)
    {
    if( ((p1.x > 155 && p1.x < 205) && (p1.y > 32 && p1.y < 232)) || ((p1.x > 155 && p1.x < 205) && (p1.y > 300 && p1.y < 550)))
        {
        return 1;
        }
    else
        {
        return 0;
        }

    }
int DecisionJoueur2(Point p1)
    {
    if( ((p1.x > 188 && p1.x < 238) && (p1.y > 32 && p1.y < 232)) || ((p1.x > 188 && p1.x < 238) && (p1.y > 300 && p1.y < 550)))
        {
        return 1;
        }
    else
        {
        return 0;
        }

    }


void cleanScore_jeu(Point jeu)
    {
    jeu.y -= 33;
    afficher_image("./image/carre_jaune.bmp",jeu);
    jeu.y += 33;
    afficher_image("./image/carre_jaune.bmp",jeu);
    jeu.y += 33 * 8;
    jeu.y += 4;
    afficher_image("./image/carre_jaune.bmp",jeu);
    jeu.y += 33;
    dessiner_rectangle(jeu,50,33,totaux);
    actualiser();
    }
void cleanScore_jeu2(Point jeu)
    {
    jeu.x += 50;
    jeu.y -= 33;
    afficher_image("./image/carre_jaune.bmp",jeu);
    jeu.y += 33;
    afficher_image("./image/carre_jaune.bmp",jeu);
    jeu.y += 33 * 8;
    jeu.y += 4;
    afficher_image("./image/carre_jaune.bmp",jeu);
    jeu.y += 33;
    dessiner_rectangle(jeu,50,33,totaux);
    actualiser();
    }

void cleanScore_tmp()
    {
    Point efface_colonne = { 102 , 0 };
    afficher_image("./image/colonne.bmp",efface_colonne);
    }

void effaceDesLock_graph(Point p1)
    {
    dessiner_rectangle(p1,60,60,plateau);
    }

Point RenouvellementDes1(Des d1, Point p1)
    {
    if(d1.stat == 1)
        {
        p1.x += 120;
        p1.y -= 313;
        }
    else
        {

        }
    return p1;
    }
Point RenouvellementDes2(Des d1, Point p1)
    {
    if(d1.stat == 1)
        {
        p1.x += 150;
        p1.y -= 313;
        }
    else
        {

        }
    return p1;
    }
Point RenouvellementDes3(Des d1, Point p1)
    {
    if(d1.stat == 1)
        {
        p1.x -= 100;
        p1.y -= 213;
        }
    else
        {

        }
    return p1;
    }
Point RenouvellementDes4(Des d1, Point p1)
    {
    if(d1.stat == 1)
        {
        p1.x -= 90;
        p1.y -= 213;
        }
    else
        {

        }
    return p1;
    }
Point RenouvellementDes5(Des d1, Point p1)
    {
    if(d1.stat == 1)
        {
        p1.x -= 83;
        p1.y -= 213;
        }
    else
        {

        }
    return p1;
    }
Des unlock(Des dice)
    {
    dice.stat = 0;
    return dice;
    }

Main compte_combi(Main m1)
    {
    int i,j;
    for(i = 1; i < 7 ; i++)
        {
        m1.nbDesParValeur[i] = 0;
        for(j = 0 ; j < 5 ; j++)
            {
            if(m1.tab[j] == i)
                {
                m1.nbDesParValeur[i] += 1;
                }
            else
                {

                }
            }
        printf("%d dé de %d \n",m1.nbDesParValeur[i],i);
        }
    return m1;
    }

Main combi(Main m1)
    {
    int i, s_total = 0,carre = 0,brelan = 0,yam=0,paire = 0,full = 0,psuite=0,gsuite=0;
    char score_graph[3];
    for(i = 1; i < 7 ; i++)
        {
        if(m1.nbDesParValeur[i]==0)
            {
            s_total = s_total + 0;
            m1.total_graph[i] = 0;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            }
        else if(m1.nbDesParValeur[i] == 1)
            {
            s_total = s_total + i;
            m1.total_graph[i] = i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            }
        else if(m1.nbDesParValeur[i] == 2)
            {
            s_total = s_total + (m1.nbDesParValeur[i] * i);
            //pairepourfull=1; on pourrai augmenter la variable de 1 quand on a une paire
            m1.total_graph[i] = m1.nbDesParValeur[i] * i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            paire = 1;
            afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            }
        else if(m1.nbDesParValeur[i] == 3)
            {
            s_total = s_total + (m1.nbDesParValeur[i] * i);
            brelan=1;
            m1.total_graph[i] = m1.nbDesParValeur[i] * i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            m1.total_graph[9] = (m1.nbDesParValeur[i] * i);
            }
        else if(m1.nbDesParValeur[i] == 4)
            {
            s_total = s_total + (m1.nbDesParValeur[i] * i);
            m1.total_graph[i] = m1.nbDesParValeur[i] * i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            carre=1;
            m1.total_graph[10] = m1.nbDesParValeur[i] * i;
            brelan=1;
            m1.total_graph[9] = (m1.nbDesParValeur[i] * i)-i;
            sprintf(score_graph,"%d",m1.total_graph[10]);
            afficher_texte(score_graph,20,m1.cordnum[10],sdlBlue);
            sprintf(score_graph,"%d",m1.total_graph[9]);
            afficher_texte(score_graph,20,m1.cordnum[9],sdlBlue);

            }
        else if(m1.nbDesParValeur[i] == 5)
            {
            s_total = s_total + (m1.nbDesParValeur[i] * i);
            carre = 1;
            brelan = 1;
            m1.total_graph[10]=(m1.nbDesParValeur[i] * i)-i;// CARRE
            m1.total_graph[9]=(m1.nbDesParValeur[i] * i)-(2*i);// BRELAN
            yam=1;
            m1.total_graph[i] = m1.nbDesParValeur[i] * i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);

            }
        else
            {

            }
        }
        if((m1.nbDesParValeur[1]!=0 && m1.nbDesParValeur[2]!=0 && m1.nbDesParValeur[3]!=0 && m1.nbDesParValeur[4]!=0) || (m1.nbDesParValeur[2]!=0 && m1.nbDesParValeur[3]!=0 && m1.nbDesParValeur[4]!=0 && m1.nbDesParValeur[5]!=0) || (m1.nbDesParValeur[3]!=0 && m1.nbDesParValeur[4]!=0 && m1.nbDesParValeur[5]!=0 && m1.nbDesParValeur[6]!=0))//petite suite
            {
            psuite = 1;
            m1.total_graph[13]=30;
            sprintf(score_graph,"%d",m1.total_graph[13]);
            afficher_texte(score_graph,20,m1.cordnum[13],sdlBlue);
            }
        else
            {
            m1.total_graph[13]=0;
            sprintf(score_graph,"%d",m1.total_graph[13]);
            afficher_texte(score_graph,20,m1.cordnum[13],sdlBlue);
            }
        if((m1.nbDesParValeur[1]!=0 && m1.nbDesParValeur[2]!=0 && m1.nbDesParValeur[3]!=0 && m1.nbDesParValeur[4]!=0 && m1.nbDesParValeur[5]!=0) || (m1.nbDesParValeur[6]!=0 && m1.nbDesParValeur[2]!=0 && m1.nbDesParValeur[3]!=0 && m1.nbDesParValeur[4]!=0 && m1.nbDesParValeur[5]!=0))//grande suite
            {
            gsuite = 1;
            psuite = 1;
            m1.total_graph[13] = 30;
            m1.total_graph[14] = 40;
            sprintf(score_graph,"%d",m1.total_graph[13]);
            afficher_texte(score_graph,20,m1.cordnum[13],sdlBlue);
            sprintf(score_graph,"%d",m1.total_graph[14]);
            afficher_texte(score_graph,20,m1.cordnum[14],sdlBlue);
            }
        else
            {
            m1.total_graph[14] = 0;
            sprintf(score_graph,"%d",m1.total_graph[14]);
            afficher_texte(score_graph,20,m1.cordnum[14],sdlBlue);
            }

        m1.total_graph[15]=s_total;
        sprintf(score_graph,"%d",m1.total_graph[15]);
        afficher_texte(score_graph,20,m1.cordnum[15],sdlBlue);
    if(brelan == 1 && paire != 1)// brelan
        {
        m1.total_graph[9] = 0;
        sprintf(score_graph,"%d",m1.total_graph[9]);// BRELAN
        afficher_texte(score_graph,20,m1.cordnum[9],sdlBlue);
        }
    else
        {
        brelan = 0;
        m1.total_graph[9] = 0;
        sprintf(score_graph,"%d",m1.total_graph[9]);// BRELAN
        afficher_texte(score_graph,20,m1.cordnum[9],sdlBlue);
        }
    if(brelan == 1 && paire == 1 && gsuite == 0 && psuite == 0)// FULL
        {
        full = 1;
        brelan = 1;
        m1.total_graph[12] = 25;
        sprintf(score_graph,"%d",m1.total_graph[12]);// FULL
        afficher_texte(score_graph,20,m1.cordnum[12],sdlBlue);
        sprintf(score_graph,"%d",m1.total_graph[9]);// BRELAN
        afficher_texte(score_graph,20,m1.cordnum[9],sdlBlue);
        }
    else
        {
        full = 0;
        m1.total_graph[12] = 0;
        sprintf(score_graph,"%d",m1.total_graph[12]);
        afficher_texte(score_graph,20,m1.cordnum[12],sdlBlue);
        }
    if(yam == 1)
        {
        m1.total_graph[11]= 50;// YAM
        sprintf(score_graph,"%d",m1.total_graph[11]);// YAM
        afficher_texte(score_graph,20,m1.cordnum[11],sdlBlue);
        }
    else
        {
        m1.total_graph[11] = 0;
        sprintf(score_graph,"%d",m1.total_graph[11]);
        afficher_texte(score_graph,20,m1.cordnum[11],sdlBlue);
        }
    if(carre == 1 && brelan == 1)
        {
        sprintf(score_graph,"%d",m1.total_graph[10]);// CARRE
        afficher_texte(score_graph,20,m1.cordnum[10],sdlBlue);
        }
    else
        {
        m1.total_graph[10]= 0;
        sprintf(score_graph,"%d",m1.total_graph[10]);
        afficher_texte(score_graph,20,m1.cordnum[10],sdlBlue);
        }

    sprintf(score_graph,"%d",s_total);
    //afficher_texte(score_graph,20,m1.cordnum[7],sdlBlue);
    afficher_texte(score_graph,20,m1.cordnum[8],sdlRed);
    printf("sous total = %d \n",s_total);
    return m1;
    }

int RenouvelerDes(Point clic)
    {
    if( (clic.x > 270 && clic.x < 337) && (clic.y > 387 && clic.y < 458) )
        {
        return 1;
        }
    else
        {
        return 0;
        }
    }


Des initDes(Des dice)
    {
    if(dice.stat != 1)
        {
        dice.valeurDes = rand()%6+1;
        dice.stat = 0;
        }
    return dice;
    }

Des afficherDes_console(Des dice)
    {
    printf("%d ",dice.valeurDes);
    printf("statut = %d \n",dice.stat);
    return dice;
    }
void afficheDes_graph(int valeurd, Point carre)
    {
    if(valeurd == 1)
        {
        afficher_image("./image/de1.bmp",carre);
        }
    else if(valeurd == 2)
        {
        afficher_image("./image/de2.bmp",carre);
        }
    else if(valeurd == 3)
        {
        afficher_image("./image/de3.bmp",carre);
        }
    else if(valeurd == 4)
        {
        afficher_image("./image/de4.bmp",carre);
        }
    else if(valeurd == 5)
        {
        afficher_image("./image/de5.bmp",carre);
        }
    else
        {
        afficher_image("./image/de6.bmp",carre);
        }
    }











