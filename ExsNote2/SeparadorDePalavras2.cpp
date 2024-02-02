#include<iostream>
#include <stdio.h>

using namespace std;

char string[50];   /* uma frase de ate 50 caracteres */
char vetor[50][30];/* cinquenta palavras de ate 30 caracteres cada */
int i,j,Npalavras,k;
int main(){
    Npalavras=1;
    /*strcpy(string,"eu fui ao baile");*/
    printf("Digite Uma Frase De No Maximo 50 Caracteres");
    gets(string);
    for(i=0;i<(int)string.size();i++){
        if(string[i]!=' '){
            vetor[j][k]=string[i];
            k++;
        }
        else{
            j++;
            k=0;
            Npalavras++;
        }
    }
    printf("\nO Texto Teve %d Palavras\n\n",Npalavras);
    for(i=0;i<Npalavras;i++){
        printf("O Que Esta Armazenado Na Posicao %d Do Vetor => %s\n",i,vetor[i]);
    }
    return 0;
}
