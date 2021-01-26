//
//  fonctions.h
//  Projet
//
//  Created by Xavier Hueber on 21/12/2020.
//

#ifndef fonctions_h
#define fonctions_h

void selection_rotor(char rotor[][2], char nom, int *lettre);
void selection_reflecteur(char reflecteur[][2], int *lettre);
void majuscule(char phrase[TAILLE_PHRASE]);
void encodage(char phrase[TAILLE_PHRASE], char rotorA[][2], char rotorB[][2], char rotorC[][2], char reflecteur[][2]);
void decodage(char phrase[TAILLE_PHRASE], char rotorA[][2], char rotorB[][2], char rotorC[][2], char reflecteur[][2]);
char echange_lettre(char lettre, char rotor[][2], int sens);
void printRotor(char rotor[][2]);

void selection_rotor(char rotor[][2], char nom, int *lettre){
    int numero_rotor;
    printf("Veuillez s%lclectionner le rotor%c:\n",233,nom);
    printf("10 rotors sont disponibles, veuillez donner le num%lcro du rotor choisis.\n",233);
    char rotor_temporaire[26][2];
//L'utilisateur choisis l'un des dix rotors utilisé pour pour l'encodage du texte.
//Ces rotors sont symbolisés par des tableaux à deux dimensions chaque ligne du tableau est composé de la lettre d'entrée du rotor, puis de la lettre que le rotor donne en sortie.
    do {
        scanf("%d", &numero_rotor);
        switch (numero_rotor) {
            case 1:
                printf("Rotor choisis: I\n");
                char rotorI[26][2] = {  {'A','E'},{'B','K'},{'C','M'},{'D','F'},{'E','L'},{'F','G'},{'G','D'},{'H','Q'},{'I','V'},
                                        {'J','Z'},{'K','N'},{'L','T'},{'M','O'},{'N','W'},{'O','Y'},{'P','H'},{'Q','X'},{'R','U'},
                                        {'S','S'},{'T','P'},{'U','A'},{'V','I'},{'W','B'},{'X','R'},{'Y','C'},{'Z','J'}
                                     };
                memcpy(rotor_temporaire, rotorI, sizeof(rotorI)); //on copie le contenue du rotor dans un tableau temporaire qui servira après la boucle DoWhile
                break;
            case 2:
                printf("Rotor choisis: II\n");
                char rotorII[26][2] = {{'A','A'},{'B','J'},{'C','D'},{'D','K'},{'E','S'},{'F','I'},{'G','R'},{'H','U'},{'I','X'},
                                       {'J','B'},{'K','L'},{'L','H'},{'M','W'},{'N','T'},{'O','M'},{'P','C'},{'Q','Q'},{'R','G'},
                                       {'S','Z'},{'T','N'},{'U','P'},{'V','Y'},{'W','F'},{'X','V'},{'Y','O'},{'Z','E'}
                                      };
                memcpy(rotor_temporaire, rotorII, sizeof(rotorII));
                break;
            case 3:
                printf("Rotor choisis: III\n");
                char rotorIII[26][2] = {{'A','B'},{'B','D'},{'C','F'},{'D','H'},{'E','J'},{'F','L'},{'G','C'},{'H','P'},{'I','R'},
                                       {'J','T'},{'K','X'},{'L','V'},{'M','Z'},{'N','N'},{'O','Y'},{'P','E'},{'Q','I'},{'R','W'},
                                       {'S','G'},{'T','A'},{'U','K'},{'V','M'},{'W','U'},{'X','S'},{'Y','Q'},{'Z','O'}
                                      };
                memcpy(rotor_temporaire, rotorIII, sizeof(rotorIII));
                break;
            case 4:
                printf("Rotor choisis: IV\n");
                char rotorIV[26][2] = {{'A','E'},{'B','S'},{'C','O'},{'D','V'},{'E','P'},{'F','Z'},{'G','J'},{'H','A'},{'I','Y'},
                                       {'J','Q'},{'K','U'},{'L','I'},{'M','R'},{'N','H'},{'O','X'},{'P','L'},{'Q','N'},{'R','F'},
                                       {'S','T'},{'T','G'},{'U','K'},{'V','D'},{'W','C'},{'X','M'},{'Y','W'},{'Z','B'}
                                      };
                memcpy(rotor_temporaire, rotorIV, sizeof(rotorIV));
                break;
            case 5:
                printf("Rotor choisis: V\n");
                char rotorV[26][2] = {{'A','V'},{'B','Z'},{'C','B'},{'D','R'},{'E','G'},{'F','I'},{'G','T'},{'H','Y'},{'I','U'},
                                       {'J','P'},{'K','S'},{'L','D'},{'M','N'},{'N','H'},{'O','L'},{'P','X'},{'Q','A'},{'R','W'},
                                       {'S','M'},{'T','J'},{'U','Q'},{'V','O'},{'W','F'},{'X','E'},{'Y','C'},{'Z','K'}
                                      };
                memcpy(rotor_temporaire, rotorV, sizeof(rotorV));
                break;
            case 6:
                printf("Rotor choisis: VI\n");
                char rotorVI[26][2] = {{'A','J'},{'B','P'},{'C','G'},{'D','V'},{'E','O'},{'F','U'},{'G','M'},{'H','F'},{'I','Y'},
                                       {'J','Q'},{'K','B'},{'L','E'},{'M','N'},{'N','H'},{'O','Z'},{'P','R'},{'Q','D'},{'R','K'},
                                       {'S','A'},{'T','S'},{'U','X'},{'V','L'},{'W','I'},{'X','C'},{'Y','T'},{'Z','W'}
                                      };
                memcpy(rotor_temporaire, rotorVI, sizeof(rotorVI));
                break;
            case 7:
                printf("Rotor choisis: VII\n");
                char rotorVII[26][2] = {{'A','N'},{'B','Z'},{'C','J'},{'D','H'},{'E','G'},{'F','R'},{'G','C'},{'H','X'},{'I','M'},
                                       {'J','Y'},{'K','S'},{'L','W'},{'M','B'},{'N','O'},{'O','U'},{'P','F'},{'Q','A'},{'R','I'},
                                       {'S','V'},{'T','L'},{'U','P'},{'V','E'},{'W','K'},{'X','Q'},{'Y','D'},{'Z','T'}
                                      };
                memcpy(rotor_temporaire, rotorVII, sizeof(rotorVII));
                break;
            case 8:
                printf("Rotor choisis: VIII\n");
                char rotorVIII[26][2] = {{'A','F'},{'B','K'},{'C','Q'},{'D','H'},{'E','T'},{'F','L'},{'G','X'},{'H','O'},{'I','C'},
                                       {'J','B'},{'K','J'},{'L','S'},{'M','P'},{'N','D'},{'O','Z'},{'P','R'},{'Q','A'},{'R','M'},
                                       {'S','E'},{'T','W'},{'U','N'},{'V','I'},{'W','U'},{'X','Y'},{'Y','G'},{'Z','V'}
                                      };
                memcpy(rotor_temporaire, rotorVIII, sizeof(rotorVIII));
                break;
            case 9:
                printf("Rotor choisis: Beta\n");
                char rotorBeta[26][2] = {{'A','L'},{'B','E'},{'C','Y'},{'D','J'},{'E','V'},{'F','C'},{'G','N'},{'H','I'},{'I','X'},
                                       {'J','W'},{'K','P'},{'L','B'},{'M','Q'},{'N','M'},{'O','D'},{'P','R'},{'Q','T'},{'R','A'},
                                       {'S','K'},{'T','Z'},{'U','G'},{'V','F'},{'W','U'},{'X','H'},{'Y','O'},{'Z','S'}
                                      };
                memcpy(rotor_temporaire, rotorBeta, sizeof(rotorBeta));
                break;
            case 10:
                printf("Rotor choisis: Gamma\n");
                char rotorGamma[26][2] = {{'A','F'},{'B','S'},{'C','O'},{'D','K'},{'E','A'},{'F','N'},{'G','U'},{'H','E'},{'I','R'},
                                       {'J','H'},{'K','M'},{'L','B'},{'M','T'},{'N','I'},{'O','Y'},{'P','C'},{'Q','W'},{'R','L'},
                                       {'S','Q'},{'T','P'},{'U','Z'},{'V','X'},{'W','V'},{'X','G'},{'Y','J'},{'Z','D'}
                                      };
                memcpy(rotor_temporaire, rotorGamma, sizeof(rotorGamma));
                break;
            default:
                printf("Veuillez entrer un num%lcro entre 1 et 10.\n",233);
                break;
        }
    } while (numero_rotor<0 || numero_rotor>11);
    //après avoir récupéré le continue du rotor sélectionné on stocke ce rotor dans le rotor appelé en argument de la fonction.
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            // *(*(matrix + i) + j) is equivalent to &matrix[i][j]
            rotor[i][j] = rotor_temporaire[i][j];
        }
    }
    *lettre = numero_rotor;
}

