//
// Created by pmdau on 04/10/2021.
//

#ifndef TD5_FONCTIONS_H
#define TD5_FONCTIONS_H

#include "structures.h"
#include "macros.h"

/************
 * EX ECOLE *
 ************/
Ecole saisirInfos (void);
void afficherInfos(Ecole e);
Ecole saisirInfosBis (void);

/*******
 * EX1 *
 *******/

NombreRationnel saisirNumerateurEtDenominateur(void);
void afficherNombreRationnelBis(NombreRationnel R);
void afficherNombreRationnel(NombreRationnel R);
NombreRationnel multiplierDeuxNombresRationnels(NombreRationnel R1, NombreRationnel R2);
NombreRationnel additionnerDeuxNombresRationnels(NombreRationnel R1, NombreRationnel R2);
NombreRationnel simplifierNombreRationnel(NombreRationnel R);
int pGCD(NombreRationnel nbR1);
NombreRationnel simplification(NombreRationnel nbR1);

/*******
 * EX2 *
 *******/

int saisirNombreDeValeursTableau (void);
int saisirValeurDansTableau(int indiceDansTableau, int monTableau[100]);
int plusGrandElementTableau(int monTableau[100], int N);

/*******
 * EX3 *
 *******/

int saisirValeursTableau(int tableauSaisi[NB_LIGNES][NB_COLONNES], int indiceLigne, int indiceColonne);
void afficherTableau(int tableauAffiche[NB_LIGNES][NB_COLONNES]);
void transformerTableau2DEnligne(int tableauDeuxDim[NB_LIGNES][NB_COLONNES], int tableauEnligne[NB_LIGNES * NB_COLONNES]);
void afficherTableau1D(int tableau1D[NB_LIGNES * NB_COLONNES]);
#endif //TD5_FONCTIONS_H
