//
// Created by pmdau on 04/10/2021.
//
#include <stdio.h>
#include "structures.h"
#include "macros.h"

/* Fonction qui permet de saisir les informations liées à l'école (nbDeClasses, nbTotalEleves, nomEcole, moyenne)
* Paramètres :
* - IN : nbDeClasses, nbTotalEleves, nomEcole, moyenne rentré par l'utilisateur
* - OUT : la structure Ecole avec les infos nbDeClasses, nbTotalEleves, nomEcole, moyenne
*/

Ecole saisirInfos (void)
{
    Ecole e;
    printf("Veuillez saisir les informations : nbDeClasses, nbTotalEleves, nomEcole, moyenne\n");
    scanf("%i %i %c %f", &e.nbDeClasses, &e.nbTotalEleves, &e.nomEcole, &e.moyenne);
    return e;
}

//ou

Ecole saisirInfosBis (void)
{              // plus lisible par l'utilisateur
    Ecole E;
    printf("Veuillez saisir le nombre de classes :\n>");
    scanf("%i", &E.nbDeClasses);
    printf("Veuillez saisir le nombre d'eleves :\n>");
    scanf("%i", &E.nbTotalEleves);
    printf("Veuillez saisir le nom de l'ecole :\n>");
    scanf(" %c", &E.nomEcole);                    //ATTENTION A L'ESPACE AVANT LE %C
    printf("Veuillez saisir la moyenne de l'etablissement :\n>");
    scanf(" %f", &E.moyenne);
    return E;
}

/* Fonction qui permet d'afficher les informations liées à l'école (nbDeClasses, nbTotalEleves, nomEcole, moyenne)
* Paramètres :
* - IN : la structure Ecole avec les infos nbDeClasses, nbTotalEleves, nomEcole, moyenne
* - OUT : les informations affichées dans la console sur l'école
*/

void afficherInfos(Ecole e)
{
    printf(" nbDeClasses = %i\n", e.nbDeClasses);
    printf("nbTotalEleves = %i\n", e.nbTotalEleves);
    printf("nomEcole = %c\n", e.nomEcole);
    printf("moyenne = %.2f", e.moyenne);
    return;
}

/*******
 * EX1 *
 *******/

/* Fonction qui permet de saisir le numérateur et le dénominateur d'un nombre rationnel
* Paramètres :
* - IN : Le numérateur et dénominateur entrés par l'utilisateur
* - OUT : la structure Rationnel avec ses deuc paramètres
*/

NombreRationnel saisirNumerateurEtDenominateur(void)
{
    NombreRationnel R = {0 , 0};
    printf("Saisir le numerateur du nombre rationnel : \n>");
    scanf("%i", &R.numerateur);
    printf("Saisir le denominateur du nombre rationnel : \n>");
    scanf("%i", &R.denominateur);
    while (R.denominateur == 0)                        // eviter les nombres rationnels avec un denominateur nul
    {
        printf("La divivsion par zero pose quelques problemes...\n>");
        scanf("%i", &R.denominateur);
    }
    return R;
}

/* Fonction qui permet d'afficher le numérateur et le dénominateur d'un nombre rationnel
* Paramètres :
* - IN : La structure NombreRationnel que l'on veut afficher
* - OUT : les inforamtions (numerateur et denominateur) sur le nombre rationnel dans la console
*/
void afficherNombreRationnel(NombreRationnel R)
{
    printf("%i\n", R.numerateur);
    printf("%i\n", R.denominateur);
    return;
}

//ou avec plus de texte

void afficherNombreRationnelBis(NombreRationnel R)
{
    printf("Le numerateur de ce nombre rationnel vaut : %i\n", R.numerateur);
    printf("Le denominateur de ce nombre rationnel vaut : %i\n", R.denominateur);
    return ;
}

/* Fonction qui permet de multiplier deux nombres rationnels
* Paramètres :
* - IN : Les structures NombreRationnel que l'on veut multiplier   (R1 et R2)
* - OUT : Le nombre rationnel optenue a la suite de ce calcul (structure) = RM
*/

NombreRationnel multiplierDeuxNombresRationnels(NombreRationnel R1, NombreRationnel R2)
{
    NombreRationnel RM = {0, 0};
    RM.numerateur = R1.numerateur * R2.numerateur;
    RM.denominateur = R1.denominateur * R2.denominateur;
    printf("Le resultat de la multiplication de ces deux rationnels vaut : \n");
    return RM;
}

/* Fonction qui permet d'additionner deux nombres rationnels
* Paramètres :
* - IN : Les structures NombreRationnel que l'on veut additionner   (R1 et R2)
* - OUT : Le nombre rationnel optenue a la suite de ce calcul (structure) = RA
*/