void selection_reflecteur(char reflecteur[][2], int *lettre){
    int numero_reflecteur;
    printf("Veuillez sélectionner le réflecteur:\n");
    printf("4 r%lcflecteurs sont disponibles, veuillez donner le num%lcro du r%lcflecteur choisis.\n",233,233,233);
    char reflecteur_temporaire[26][2];
    do {
        scanf("%d", &numero_reflecteur);
        switch (numero_reflecteur) {
            case 1:
                printf("R%lcflecteur choisis: B\n",233);
                char reflecteurB[26][2] = {  {'A','Y'},{'B','R'},{'C','U'},{'D','H'},{'E','Q'},{'F','S'},{'G','L'},{'H','D'},{'I','P'},
                                             {'J','X'},{'K','N'},{'L','G'},{'M','O'},{'N','K'},{'O','M'},{'P','I'},{'Q','E'},{'R','B'},
                                             {'S','F'},{'T','Z'},{'U','C'},{'V','W'},{'W','V'},{'X','J'},{'Y','A'},{'Z','T'}
                                          };
                memcpy(reflecteur_temporaire, reflecteurB, sizeof(reflecteurB));
                break;
            case 2:
                printf("R%lcflecteur choisis: C\n",233);
                char reflecteurC[26][2] = {  {'A','F'},{'B','V'},{'C','P'},{'D','J'},{'E','I'},{'F','A'},{'G','O'},{'H','Y'},{'I','E'},
                                             {'J','D'},{'K','R'},{'L','Z'},{'M','X'},{'N','W'},{'O','G'},{'P','C'},{'Q','T'},{'R','K'},
                                             {'S','U'},{'T','Q'},{'U','S'},{'V','B'},{'W','N'},{'X','M'},{'Y','H'},{'Z','L'}
                                          };
                memcpy(reflecteur_temporaire, reflecteurC, sizeof(reflecteurC));
                break;
            case 3:
                printf("R%lcflecteur choisis: B D%lcnn\n",233,252);
                char reflecteurBd[26][2] = {  {'A','E'},{'B','N'},{'C','K'},{'D','Q'},{'E','A'},{'F','U'},{'G','Y'},{'H','W'},{'I','J'},
                                              {'J','I'},{'K','C'},{'L','O'},{'M','P'},{'N','B'},{'O','L'},{'P','M'},{'Q','D'},{'R','X'},
                                              {'S','Z'},{'T','V'},{'U','F'},{'V','T'},{'W','H'},{'X','R'},{'Y','G'},{'Z','S'}
                                           };
                memcpy(reflecteur_temporaire, reflecteurBd, sizeof(reflecteurBd));
                break;
            case 4:
                printf("R%lcflecteur choisis: C D%lcnn\n",233,252);
                char reflecteurCd[26][2] = {  {'A','R'},{'B','D'},{'C','O'},{'D','B'},{'E','J'},{'F','N'},{'G','T'},{'H','K'},{'I','V'},
                                              {'J','E'},{'K','H'},{'L','M'},{'M','L'},{'N','F'},{'O','C'},{'P','W'},{'Q','Z'},{'R','A'},
                                              {'S','X'},{'T','G'},{'U','Y'},{'V','I'},{'W','P'},{'X','S'},{'Y','U'},{'Z','Q'}
                                           };
                memcpy(reflecteur_temporaire, reflecteurCd, sizeof(reflecteurCd));
                break;
            default:
                printf("Veuillez entrer un num%lcro entre 1 et 4.\n",233);
                break;
        }
    } while (numero_reflecteur<1 || numero_reflecteur>4);
    //après avoir récupéré le continue du réflecteur sélectionné on stocke ce réflecteur dans le réflecteur appelé en argument de la fonction.
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            // *(*(matrix + i) + j) is equivalent to &matrix[i][j]
            reflecteur[i][j] = reflecteur_temporaire[i][j];
        }
    }
    *lettre = numero_reflecteur;
}

