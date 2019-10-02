#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <time.h>
#include "prototype.h"
#include <string.h>

void remplissagemat() //on remplit la matrice mat qui va matérialiser le plateau par des zeros pour éviter les erreurs
{int i;
int j ;
for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
            mat[i][j]=0;
        }
}
void affichage_matrice(int test[9][9]) // matrice utilisé pour la verification
{int i , j;
for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
            {
                printf("%d\t",test[i][j]);
            }
    putchar('\n');
    }
}
 void gotoxy(int x,int y) //Poser le curseur dans la position x ,y de la console
 {COORD coord={0,0};
   coord.X=x;// x sont les colonnes
 coord.Y=y;// y sont les lignes
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }


void plateau() // pour afficher le plateau du jeu Hex
{ int i=0;
int c,x=0,y=1,y1=3,x1=0,x2=1,y2=5,x3=0,y3=4,xzero=36,yzero=4,xun=xzero+1,yun=yzero+1;
system("COLOR 75");//On incrémente alors à partir de la position choisie par l'utilisteur
printf(" 1 B 2 B 3 B 4 B 5 B 6 B 7 B 8 B 9\n ");
for (i=0;i<9;i++)
    printf("/\\  " );
printf("\n");
for (i=0;i<9;i++)
    printf("/  \\" );
do
{
    for (c=1;c<=9;c++)
        {   gotoxy(x1,y1);
            for (i=0;i<10;i++)
                printf("|   ");
            printf("%d",c);
            x1=x1+2;
            y1=y1+3;
        }
}while(x1<9);
do{
        gotoxy(x3,y3);
        for (i=0;i<9;i++)
            printf("\\  /");
        x3=x3+2;
        y3=y3+3;
}while(x3<18);
do{
        gotoxy(x2,y2);
        for (i=0;i<9;i++)
            printf("\\/  ");
        x2=x2+2;
        y2=y2+3;
}while(x2<18);
do{
        gotoxy(xzero,yzero);
        printf("\\");
        xzero=xzero+2;
        yzero=yzero+3;
}while(yzero<28);
do{
        gotoxy(xun,yun);
        printf("\\");
        xun=xun+2;
        yun=yun+3;
}while(yun<28);
gotoxy(60,2);
printf("1:Blanc");
gotoxy(60,3);
printf("2:Noir");
}

void afficher(int couleur) //Cette fonction est utilisée pour l'affichage des coordonnées entrées par
//le joueur en fct de la couleur de son pion
{int xchoisi ;
int ychoisi;
int i;
do{printf("choisissez une colonne");// on demande a l utilisateur d entrer son choix
scanf("%d",&xchoisi); // on stocke son choix dans une variable
printf("choisissez une ligne");
scanf("%d",&ychoisi);
if (mat[ychoisi-1][xchoisi-1]==0) //si la case est vide
    i=1;
else
    i=0;
if (i==1 && (xchoisi)>0 &&(ychoisi)<10 &&(xchoisi)<10&&(ychoisi)>0 ) // si la case est vide et les choix entrés
    //sont dans le plateau
        {mat[ychoisi-1][xchoisi-1]=couleur; //on stocke le choix dans mat
                if (ychoisi==1)
                    {    if (xchoisi==1) {gotoxy(2,3); printf("%d",couleur);}
                        else {gotoxy(2+4*(xchoisi-1),3);printf("%d",couleur);}
                    }

                else
                { if (ychoisi==2)
                    {gotoxy(4+4*(xchoisi-1),6);
                        printf("%d",couleur);
                    }
                    else
                        { gotoxy(4+4*(xchoisi-1)+2*(ychoisi-2),6+3*(ychoisi-2));
                            printf("%d",couleur);
                        }
                }
            }
}while(i==0||xchoisi<=0||ychoisi>=10||xchoisi>=10||ychoisi<=0); // si l'utilisateur entre une case qui ne
// figure pas dans le plateau ou si la case est deja prise on lui demande de réentrer d'autre coordonnées
}


int test_voisinage_blanc(int test[9][9],int lig,int cln) //fct recursive qui test le voisinage d'une case
{
test[lig][cln]=1;
if(mat[lig+1][cln]==1&& lig!=8 &&test[lig+1][cln]!=1)
    {if(test_voisinage_blanc(test,lig+1,cln)==1)
    return 1;
    }
else if(mat[lig+1][cln-1]==1 && cln!=0&&lig!=8 &&test[lig+1][cln-1]!=1)
    {if (test_voisinage_blanc(test,lig+1,cln-1)==1)
    return 1;}
else if(mat[lig][cln-1]==1 &&cln!=0 &&test[lig][cln-1]!=1)
{if (test_voisinage_blanc(test,lig,cln-1)==1)
return 1;}
else if(mat[lig][cln+1]==1 && cln!=8 &&test[lig][cln+1]!=1)
{if(test_voisinage_blanc(test,lig,cln+1)==1)
return 1;}
else if(mat[lig-1][cln+1]==1 && lig!=0 && cln!=8 && test[lig-1][cln+1]!=1)
{if (test_voisinage_blanc(test,lig-1,cln+1)==1)
return 1;}
else if(mat[lig-1][cln]==1 && lig!=0 &&test[lig-1][cln]!=1)
{if(test_voisinage_blanc(test,lig-1,cln)==1)
return 1;}
if(lig==8) return 1;
return 0;

}


