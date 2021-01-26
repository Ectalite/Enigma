//
//  boutons.h
//  ProjectGraphique
//
//  Created by Xavier Hueber on 19/01/2021.
//
//Fichier servant aux fonctions appelés par les boutons de l'interface graphique
#ifndef boutons_h
#define boutons_h

typedef struct elementselectione_t elementselectione_t;
struct elementselectione_t {
    GtkWidget *selectionrotor1;
    GtkWidget *selectionrotor2;
    GtkWidget *selectionrotor3;
    GtkWidget *selectionreflecteur;
    GtkWidget *text;
    GtkWidget *boutton_encodage;
    GtkWidget *sortie;
    GtkWidget *boutton_texte;
    char *emplacementfichier;
};

typedef struct boutton_t boutton_t;
struct boutton_t {
    GtkWidget *selection;
    GtkWidget *boutton_encodage;
    GtkWidget *boutton_decodage;
    GtkWidget *titretexte;
    GtkWidget *textesortie;
    GtkWidget *boutton_texte;
    GtkWidget *boutton_fichier;
    GtkWidget *text;
    GtkWidget *bouttonouvrirfenetre;
    GtkWidget *titrefichier;
};

//Fonction appelée lorsque l'on appuie sur le bouton
void selectionListes(GtkWidget *boutton, gpointer texte){
    GtkTextBuffer* text_buffer=0;
    GtkTextIter start;
    GtkTextIter end;
    gchar* buf=0;
    elementselectione_t *elementselectione = (elementselectione_t*)texte;
//    Initialisation des tableaux généraux
    char rotorA[26][2];
    char rotorB[26][2];
    char rotorC[26][2];
    char reflecteur[26][2];
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(boutton))) {
        printf("Voici la sélection choisie par l'utilisateur:\n");
        printf("Rotor 1: %s\n", gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(elementselectione->selectionrotor1)));
        printf("Rotor 2: %s\n", gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(elementselectione->selectionrotor2)));
        printf("Rotor 3: %s\n", gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(elementselectione->selectionrotor3)));
        printf("Reflecteur: %s\n", gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(elementselectione->selectionreflecteur)));
        selection_rotor(rotorA, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(elementselectione->selectionrotor1)));
        selection_rotor(rotorB, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(elementselectione->selectionrotor2)));
        selection_rotor(rotorC, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(elementselectione->selectionrotor3)));
        selection_reflecteur(reflecteur, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(elementselectione->selectionreflecteur)));
//        On récupère le texte dans la boite de texte dans une chaine de texte
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(elementselectione->boutton_texte))) { //si on est en mode texte
            text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(elementselectione->text));
            gtk_text_buffer_get_start_iter(text_buffer,&start);
            gtk_text_buffer_get_end_iter(text_buffer,&end);
            buf=gtk_text_buffer_get_text(text_buffer,&start, &end,TRUE);
            majuscule(buf);
            printf("Texte entré: %s\n", buf);
            printf("Application des tableaux de rotors:");
            if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(elementselectione->boutton_encodage))) {
                printf("Mode Encodage\n");
                encodage(buf, rotorA, rotorB, rotorC, reflecteur);
                printf("Texte encodé: %s\n", buf);
            } else {
                printf("Mode Décodage\n");
                decodage(buf, rotorA, rotorB, rotorC, reflecteur);
                printf("Texte décodé: %s\n", buf);
            }
            gtk_label_set_text (GTK_LABEL(elementselectione->sortie),buf);
        } else { //si on est en mode selection de fichier
            char phrase[1000];
            FILE *fichier;
            FILE *sortie = fopen("sortie.txt", "a+");
            fichier = fopen(elementselectione->emplacementfichier,"r");
            printf("The currently file selected : %s\n", elementselectione->emplacementfichier);
            fprintf(sortie, "--Ce fichier a été crée automatiquement par le programme Enigma.--\n");
            fprintf(sortie, "------------------------------------------------------------------\n");
            while (fgets(phrase, 1000, fichier) != NULL){ // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                majuscule(phrase);
                encodage(phrase, rotorA, rotorB, rotorC, reflecteur);
                fprintf(sortie, "%s\n",phrase);
            }
            fclose(sortie);
            fclose(fichier);
        }
        
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(boutton), FALSE); //on désactive le bouton
    }
}

//Fonction lorsqu'on appuie sur le boutton d'encodage
void boutton_encodage(GtkWidget *bouttonencodage, gpointer boutton){
    boutton_t *pointer_boutton = (boutton_t*)boutton;
    GtkWidget *bouttondecodeur = pointer_boutton->boutton_decodage;
    GtkWidget *bouttonselection = pointer_boutton->selection;
    GtkWidget *textesortie = pointer_boutton->textesortie;
    GtkWidget *titretexte = pointer_boutton->titretexte;
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bouttonencodage))) {
        gtk_widget_set_sensitive(GTK_WIDGET(bouttonencodage), FALSE);
        printf("Boutton Encodage: True\n");
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bouttondecodeur), FALSE);
        gtk_button_set_label(GTK_BUTTON(bouttonselection), "Encoder");
        gtk_label_set_text(GTK_LABEL(textesortie),"<span face=\"Optima\" size=\"20480\">Texte encodé:</span>");
        gtk_label_set_use_markup(GTK_LABEL(textesortie), TRUE);
        gtk_label_set_text(GTK_LABEL(titretexte),"<span face=\"Optima\" size=\"20480\">Texte à encoder:</span>");
        gtk_label_set_use_markup(GTK_LABEL(titretexte), TRUE);
    } else {
        printf("Boutton Encodage: False\n");
        gtk_widget_set_sensitive(GTK_WIDGET(bouttonencodage), TRUE);
    }
}

