#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
    char *V[5];
    char *Buff= (char *) malloc(100*sizeof(char));
    

    
    for (int i = 0; i < 5; i++)   //ingresa nombres
    {
        
       printf("\n ingrese el nombre %d: ",i+1);
       gets(Buff);
       V[i]= (char *) malloc((strlen(Buff)+1)*sizeof(char));
       strcpy(V[i],Buff);
    }

    for (int i = 0; i < 5; i++) //muestro nombres
    {
        printf("\n El nombre %d es: ",i+1);
        puts(V[i]);
    }

    for (int i = 0; i < 5; i++)//libero memoria
    {
        free(V[i]);

    }
    free(Buff);
}