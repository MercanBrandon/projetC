#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//variable globale
//char* lec1 ;
int resultat = 0;
FILE* fresultat = NULL;
FILE* fnum1 = NULL;
FILE* fnum2 = NULL;
int num1 = 0;
int num2 = 0;

int i1 = 0; //compte le nombre de chiffre du nombre 1
int i2 = 0;

//recuperation du nombre n1.
int recupn(){
  fnum1 = fopen("n1.txt","r");
  if (fnum1 != NULL) {
    do{
      num1= fgetc(fnum1);
      printf("%c", num1);
      i1++;
    }
    while (num1 != EOF);
    printf("\nil y à : %d chiffres dans le nombre1\n", i1);
  }
  else {
    printf("on ne peux pas lire le fichier : il n'existe certainement pas.\n" );
  }


  fnum2 = fopen("n2.txt","r");
  if (fnum2 != NULL) {
    do{
      num2= fgetc(fnum2);
      printf("%c", num2);
      i2++;
    }
    while (num2 != EOF);
    printf("\nil y à : %d chiffres dans le nombre2\n", i2);
  }
  else {
    printf("on ne peux pas lire le fichier : il n'existe certainement pas.\n" );
  }
  return 0;
}

//Programme de calcul
int calcul(){
  resultat = "150"-"125";
}


//script de résultat
void ecriture(){
  fresultat = fopen("resultat.txt","r+");
  fputc(resultat,fresultat);
  fclose(fresultat);
}

//programme principal
int main(int argc, char** argv) {
  recupn();
  calcul();
  ecriture();

}

//recupN1(){}
