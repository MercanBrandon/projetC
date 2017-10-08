/***************************************/
/**           Realisation c           **/
/**  MARIVINT Yvann & MERCAN Brandon  **/
/***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAILLE_MAX 1000 // TAILLE MAX LECTURE DU FICHIER

// INITIALISATION DES FONCTIONS
void initialiser(int argc);
int menu();
int menuRechercherCommune();
int menuAjouterCommune();
void afficherCommunes();
void rechercherCommuneNom();
void rechercherCommuneCp();
void ajouterCommune();
// FIN INITIALISATION

typedef struct {
    char* nom;
    int code_postale;
} commune, *pcommune;

// VARIABLES GLOBALE
int retour = 1;
char chaine[TAILLE_MAX] = "";
// FIN VARIABLES GLOBALE

// DEBUT MAIN
int main (int argc, char** argv) {
    initialiser(argc);
    while(retour != 0){
        switch(menu()){ // AFFICHE LE MENU PRINCIPALE, RETOURNE LE CHOIX UTILISATEUR
            case 1 : // AFFICHE LES COMMUNES
                afficherCommunes();
            break;

            case 2: // RECHERCHE UNE COMMUNE
                if(menuRechercherCommune() == 1){
                    rechercherCommuneNom();
                }else{
                    rechercherCommuneCp();
                }
            break;

            case 3: // AJOUTE UNE COMMUNE AU FICHIER .TXT
                ajouterCommune();
            break;
        }
        //RETOUR AU MENU
        printf("\n\n");
        printf(" Revenir au menu?\n");
        printf("\n 0 - Non\n");
        printf(" 1 - Oui\n");
        printf("\n Votre choix : ");
        scanf("%d",&retour);
        //FIN RETOUR MENU//
    }
  return 0;
}
// FIN MAIN

/***************************************/
/**            FONCTIONS              **/
/***************************************/

void initialiser(int argc){
    if(argc > 1){
        printf("Erreur il ne faut aucun parametre");
        exit(1);
    }
}
// DEBUT FONCTIONS MENU
int menu(){
    int choix = 0;
    while(choix < 1 || choix > 3 ){
        system ("clear");
        printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
        printf(" Que voulez-vous faire ? :\n\n");
        printf(" 1. Afficher la liste des communes\n");
        printf(" 2. Rechercher une commune\n");
        printf(" 3. Ajouter une commune\n\n");
        printf(" Votre choix ? : ");
        scanf("%d", &choix);
        printf("\n\n");
    }
    return choix;
}

int menuRechercherCommune(){
    int choix = 0;
    while(choix < 1 || choix > 2){
        system("clear");
        printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
        printf(" Rechercher une commune de Guadeloupe : \n");
        printf(" 1. Par nom de commune\n");
        printf(" 2. Par code postal\n");
        printf("\n Votre choix : ");
        scanf("%d",&choix);
    }
    return choix;
}

int menuAjouterCommune(){
    int choix = 0;
    while(choix < 1 || choix > 2){
        system("clear");
        printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
        printf(" Ajouter une commune de Guadeloupe : \n");
        printf(" 1. Par nom de commune\n");
        printf(" 2. Par code postale\n");
        printf("\n Votre choix : ");
        scanf("%d",&choix);
    }
    return choix;
}
//FIN MENU

// CASE 1 AFFICHER COMMUNE
void afficherCommunes(){
    system("clear");
    printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
    printf(" Liste des communes de Guadeloupe : \n");
    FILE* fichier  = NULL;
    fichier = fopen("communes.txt", "r+");
    if(fichier != NULL){
        while(fgets(chaine, TAILLE_MAX, fichier) != NULL){ // LECTURE & AFFICHAGE DU FICHIER ENTIER, NE DEPASSE PAS 1000 CHARACTERE
            printf(" - %s",chaine);
        }
        fclose(fichier);
    }else{
        printf(" Impossible d'ouvrir le fichier!");
    }
}
// FIN CASE 1