void majuscule(char phrase[TAILLE_PHRASE]){
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        phrase[i] = toupper(phrase[i]);
    }
}

void encodage(char phrase[TAILLE_PHRASE], char rotorA[][2], char rotorB[][2], char rotorC[][2], char reflecteur[][2]){
//    Dans cette fonction nous allons encoder le message écrit dans la variable phrase à l'aide des 3 rotors et du réflecteur.
//    Pour cela, chaque lettre du message va se faire remplacer par celle correspondante dans le rotor choisis.
//    Nous allons faire cela 3 fois pour les 3 rotors.
//    Puis la lettre sera remplacer par celle du réflecteur et repassera ensuite dans les 3 rotors pour se faire échanger de nouveau.
//    Premier encodage:
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorA\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorA, 0);
        }
    }
    printf("La phrase encod%lce(1) est:\n",233);
    printf("%s\n", phrase);
//    Second encodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorB\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorB, 0);
        }
    }
    printf("La phrase encod%lce(2) est:\n",233);
    printf("%s\n", phrase);
//    Troisième encodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorC\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorC, 0);
        }
    }
    printf("La phrase encod%lce(3) est:\n",233);
    printf("%s\n", phrase);
//    Réflecteur
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le r%lcflecteur\n", phrase[i],233);
            phrase[i] = echange_lettre(phrase[i], reflecteur, 0);
        }
    }
    printf("La phrase r%lcfl%lcchie est:\n",233,233);
    printf("%s\n", phrase);
