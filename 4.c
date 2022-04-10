#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int cantidad;
    char *Buff;
    char **V;
    printf("Ingrese la cantidad de nombres a ingresar:");
    scanf("%i",&cantidad);
    getchar();
    V = (char**)malloc(sizeof(char *) * cantidad);

    Buff = (char *)malloc(100 * sizeof(char));
    
    for (int i=0; i<cantidad; i++)
    {
        printf("Ingrese el %d) nombre: ",i);
        gets(Buff);
        *(V+i)=(char *)malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(*(V+i),Buff);
    }
    
    for (int j=0; j<cantidad; j++)
    {
        printf("\n los nombres ingresados son: %s",*(V+j));
    }
        
    for (int i=0; i<cantidad; i++)
    {
        free(V[i]);
    }
    
    free(Buff);


    
}