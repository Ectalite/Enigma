//
//  main.c
//  Projet
//
//  Created by Xavier Hueber on 15/12/2020.
//
#define TAILLE_PHRASE 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>
#include "fonctions.h"

void clrscr(void);

int main(int argc, const char * argv[]) {
//    intialisation: on demande à l'utilisateur quels rotors et quel réflecteur il souhaite utiliser.
    char rotorA[26][2];
    char rotorB[26][2];
    char rotorC[26][2];
    char reflecteur[26][2];
    int A,B,C,numero_reflecteur;
    char phrase[TAILLE_PHRASE];
    FILE* fichier = NULL; //l'utilisateur pourra choisir d'encoder/decoder un fichier
    FILE* sortie = NULL; //fichier de sortie encodé ou décodé
    setlocale( LC_ALL, "fr_FR.UTF-8" );
    printf("Bienvenue sur l'encodeur Enigma.\n");
    selection_rotor(rotorA, 'A', &A); //Enigma est composé de 3 rotors que l'on peut choisir dans une gamme de 10 rotors différents. Grâce a cette fonction, l'utilisateur va pouvoir choisir quel rotor il voudra sélectionner en première, deuxième et troisième position.
    selection_rotor(rotorB, 'B', &B);
    selection_rotor(rotorC, 'C', &C);
    selection_reflecteur(reflecteur, &numero_reflecteur);
//    printRotor(reflecteur);
    int choix;
    do {
        do {
            clrscr();//clean screen
            printf("----------Infos----------\n");
            printf("Rotor A: %d || Rotor B: %d || Rotor C: %d\n",A,B,C);
            printf("R%lcflecteur: %d\n",233,numero_reflecteur);
            printf("Derni%lcre phrase:\n",232);
            printf("%s\n",phrase);
            printf("--------Menu Principal--------\n");
            printf("1 - Encoder un message\n");
            printf("2 - D%lccoder un message\n",233);
            printf("3 - Encoder un fichier\n");
            printf("4 - D%lccoder un fichier\n",233);
            printf("5 - Choisir d'autres rotors\n");
            printf("0 - Sortir\n");
            scanf("%d", &choix);
            clrscr();
            switch (choix) {
                case 0:
                    printf("Au revoir\n");
                    break;
                case 1:
                    printf("------Encodage------\n");
                    printf("Veuillez donner une phrase %lc encoder:\n",223);
                    scanf(" "); //il faut mettre cette fonction scanf avant d'utiliser le fgets, sinon fgets ne lira pas ce que l'on va écrire.
                    fgets(phrase, TAILLE_PHRASE, stdin);
                    majuscule(phrase);
                    encodage(phrase, rotorA, rotorB, rotorC, reflecteur);
                    break;
                case 2:
                    printf("------D\x82 codage------\n");
                    printf("Veuillez donner une phrase %lc d%lccoder:\n",224,233);
                    scanf(" "); //il faut mettre cette fonction scanf avant d'utiliser le fgets, sinon fgets ne lira pas ce que l'on va écrire.
                    fgets(phrase, TAILLE_PHRASE, stdin);
                    majuscule(phrase);
                    decodage(phrase, rotorA, rotorB, rotorC, reflecteur);
                    break;
                case 3:
                    printf("------Encodage d'un fichier------\n");
                    fichier = fopen("texte.txt", "a"); //on créer le fichier texte.txt si il ne l'est pas deja
                    fclose(fichier);
                    sortie = fopen("sortie.txt", "a+");
                    printf("L'encodage se fera dans le fichier \"texte.exe\" à la racine du programme.\n");
                    printf("Veuillez %lcditer le fichier puis appuyer sur entr%lce.\n",233,233);
                    scanf(" ");
                    getchar(); //on attend que l'utilisateur ai appuyé sur entrée
                    fprintf(sortie, "--Ce fichier a été crée automatiquement par le programme Enigma.--\n");
                    fprintf(sortie, "------------------------------------------------------------------\n");
                    fichier = fopen("texte.txt", "r");
                    while (fgets(phrase, TAILLE_PHRASE, fichier) != NULL){ // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                        majuscule(phrase);
                        encodage(phrase, rotorA, rotorB, rotorC, reflecteur);
                        fprintf(sortie, "%s\n",phrase);
                    }
                    fclose(sortie);
                    fclose(fichier);
                    break;
                case 4:
                    printf("------D%lccodage d'un fichier------\n",233);
                    fichier = fopen("texte.txt", "a"); //on créer le fichier texte.txt si il ne l'est pas deja
                    fclose(fichier);
                    sortie = fopen("sortie.txt", "a+");
                    printf("L'encodage se fera dans le fichier \"texte.exe\" à la racine du programme.\n");
                    printf("Veuillez %lcditer le fichier puis appuyer sur entr%lce.\n",233,233);
                    scanf(" ");
                    getchar(); //on attend que l'utilisateur ai appuyé sur entrée
                    fprintf(sortie, "--Ce fichier a été crée automatiquement par le programme Enigma.--\n");
                    fprintf(sortie, "------------------------------------------------------------------\n");
                    fichier = fopen("texte.txt", "r");
                    printf("TEST");
                    while (fgets(phrase, TAILLE_PHRASE, fichier) != NULL){ // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                        majuscule(phrase);
                        decodage(phrase, rotorA, rotorB, rotorC, reflecteur);
                        fprintf(sortie, "%s\n",phrase);
                    }
                    fclose(sortie);
                    fclose(fichier);
                    break;
                case 5:
                    selection_rotor(rotorA, 'A', &A);
                    selection_rotor(rotorB, 'B', &B);
                    selection_rotor(rotorC, 'C', &C);
                    selection_reflecteur(reflecteur, &numero_reflecteur);
                default:
                    printf("Mauvaise entr%lce, veuillez donner un chiffre entre 0 et 2\n",233);
                    break;
            }
        } while(choix<0 || choix>2);
    } while(choix !=0);
//    printRotor(rotorA);
    return 0;
}

void clrscr()
{
    system("@cls||clear");
}
