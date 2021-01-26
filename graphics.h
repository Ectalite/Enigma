//
//  graphics.h
//  ProjectGraphique
//
//  Created by Xavier Hueber on 23/12/2020.
//
#include <gtk/gtk.h>
#include "fonctions.h"
#include "boutons.h"

#ifndef graphics_h
#define graphics_h
#define espacement 10 //espacement entre les éléments graphiques

void initialisation(int argc, const char * argv[]){
//    Initialisation de gtk
    /* Variables-Pointeurs */
    GtkWidget *Enigma = NULL;
    GtkWidget *rotors, *vbox1, *vboxrotor1, *vboxrotor2, *vboxrotor3, *vboxreflecteur, *vboxtexte, *hboxboutton1, *vboxsortie, *hboxboutton2;
    GtkWidget *Titre, *selectionRotor1, *selectionRotor2, *selectionRotor3, *selectionReflecteur, *titretexte, *textesortie, *sortie, *titrefichier;
    GtkWidget *menuRotor1, *menuRotor2, *menuRotor3, *menuReflecteur;
    GtkWidget *text;
    GtkWidget *boutton, *bouttonencodeur, *bouttondecodeur, *bouttontexte, *bouttonfichier, *bouttonouvrirfenetre;
    char emplacementfichier[1000];
    
    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);
    /* Création de la fenêtre */
    Enigma = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(Enigma), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
    
    //Tableaux acceuillant les textes, les boutons et fenêtres déroulantes
    vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 70); //On créer un tableau vertical général
    rotors = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0); //On créer un tableau horizontal acceuillant les tableaux des rotors
    vboxrotor1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); //On créer un tableau horizontal acceuillant notre texte
    vboxrotor2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); //On créer un tableau horizontal acceuillant notre texte
    vboxrotor3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); //On créer un tableau horizontal acceuillant notre texte
    vboxreflecteur = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); //On créer un tableau horizontal acceuillant notre texte
    vboxtexte = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); //On créer un tableau horizontal acceuillant notre texte
    hboxboutton1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 50);
    vboxsortie = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    hboxboutton2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 50);
    
    //Textes
    Titre = gtk_label_new("<span face=\"Courier New\" size=\"30720\"><b>ENIGMA</b></span>"); //taille de police  = taille * 1024
    gtk_label_set_use_markup(GTK_LABEL(Titre), TRUE); //on active l'utilisation des balises de style
    gtk_label_set_justify(GTK_LABEL(Titre), GTK_JUSTIFY_CENTER); // On centre notre texte
    selectionRotor1 = gtk_label_new("<span face=\"Optima\" size=\"20480\">Sélection rotor 1:</span>");
    gtk_label_set_use_markup(GTK_LABEL(selectionRotor1), TRUE);
    gtk_label_set_justify(GTK_LABEL(selectionRotor1), GTK_JUSTIFY_CENTER); // On centre notre texte
    selectionRotor2 = gtk_label_new("<span face=\"Optima\" size=\"20480\">Sélection rotor 2:</span>");
    gtk_label_set_use_markup(GTK_LABEL(selectionRotor2), TRUE);
    gtk_label_set_justify(GTK_LABEL(selectionRotor2), GTK_JUSTIFY_CENTER); // On centre notre texte
    selectionRotor3 = gtk_label_new("<span face=\"Optima\" size=\"20480\">Sélection rotor 3:</span>");
    gtk_label_set_use_markup(GTK_LABEL(selectionRotor3), TRUE);
    gtk_label_set_justify(GTK_LABEL(selectionRotor3), GTK_JUSTIFY_CENTER); // On centre notre texte
    selectionReflecteur = gtk_label_new("<span face=\"Optima\" size=\"20480\">Sélection réflecteur:</span>");
    gtk_label_set_use_markup(GTK_LABEL(selectionReflecteur), TRUE);
    gtk_label_set_justify(GTK_LABEL(selectionReflecteur), GTK_JUSTIFY_CENTER); // On centre notre texte
    titretexte = gtk_label_new("<span face=\"Optima\" size=\"20480\">Texte à encoder:</span>");
    gtk_label_set_use_markup(GTK_LABEL(titretexte), TRUE);
    gtk_label_set_justify(GTK_LABEL(titretexte), GTK_JUSTIFY_CENTER); // On centre notre texte
    titrefichier = gtk_label_new("<span face=\"Optima\" size=\"20480\">Sélection d'un fichier:</span>");
    gtk_label_set_use_markup(GTK_LABEL(titrefichier), TRUE);
    gtk_label_set_justify(GTK_LABEL(titrefichier), GTK_JUSTIFY_CENTER); // On centre notre texte
    textesortie = gtk_label_new("<span face=\"Optima\" size=\"20480\">Texte encodé:</span>");
    gtk_label_set_use_markup(GTK_LABEL(textesortie), TRUE);
    sortie = gtk_label_new("");
    gtk_label_set_selectable(GTK_LABEL(sortie), TRUE); //on fait en sorte que le texte soit selectionnable. Comme ça on peut le copier-coller.
    
    //Boutons
    boutton = gtk_toggle_button_new_with_label("Encoder");
    gtk_widget_set_margin_start(boutton, 70);
    gtk_widget_set_margin_end(boutton, 70);
    bouttonencodeur = gtk_toggle_button_new_with_label("Encodage");
    gtk_widget_set_margin_start(bouttonencodeur, 70);
    bouttondecodeur = gtk_toggle_button_new_with_label("Décodage");
    gtk_widget_set_margin_end(bouttondecodeur, 70);
    bouttontexte = gtk_toggle_button_new_with_label("Texte");
    gtk_widget_set_margin_start(bouttontexte, 120);
    bouttonfichier = gtk_toggle_button_new_with_label("Fichier");
    gtk_widget_set_margin_end(bouttonfichier, 120);
    bouttonouvrirfenetre = gtk_file_chooser_button_new("Sélection d'un fichier",GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_widget_set_margin_start(bouttonouvrirfenetre, 150);
    gtk_widget_set_margin_end(bouttonouvrirfenetre, 150);
    
    //Menus déroulants
    const char *listerotor[] = {"Rotor I", "Rotor II", "Rotor III", "Rotor IV", "Rotor V", "Rotor VI", "Rotor VII", "Rotor VIII", "Rotor Beta", "Rotor Gamma"}; //Listes contenant les éléments pouvant etres choisis dans la liste déroulante
    const char *listereflecteur[] = {"Réflecteur B", "Réflecteur C", "Réflecteur B Dünn", "Réflecteur C Dünn"};
    
    menuRotor1 = gtk_combo_box_text_new();//On créer les listes déroulantes
    menuRotor2 = gtk_combo_box_text_new();
    menuRotor3 = gtk_combo_box_text_new();
    menuReflecteur = gtk_combo_box_text_new();
    
    for (int i = 0; i < G_N_ELEMENTS (listerotor); i++){ //On ajoute chaque élément de la liste aux listes déroulantes
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(menuRotor1), listerotor[i]);
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(menuRotor2), listerotor[i]);
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(menuRotor3), listerotor[i]);
    }
    for (int i = 0; i < G_N_ELEMENTS (listereflecteur); i++){
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(menuReflecteur), listereflecteur[i]);
    }
    
    gtk_combo_box_set_active(GTK_COMBO_BOX(menuRotor1), 0);
    gtk_combo_box_set_active(GTK_COMBO_BOX(menuRotor2), 0);
    gtk_combo_box_set_active(GTK_COMBO_BOX(menuRotor3), 0);
    gtk_combo_box_set_active(GTK_COMBO_BOX(menuReflecteur), 0);
    
    //Boite de texte
    text = gtk_text_view_new();
    gtk_widget_set_margin_start(text, 100);
    gtk_widget_set_margin_end(text, 100);
    
    //on créer un pointeur pointant vers les boutons pour pouvoir gérer leur état dans les fonctions boutton_encodage et boutton_decodage
    boutton_t pointer_boutton;
    pointer_boutton.boutton_decodage = bouttondecodeur;
    pointer_boutton.boutton_encodage = bouttonencodeur;
    pointer_boutton.selection = boutton;
    pointer_boutton.textesortie = textesortie;
    pointer_boutton.titretexte = titretexte;
    pointer_boutton.boutton_fichier = bouttonfichier;
    pointer_boutton.boutton_texte = bouttontexte;
    pointer_boutton.text = text;
    pointer_boutton.bouttonouvrirfenetre = bouttonouvrirfenetre;
    pointer_boutton.titrefichier = titrefichier;
    
    //On a crée un type elementselectione_t pour pouvoir récupérer les données des menus déroulants et des bouttons à travers le gpointer lorsque que l'on clique sur le bouton
    elementselectione_t elementselectione;
    elementselectione.selectionrotor1 = menuRotor1;
    elementselectione.selectionrotor2 = menuRotor2;
    elementselectione.selectionrotor3 = menuRotor3;
    elementselectione.selectionreflecteur = menuReflecteur;
    elementselectione.text = text;
    elementselectione.boutton_encodage = bouttonencodeur;
    elementselectione.sortie = sortie;
    elementselectione.boutton_texte = bouttontexte;
    elementselectione.emplacementfichier = emplacementfichier;
    
    /* Affichage et boucle évènementielle */
    gtk_window_set_title(GTK_WINDOW(Enigma), "Enigma");
    gtk_widget_show(Enigma);
    gtk_window_resize(GTK_WINDOW(Enigma), 720, 480); //Fonction servant a définir la hauteur et la largeur de la fenêtre.
    gtk_window_set_resizable(GTK_WINDOW(Enigma), TRUE);
    
    gtk_container_add(GTK_CONTAINER(Enigma), vbox1);
    gtk_box_pack_start(GTK_BOX(vbox1), Titre, TRUE, FALSE, espacement); //on ajoute le texte Titre au tableau vertical
    gtk_box_pack_start(GTK_BOX(vbox1), hboxboutton1, TRUE, TRUE, 0); //on ajoute un tableau horizontal au tableau vertical
    gtk_box_pack_start(GTK_BOX(hboxboutton1), bouttonencodeur, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hboxboutton1), bouttondecodeur, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox1), hboxboutton2, TRUE, TRUE, 0); //on ajoute un tableau horizontal au tableau vertical
    gtk_box_pack_start(GTK_BOX(hboxboutton2), bouttontexte, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hboxboutton2), bouttonfichier, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox1), rotors, TRUE, TRUE, 0); //on ajoute un tableau horizontal au tableau vertical
    gtk_box_pack_start(GTK_BOX(rotors), vboxrotor1, TRUE, TRUE, espacement); //on ajoute un tableau horizontal au tableau vertical
    gtk_box_pack_start(GTK_BOX(vboxrotor1), selectionRotor1, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vboxrotor1), menuRotor1, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(rotors), vboxrotor2, TRUE, TRUE, espacement); //on ajoute un tableau horizontal au tableau vertical
    gtk_box_pack_start(GTK_BOX(vboxrotor2), selectionRotor2, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vboxrotor2), menuRotor2, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(rotors), vboxrotor3, TRUE, TRUE, espacement); //on ajoute un tableau horizontal au tableau vertical
    gtk_box_pack_start(GTK_BOX(vboxrotor3), selectionRotor3, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vboxrotor3), menuRotor3, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(rotors), vboxreflecteur, TRUE, TRUE, espacement); //on ajoute un tableau horizontal au tableau vertical
    gtk_box_pack_start(GTK_BOX(vboxreflecteur), selectionReflecteur, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vboxreflecteur), menuReflecteur, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vbox1), vboxtexte, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vboxtexte), titretexte, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vboxtexte), text, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox1), boutton, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vbox1), vboxsortie, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vboxsortie), textesortie, TRUE, TRUE, espacement);
    gtk_box_pack_start(GTK_BOX(vboxsortie), sortie, TRUE, TRUE, espacement);
    
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bouttonencodeur), TRUE); //on met le bouton encodeur en activé par default
    gtk_widget_set_sensitive(GTK_WIDGET(bouttonencodeur), FALSE); //on bloque le bouton pour que l'utilisateur ne puisse pas le déselectionner
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(bouttontexte), TRUE); //on fait de même avec le boutton texte
    gtk_widget_set_sensitive(GTK_WIDGET(bouttontexte), FALSE);
    gtk_widget_show_all(Enigma);
    gtk_box_pack_start(GTK_BOX(vboxtexte), titrefichier, TRUE, TRUE, 0); //on ajoute ces éléments à l'interface après avoir afficher les autres
    gtk_box_pack_start(GTK_BOX(vboxtexte), bouttonouvrirfenetre, TRUE, TRUE, 0); //comme ça ils sont cachés
    
    //les fonctions appelées par les boutons se trouvent dans le header boutons.h
    g_signal_connect(G_OBJECT(boutton), "clicked", G_CALLBACK(selectionListes), (gpointer)&elementselectione);
    g_signal_connect(G_OBJECT(bouttonencodeur), "clicked", G_CALLBACK(boutton_encodage), (gpointer)&pointer_boutton);
    g_signal_connect(G_OBJECT(bouttondecodeur), "clicked", G_CALLBACK(boutton_decodage), (gpointer)&pointer_boutton);
    g_signal_connect(G_OBJECT(bouttontexte), "clicked", G_CALLBACK(boutton_texte), (gpointer)&pointer_boutton);
    g_signal_connect(G_OBJECT(bouttonfichier), "clicked", G_CALLBACK(boutton_fichier), (gpointer)&pointer_boutton);
    g_signal_connect(G_OBJECT(bouttonouvrirfenetre), "file-set", G_CALLBACK(boutton_ouvrirfenetre), (gpointer)&elementselectione);
    gtk_main();
}
#endif /* graphics_h */
