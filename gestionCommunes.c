//lecture des communes
#include <stdio.h>
#include <stdlib.h>

//recupération du nom de la commune
int main(int argc, char const *argv[]) {
  //char nomCom = ;
  char commune = "petit-canal";
  FILE* fichier = fopen("listeCom.txt","r");
  if (fichier != NULL){
    fscanf(fichier,"%s",&commune);
    printf("%s\n",commune );
  }
  /*
  fscanf(ficher,"%s",&nomCom);
  printf("%s\n",nomCom );*/
  return 0;
}
