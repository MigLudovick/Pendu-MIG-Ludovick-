#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TENTATIVES 8

int main() {
    char motSecret[] = "ordinateur";
    int longueur = strlen(motSecret);
    char motCache[longueur + 1];
    int tentativesRestantes = MAX_TENTATIVES;
    char lettre;
    int trouve = 0;


    for (int i = 0; i < longueur; i++) {
        motCache[i] = '_';
    }
    motCache[longueur] = '\0';

    printf("=== Jeu du Pendu ===\n\n");

    while (tentativesRestantes > 0) {
        printf("Mot : %s\n", motCache);
        printf("Tentatives restantes : %d\n", tentativesRestantes);
        printf("Propose une lettre : ");
        scanf(" %c", &lettre);
        lettre = tolower(lettre);

        int bonneLettre = 0;
        for (int i = 0; i < longueur; i++) {
            if (motSecret[i] == lettre && motCache[i] == '_') {
                motCache[i] = lettre;
                bonneLettre = 1;
            }
        }

        if (bonneLettre) {
            printf("Bien joué !\n\n");
        }
        else {
            tentativesRestantes--;
            printf("Raté !\n\n");
        }

        if (strcmp(motSecret, motCache) == 0) {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Bravo ! Le mot était bien \"%s\" \n", motSecret);
    }
    else {
        printf("Dommage ! Le mot était \"%s\" \n", motSecret);
    }

    return 0;
}