//    Premier Réencodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorC\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorC, 1);
        }
    }
//    Deuxième réencodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorB\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorB, 1);
        }
    }
//    Troisième réencodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorA\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorA, 1);
        }
    }
    printf("La phrase encod%lce est:\n",233);
    printf("%s\n", phrase);
}

void decodage(char phrase[TAILLE_PHRASE], char rotorA[][2], char rotorB[][2], char rotorC[][2], char reflecteur[][2]){
//    Le decodage fonctionne de la manière inverse de l'encodage.
//    Troisième réencodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorA\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorA, 0);
        }
    }
//    Deuxième réencodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorB\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorB, 0);
        }
    }
//    Premier réencodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le rotorC\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorC, 0);
        }
    }
//    Réflecteur
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le réflecteur\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], reflecteur, 0);
        }
    }
    printf("La phrase reflet%lc est:\n",233);
    printf("%s\n", phrase);
//    Troisième encodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le RotorC\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorC, 1);
        }
    }
    printf("La phrase encod%lce(3) est:\n",233);
    printf("%s\n", phrase);
//    Deuxième encodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le RotorB\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorB, 1);
        }
    }
    printf("La phrase encod%lce(2) est:\n",233);
    printf("%s\n", phrase);
//    Premier encodage
    for (int i = 0; i<(strlen(phrase)-1); i++) {
        if (isalpha(phrase[i])){
            printf("Echange de %c avec le RotorA\n", phrase[i]);
            phrase[i] = echange_lettre(phrase[i], rotorA, 1);
        }
    }
    printf("La phrase d%lccod%lce est:\n",233,233);
    printf("%s\n", phrase);
}

char echange_lettre(char lettre, char rotor[][2], int sens){
//    Un rotor a deux sens de fonctionnement. Le sens du rotor A vers le réflecteur et le sens du réflecteur vers le rotor A.
//    Le sens n'a pas d'incidence sur le réflecteur.
    int i = 0;
    if (isalpha(lettre)) {
        if (sens == 0) { //sens 0: du rotor vers le réflecteur
            while (rotor[i][0] != lettre) {
    //            printf("%c",rotor[i][0]);
                i++;
            }
    //        printf("\n");
            return rotor[i][1]; //il faut prendre i-1 sinon on echange la lettre suivante
        }else{ //sens 1: du réflecteur vers le rotor
            while (rotor[i][1] != lettre) {
        //        printf("%c",rotor[i][0]);
                i++;
            }
        //    printf("\n");
            return rotor[i][0];
        }
    } else return lettre;
}

//Fonction utilsée pour voir si le rotor sélectionné a bien été copié dans notre tableau.
void printRotor(char (*rotor)[2]){
    int i, j;
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < 2; j++)
        {
            // *(*(matrix + i) + j) is equivalent to matrix[i][j]
            printf("%c ", rotor[i][j]);
        }
        printf("\n");
    }
}


#endif /* fonctions_h */
