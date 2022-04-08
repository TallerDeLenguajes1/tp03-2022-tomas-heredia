#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
    char *V[5];
    
    for (int i = 0; i < 5; i++)
    {
        V[i] = (char *)malloc(20*sizeof(char));

    }
    
    for (int i = 0; i < 5; i++)
    {
       printf("\n ingrese el nombre %d: ",i+1);
       gets(V[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\n El nombre %d es: ",i+1);
        puts(V[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        free(V[i]);

    }
}