NombreRationnel additionnerDeuxNombresRationnels(NombreRationnel R1, NombreRationnel R2)
{
    NombreRationnel RA = {0, 0};
    RA.numerateur = R1.numerateur * R2.denominateur + R2.numerateur * R1.denominateur;
    RA.denominateur = R1.denominateur * R2.denominateur;
    printf("Le resultat de l'addition de ces deux rationnels vaut : \n");
    return RA;
}

/*************
 * EX1 BONUS *
 *************/

/* Fonction prototype avant consignes qui permet de simplifier un nombre rationnel
* Paramètres :
* - IN : Un nombre rationnel que l'on veut simplifier si possible
* - OUT : Le nombre rationnel simplifié
*/

NombreRationnel simplifierNombreRationnel(NombreRationnel R)
{
    int i = 0;
    NombreRationnel RationnelSimplifie = {R.numerateur, R.denominateur};            //Pour rationnel simplifié
    if (RationnelSimplifie.numerateur > RationnelSimplifie.denominateur)
    {
        i = RationnelSimplifie.denominateur;                                       // prend la valeur du plus grand multiple commun potentiel
        while(i > 0)
        {
            if (RationnelSimplifie.denominateur % i == 0 && RationnelSimplifie.numerateur % i == 0)                // cherche la situation ou le numerateur et le denominateru auraient un multiple en commun
            {
                RationnelSimplifie.numerateur = RationnelSimplifie.numerateur / i;                               // on change la valeur en divisant par le multiple commun en haut et en bas
                RationnelSimplifie.denominateur = RationnelSimplifie.denominateur / i;
            }
            i -= 1;                        // on teste toutes les valeurs en dessous du premier plus grnad multiple commun potentiel
        }
    }
    else
    {
        i = RationnelSimplifie.numerateur;                                     // on fait de meme dans le cas de figure complémentaire
        while (i > 0)
        {
            if (RationnelSimplifie.denominateur % i == 0 && RationnelSimplifie.numerateur % i == 0)
            {
                RationnelSimplifie.numerateur = RationnelSimplifie.numerateur / i;
                RationnelSimplifie.denominateur = RationnelSimplifie.denominateur / i;
            }
            i -= 1;
        }
    }
    return RationnelSimplifie;
}

/* Fonction qui prend un nombre rationnel et renvoie le plus grand diviseur commun du numérateur et du dénominateur
* Paramètres :
* - IN : Un nombre rationnel
* - OUT : Le PGCD du numérateur et du dénominateur de ce nombre rationnel
*/

int pGCD(NombreRationnel nbR1)
{
    int PGCD = 0;
    if (nbR1.numerateur > nbR1.denominateur)                                   // cela permet de reduire le nombre de calculs necessaires en prenant le plus grand PGCD potentiel
    {
        PGCD = nbR1.denominateur;
        while (PGCD >= 0 && !(nbR1.numerateur % PGCD == 0 && nbR1.denominateur % PGCD == 0))                   // la condition permet de s'arreter quand on a trouvé le pgcd ou que l'on a un pgcd = 1
        {
            PGCD -= 1;
        }
    }
    else
    {
        PGCD = nbR1.numerateur;
        while (PGCD >= 0 && !(nbR1.numerateur % PGCD == 0 && nbR1.denominateur % PGCD == 0))
        {
            PGCD -= 1;
        }
    }
    return PGCD;
}

/* Fonction qui prend un nombre rationnel et renvoie le nombre rationnel simplifié
* Paramètres :
* - IN : Un nombre rationnel
* - OUT : Le nombre rationnel simplifié
*/

NombreRationnel simplification(NombreRationnel nbR1)
{
    NombreRationnel nbR2 = nbR1;                 // on prend le nombre rationnel de depart comme base à simplifier
    int PGCDTemp = pGCD(nbR1);               // on crée le pgcd temporaire du nombre rationnel de depart qui va ensuite evoluer plus le nombre rationnel est simplifié
    while (PGCDTemp > 1)                       // on parcours tous les diviseurs communs des numérateurs et dénominateurs
    {
        nbR2.numerateur = nbR2.numerateur / PGCDTemp;                    // on actualise les valeurs qui permettent de simplifier le nombre rationnel
        nbR2.denominateur = nbR2.denominateur / PGCDTemp;
        PGCDTemp = pGCD(nbR2);                                       // et on cherche le pgcd du nouveau nombre rationnel à simplifieer si possible
    }
    return nbR2;
}

/*******
 * EX2 *
 *******/

/* Fonction qui permet de saisir le nombre de valeurs que l'utilisateur veut rentrer dans le tableau
* Paramètres :
* - IN : Le nombre de valeurs que l'utilisateur veut rentrer
* - OUT : le nombre de valeurs entré
*/

