#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>


typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}PRODUCTO;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    PRODUCTO *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}CLIENTE;

void CargarCliente(CLIENTE *Clientes, int cantidad);
void CargarProductos(PRODUCTO *producto, int cant);
void mostrarCliente(CLIENTE *Clientes, int cant);
void mostrarProductos(PRODUCTO *productos, int cant);
int totalProducto(int cantidad, float precio);

int main(){
    srand(time(NULL));

    int cantidadClientes;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    printf ("Ingrese la cantidad de clientes:");
    scanf("%d", &cantidadClientes);
    CLIENTE *pClientes;
    pClientes= (CLIENTE*) malloc(sizeof(CLIENTE)*cantidadClientes);

    CargarCliente(pClientes, cantidadClientes);
    mostrarCliente(pClientes, cantidadClientes);
    getchar();
    getchar();
    return 0;

}

void CargarCliente(CLIENTE *Clientes, int cantidad){

    for(int i=0; i < cantidad; i++){
        Clientes[i].ClienteID = i + 1;
        Clientes[i].NombreCliente = (char*)malloc(sizeof(char)*100);
        printf("Ingrese el nombre del cliente: \n");
        fflush(stdin);
        gets(Clientes[i].NombreCliente);
        Clientes[i].CantidadProductosAPedir = rand() % 6 + 1;
        Clientes[i].Productos = (PRODUCTO*)malloc(sizeof(PRODUCTO)*Clientes[i].CantidadProductosAPedir);
        CargarProductos(Clientes[i].Productos, Clientes[i].CantidadProductosAPedir);
    }
}

void CargarProductos(PRODUCTO *Productos, int cant){
    
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    for(int i=0; i < cant; i++){
        Productos[i].ProductoID = i + 1;
        Productos[i].Cantidad = rand() % 11 + 1 ; 
        Productos[i].TipoProducto = TiposProductos[rand() % 5];
        Productos[i].PrecioUnitario = rand () % 101 + 10;
    }
}

void mostrarCliente(CLIENTE *Clientes, int cant){
    char prod;
    for(int i=0; i < cant; i++){
        printf("---------- \n");
        printf("ID del cliente: %d \n", Clientes[i].ClienteID);
        printf("Nombre del cliente: %s \n", Clientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d \n", Clientes[i].CantidadProductosAPedir);
        printf("Productos pedidos: \n");
        mostrarProductos(Clientes[i].Productos, Clientes[i].CantidadProductosAPedir);
     }
}

void mostrarProductos(PRODUCTO *Productos, int cant){
    float total = 0;
     for(int i=0; i < cant; i++){
        printf("ID del producto: %d \n", Productos[i].ProductoID);
        printf("Cantidad: %d \n", Productos[i].Cantidad);
        printf("Tipo de producto: %s \n", Productos[i].TipoProducto);
        printf("Precio unitario: %f \n", Productos[i].PrecioUnitario);
        total+= totalProducto(Productos[i].Cantidad, Productos[i].PrecioUnitario);
     }
     printf("Precio total: %f \n", total);
}

int totalProducto(int cantidad, float precio){
    float aux;
    aux= cantidad * precio ;
    return (aux);
}