//
// Created by pmdau on 06/10/2021.
//
#include <stdio.h>
#include "fonctions.h"

void exClasses(void)
{
    Ecole ecole1;
    ecole1 = saisirInfosBis();
    afficherInfos(ecole1);
    return ;
}

void ex1()
{
    int choixRationnel = 0;
    /*
     * methode avant consigne avec pgcd
     */
    //afficherNombreRationnel(simplifierNombreRationnel(multiplierDeuxNombresRationnels(saisirNumerateurEtDenominateur(),saisirNumerateurEtDenominateur())));
    //afficherNombreRationnel(simplifierNombreRationnel(additionnerDeuxNombresRationnels(saisirNumerateurEtDenominateur(),saisirNumerateurEtDenominateur())));
    /*
     * methode avec pgcd
     */
    do {
        printf("Que souhaitez vous faire ? Pour additionner deux rationnels tapez 1 ; pour multiplier deux rationnels tapez 2 ; \n pour sortir tapez 0 : \n>");
        scanf("%d", &choixRationnel);
        switch (choixRationnel) {
            case 0 :
            {
                printf("FIN EX1\n");
                break;
            }
            case 1 :
            {
                afficherNombreRationnel(simplification(additionnerDeuxNombresRationnels(saisirNumerateurEtDenominateur(),saisirNumerateurEtDenominateur())));
                break;
            }
            case 2 :
            {
                afficherNombreRationnel(simplification(multiplierDeuxNombresRationnels(saisirNumerateurEtDenominateur(),saisirNumerateurEtDenominateur())));
                break;
            }
            default :
            {
                printf("Le numero choisi n'est pas valide \n");
                break;
            }
        }
    }while(choixRationnel != 1 && choixRationnel != 2 && choixRationnel != 0);
    return;
}

void ex2()
{
    int monTableau[100] = {0}, i = 0, N = saisirNombreDeValeursTableau();
    for (i = 0; i < N ; i++)
    {
        saisirValeurDansTableau(i, monTableau);
    }
    printf("La valeur du plus grand element de ce tableau vaut : %i", plusGrandElementTableau(monTableau, N));
    return ;
}

void ex3()
{
    int tableau2D[NB_LIGNES][NB_COLONNES] = {{0}}, tableauEnLgne[NB_LIGNES * NB_COLONNES] = {0}, i = 0, j = 0;
    for (i = 0; i < NB_LIGNES; i++)
    {
        for(j = 0; j < NB_COLONNES; j++)
        {
            saisirValeursTableau(tableau2D, i, j);
        }
    }
    afficherTableau(tableau2D);                 // cela permet de verifier le bon placement des valeurs
    transformerTableau2DEnligne(tableau2D, tableauEnLgne);
    afficherTableau1D(tableauEnLgne);
    return;
}