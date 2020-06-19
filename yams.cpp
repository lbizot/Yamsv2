#include "yams.h"



Yams::Yams(){
	srand(time(NULL));
    Point p={250,250};
    lb.ouvrir_fenetre(RESH,RESV);
    lb.afficher_texte("YAM's!",100,p,sdlRed);
    lb.attente(2000);
    Point afficheimage={0, 0};
    lb.afficher_image("./files/image/fondyams.bmp",afficheimage);   
    Point efface_colonne = { 204 , 0 };
    lb.afficher_image("./files/image/colonne.bmp",efface_colonne);
    total_jeu = {155,267};
 // ******* DECLARATION DéS ******

    //Des d1;
    //Des d2;
    //Des d3;
    //Des d4;
    //Des d5;
    //Main m1;

// ******* OUVERTURE FICHIER **********

	fichier = NULL;


    fichier = fopen("test.txt", "r+");

// ********************** POINT DE COORDONNEES : SCORE DU ROUND (SCORE TEMP)*****************************

    m1.cordnum[1].x = 123;//TOTAL 1
    m1.cordnum[1].y = 35;
    m1.cordnum[2].x = 123;// TOTAL 2
    m1.cordnum[2].y = 70;
    m1.cordnum[3].x = 123;// TOTAL 3
    m1.cordnum[3].y = 105;
    m1.cordnum[4].x = 123;// TOTAL 4
    m1.cordnum[4].y = 137;
    m1.cordnum[5].x = 123;// TOTAL 5
    m1.cordnum[5].y = 170;
    m1.cordnum[6].x = 123;// TOTAL 6
    m1.cordnum[6].y = 205;
    m1.cordnum[7].x = 123;// BONUS 
    m1.cordnum[7].y = 237;
    m1.cordnum[8].x = 123;// TOTAL 1
    m1.cordnum[8].y = 270;
    m1.cordnum[9].x = 123;// BRELAN
    m1.cordnum[9].y = 305;
    m1.cordnum[10].x = 123;// CARRE
    m1.cordnum[10].y = 340;
    m1.cordnum[11].x = 123;// YAM
    m1.cordnum[11].y = 470;
    m1.cordnum[12].x = 123;// FULL
    m1.cordnum[12].y = 370;
    m1.cordnum[13].x = 123;// petite suite
    m1.cordnum[13].y = 405;
    m1.cordnum[14].x = 123;// grande suite
    m1.cordnum[14].y = 437;
    m1.cordnum[15].x = 123;// chance
    m1.cordnum[15].y = 505;

// ********************* POINT DE COORDONNEES : CHOIX JOUEUR -> SAUVEGARDE ****************************
    
    psauvegarde = {175,35}; // 1
    psauvegarde2 = {175,70};// 2
    psauvegarde3 = {175,105};// 3
    psauvegarde4 = {175,137};// 4
    psauvegarde5 = {175,170};// 5
    psauvegarde6 = {175,205};// 6
    psauvegarde7 = {175,237};// BONUS
    psauvegarde8 = {175,270};// TOTAL 1
    psauvegarde9 = {175,305};// BRELAN
    psauvegarde10 = {175,340};// CARRE
    psauvegarde11 = {175, 370};// FULL 
    psauvegarde12 = {175, 405};// PETITE SUITE
    psauvegarde13 = {175, 440};// GRANDE SUITE 
    psauvegarde14 = {175, 470};// YAMS 
    psauvegarde15 = {175, 505};// CHANCE TOTAL
    psauvegarde16 = {175, 540};// TOTAL 2.1
    psauvegarde17 = {175, 575};// TOTAL 2


// ********* DECLARATION POINTS OU LES DéS SERONT AFFICHé ******

    p1 = { 440 , 200 };
    p2 = { 560 , 200 };
    p3 = { 400 , 300 };
    p4 = { 500 , 300 };
    p5 = { 600 , 300 };

// *********** VARIABLES CONCERNANT JOUEUR 1 ********************
    
    score_jeu_i2 = 0;
    score_jeu_intermediaire = 0;
    score_jeu_total = 0;//joueur 1
    case1_1 = 0;
    case2_1 = 0;
    case3_1 = 0;
    case4_1 = 0;
    case5_1 = 0;
    case6_1 = 0;
    case7_1 = 0;
    case8_1 = 0;
    case9_1 = 0;
    case12_1 = 0;
    case10_1 = 0;
    case11_1 = 0;
    case15_1 = 0;//case quand on clic dessus, le temps qu'on a pas cliqué sur toute les cases on continu le jeu. JOUEUR 1.
    t_case1_1 = 0;
    t_case2_1 = 0;
    t_case3_1 = 0;
    t_case4_1 = 0;
    t_case5_1 = 0;
    t_case6_1 = 0;
    t_case7_1 = 0;
    t_case8_1 = 0;
    t_case9_1 = 0;
    t_case12_1 = 0;
    t_case10_1 = 0;
    t_case11_1 = 0;
    t_case15_1 = 0;//JOUEUR 1

// ************** VARIABLES CONCERNANT JOUEUR 2 *****************
    
    score_jeu_intermediaire_2 = 0;
    score_jeu_i2_2 = 0;
    score_jeu_total_2 = 0;//variables joueur 2
    
    case1_2 = 0;
    case2_2 = 0;
    case3_2 = 0;
    case4_2 = 0;
    case5_2 = 0;
    case6_2 = 0;
    case7_2 = 0;
    case8_2 = 0;
    case9_2 = 0;
    case10_2 = 0;
    case11_2 = 0;
    case15_2 = 0;
    case12_2 = 0;// JOUEUR 2.
    t_case1_2 = 0;
    t_case2_2 = 0;
    t_case3_2 = 0;
    t_case4_2 = 0;
    t_case5_2 = 0;
    t_case6_2 = 0;
    t_case7_2 = 0;
    t_case8_2 = 0;
    t_case9_2 = 0;
    t_case10_2 = 0;
    t_case11_2 = 0;
    t_case12_2 = 0;
    t_case15_2 = 0;//JOUEUR 2

    Point o1 = { 600 , 20 };
    Point affiche_joueur = { 400 , 20 };
    tour_joueur = 0;
    deja_clique = 0;
    score_final = 0;
    lastscore = 0;
    score_graph[3];    
    scorejeu_graph[3];
    bonus = 0;
    runGame();
}