int saisirNombreDeValeursTableau (void)
{
    int N = 0;
    do
    {
        printf("Veuillez saisir le nombre de valeurs que vous voulez saisir dans le tableau (<100) : \n>");
        scanf("%i", &N);
    }
    while (N > 100);                        // permet de redemander le nombre de valeurs si l'utilisateur rentre un nombre plus grand que 100
    return N;
}

/* Fonction qui permet de saisir le nombre de valeurs que l'utilisateur veut rentrer dans le tableau
* Paramètres :
* - INOUT : Le tableau monTableau
* - IN : les valerus entrées par l'utilisateur et l'indice ou la valeur sera stockée
* - OUT : Le tableau modifié
*/

void saisirValeurDansTableau(int indiceDansTableau, int monTableau[100])
{
    printf("Saisir la valeur a entrer a l'espace d'indice %i \n>", indiceDansTableau + 1);    // en partant de 1 a la premiere valeur pour plus de compréhensibilté avec l'utilisateur
    scanf("%i", &monTableau[indiceDansTableau]);
    return;
}

/* Fonction qui permet de renvoyer la valeur la plus élevée du tableau
* Paramètres :
* - INOUT : Le tableau monTableau
* - IN : les valeurs entrées contenues dans le tableau à comparer et le nombre d'entres elles
* - OUT : La valeur la plus élevée dans le tableau
*/

int plusGrandElementTableau(int monTableau[100], int N)
{
    int i = 0, plusGrand = 0;
    for (i = 0; i < N; i++)
    {
        plusGrand = (monTableau[i] > plusGrand)? monTableau[i] : plusGrand ;                // condition ternaire qui permet de rentrer trouver le plus grand élément du tableau
    }
    return plusGrand;
}

/*******
 * EX3 *
 *******/

/* Fonction qui permet a l'utilisateur de saisir l'entier dans le tableau
* Paramètres :
* - INOUT : Le tableau tableau2D
* - IN : la valeur entrée par l'utilisateur
* - OUT : La valeur dans le tableau bien située
*/

int saisirValeursTableau(int tableau2D[NB_LIGNES][NB_COLONNES], int indiceLigne, int indiceColonne)
{
    printf("Saisir la valeur a stocker dans l'espace d'indice de ligne %i ", indiceLigne + 1);           // toujours pour plus de lisibilité dans le tableau
    printf("et d'indice de colonne %i \n>", indiceColonne + 1);
    scanf("%i", &tableau2D[indiceLigne][indiceColonne]);
    return tableau2D[indiceColonne][indiceColonne];
}

/* Fonction qui permet d'afficher le tableau complet
* Paramètres :
* - IN : le tableau que l'on souhaite afficher dans la console
* - OUT : le tableau affiché dans la console
*/

void afficherTableau(int tableauAffiche[NB_LIGNES][NB_COLONNES])
{
    for (int a = 0; a < NB_LIGNES; a++)                // parcours en second temps les lignes après avoir rentré chaque élément de la ligne précédente
    {
        for (int b = 0; b < NB_COLONNES; b++)             // parcours chaque colonne d'une ligne
        {
            printf("%d ", tableauAffiche[a][b]);
        }
        printf("\n");
    }
    printf("\n");
    return ;
}

/* Fonction qui permet de transformer un tableau 2D en un tbleau à une dim
* Paramètres :
* - IN : le tableau 2D
* - OUT : le tableau qui est affiché en ligne
*/

void transformerTableau2DEnligne(int tableauDeuxDim[NB_LIGNES][NB_COLONNES], int tableauEnligne[NB_LIGNES * NB_COLONNES])
{
    int  i = 0, j = 0;
    for (i = 0; i < NB_LIGNES; i++)                         // on parcours en second temps les lignes apres avoir transvasé la ligne précédente
    {
        for(j = 0; j < NB_COLONNES; j++)                        //d'abord on parcours toute une ligne
        {
            tableauEnligne[j + i * NB_COLONNES] = tableauDeuxDim[i][j];                // c'est la que réside la force de la fonction car on place les lignes du tableau les unes après les autres dans un tableau en ligne
        }                                                                              //Donc l'élément en position [i][j] va à la place [j+i*NB_COLONNES]
    }
    return;
}

/* Fonction qui permet d'afficher le tableau complet
* Paramètres :
* - IN : le tableau que l'on souhaite afficher dans la console
* - OUT : le tableau affiché dans la console
*/

void afficherTableau1D(int tableau1D[NB_LIGNES * NB_COLONNES])
{
    int i = 0;
    for (i = 0; i < NB_LIGNES * NB_COLONNES; i++)                            // cette fonction permet d'afficher le tableau en retour de la fonction precedente (taille compatible)
    {
        printf("%d ", tableau1D[i]);
    }
    return;
}