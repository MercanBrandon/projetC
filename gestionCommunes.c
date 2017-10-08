/***************************************/
/**           Realisation c           **/
/**   MARIVINT Yvann & BRANDON xxxxx  **/
/***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAILLE_MAX 1000 // TAILLE MAX LECTURE DU FICHIER

void initialiser(int argc);
int menu();
int menuRechercherCommune();
int menuAjouterCommune();
void afficherCommunes();
void rechercherCommuneNom();
void rechercherCommuneCp();
void ajouterCommune();

typedef struct {
  char* nom;
} commune, *pcommune;

typedef struct {
  int code;
  pcommune commune;
} code_postale, *pcode_postale;

int retour = 1;
char chaine[TAILLE_MAX] = "";

int main (int argc, char** argv) {
    initialiser(argc);
    do{
        switch(menu()){
            case 1 :
                system("clear");
                printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
              printf(" Liste des communes de Guadeloupe : \n");
                afficherCommunes();
            break;

            case 2:
              if(menuRechercherCommune() == 1){
                    rechercherCommuneNom();
              }else{
                    rechercherCommuneCp();
              }
            break;

            case 3:

            break;
        }
        //RETOUR AU MENU
        printf("\n\n");
        printf(" Revenir au menu?\n");
        printf("\n 1 - Oui\n");
        printf(" 2 - Non\n");
        printf("\n Votre choix : ");
        scanf("%d",&retour);
        //FIN RETOUR MENU//
    }while(retour != 2);
  return 0;
}

void initialiser(int argc){
    if(argc > 1){
        printf("Erreur il ne faut aucun parametre");
        exit(1);
    }
}

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

void afficherCommunes(){
    FILE* fichier  = NULL;
    fichier = fopen("communes.txt", "r+");
    if(fichier != NULL){
        while(fgets(chaine, TAILLE_MAX, fichier) != NULL){
            printf(" - %s",chaine);
        }
        fclose(fichier);
    }else{
        printf(" Impossible d'ouvrir le fichier!");
    }
}

void rechercherCommuneNom(){
    char nom_commune_a_rechercher[1024] = "";
    char commune[1024] = "";
    int code_postale = 0;
    system("clear");
    printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
    printf(" Recherche par nom de commune : \n");
    printf(" Votre recherche : ");
    scanf("%s",&nom_commune_a_rechercher);

    FILE* fichier = NULL;
    fichier = fopen("communes.txt","r+");

    if(fichier != NULL){
        while(fscanf(fichier,"%s %d",&commune,&code_postale) != EOF){
            if(strcmp(commune,nom_commune_a_rechercher)==0){
                system("clear");
                printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
                printf(" Recherche par nom de commune : \n\n");
                printf(" Resultat de la recherche :  - %s %d",commune,code_postale);
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
    char cp_commune_a_rechercher_str[1024] = "";
    char commune[1024] = "";
    int code_postale = 0;
    system("clear");
    printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
    printf(" Recherche par code postale : \n");
    printf(" Votre recherche : ");
    scanf("%d",&cp_commune_a_rechercher);

    FILE* fichier = NULL;
    fichier = fopen("communes.txt","r+");

    sprintf(cp_commune_a_rechercher_str, "%d", cp_commune_a_rechercher);
    if(fichier != NULL){
        system("clear");
        printf(" GESTION DES COMMUNES DE GUADELOUPE\n\n");
        printf(" Recherche par code postale : %d \n\n",cp_commune_a_rechercher);
        printf(" Resultat de la recherche : \n");
        if(strlen(cp_commune_a_rechercher_str)==5){
            while(fscanf(fichier,"%s %d",&commune,&code_postale) != EOF){
                if(code_postale == cp_commune_a_rechercher){
                    printf(" - %s %d\n",commune,code_postale);
                    break;
                }
            }
        }else{
            char cp_commune_str[1024] = "";
            char cp_commune_str_bis[1024] = "";
            while(fscanf(fichier,"%s %d",&commune,&code_postale) != EOF){
                sprintf(cp_commune_str, "%d", code_postale);
                memcpy ( cp_commune_str_bis, cp_commune_str, strlen(cp_commune_a_rechercher_str) );
                printf("Commune a rechercher : %s \n Commune : %s",cp_commune_a_rechercher_str,cp_commune_str_bis);
                if(strcmp(cp_commune_str_bis,cp_commune_a_rechercher_str)==0){
                    printf("%s - %s %d\n",cp_commune_a_rechercher_str,commune,code_postale);
                }
            }
        }
    fclose(fichier);
    }else{
        printf(" Impossible d'ouvrir le fichier!");
    }
}

void ajouterCommune(){

}