void Yams::runGame(){
    if (fichier != NULL)
        {
        fscanf(fichier,"%d",&score_jeu_total);
        lastscore = score_final;
        sprintf(score_graph,"LAST HIGH SCORE : %d",score_jeu_total);
        lb.afficher_texte(score_graph,15,o1,sdlWhite);
        }
    else
        {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt \n");
        }
    while(case1_1!=1 || case2_1!=1 || case3_1!=1 || case4_1!=1 || case5_1!=1 || case6_1!=1 || case7_1!=1 || case8_1 != 1 || case9_1 != 1 || case10_1 != 1 || case11_1 != 1 || case12_1 != 1 || case15_1 != 1 || case1_2!=1 || case2_2!=1 || case3_2!=1 || case4_2!=1 || case5_2!=1 || case6_2!=1 || case7_2!=1 || case8_2 != 1 || case9_2 != 1 || case10_2 != 1 || case11_2 != 1 || case12_2 != 1 || case15_2 != 1)
        {
        lb.dessiner_rectangle(affiche_joueur,87,23,background);
        if(tour_joueur % 2 == 0)
            {
            lb.afficher_texte("Joueur 1",20,affiche_joueur,sdlWhite);
            }
        else
            {
            lb.afficher_texte("Joueur 2",20,affiche_joueur,sdlWhite);
            }
        clic = lb.attendre_clic(); 

        for(i = 0; i < 3 ; i++)
            {
            if(RenouvelerDes(clic) == 1) // clic sur lancer les dés
                {
                
                
                for(k = 0 ; k < 8 ; k++)
                    {
                    lb.attente(120);
                    d1 = initDes(d1);
                    d2 = initDes(d2);
                    d3 = initDes(d3);
                    d4 = initDes(d4);
                    d5 = initDes(d5);
                    afficheDes_graph(d1.valeurDes, p1);
                    afficheDes_graph(d2.valeurDes, p2);
                    afficheDes_graph(d3.valeurDes, p3);
                    afficheDes_graph(d4.valeurDes, p4);
                    afficheDes_graph(d5.valeurDes, p5); 
                    }
                d1 = afficherDes_console(d1);
                d2 = afficherDes_console(d2);
                d3 = afficherDes_console(d3);
                d4 = afficherDes_console(d4);
                d5 = afficherDes_console(d5);
                
                clic = lb.attendre_clic();
                }
            else
                {
                clic = lb.attendre_clic();
                }
            while(RenouvelerDes(clic) != 1) // TACHE A FAIRE : CREER LA POSSIBILITE DANNULER NOTRE CHOIX DE SELECTION DE DéS
                {
                
                if( (clic.x > 440 && clic.x < 500) && (clic.y > 200 && clic.y < 260) && d1.stat == 0)
                    {
                    lb.dessiner_rectangle(p1,60,60,plateau);
                    p1.x -= 120;
                    p1.y += 313;
                    afficheDes_graph(d1.valeurDes, p1);
                    d1.stat = 1;
                    sauv[i] = 1;
                    } 
                else if( (clic.x > 560 && clic.x < 620) && (clic.y > 200 && clic.y < 260) && d2.stat == 0)
                    {
                    lb.dessiner_rectangle(p2,60,60,plateau);
                    p2.x -= 150;
                    p2.y += 313;
                    afficheDes_graph(d2.valeurDes, p2);
                    d2.stat = 1;
                    sauv[i] = 1;
                    }
                else if( (clic.x > 400 && clic.x < 460) && (clic.y > 300 && clic.y < 360) && d3.stat == 0)
                    {
                    lb.dessiner_rectangle(p3,60,60,plateau);
                    p3.x += 100;
                    p3.y += 213;
                    afficheDes_graph(d3.valeurDes, p3);
                    d3.stat = 1;
                    sauv[i] = 1;    
                    }
                else if( (clic.x > 500 && clic.x < 560) && (clic.y > 300 && clic.y < 360) && d4.stat == 0)
                    {
                    lb.dessiner_rectangle(p4,60,60,plateau);
                    p4.x += 90;
                    p4.y += 213;
                    afficheDes_graph(d4.valeurDes, p4);
                    d4.stat = 1;
                    sauv[i] = 1;    
                    }
                else if( (clic.x > 600 && clic.x < 660) && (clic.y > 300 && clic.y < 360) && d5.stat == 0)
                    {
                    lb.dessiner_rectangle(p5,60,60,plateau);
                    p5.x += 83;
                    p5.y += 213;
                    afficheDes_graph(d5.valeurDes, p5);
                    d5.stat = 1;
                    sauv[i] = 1;    
                    }
                else
                    {
                    
                    }
                    
                    
//******************************************* ANNULER CLIC ************************************* 


                if( (clic.x > 320 && clic.x < 380) && (clic.y > 513 && clic.y < 573) && (d1.stat == 1 && sauv[i]==1) )
                    {
                    lb.dessiner_rectangle(p1,60,60,plateau);
                    p1.x += 120;
                    p1.y -= 313;
                    afficheDes_graph(d1.valeurDes, p1);
                    d1.stat = 0;
                    } 
                else if( (clic.x > 410 && clic.x < 470) && (clic.y > 513 && clic.y < 573) && (d2.stat == 1 && sauv[i]==1) )
                    {
                    lb.dessiner_rectangle(p2,60,60,plateau);
                    p2.x += 150;
                    p2.y -= 313;
                    afficheDes_graph(d2.valeurDes, p2);
                    d2.stat = 0;
                    }
                else if( (clic.x > 500 && clic.x < 560) && (clic.y > 513 && clic.y < 573) && (d3.stat == 1 && sauv[i]==1) )
                    {
                    lb.dessiner_rectangle(p3,60,60,plateau);
                    p3.x -= 100;
                    p3.y -= 213;
                    afficheDes_graph(d3.valeurDes, p3);
                    d3.stat = 0;
                    }
                else if( (clic.x > 590 && clic.x < 650) && (clic.y > 513 && clic.y < 573) && (d4.stat == 1 && sauv[i]==1) )
                    {
                    lb.dessiner_rectangle(p4,60,60,plateau);
                    p4.x -= 90;
                    p4.y -= 213;
                    afficheDes_graph(d4.valeurDes, p4);
                    d4.stat = 0;
                    }
                else if( (clic.x > 683 && clic.x < 743) && (clic.y > 513 && clic.y < 573) && (d5.stat == 1 && sauv[i]==1) )
                    {
                    lb.dessiner_rectangle(p5,60,60,plateau);
                    p5.x -= 83;
                    p5.y -= 213;
                    afficheDes_graph(d5.valeurDes, p5);
                    d5.stat = 0;
                    }
                else
                    {
                    
                    }
                
                // *************************** FIN ****************************************
                
                
                clic = lb.attendre_clic();
                RenouvelerDes(clic);
                }
                if(d1.stat == 1 && d2.stat == 1 && d3.stat == 1 && d4.stat == 1 && d5.stat == 1 ) break;
    
            }
            m1.tab[0] = d1.valeurDes;
            m1.tab[1] = d2.valeurDes;
            m1.tab[2] = d3.valeurDes;
            m1.tab[3] = d4.valeurDes;
            m1.tab[4] = d5.valeurDes;
            m1 = compte_combi(m1);
            m1 = combi(m1);
            
    //****************** SAUVEGARDE DU SCORE JOUEUR 1 *************************
            if(tour_joueur%2 == 0)
                {
                choix_score = lb.attendre_clic();
                do
                    {
                    if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 32 && choix_score.y < 65) && case1_1 == 0)
                        {
                        sprintf(score_graph,"%d",m1.total_graph[1]);
                        lb.afficher_texte(score_graph,20,psauvegarde,sdlGris);
                        case1_1 = 1;
                        t_case1_1 = m1.total_graph[1];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 65 && choix_score.y < 98) && case2_1 == 0)
                        {
                        sprintf(score_graph,"%d",m1.total_graph[2]);
                        lb.afficher_texte(score_graph,20,psauvegarde2,sdlGris);
                        case2_1 = 1;
                        t_case2_1 = m1.total_graph[2];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 98 && choix_score.y < 131) && case3_1 == 0)
                        {
                        sprintf(score_graph,"%d",m1.total_graph[3]);
                        lb.afficher_texte(score_graph,20,psauvegarde3,sdlGris);
                        case3_1 = 1;
                        t_case3_1 = m1.total_graph[3];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 131 && choix_score.y < 164) && case4_1 == 0)
                        {
                        sprintf(score_graph,"%d",m1.total_graph[4]);
                        lb.afficher_texte(score_graph,20,psauvegarde4,sdlGris);
                        case4_1 = 1;
                        t_case4_1 = m1.total_graph[4];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 164 && choix_score.y < 197) && case5_1 == 0 )
                        {
                        sprintf(score_graph,"%d",m1.total_graph[5]);
                        lb.afficher_texte(score_graph,20,psauvegarde5,sdlGris);
                        case5_1 = 1;
                        t_case5_1 = m1.total_graph[5];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 200 && choix_score.y < 232) && case6_1 == 0 )
                        {
                        sprintf(score_graph,"%d",m1.total_graph[6]);
                        lb.afficher_texte(score_graph,20,psauvegarde6,sdlGris);
                        case6_1 = 1;
                        t_case6_1 = m1.total_graph[6];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 300 && choix_score.y < 332) && case7_1 == 0 ) // BRELAN
                        {
                        sprintf(score_graph,"%d",m1.total_graph[9]);
                        lb.afficher_texte(score_graph,20,psauvegarde9,sdlGris);
                        case7_1 = 1;
                        t_case7_1 = m1.total_graph[9];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 332 && choix_score.y < 364) && case8_1 == 0 ) // CARRE
                        {
                        sprintf(score_graph,"%d",m1.total_graph[10]);
                        lb.afficher_texte(score_graph,20,psauvegarde10,sdlGris);
                        case8_1 = 1;
                        t_case8_1 = m1.total_graph[10];
                        deja_clique = 1;
                        }           
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 364 && choix_score.y < 396) && case9_1 == 0 ) // FULL
                        {
                        sprintf(score_graph,"%d",m1.total_graph[12]);
                        lb.afficher_texte(score_graph,20,psauvegarde11,sdlGris);
                        case9_1 = 1;
                        t_case9_1 = m1.total_graph[12];
                        deja_clique = 1; 
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 396 && choix_score.y < 428) && case10_1 == 0 ) // PETITE SUITE
                        {
                        sprintf(score_graph,"%d",m1.total_graph[13]);
                        lb.afficher_texte(score_graph,20,psauvegarde12,sdlGris);
                        case10_1 = 1;
                        t_case10_1 = m1.total_graph[13];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 428 && choix_score.y < 460) && case11_1 == 0 ) // GRANDE SUITE
                        {
                        sprintf(score_graph,"%d",m1.total_graph[14]);
                        lb.afficher_texte(score_graph,20,psauvegarde13,sdlGris);
                        case11_1 = 1;
                        t_case11_1 = m1.total_graph[14];
                        deja_clique = 1;
                        }           
                    else if( (choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 460 && choix_score.y < 492) && case12_1 == 0 ) // YAM
                        {
                        sprintf(score_graph,"%d",m1.total_graph[11]);
                        lb.afficher_texte(score_graph,20,psauvegarde14,sdlGris);
                        case12_1 = 1;
                        t_case12_1 = m1.total_graph[11];
                        deja_clique = 1;
                        }
                    else if( ((choix_score.x > 155 && choix_score.x < 205) && (choix_score.y > 501 && choix_score.y < 533)) && case15_1 == 0 ) // chance
                        {
                        sprintf(score_graph,"%d",m1.total_graph[15]);
                        lb.afficher_texte(score_graph,20,psauvegarde15,sdlGris);
                        case15_1 = 1;
                        t_case15_1 = m1.total_graph[15];
                        deja_clique = 1;                
                        }                                                   
                    else 
                        {
                        choix_score = lb.attendre_clic();
                        }       
                    }while(DecisionJoueur(choix_score) != 1 || deja_clique != 1);
                deja_clique = 0; // remet à 0 pour le prochain tour ;)  
                score_jeu_intermediaire = t_case1_1 + t_case2_1 + t_case3_1 + t_case4_1 + t_case5_1 + t_case6_1;
                if(score_jeu_intermediaire > 62)
                    {
                    bonus = 35;
                    score_jeu_intermediaire += 35;
                    }
                else
                    {
                    bonus = 0;
                    }
                    sprintf(scorejeu_graph,"%d",bonus);
                    lb.afficher_texte(scorejeu_graph,20,psauvegarde7,sdlRed);
                score_jeu_i2 = t_case7_1 + t_case8_1 + t_case9_1 + t_case10_1 + t_case11_1 + t_case12_1 + t_case15_1;
                score_jeu_total = score_jeu_intermediaire + score_jeu_i2;
                sprintf(scorejeu_graph,"%d",score_jeu_intermediaire);
                cleanScore_jeu(total_jeu);
                lb.afficher_texte(scorejeu_graph,20,psauvegarde7,sdlGris);
                lb.afficher_texte(scorejeu_graph,20,psauvegarde8,sdlRed);
                sprintf(scorejeu_graph,"%d",score_jeu_i2);
                lb.afficher_texte(scorejeu_graph,20,psauvegarde16,sdlRed);
                sprintf(scorejeu_graph,"%d",score_jeu_total);
                lb.afficher_texte(scorejeu_graph,20,psauvegarde17,sdlWhite);
                
                }
            else // JOUEUR 2 A PARTIR D'ICI
                {
                choix_score = lb.attendre_clic();
                do
                    {
                    if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 32 && choix_score.y < 65) && case1_2 == 0)
                        {
                        psauvegarde.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[1]);
                        lb.afficher_texte(score_graph,20,psauvegarde,sdlGris);
                        psauvegarde.x -= 33;
                        case1_2 = 1;
                        t_case1_2 = m1.total_graph[1];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 65 && choix_score.y < 98) && case2_2 == 0)
                        {
                        psauvegarde2.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[2]);
                        lb.afficher_texte(score_graph,20,psauvegarde2,sdlGris);
                        psauvegarde2.x -= 33;
                        case2_2 = 1;
                        t_case2_2 = m1.total_graph[2];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 98 && choix_score.y < 131) && case3_2 == 0)
                        {
                        psauvegarde3.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[3]);
                        lb.afficher_texte(score_graph,20,psauvegarde3,sdlGris);
                        psauvegarde3.x -= 33;
                        case3_2 = 1;
                        t_case3_2 = m1.total_graph[3];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 131 && choix_score.y < 164) && case4_2 == 0)
                        {
                        psauvegarde4.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[4]);
                        lb.afficher_texte(score_graph,20,psauvegarde4,sdlGris);
                        psauvegarde4.x -= 33;
                        case4_2 = 1;
                        t_case4_2 = m1.total_graph[4];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 164 && choix_score.y < 197) && case5_2 == 0 )
                        {
                        psauvegarde5.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[5]);
                        lb.afficher_texte(score_graph,20,psauvegarde5,sdlGris);
                        psauvegarde5.x -= 33;
                        case5_2 = 1;
                        t_case5_2 = m1.total_graph[5];
                        deja_clique = 1; 
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 200 && choix_score.y < 232) && case6_2 == 0 )
                        {
                        psauvegarde6.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[6]);
                        lb.afficher_texte(score_graph,20,psauvegarde6,sdlGris);
                        psauvegarde6.x -= 33;
                        case6_2 = 1;
                        t_case6_2 = m1.total_graph[6];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 300 && choix_score.y < 332) && case7_2 == 0 ) // BRELAN
                        {
                        psauvegarde9.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[9]);
                        lb.afficher_texte(score_graph,20,psauvegarde9,sdlGris);
                        psauvegarde9.x -= 33;
                        case7_2 = 1;
                        t_case7_2 = m1.total_graph[9];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 332 && choix_score.y < 364) && case8_2 == 0 ) // CARRE
                        {
                        psauvegarde10.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[10]);
                        lb.afficher_texte(score_graph,20,psauvegarde10,sdlGris);
                        psauvegarde10.x -= 33;
                        case8_2 = 1;
                        t_case8_2 = m1.total_graph[10];
                        deja_clique = 1;
                        }           
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 364 && choix_score.y < 396) && case9_2 == 0 ) // FULL
                        {
                        psauvegarde11.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[12]);
                        lb.afficher_texte(score_graph,20,psauvegarde11,sdlGris);
                        psauvegarde11.x -= 33;
                        case9_2 = 1;
                        t_case9_2 = m1.total_graph[12];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 396 && choix_score.y < 428) && case10_2 == 0 ) // PETITE SUITE
                        {
                        psauvegarde12.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[13]);
                        lb.afficher_texte(score_graph,20,psauvegarde12,sdlGris);
                        psauvegarde12.x -= 33;
                        case10_2 = 1;
                        t_case10_2 = m1.total_graph[13];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 428 && choix_score.y < 460) && case11_2 == 0 ) // GRANDE SUITE
                        {
                        psauvegarde13.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[14]);
                        lb.afficher_texte(score_graph,20,psauvegarde13,sdlGris);
                        psauvegarde13.x -= 33;
                        case11_2 = 1;
                        t_case11_2 = m1.total_graph[14];
                        deja_clique = 1;
                        }
                    else if( (choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 460 && choix_score.y < 492) && case12_2 == 0 ) // YAM
                        {
                        psauvegarde14.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[11]);
                        lb.afficher_texte(score_graph,20,psauvegarde14,sdlGris);
                        psauvegarde14.x -= 33;
                        case12_2 = 1;
                        t_case12_2 = m1.total_graph[11];
                        deja_clique = 1;
                        }
                    
                    else if((choix_score.x > 188 && choix_score.x < 238) && (choix_score.y > 501 && choix_score.y < 533) && case15_2 == 0 ) // chance
                        {
                        psauvegarde15.x += 33;
                        sprintf(score_graph,"%d",m1.total_graph[15]);
                        lb.afficher_texte(score_graph,20,psauvegarde15,sdlGris);
                        psauvegarde15.x -= 33;
                        case15_2 = 1;
                        t_case15_2 = m1.total_graph[15];
                        deja_clique = 1;                
                        }                                                                       
                    else 
                        {
                        choix_score = lb.attendre_clic();
                        }       
                }while(DecisionJoueur2(choix_score) != 1 || deja_clique != 1);
                deja_clique = 0; // remet à 0 pour le prochain tour ;)  
                score_jeu_intermediaire_2 = t_case1_2 + t_case2_2 + t_case3_2 + t_case4_2 + t_case5_2 + t_case6_2;
                if(score_jeu_intermediaire_2 > 62)
                    {
                    bonus = 35;
                    score_jeu_intermediaire_2 += 35;
                    }
                else
                    {
                    bonus = 0;
                    } 
                    sprintf(scorejeu_graph,"%d",bonus);
                    lb.afficher_texte(scorejeu_graph,20,psauvegarde7,sdlRed);
                score_jeu_i2_2 = t_case7_2 + t_case8_2 + t_case9_2 + t_case12_2 + t_case10_2 + t_case11_2 + t_case15_2;
                score_jeu_total_2 = score_jeu_intermediaire_2 + score_jeu_i2_2;
                sprintf(scorejeu_graph,"%d",score_jeu_intermediaire_2);
                cleanScore_jeu2(total_jeu);
                lb.afficher_texte(scorejeu_graph,20,psauvegarde7,sdlGris);
                psauvegarde8.x += 33;
                lb.afficher_texte(scorejeu_graph,20,psauvegarde8,sdlRed);
                psauvegarde8.x -= 33;
                sprintf(scorejeu_graph,"%d",score_jeu_i2_2);
                psauvegarde16.x += 33;
                lb.afficher_texte(scorejeu_graph,20,psauvegarde16,sdlRed);
                psauvegarde16.x -= 33;
                sprintf(scorejeu_graph,"%d",score_jeu_total_2);
                psauvegarde17.x += 33;
                lb.afficher_texte(scorejeu_graph,20,psauvegarde17,sdlWhite);
                psauvegarde17.x -= 33;
                }
                tour_joueur ++;         
            
