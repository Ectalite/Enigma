//
//  main.c
//  Projet
//
//  Created by Xavier Hueber on 15/12/2020.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <gtk/gtk.h>
#include "graphics.h"
#include "fonctions.h"

int main(int argc, const char * argv[]){
//    char phrase[TAILLE_PHRASE];
    initialisation(argc, argv);
    /* On quitte.. */
    return 0;
//    printf("Bienvenue sur l'encodeur Enigma.\n");
//    selection_rotor(rotorA, 'A'); //Enigma est composé de 3 rotors que l'on peut choisir dans une gamme de 10 rotors différents. Grâce a cette fonction, l'utilisateur va pouvoir choisir quel rotor il voudra sélectionner en première, deuxième et troisième position.
//    selection_rotor(rotorB, 'B');
//    selection_rotor(rotorC, 'C');
//    selection_reflecteur(reflecteur);
//    printRotor(reflecteur);
//    int choix;
//    printf("Que voulez-vous faire ?\n");
//    printf("1 - Encoder un message\n");
//    printf("2 - Decoder un message\n");
//    printf("0 - Sortir\n");
//    do {
//        scanf("%d", &choix);
//        switch (choix) {
//            case 0:
//                printf("Au revoir\n");
//                break;
//            case 1:
//                printf("------Encodage------\n");
//                printf("Veuillez donner une phrase à encoder:\n");
//                scanf(" "); //il faut mettre cette fonction scanf avant d'utiliser le fgets, sinon fgets ne lira pas ce que l'on va écrire.
//                fgets(phrase, TAILLE_PHRASE, stdin);
//                majuscule(phrase);
//                encodage(phrase, rotorA, rotorB, rotorC, reflecteur);
//                break;
//            case 2:
//                printf("------Décodage------\n");
//                printf("Veuillez donner une phrase à décoder:\n");
//                scanf(" "); //il faut mettre cette fonction scanf avant d'utiliser le fgets, sinon fgets ne lira pas ce que l'on va écrire.
//                fgets(phrase, TAILLE_PHRASE, stdin);
//                majuscule(phrase);
//                decodage(phrase, rotorA, rotorB, rotorC, reflecteur);
//                break;
//            default:
//                printf("Mauvaise entrée, veuillez donner un chiffre entre 0 et 2\n");
//                break;
//        }
//    } while (choix<0 || choix>2);
//    printRotor(rotorA);
//    return EXIT_SUCCESS;
}
