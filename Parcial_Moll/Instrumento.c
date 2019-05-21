#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Instrumento.h" //cambiar por nombre entidad
#define MAX_CHAR_TIPO 15


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumento Array of instrumento
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumento_Inicializar(Instrumento array[], int size)                                    //cambiar instrumento
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
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
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumento
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
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

int instrumento_tipo(Instrumento unaInstrumento,char*tipos)
{
    int retorno = 0;
    if(tipos != NULL)
    {
        switch(unaInstrumento.tipo)
        {
        case 1:
            strcpy((char*)tipos,"Cuerdas");
            break;
        case 2:
            strcpy((char*)tipos,"Viento-Madera");
            break;
        case 3:
            strcpy((char*)tipos,"Viento-Metal");
            break;
        case 4:
            strcpy((char*)tipos,"Percusion");
            break;
        }
        retorno = 1;

    }
    return retorno;
}
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumento_alta(Instrumento array[], int size, int* contadorID)                          //cambiar instrumento
{
    int retorno=0;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumento_buscarEmpty(array,size,&posicion)==-1)                          //cambiar instrumento
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            if(!utn_getName("\nIngrese Nombre de la Instrumento: ","\nError",1,MAX_CHAR_TIPO,1,array[posicion].nombre)&&
                !utn_getUnsignedInt("\nIngrese tipo de la instrumento(1-Cuerdas, 2-Viento-Madera,3-Viento-Metal,4-Percusion: ","\nError",
                                        1,sizeof(int),1,10,1,&array[posicion].tipo))
            {
                retorno=1;
            }
        }
    }
    return retorno;
}

//Listar
/** \brief Lista los elementos de un array
* \param array instrumento Array de instrumento
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumento_listar(Instrumento array[], int size)                      //cambiar instrumento
{
    int retorno=-1;
    int i;
    char tipoString[MAX_CHAR_TIPO];

    if(array!=NULL && size>=0)
    {
        for(i=0; i<=size; i++)
        {
            if(array[i].isEmpty)
                continue;
            else
            {
                instrumento_tipo(array[i],tipoString);
                printf("\nID: %d\nNombre: %s\nTipo: %s",
                       array[i].idUnico,array[i].nombre,tipoString);
            }
        }
        retorno=0;
    }
    return retorno;
}


void instrumento_mock(Instrumento arrayInstrumento[], int size,int *contadorId)                      //cambiar instrumento
{
    //*******************************************************************
    arrayInstrumento[0].idUnico=*contadorId;
    arrayInstrumento[0].isEmpty=0;
    arrayInstrumento[0].tipo=1;
    strcpy(arrayInstrumento[0].nombre,"Guitarra");
    *contadorId = *contadorId +1;

    arrayInstrumento[1].idUnico=*contadorId;
    arrayInstrumento[1].isEmpty=0;
    arrayInstrumento[1].tipo=1;
    strcpy(arrayInstrumento[1].nombre,"Guiatarra Electrica");
    *contadorId = *contadorId +1;

    arrayInstrumento[2].idUnico=*contadorId;
    arrayInstrumento[2].isEmpty=0;
    arrayInstrumento[2].tipo=2;
    strcpy(arrayInstrumento[2].nombre,"Flauta");
    *contadorId = *contadorId +1;

    arrayInstrumento[3].idUnico=*contadorId;
    arrayInstrumento[3].isEmpty=0;
    arrayInstrumento[3].tipo=4;
    strcpy(arrayInstrumento[3].nombre,"Tambores");


}