// *********************************************************************************
            effaceDesLock_graph(p1);
            effaceDesLock_graph(p2);
            effaceDesLock_graph(p3);
            effaceDesLock_graph(p4);
            effaceDesLock_graph(p5);
            p1 = RenouvellementDes1(d1,p1);
            p2 = RenouvellementDes2(d2,p2);
            p3 = RenouvellementDes3(d3,p3);
            p4 = RenouvellementDes4(d4,p4);
            p5 = RenouvellementDes5(d5,p5);
            d1 = unlock(d1);
            d2 = unlock(d2);
            d3 = unlock(d3);
            d4 = unlock(d4);
            d5 = unlock(d5);
            cleanScore_tmp();
        }
    if(score_jeu_total < score_jeu_total_2)
        {
        score_final = score_jeu_total_2;
        }
    else
        {
        score_final = score_jeu_total; 
        }
    if (fichier != NULL)
        {
        if(lastscore < score_final)
            {
            fseek(fichier,0,SEEK_SET);
            fprintf(fichier,"%d",score_final);
            fscanf(fichier,"%d",&score_final);
            fclose(fichier);
            }
        else
            {
            printf("Vous avez fait un score inférieur au joueur précédent \n");
            }
        }

    lb.attendre_clic();
    lb.fermer_fenetre();
}