// CASE 2 RECHERCHER COMMUNE
void rechercherCommuneNom(){
    char nom_commune_a_rechercher[40] = "";
    char nom_commune[40] = "";
    int code_postale = 0;
    system("clear");
    printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
    printf(" Recherche par nom de commune : \n");
    printf(" Votre recherche : ");
    scanf("%s",&nom_commune_a_rechercher);

    FILE* fichier = NULL;
    fichier = fopen("communes.txt","r+");

    if(fichier != NULL){
        while(fscanf(fichier,"%s %d",&nom_commune,&code_postale) != EOF){ // EOF = FIN DU FICHIER
            if(strcmp(nom_commune,nom_commune_a_rechercher)==0){ // STRCMP() COMPARE DEUX CHAINES DE CARACTERE, RENVOIE 0 SI IDENTITQUE
                system("clear");
                printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
                printf(" Recherche par nom de commune : \n\n");
                printf(" Resultat de la recherche : \n\n");
                printf(" - %s %d\n",nom_commune,code_postale);
                break;
            }
        }
    fclose(fichier);
    }else{
        printf(" Impossible d'ouvrir le fichier!");
    }
}

void rechercherCommuneCp(){
    int cp_commune_a_rechercher = 0;
    char cp_commune_a_rechercher_str[40] = "";
    int code_postale = 0;
    char nom_commune[40] = "";
    system("clear");
    printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
    printf(" Recherche par code postale : \n");
    printf(" Votre recherche : ");
    scanf("%d",&cp_commune_a_rechercher);

    FILE* fichier = NULL;
    fichier = fopen("communes.txt","r+");

    sprintf(cp_commune_a_rechercher_str, "%d", cp_commune_a_rechercher); // CONVERSION VARAIBLE INT EN CHAINE DE CARACTERE
    if(fichier != NULL){
        system("clear");
        printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
        printf(" Recherche par code postale : %d \n\n",cp_commune_a_rechercher);
        printf(" Resultat de la recherche : \n");
        if(strlen(cp_commune_a_rechercher_str)==5){ // VERIFICATION SI IL S'AGIT BIEN D'UN CODE POSTAL DE 5 CHIFFRES
            while(fscanf(fichier,"%s %d",&nom_commune,&code_postale) != EOF){ // EOF = FIN DU FICHIER
                if(code_postale == cp_commune_a_rechercher){
                    printf(" - %s %d\n",nom_commune,code_postale);
                    break;
                }
            }
        }
    fclose(fichier);
    }else{
        printf(" Impossible d'ouvrir le fichier!");
    }
}
// FIN CASE 2

// CASE 3 AJOUTER UNE COMMUNE
void ajouterCommune(){
    char nom_commune_a_ajouter[40];
    int cp_commune_a_ajouter = 0;
    system("clear");
    printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
    printf(" Ajouter une commune : \n\n");
    printf(" - Nom de la commune : ");
    scanf("%s",nom_commune_a_ajouter);
    printf(" - Code postal de la commune : ");
    scanf("%d",&cp_commune_a_ajouter);

    pcommune commune = malloc(sizeof(commune));     // UTILISATION DE LA STRUCTURE "COMMUNE" EN ALLOCATION DYNAMIQUE
	(*commune).nom = nom_commune_a_ajouter;         // LE NOM
	(*commune).code_postale = cp_commune_a_ajouter; // LE CODE POSTALE

    FILE* fichier = NULL;
    fichier = fopen("communes.txt","a");            // LECTURE DU FICHIER EN "a" POUR L'ECRITURE EN FIN DE FICHIER

    if(fichier != NULL){
        fprintf(fichier,"\n%s %d",commune->nom, commune->code_postale);
        fclose(fichier);
    }else{
        printf(" Impossible d'ouvrir le fichier!");
    }
    free(commune);
}
// FIN CASE 3
