#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED
int mat[9][9];
int gagnant;
int compt;
void gotoxy(int x,int y);
void plateau();
void afficher( int couleur);
void remplissagemat();
int gagnantblanc();
int debutblanc (int dejatester[9][9]);
int testblanc(int dejatester[9][9],int i,int pos);
void affichage_matrice(int test[9][9]);
int opt1();
int commenceparcours();
int test_voisinage(int test[9][9],int lig,int cln);
int commenceparcours();
int debutblanc (int test[9][9]);
int gagnantblanc();
void joueur_ordinateur(int couleur);
int test_voisinage_blanc(int test[9][9],int lig,int cln);
int opt2();
int gagnantnoir();
int test_voisinage_noir(int test[9][9],int lig,int cln);
int joueur_ordinateur_strategie_maillon(int couleur);
void ordi();

#endif // PROTOTYPE_H_INCLUDED