//Fonction lorsqu'on appuie sur le boutton de décodage
void boutton_decodage(GtkWidget *bouttondecodage, gpointer boutton){
    boutton_t *pointer_boutton = (boutton_t*)boutton;
    GtkWidget *bouttonencodeur = pointer_boutton->boutton_encodage;
    GtkWidget *bouttonselection = pointer_boutton->selection;
    GtkWidget *textesortie = pointer_boutton->textesortie;
    GtkWidget *titretexte = pointer_boutton->titretexte;
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bouttondecodage))) {
        gtk_widget_set_sensitive(GTK_WIDGET(bouttondecodage), FALSE);
        printf("Boutton Décodage: True\n");
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bouttonencodeur), FALSE);
        gtk_button_set_label(GTK_BUTTON(bouttonselection), "Décoder");
        gtk_label_set_text(GTK_LABEL(textesortie),"<span face=\"Optima\" size=\"20480\">Texte décodé:</span>");
        gtk_label_set_use_markup(GTK_LABEL(textesortie), TRUE);
        gtk_label_set_text(GTK_LABEL(titretexte),"<span face=\"Optima\" size=\"20480\">Texte à décoder:</span>");
        gtk_label_set_use_markup(GTK_LABEL(titretexte), TRUE);
    } else {
        printf("Boutton Décodage: False\n");
        gtk_widget_set_sensitive(GTK_WIDGET(bouttondecodage), TRUE);
    }
}

void boutton_texte(GtkWidget *bouttontexte, gpointer boutton){
    boutton_t *pointer_boutton = (boutton_t*)boutton;
    GtkWidget *bouttonfichier = pointer_boutton->boutton_fichier;
    GtkWidget *titretexte = pointer_boutton->titretexte;
    GtkWidget *text = pointer_boutton->text;
    GtkWidget *bouttonouvrirfenetre = pointer_boutton->bouttonouvrirfenetre;
    GtkWidget *titrefichier = pointer_boutton->titrefichier;
    GtkWidget *textesortie = pointer_boutton->textesortie;
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bouttontexte))) {
        gtk_widget_set_sensitive(GTK_WIDGET(bouttontexte), FALSE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bouttonfichier), FALSE);
        gtk_widget_hide(GTK_WIDGET(bouttonouvrirfenetre));
        gtk_widget_hide(GTK_WIDGET(titrefichier));
        gtk_widget_show(GTK_WIDGET(titretexte));
        gtk_widget_show(GTK_WIDGET(text));
        gtk_label_set_text(GTK_LABEL(textesortie),"<span face=\"Optima\" size=\"20480\">Texte encodé:</span>");
        gtk_label_set_use_markup(GTK_LABEL(textesortie), TRUE);
    } else {
        gtk_widget_set_sensitive(GTK_WIDGET(bouttontexte), TRUE);
    }
}

void boutton_fichier(GtkWidget *bouttonfichier, gpointer boutton){
    boutton_t *pointer_boutton = (boutton_t*)boutton;
    GtkWidget *bouttontexte = pointer_boutton->boutton_texte;
    GtkWidget *titretexte = pointer_boutton->titretexte;
    GtkWidget *text = pointer_boutton->text;
    GtkWidget *bouttonouvrirfenetre = pointer_boutton->bouttonouvrirfenetre;
    GtkWidget *titrefichier = pointer_boutton->titrefichier;
    GtkWidget *textesortie = pointer_boutton->textesortie;
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bouttonfichier))) {
        gtk_widget_set_sensitive(GTK_WIDGET(bouttonfichier), FALSE);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bouttontexte), FALSE);
        gtk_widget_hide(GTK_WIDGET(titretexte));
        gtk_widget_hide(GTK_WIDGET(text));
        gtk_widget_show(GTK_WIDGET(bouttonouvrirfenetre));
        gtk_widget_show(GTK_WIDGET(titrefichier));
        gtk_label_set_text(GTK_LABEL(textesortie),"<span face=\"Optima\" size=\"20480\">Le fichier texte de sortie se trouve dans le dossier de l'exécutable.</span>");
        gtk_label_set_use_markup(GTK_LABEL(textesortie), TRUE);
    } else {
        gtk_widget_set_sensitive(GTK_WIDGET(bouttonfichier), TRUE);
    }
}

void boutton_ouvrirfenetre(GtkFileChooser *bouttonouvrirfenetre, gpointer fichiert){
    elementselectione_t *pointer_fichier = (elementselectione_t*)fichiert;
    char *emplacementfichier = pointer_fichier->emplacementfichier;
    gchar *fichier =  gtk_file_chooser_get_filename(bouttonouvrirfenetre);
    if (!fichier) return;
    printf("The currently file selected : %s\n", fichier);
    strcpy(emplacementfichier,fichier);
    printf("The currently file selected : %s\n", emplacementfichier);
    g_free(fichier);
}

#endif /* boutons_h */