int Yams::DecisionJoueur(Point p1){
    if( ((p1.x > 155 && p1.x < 205) && (p1.y > 32 && p1.y < 232)) || ((p1.x > 155 && p1.x < 205) && (p1.y > 300 && p1.y < 550)))
        {
        return 1;
        }
    else
        {
        return 0;
        }

}

int Yams::DecisionJoueur2(Point p1){
    if( ((p1.x > 188 && p1.x < 238) && (p1.y > 32 && p1.y < 232)) || ((p1.x > 188 && p1.x < 238) && (p1.y > 300 && p1.y < 550)))
        {
        return 1;
        }
    else
        {
        return 0;
        }

}


void Yams::cleanScore_jeu(Point jeu){
    jeu.y -= 33;
    lb.afficher_image("./files/image/carre_jaune.bmp",jeu);
    jeu.y += 33;
    lb.afficher_image("./files/image/carre_jaune.bmp",jeu);
    jeu.y += 33 * 8;
    jeu.y += 4;
    lb.afficher_image("./files/image/carre_jaune.bmp",jeu);
    jeu.y += 33;
    lb.dessiner_rectangle(jeu,50,33,totaux);
}

void Yams::cleanScore_jeu2(Point jeu){
    jeu.x += 50;
    jeu.y -= 33;
    lb.afficher_image("./files/image/carre_jaune.bmp",jeu);
    jeu.y += 33;
    lb.afficher_image("./files/image/carre_jaune.bmp",jeu);
    jeu.y += 33 * 8;
    jeu.y += 4;
    lb.afficher_image("./files/image/carre_jaune.bmp",jeu);
    jeu.y += 33;
    lb.dessiner_rectangle(jeu,50,33,totaux);
}

