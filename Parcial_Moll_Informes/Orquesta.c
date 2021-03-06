#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "Get.h"
#include "Orquesta.h" //cambiar por nombre entidad
#include "Musico.h"
#define MAX_CHAR_TIPO 15


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)                                    //cambiar orquesta
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(; size>=0; size--)
        {
            array[size].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0; i<=size; i++)
        {
            if(array[i].isEmpty)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)                    //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int orquesta_tipo(Orquesta unaOrquesta,char*tipos)
{
    int retorno = 0;
    if(tipos != NULL)
    {
        switch(unaOrquesta.tipo)
        {
        case 1:
            strcpy((char*)tipos,"Sinfonica");
            break;
        case 2:
            strcpy((char*)tipos,"Filarmonica");
            break;
        case 3:
            strcpy((char*)tipos,"Camara");
            break;
        }
        retorno = 1;
    }
    return retorno;
}
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)                          //cambiar orquesta
{
    int retorno=0;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)                          //cambiar orquesta
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            if(!utn_getTexto("\nIngrese Nombre de la Orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)&&
                    !utn_getTexto("\nIngrese lugar de origen de la orquesta: ","\nError",1,TEXT_SIZE,1,array[posicion].lugar)&&
                    !GET_Edad("\nIngrese tipo de la orquesta(1-Sinfonica, 2-Filarmonica,3-Camara): ","\nError",
                              1,3,1,&array[posicion].tipo))
            {
                retorno=1;
            }
        }
    }
    return retorno;
}

//*****************************************

//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray,int id)                                      //cambiar orquesta
{
    int retorno=-1;
    int posicion;
    if(array!= NULL && sizeArray>=0)
    {

        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].tipo=0;                                                               //cambiar campo varInt
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posicion].lugar,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}


int orquesta_listarUnaOrquesta(Orquesta unaOrquesta)
{
    int retorno = -1;
    char tipoString[MAX_CHAR_TIPO];
    orquesta_tipo(unaOrquesta, tipoString);
    printf("\nId: %d\nNombre: %s\nLugar: %s\nTipo: %s",
           unaOrquesta.idUnico,unaOrquesta.nombre,unaOrquesta.lugar,tipoString);
    retorno = 0;

    return retorno;

}
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)                      //cambiar orquesta
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0; i<=size; i++)
        {
            if(array[i].isEmpty)
                continue;
            else
            {
                orquesta_listarUnaOrquesta(array[i]);
            }
        }
        retorno=0;
    }
    return retorno;
}


void orquesta_mock(Orquesta arrayOrquesta[],int *contadorId)                      //cambiar orquesta
{
    //*******************************************************************
    arrayOrquesta[1].idUnico=1;
    arrayOrquesta[1].isEmpty=0;
    arrayOrquesta[1].tipo=1;
    strcpy(arrayOrquesta[1].nombre,"Orquesta1");
    strcpy(arrayOrquesta[1].lugar,"Lugar1");
    //*contadorId = *contadorId +1;

    arrayOrquesta[2].idUnico=2;
    arrayOrquesta[2].isEmpty=0;
    arrayOrquesta[2].tipo=2;
    strcpy(arrayOrquesta[2].nombre,"Orquesta2");
    strcpy(arrayOrquesta[2].lugar,"Lugar1");
    //*contadorId = *contadorId +1;

    arrayOrquesta[3].idUnico=3;
    arrayOrquesta[3].isEmpty=0;
    arrayOrquesta[3].tipo=3;
    strcpy(arrayOrquesta[3].nombre,"Orquesta3");
    strcpy(arrayOrquesta[3].lugar,"Lugar2");
    //*contadorId = *contadorId +1;

    arrayOrquesta[4].idUnico=4;
    arrayOrquesta[4].isEmpty=0;
    arrayOrquesta[4].tipo=2;
    strcpy(arrayOrquesta[4].nombre,"Orquesta4");
    strcpy(arrayOrquesta[4].lugar,"Lugar3");
    *contadorId = 4;
}

