#include <stdio.h>
#include "exercices.h"
/*#define NB_ELEM_MAX 10
int main(void){
    int i = 0;
    int monTableau[NB_ELEM_MAX];   // tableau d'au plus 10 entiers
    for(i = 0; i < NB_ELEM_MAX; i++){
        // monTableau[i] correspond à la valeur de la case parcourue
        monTableau[i] = i * i; // on donne à chaque case la valeur de son indice au carré
        printf("%d ", monTableau[i]); // puis on affiche la valeur de la case parcourue
    }
    return 0;
}*/

int main(void)
{
    int choixExercice = 0;
    printf("=====\tTP5 : Les structures et tableaux\t=====\n");
    do {
        printf("Veuillez saisir le numero d'exercice a lancer : \n>");
        scanf("%d", &choixExercice);
        switch (choixExercice) {
            case 0 :
            {
                printf("Merci d'avoir utilise mon code, a bientot");
                break;
            }
            case 1 :
            {
                ex1();
                printf("\n");
                break;
            }
            case 2 :
            {
                ex2();
                printf("\n");
                break;
            }
            case 3 :
            {
                ex3();
                printf("\n");
                break;
            }
            case 4 :           // pour l'exercice sur les classes hors TD
            {
                exClasses();
                printf("\n");
                break;
            }
            default :
            {
                printf("Choix Invalide ! Veuillez selectionner un autre numero d'exercice :\n");
                break;
            }
        }
    }while (choixExercice != 0);
    return 0;
}