int opt1() // On compte le nbre de premier pion blanc joué dans chaque ligne , il doit au moins y avoir 9 pions
//joués dans chaque ligne pour avoir un vainqueur
{int i , j ,compt=0 ;
for(i=0;i<9;i++)
{for(j=0;j<9;j++)
    {if (mat[i][j]==1)
        {compt++;
        break;
        }
    }
}
if (compt==9) return 1;
else return 0;
}
int gagnantblanc() // fct qui teste si la ligne est complète ou pas pour les blancs
{ int i ,j ,gagn=0,test[9][9];
 for (i=0;i<9;i++)
    { for (j=0;j<9;j++)
        test[i][j]=0;
    }
if( opt1()==1 )
{   for (i=0;i<9;i++)
        {if (mat[0][i]==1 && test[0][i]!=1)
        {gagn=test_voisinage_blanc(test,0,i);}
        }
}
return gagn;
}

int test_voisinage_noir(int test[9][9],int lig,int cln)
{
test[lig][cln]=1;
if(mat[lig+1][cln]==2&& lig!=8 &&test[lig+1][cln]!=1)
    {if(test_voisinage_noir(test,lig+1,cln)==2)
    return 2;
    }
else if(mat[lig+1][cln-1]==2 && cln!=0&&lig!=8 &&test[lig+1][cln-1]!=1)
    {if (test_voisinage_noir(test,lig+1,cln-1)==2)
    return 2;}
else if(mat[lig][cln-1]==2 &&cln!=0 &&test[lig][cln-1]!=1)
{if (test_voisinage_noir(test,lig,cln-1)==2)
return 2;}
else if(mat[lig][cln+1]==2 && cln!=8 &&test[lig][cln+1]!=1)
{if(test_voisinage_noir(test,lig,cln+1)==2)
return 2;}
else if(mat[lig-1][cln+1]==2 && lig!=0 && cln!=8 && test[lig-1][cln+1]!=1)
{if (test_voisinage_noir(test,lig-1,cln+1)==2)
return 2;}
else if(mat[lig-1][cln]==2 && lig!=0 &&test[lig-1][cln]!=1)
{if(test_voisinage_noir(test,lig-1,cln)==2)
return 2;}
if(cln==8) return 2;
return 0;

}

int opt2()
{int i , j ,compt=0 ;
for(i=0;i<9;i++)
{for(j=0;j<9;j++)
    {if (mat[j][i]==2)
        {compt++;
        break;}}}
if (compt==9) return 1;
else return 0;
}
int gagnantnoir()
{ int i ,j ,gagn=0,test1[9][9];
    for (i=0;i<9;i++)
        { for (j=0;j<9;j++)
            test1[i][j]=0;
        }
    if( opt2()==1)
        {   for (i=0;i<9;i++)
            {if (mat[i][0]==2 && test1[i][0]!=1)
                {gagn=test_voisinage_noir(test1,i,0);}
            }
        }
    return gagn;
}



void joueur_ordinateur(int couleur) //affiche le choix de l'ordinateur
{   int i, max =9 , min =1, xaleatoire ,yaleatoire;
 do{
    xaleatoire = (rand() % (max - min + 1)) + min;
    yaleatoire = (rand() % (max - min + 1)) + min;

if (mat[yaleatoire-1][xaleatoire-1]==0)
         i=1;
     else
         i=0;
    if(i==1)
    {mat[yaleatoire-1][xaleatoire-1]=couleur;
    if (yaleatoire==1)
            { if (xaleatoire==1) {gotoxy(2,3); printf("%d",couleur);}
                    else {gotoxy(2+4*(xaleatoire-1),3);printf("%d",couleur);}
            }

    else
            { if (yaleatoire==2)
            {
                gotoxy(4+4*(xaleatoire-1),6);
                printf("%d",couleur);
            }
            else
                {
                  gotoxy(4+4*(xaleatoire-1)+2*(yaleatoire-2),6+3*(yaleatoire-2));
                  printf("%d",couleur);}
                }
                }
 }while(i==0);

}
void afficher_ordi(int xchoisi, int ychoisi) //Cette fonction est utilisée pour l'affichage des coordonnées entrées par
//le joueur en fct de la couleur de son pion
{
int i;
int couleur=2;
mat[ychoisi-1][xchoisi-1]=couleur;
                if (ychoisi==1)
                    {    if (xchoisi==1) {gotoxy(2,3); printf("%d",couleur);}
                        else {gotoxy(2+4*(xchoisi-1),3);printf("%d",couleur);}
                    }

                else
                { if (ychoisi==2)
                    {gotoxy(4+4*(xchoisi-1),6);
                        printf("%d",couleur);
                    }
                    else
                        { gotoxy(4+4*(xchoisi-1)+2*(ychoisi-2),6+3*(ychoisi-2));
                            printf("%d",couleur);
                        }
                }

            }
int mini(int tab[9])
{  int min=1 , i;
for(i=0;i<9;i++)
{if (tab[i]!=0)
    {if (tab[i]<tab[min]) min=i;}}
  return min ;
}

void ordi()
{ int i , tab[9],min , tab1[9];
for(i=0;i<9;i++) tab[i]=0; //intialise le tab par des zeros
for(i=0;i<9;i++) tab1[i]=0;
if (compt==1) // le premier tour
    {   if (mat[4][0]==0) afficher_ordi(1,5);
        else{
        for(i=0;i<9;i++)
            { if (mat[i][0]==0)
                { tab[i]=abs(5-i);}
            }
        i=mini(tab);
        afficher_ordi(1,i);}
}
if (compt==2) // le premier tour
    {   if (mat[4][8]==0) afficher_ordi(9,5);
        else{
        for(i=0;i<9;i++)
            { if (mat[i][0]==0)
                { tab1[i]=abs(5-i);}
            }
        i=mini(tab1);
        afficher_ordi(9,i);}
    }



}






