#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
void initialiser(int argc, char** argv);
 
typedef struct {
    char* nom;
} commune, *pcommune;
 
typedef struct {
    int code;
    pcommune commune;
} code_postale, *pcode_postale;
 
int main (int argc, char** argv) {
    initialiser(argc,argv);
    return 0 ;
}
 
 
void initialiser(int argc,char** argv){
    if(argc > 1){
        printf("Erreur il ne faut aucun parametre");
        exit(1);
    }
}
