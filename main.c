#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <time.h>
#include "prototype.h"
#include <string.h>
int main()
{   char option;//pour l option entre par l utilisateur
    char joueur1[100];//nom du joueur1
    char joueur2[100];//nom du joueur2
    int couleur_piecej1;//un pion
    int couleur_piecej2;//un pion
    int joueurCommence;//le resultat de l'aleatoire
    int j ,i ;//pour le parcours des boucle
	int MIN = 1 , MAX = 2;//pour definir l'intervalle de random
	int optdifficulte;//pour une entree du menu
    int mode_affec;//pour une entree du menu
    int choix_comm;//pour une entree du menu
    remplissagemat();//remplissage de la matrice mat (mat est une variable globale)
    int gagnantn;
    int gagnantb;
    gagnant=0;
    compt=0;
	srand(time(NULL));//pour intialiser la fct srand sur le temps actuel
	joueurCommence = (rand() % (MAX - MIN + 1)) + MIN;//le resultat de l'aleatoire


    system("COLOR 31");//pour changer la couleur du fond d ecran de la console ainsi que la couleur du texte


do
    {
    system("cls");//pour effacer la console
    for (i=0;i<20;i++)//decor
    printf("/ \\" );
    printf("\n");
    for (i=0;i<20;i++)
        printf("| |");
    printf("\n");
    for (i=0;i<20;i++)
    printf("\\ /");
    printf("\n");
    printf("\t\t Bienvenue dans le jeu Hex\n");
    for (i=0;i<20;i++)
    printf("/ \\" );
    printf("\n");
    for (i=0;i<20;i++)
    printf("| |");
    printf("\n");
    for (i=0;i<20;i++)
    printf("\\ /");





    printf("\n Choisissez une option en tapant le numero correspondant :\n");//ecrire les choix possibles
    printf("1:Partie contre humain\n");
    printf("2:partie contre ordinateur\n");
    printf("3:Lire les regles du jeu\n");
    printf("4:Quitter\n");
    printf("Tapez votre choix : ");
    scanf("%c",&option);

    switch (option)//pour definir le menu
      {

           case '1' ://le 1er choix :la partie humain vs humain
           {


               printf("Vous allez jouer une partie contre un humain\n");
               printf("Quel est le nom du joueur 1 ? ");//Entrer le nom des 2 joueurs
               scanf("%s",&joueur1);
               do{printf("Quel est le nom du joueur 2 ? ");
               scanf("%s",&joueur2);}
               while(strcmp(joueur1,joueur2)==0);//les noms doivent etre different l'un de l'autre

               if(joueurCommence==1)// Si la variable de l'aleatoire correspond a 1 le 1er joueur commence
                    {printf("\n%s commence avec les noirs\n",joueur1);
                    couleur_piecej1=2;//On affecte 2 a la couleur du 1er joueur qui signifie le noir
                    couleur_piecej2=1;}//On affecte 1 a la couleur du 2er joueur qui signifie le blanc
                else // Si la variable de l'aleatoire correspond a 2 le 2eme joueur commence
                { printf("\n%s commence avec les noirs\n ",joueur2);
                couleur_piecej1=1;
                couleur_piecej2=2;
                    }

                    system("pause");
                    system("cls");
                    plateau();//On efface la console et on affiche le plateau


           while(gagnant==0)  { gotoxy(0,45);//les 2 joueurs jouent a tour de role jusqu'a ce que la valeur de gagnant change

                   if(joueurCommence==1)//le tour du 1er joueur
                        {
                            printf("c est votre tour\a, %s\n",joueur1);
                            afficher(couleur_piecej1);//on affiche le numero de la couleur sur le plateau
                            joueurCommence=2;//on permute la valeur
                        }

                    else if(joueurCommence==2)//le tour du 2eme joueur
                        {  gotoxy(0,45);
                           printf("c est votre tour\a\a, %s\n",joueur2);
                           afficher(couleur_piecej2);//on affiche le numero de la couleur sur le plateau
                           joueurCommence=1;//on permute la valeur
                        }

                    gagnantb=gagnantblanc();//test de ligne droite pour les blancs
                    gagnantn=gagnantnoir();//test de ligne droite pour les noirs
                    if (gagnantn==2)
                        {gotoxy(0,65);
                            printf("\n\n\n\t\t***************************************\n\t\t\tLes noirs ont gagne\n\t\t***************************************\n");
                            break;}
                    if(gagnantb==1)
                    {gotoxy(0,65);
                    printf("\n\n\n\t\t***************************************\n\t\t\tLes blancs ont gagne\n\t\t***************************************\n");
                    break;}

            }system("pause");

            }break;


            case '2' ://Commencer la partie  option ordinateur
           {    system("cls");//effacer la console
               printf("Vous avez choisi de commencer une nouvelle partie contre ordinateur\n");//decor
                for (i=0;i<20;i++)
                    printf("/ \\" );
                    printf("\n");
                for (i=0;i<20;i++)
                    printf("| |");
                    printf("\n");
                for (i=0;i<20;i++)
                    printf("\\ /");
                    printf("\n");
                    printf("\t\t Partie contre ordinateur\n");
                for (i=0;i<20;i++)
                    printf("/ \\" );
                    printf("\n");
                for (i=0;i<20;i++)
                    printf("| |");
                    printf("\n");
                for (i=0;i<20;i++)
                    printf("\\ /");

                printf("\n\n Choisissez une difficulte du jeu en tapant le numero correspondant :\n");//ecrire le menu de la partie ordinateur
                printf("1:Option facile\n");
                printf("2:Option difficile\n");
                printf("Tapez votre choix : ");
                scanf("%d",&optdifficulte);
                switch (optdifficulte)//switch sur le menu de la difficulte de la partie jouee
                     {

                            case 1 :
                                    {  system("cls");//effacer la console
                                       printf("Vous allez jouer une partie facile contre ordinateur\n");//decor
                                       for (i=0;i<20;i++)
                                           printf("/ \\" );
                                           printf("\n");
                                       for (i=0;i<20;i++)
                                           printf("| |");
                                           printf("\n");
                                       for (i=0;i<20;i++)
                                            printf("\\ /");
                                            printf("\n");
                                            printf("\t\t Partie facile contre ordinateur\n");
                                       for (i=0;i<20;i++)
                                            printf("/ \\" );
                                            printf("\n");
                                       for (i=0;i<20;i++)
                                            printf("| |");
                                            printf("\n");
                                       for (i=0;i<20;i++)
                                            printf("\\ /");

                                        printf("\n\n\n Choisissez le mode d'affectation en tapant le numero correspondant\n\n\n");//ecrire le menu du mode de choix
                                        printf("1:Mode choix humain\n");
                                        printf("2:Mode choix adversaire(machine)\n");
                                        printf("Tapez votre choix : ");
                                        scanf("%d",&mode_affec);

                                        switch (mode_affec)//,enu du mode choix
                                            {
                                                     case 1 : //mode humain
                                                         { printf("\n\n\nChoisissez qui commencera le premier en tapant le numero correspondant\n\n\n");
                                                           printf("1:Vous commencez\n");
                                                           printf("2:L'ordinateur commence\n");
                                                           printf("Tapez votre choix : ");
                                                           scanf("%d",&choix_comm);
                                                           switch (choix_comm)
                                                                        {
                                                                                 case 1 ://l'humain commence
                                                                                     { printf("\n\n\nVous commencez avec les pions noirs\n");
                                                                                       printf("Entrez votre nom:");
                                                                                       scanf("%s",joueur1);
                                                                                       system("pause");
                                                                                       system("cls");//effacer la console
                                                                                       plateau();//Charger le plateau
                                                                                        while(gagnant==0)//les tours
                                                                                            { gotoxy(0,40);

                                                                                                printf("c est votre tour\a, %s\n",joueur1);
                                                                                                afficher(2);//affichage du numero correspondant a la couleur sue le plateau
                                                                                                gotoxy(0,45);
                                                                                                joueur_ordinateur(1);//tour de l'ordinateur et affichage sur plateau
                                                                                                gagnantb=gagnantblanc();//test de la ligne continue pour les blancs
                                                                                                gagnantn=gagnantnoir();//test de la ligne continue pour les noirs
                                                                                                if (gagnantn==2)
                                                                                                    {gotoxy(0,65);
                                                                                                    printf("\n\n\n\t\t***************************************\n\t\t\t%s a gagne\n\t\t***************************************\n",joueur1);
                                                                                                    break;}
                                                                                                if(gagnantb==1)
                                                                                                        {gotoxy(0,65);
                                                                                                            printf("\n\n\n\t\t***************************************\n\t\t\tL ordinateur a gagne\n\t\t***************************************\n");
                                                                                                            break;}


                                                                                                }system("pause");

                                                                                     }break;
                                                                                 case 2 ://l'ordinateur commence
                                                                                    { printf("\n\n\n L'ordinateur commence avec les pions noirs\n");
                                                                                      printf("Vous jouerez le deuxieme tour\n");
                                                                                      printf("Entrez votre nom:");
                                                                                      scanf("%s",joueur2);
                                                                                      system("pause");
                                                                                      system("cls");
                                                                                      plateau();//Charger le plateau
                                                                                      while(gagnant==0)//les tours de roles
                                                                                            {
                                                                                                joueur_ordinateur(2);//tour de l'ordinateur +affichage sur e plateau
                                                                                                gotoxy(0,40);
                                                                                                printf("c est votre tour\a, %s\n",joueur2);
                                                                                                afficher(1);//affichage sur le plateau
                                                                                                gagnantb=gagnantblanc();//test de la ligne continue pour les blancs
                                                                                                gagnantn=gagnantnoir();//test de la ligne continue pour les noirs
                                                                                                if (gagnantn==2)
                                                                                                {gotoxy(0,65);
                                                                                                    printf("\n\n\n\t\t***************************************\n\t\t\tL ordinateur a gagne\n\t\t***************************************\n");
                                                                                                    break;}
                                                                                                if(gagnantb==1)
                                                                                                {gotoxy(0,65);
                                                                                                    printf("\n\n\n\t\t***************************************\n\t\t\t%s gagne\n\t\t***************************************\n",joueur2);
                                                                                                    break;}
                                                                                                }system("pause");
                                                                                    }break;
                                                                                }
                                    }break;
                                        case 2:// mode choix adversaire
                                        {
                                                if(joueurCommence==1)//l'aleatoire pour le choix du joueur qui commence
                                                            { printf("\n\n\nVous commencez avec les pions noirs\n");
                                                            printf("Entrez votre nom:");
                                                            scanf("%s",joueur1);
                                                            system("pause");
                                                            system("cls");//effacer la console
                                                            plateau();//Charger le plateau
                                                            while(gagnant==0)//les tours de roles
                                                                    { gotoxy(0,40);
                                                                      printf("c est votre tour\a, %s\n",joueur1);
                                                                      afficher(2);
                                                                      gotoxy(0,45);
                                                                      joueur_ordinateur(1);
                                                                      gagnantb=gagnantblanc();
                                                                      gagnantn=gagnantnoir();
                                                                      if (gagnantn==2)
                                                                    { gotoxy(0,65);
                                                                      printf("\n\n\n\t\t***************************************\n\t\t\t%s a gagne\n\t\t***************************************\n",joueur1);
                                                                      break;}
                                                                     if(gagnantb==1)
                                                                    { gotoxy(0,65);
                                                                      printf("\n\n\n\t\t***************************************\n\t\t\tL ordinateur a gagne\n\t\t***************************************\n");
                                                                      break;}
                                                                    }
                                                                                                }
                                                     if(joueurCommence==2)
                                                    {            printf("\n\n\n L'ordinateur commence avec les pions noirs\n");
                                                                 printf("Vous jouerez le deuxieme tour\n");
                                                                 printf("Entrez votre nom:");
                                                                 scanf("%s",joueur2);
                                                                 system("pause");
                                                                 system("cls");
                                                                 plateau();//Charger le plateau

                                                                 while(gagnant==0)
                                                                {
                                                                    joueur_ordinateur(2);//le tour de l'ordinateur +affichage sue le plateau
                                                                    gotoxy(0,40);
                                                                    printf("c est votre tour\a, %s\n",joueur2);
                                                                    afficher(1);//l'affichage sur le plateau
                                                                    gagnantb=gagnantblanc();//test de la ligne continue pour les blancs
                                                                    gagnantn=gagnantnoir();//test de la ligne continue pour les noirs
                                                                    if (gagnantn==2)
                                                                    {  gotoxy(0,65);
                                                                       printf("\n\n\n\t\t***************************************\n\t\t\tL ordinateur a gagne\n\t\t***************************************\n");
                                                                        break;}
                                                                    if(gagnantb==1)
                                                                    {   gotoxy(0,65);
                                                                        printf("\n\n\n\t\t***************************************\n\t\t\t%s gagne\n\t\t***************************************\n",joueur2);
                                                                        break;}
                                                                    }
                                                                    }system("pause");
                                                                    }
                                                                    break;

                                                                    }
                                                                    }break;

                            case 2 ://la partie contre ordinateur avec intelligence evoluee
                                {
                                   system("cls");//decor
                                   printf("Vous allez jouer une partie difficile contre ordinateur\n");//decor
                                   for (i=0;i<20;i++)
                                           printf("/ \\" );
                                           printf("\n");
                                       for (i=0;i<20;i++)
                                           printf("| |");
                                           printf("\n");
                                       for (i=0;i<20;i++)
                                            printf("\\ /");
                                            printf("\n");
                                            printf("\t\t Partie difficile contre ordinateur\n");
                                       for (i=0;i<20;i++)
                                            printf("/ \\" );
                                            printf("\n");
                                       for (i=0;i<20;i++)
                                            printf("| |");
                                            printf("\n");
                                       for (i=0;i<20;i++)
                                            printf("\\ /");

                                    printf("\n\n\nL'ordinateur commence avec les pions noirs\n");//l'ordinateur commence(la 1ere strategie gagnante)
                                    printf("Vous jouerez le deuxieme tour\n");
                                    printf("Entrez votre nom:");
                                    scanf("%s",joueur2);
                                    system("pause");
                                    system("cls");
                                    plateau();//Charger le plateau
                                    gotoxy(26,15);//le 1er tour l'ordinateur place son pion dans la case centrale du plateau (la 2ere strategie gagnante
                                    printf("2");
                                    while(gagnant==0)//les tours de roles
                                                                    {
                                                                        gotoxy(0,40);
                                                                      printf("c est votre tour\a, %s\n",joueur2);
                                                                      afficher(1);
                                                                    compt++;

                                                                    ordi();

                                                                      //joueur_ordinateur_strategie_maillon(2);
                                                                      gagnantb=gagnantblanc();
                                                                      gagnantn=gagnantnoir();
                                                                      if (gagnantn==2)
                                                                    { gotoxy(0,65);
                                                                      printf("\n\n\n\t\t***************************************\n\t\t\t%s a gagne\n\t\t***************************************\n",joueur1);
                                                                      break;}
                                                                     if(gagnantb==1)
                                                                    { gotoxy(0,65);
                                                                      printf("\n\n\n\t\t***************************************\n\t\t\tL ordinateur a gagne\n\t\t***************************************\n");
                                                                      break;}
                                                                    }




                                    system("pause");


                                }break;//fin de case de difficulte evoluee
                                    }


                }break;//fin de case 2:jouer avec ordinateur

    case '3' ://choisir dans le 1er menu de lire les regles du jeu
           {
               system("cls");//effacer la console
                for (i=0;i<20;i++)//decor
                    printf("/ \\" );
                    printf("\n");
                for (i=0;i<20;i++)
                    printf("| |");
                    printf("\n");
                for (i=0;i<20;i++)
                    printf("\\ /");
                    printf("\n");
                    printf("\t\t Les regles du jeu\n");
                for (i=0;i<20;i++)
                    printf("/ \\" );
                    printf("\n");
                for (i=0;i<20;i++)
                    printf("| |");
                    printf("\n");
                for (i=0;i<20;i++)
                    printf("\\ /");
                    printf("\n\n\n");
                    printf("Le but du jeu est de  former une rangee ininterrompue de pieces de la meme\n"
                          "couleur qui relie un des cotes du plateau au cote oppose :\n"
                          "les pieces blanches relient les cotes blans et les noires les cotes noirs.\n"
                          "Cest le joueur qui reussit le premier a realiser cette rangee \nqui gagnera la partie.\n \n"
                          "On tire au sort pour savoir qui jouera avec les pieces noires.\n"
                          "Vous devez entrer les coordonnees de la case choisie.\nVous ne pouvez pas changer votre choix une fois celui-ci est fait\n"
                          "Vous ne pouvez chosir une case deja remplie.\n\n\n\n\n\n\n");
                    printf("entrez sur une touche pour revenir au menu\n");
               system("pause");

           }break;

           case '4' ://Quitter le jeu
           {

               printf("\n\n\n\t\t***************************************\n\t\t\tVous avez quittez le jeu\n\t\t***************************************");
               printf("\n Tapez n'importe quelle touche pour fermer la console");


           }break;

           default :
           {
               printf("\n Cette option ne figure pas dans la liste , recommencez \n");
               Sleep(1000);
               system("cls");

           }break;

      }
      } while(option!='4');

return 0;
}
