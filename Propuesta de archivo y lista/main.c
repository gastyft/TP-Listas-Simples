#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    char nombre[30];
    int edad;
} persona;

typedef struct
{

    persona pers;
    struct nodo *siguiente;


} nodo;


nodo * crearNodo (persona pers);
nodo * inicLista();
nodo * agregarPpio (nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
void mostrarUnNodo(nodo * aux);

///Hacer un programa que lea de un archivo datos y los inserte en una lista.
int main()
{
    system("COLOR B");
    FILE *archi= fopen("ARCH","a+b");
    persona pers;
    if(archi)
    {
            pers.edad=20

          fwrite(&pers,sizeof(persona),1,archi);

           fwrite(&pers,sizeof(persona),1,archi);
              pers.edad+=1;
                pers.nombre= "Robert";
            fwrite(&nume,sizeof(nume),1,archi);
               pers.edad+=1;
               pers.nombre="Slash";
             fwrite(&nume,sizeof(nume),1,archi);

        fclose(archi);
        nume num1;
        int num3,cant;
        archi=fopen("ARCH","r+b");
        nodo *list= NULL ;



        while(!feof(archi))
        {
            cant=fread(&num3,sizeof(int),1,archi);
            for(int i=0; i<cant; i++)
            {
                printf("%d \n",num3);
                num1.num= num3;

                nodo * nuevo=NULL;
                nuevo =crearNodo(num1);
                list= agregarPpio(list,nuevo);
            }
        }

        nodo * aux= list;

        mostrarUnNodo(aux);


    }
    else
    {
        printf("ERROR \n");
    }

    fclose(archi);
    return 0;
}

nodo * inicLista()
{
    return NULL;
}


nodo * crearNodo (nume num2)
{
//crea un puntero de tipo nodo
    nodo * aux = (nodo*) malloc(sizeof(nodo));
//asigna valores a sus campos de información
    aux->num= num2;
//asigna valor NULL al campo que contiene la dirección de memoria del //siguiente nodo
    aux->siguiente = NULL;
//retorna la dirección de memoria del nuevo nodo, que deberá ser asignada a una variable de tipo "puntero a nodo".
    return aux;
}


nodo * agregarPpio (nodo * lista, nodo * nuevoNodo)
{
//si la lista está vacía, ahora apuntará al nuevo nodo.
    if(lista == NULL)
    {
        lista = nuevoNodo;

    }
    else
//si la lista no está vacía, inserta el nuevo nodo al comienzo de la //misma, y el viejo primer nodo pasa a ser el segundo de la lista.
    {
        nuevoNodo->siguiente = lista;   /// PREGUNTAR PORQUE TIRA WARNING. SI PONGO   lista ->siguiente  ENTONCES SE VA EL WARNING
        lista = nuevoNodo;

    }
    return lista;
}


nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg= seg->siguiente;    /// PREGUNTAR PORQUE TIRA WARNING. SI PONGO   seg->siguiente  ENTONCES SE VA EL WARNING
        }
    return seg;
}

void mostrarUnNodo(nodo * aux)
{
    nodo *seg=NULL;

    seg=aux;

    if(seg!=NULL)
    {


        while(seg != NULL)
        {

            printf("NUMEROS EN LA LISTA  %d \n",seg->num.num);
            seg = seg ->siguiente;
        }
    }
}