void Yams::cleanScore_tmp(){
    Point efface_colonne = { 102 , 0 };
    lb.afficher_image("./files/image/colonne.bmp",efface_colonne);
}

void Yams::effaceDesLock_graph(Point p1){
    lb.dessiner_rectangle(p1,60,60,plateau);
}

Point Yams::RenouvellementDes1(Des d1, Point p1){
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

Point Yams::RenouvellementDes2(Des d1, Point p1){
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

Point Yams::RenouvellementDes3(Des d1, Point p1){
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

Point Yams::RenouvellementDes4(Des d1, Point p1){
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

Point Yams::RenouvellementDes5(Des d1, Point p1){
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

Des Yams::unlock(Des dice){
    dice.stat = 0;
    return dice;
}

Main Yams::compte_combi(Main m1){
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
        }
    return m1;
}

Main Yams::combi(Main m1){
    int i, s_total = 0,carre = 0,brelan = 0,yam=0,paire = 0,full = 0,psuite=0,gsuite=0;
    char score_graph[3];
    for(i = 1; i < 7 ; i++)
        {
        if(m1.nbDesParValeur[i]==0)
            {
            s_total = s_total + 0;
            m1.total_graph[i] = 0;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            lb.afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            }
        else if(m1.nbDesParValeur[i] == 1)
            {
            s_total = s_total + i;
            m1.total_graph[i] = i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            lb.afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            }
        else if(m1.nbDesParValeur[i] == 2)
            {
            s_total = s_total + (m1.nbDesParValeur[i] * i);
            //pairepourfull=1; on pourrai augmenter la variable de 1 quand on a une paire
            m1.total_graph[i] = m1.nbDesParValeur[i] * i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            paire = 1;
            lb.afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            }
        else if(m1.nbDesParValeur[i] == 3)
            {
            s_total = s_total + (m1.nbDesParValeur[i] * i);
            brelan=1;
            m1.total_graph[i] = m1.nbDesParValeur[i] * i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            lb.afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            m1.total_graph[9] = (m1.nbDesParValeur[i] * i);
            }
        else if(m1.nbDesParValeur[i] == 4)
            {
            s_total = s_total + (m1.nbDesParValeur[i] * i);
            m1.total_graph[i] = m1.nbDesParValeur[i] * i;
            sprintf(score_graph,"%d",m1.total_graph[i]);
            lb.afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);
            carre=1;
            m1.total_graph[10] = m1.nbDesParValeur[i] * i;
            brelan=1;
            m1.total_graph[9] = (m1.nbDesParValeur[i] * i)-i;
            sprintf(score_graph,"%d",m1.total_graph[10]);
            lb.afficher_texte(score_graph,20,m1.cordnum[10],sdlBlue);
            sprintf(score_graph,"%d",m1.total_graph[9]);
            lb.afficher_texte(score_graph,20,m1.cordnum[9],sdlBlue);

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
            lb.afficher_texte(score_graph,20,m1.cordnum[i],sdlBlue);

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
            lb.afficher_texte(score_graph,20,m1.cordnum[13],sdlBlue);
            }
        else
            {
            m1.total_graph[13]=0;
            sprintf(score_graph,"%d",m1.total_graph[13]);
            lb.afficher_texte(score_graph,20,m1.cordnum[13],sdlBlue);
            }
        if((m1.nbDesParValeur[1]!=0 && m1.nbDesParValeur[2]!=0 && m1.nbDesParValeur[3]!=0 && m1.nbDesParValeur[4]!=0 && m1.nbDesParValeur[5]!=0) || (m1.nbDesParValeur[6]!=0 && m1.nbDesParValeur[2]!=0 && m1.nbDesParValeur[3]!=0 && m1.nbDesParValeur[4]!=0 && m1.nbDesParValeur[5]!=0))//grande suite
            {
            gsuite = 1;
            psuite = 1;
            m1.total_graph[13] = 30;
            m1.total_graph[14] = 40;
            sprintf(score_graph,"%d",m1.total_graph[13]);
            lb.afficher_texte(score_graph,20,m1.cordnum[13],sdlBlue);
            sprintf(score_graph,"%d",m1.total_graph[14]);
            lb.afficher_texte(score_graph,20,m1.cordnum[14],sdlBlue);
            }
        else
            {
            m1.total_graph[14] = 0;
            sprintf(score_graph,"%d",m1.total_graph[14]);
            lb.afficher_texte(score_graph,20,m1.cordnum[14],sdlBlue);
            }

        m1.total_graph[15]=s_total;
        sprintf(score_graph,"%d",m1.total_graph[15]);
        lb.afficher_texte(score_graph,20,m1.cordnum[15],sdlBlue);
    if(brelan == 1 && paire != 1)// brelan
        {
        m1.total_graph[9] = 0;
        sprintf(score_graph,"%d",m1.total_graph[9]);// BRELAN
        lb.afficher_texte(score_graph,20,m1.cordnum[9],sdlBlue);
        }
    else
        {
        brelan = 0;
        m1.total_graph[9] = 0;
        sprintf(score_graph,"%d",m1.total_graph[9]);// BRELAN
        lb.afficher_texte(score_graph,20,m1.cordnum[9],sdlBlue);
        }
    if(brelan == 1 && paire == 1 && gsuite == 0 && psuite == 0)// FULL
        {
        full = 1;
        brelan = 1;
        m1.total_graph[12] = 25;
        sprintf(score_graph,"%d",m1.total_graph[12]);// FULL
        lb.afficher_texte(score_graph,20,m1.cordnum[12],sdlBlue);
        sprintf(score_graph,"%d",m1.total_graph[9]);// BRELAN
        lb.afficher_texte(score_graph,20,m1.cordnum[9],sdlBlue);
        }
    else
        {
        full = 0;
        m1.total_graph[12] = 0;
        sprintf(score_graph,"%d",m1.total_graph[12]);
        lb.afficher_texte(score_graph,20,m1.cordnum[12],sdlBlue);
        }
    if(yam == 1)
        {
        m1.total_graph[11]= 50;// YAM
        sprintf(score_graph,"%d",m1.total_graph[11]);// YAM
        lb.afficher_texte(score_graph,20,m1.cordnum[11],sdlBlue);
        }
    else
        {
        m1.total_graph[11] = 0;
        sprintf(score_graph,"%d",m1.total_graph[11]);
        lb.afficher_texte(score_graph,20,m1.cordnum[11],sdlBlue);
        }
    if(carre == 1 && brelan == 1)
        {
        sprintf(score_graph,"%d",m1.total_graph[10]);// CARRE
        lb.afficher_texte(score_graph,20,m1.cordnum[10],sdlBlue);
        }
    else
        {
        m1.total_graph[10]= 0;
        sprintf(score_graph,"%d",m1.total_graph[10]);
        lb.afficher_texte(score_graph,20,m1.cordnum[10],sdlBlue);
        }

    sprintf(score_graph,"%d",s_total);
    lb.afficher_texte(score_graph,20,m1.cordnum[7],sdlBlue);
    lb.afficher_texte(score_graph,20,m1.cordnum[8],sdlRed);
    return m1;
}

int Yams::RenouvelerDes(Point clic){
    if( (clic.x > 270 && clic.x < 337) && (clic.y > 387 && clic.y < 458) )
        {
        return 1;
        }
    else
        {
        return 0;
        }
}


Des Yams::initDes(Des dice){
    if(dice.stat != 1)
        {
        dice.valeurDes = (int)rand()%6+1;
        dice.stat = 0;
        }
    return dice;
}

Des Yams::afficherDes_console(Des dice){
    return dice;
}
    
void Yams::afficheDes_graph(int valeurd, Point carre){
    if(valeurd == 1)
        {
        lb.afficher_image("./files/image/de1.bmp",carre);
        }
    else if(valeurd == 2)
        {
        lb.afficher_image("./files/image/de2.bmp",carre);
        }
    else if(valeurd == 3)
        {
        lb.afficher_image("./files/image/de3.bmp",carre);
        }
    else if(valeurd == 4)
        {
        lb.afficher_image("./files/image/de4.bmp",carre);
        }
    else if(valeurd == 5)
        {
        lb.afficher_image("./files/image/de5.bmp",carre);
        }
    else
        {
        lb.afficher_image("./files/image/de6.bmp",carre);
        }
}