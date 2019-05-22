#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Musico.h" //cambiar por nombre entidad
#include "Instrumento.h"
#include "Orquesta.h"
#define QTY_ARRAY_ORQUESTA 50
#define MAX_CHAR_TIPO 50

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)                                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
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
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
/*int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}*/


//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID)                          //cambiar musico
{
    int retorno=0;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)                          //cambiar musico
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            if(!utn_getName("\nIngrese Nombre del musico: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)&&
                    !utn_getName("\nIngrese Apellido del musico: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido)&&
                    !utn_getUnsignedInt("\nIngrese su edad: ","\nError",1,sizeof(int),5,88,1,&array[posicion].edad))
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)                                      //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),0,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=-1;                                                                   //cambiar campo id
            array[posicion].idOrquesta=-1;                                                               //cambiar campo varInt
            array[posicion].idInstrumento=-1;
            array[posicion].edad=0;                                                              //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posicion].apellido,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

int musico_bajaPorOrquesta(Musico array[],int* posABorrar)
{
    int retorno = -1;
    if(array != NULL && posABorrar != NULL)
    {
        for(int i=0; posABorrar[i] != -1; i++)
        {
            array[posABorrar[i]].isEmpty=1;
            array[posABorrar[i]].idUnico=-1;                                                                   //cambiar campo id
            array[posABorrar[i]].idOrquesta=-1;                                                               //cambiar campo varInt
            array[posABorrar[i]].idInstrumento=-1;
            array[posABorrar[i]].edad=0;                                                              //cambiar campo varFloat
            strcpy(array[posABorrar[i]].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posABorrar[i]].apellido,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

int musico_buscarIdOrquesta(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    int j=0;
    if(array!= NULL && size>=0)
    {
        for(i=0; i<=size; i++)
        {
            if(array[i].isEmpty)
                continue;
            else if(array[i].idOrquesta==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                posicion[j] = i;
                j++;

            }
        }
        posicion[j] = -1;
    }
    return retorno;
}
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_mostrarDatosPersonales(Musico array[],int sizeArray)
{
    int retorno = 0;
    int i;
    if(array != NULL && sizeArray>=0)
    {
        for(i=0; sizeArray<=i; i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nId: %d\nNombre: %s\nApellido: %s",
                       array[i].idUnico,array[i].nombre,array[i].apellido);
            }
            else
                continue;
        }
        retorno = 1;
    }
    return retorno;
}

int musico_ordenarApellido(Musico *array, int sizeArray)
{
    int retorno = -1;
    Musico aux;
    int i;
    int j;
    if(array != NULL && sizeArray > 0)
    {
        for(i=0;i<sizeArray;i++)
        {
            for(j=0;j<=sizeArray;j++)
            if(array[j].isEmpty)
                continue;
            else if (strcmp(array[i].apellido,array[j].apellido)<0)
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int musico_modificar(Musico array[], int sizeArray)                                //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {
                utn_getSignedInt("Modificar 1-Edad, 2-Id de orquesta:\n3-Salir","Opcion Invalida",1,1,1,2,2,&opcion);
                switch(opcion)
                {
                case 1:
                    if(!utn_getUnsignedInt("Ingrese la nueva edad","Edad invalida",1,2,10,88,2,&array[posicion].edad))
                    {
                        printf("Edad cambiada satisfactoriamente");
                    }
                    break;
                case 2:
                    if(!utn_getUnsignedInt("Ingrese el nuevo id de la orquesta","Id invalid",1,2,0,QTY_ARRAY_ORQUESTA,2,&array[posicion].idOrquesta))
                    {
                        printf("Orquesta cambiada satisfactoriamente");
                    }
                    break;
                }

            }
            while(opcion!=3);
            retorno=0;
        }
    }
    return retorno;
}

int musico_listarUnMusico(Musico unMusico,Orquesta* arrayOrquesta,int sizeOrquesta,Instrumento* arrayInstrumento,int sizeInstrumento)
{
    int retorno = -1;
    int posOrquesta;
    int posInstrumento;
    char tipoString[MAX_CHAR_TIPO];
    if(arrayOrquesta != NULL)
    {
        orquesta_buscarID(arrayOrquesta, sizeOrquesta,unMusico.idOrquesta,&posOrquesta);
        orquesta_tipo(arrayOrquesta[posOrquesta], tipoString);
        instrumento_buscarID(arrayInstrumento, sizeInstrumento,unMusico.idInstrumento,&posInstrumento);
        printf("\nID: %d\nNombre: %s\nApellido: %s\nEdad: %d\nNombre de Instrumento: %s\nNombre de la Orquesta: %s\n",
            unMusico.idUnico,unMusico.nombre,unMusico.apellido,unMusico.edad,arrayInstrumento[posInstrumento].nombre,arrayOrquesta[posOrquesta].nombre);
        retorno = 0;
    }


    return retorno;

}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[],Instrumento arrayI[],int sizeI, int size)                      //cambiar musico
{
    int retorno=-1;
    int i;
    int idIns;
    char tipoIns[MAX_CHAR_TIPO];

    if(array!=NULL && size>=0)
    {
        for(i=0; i<size; i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                if(!instrumento_buscarID(arrayI,sizeI,array[i].idInstrumento,&idIns)&&
                        instrumento_tipo(arrayI[idIns],tipoIns))
                {
                    printf("\nID: %d\nNombre: %s\nNombre de Instrumento: %s\nTipo de Instrumento: %s\nId Orquesta: %d\n",
                           array[i].idUnico,array[i].nombre,arrayI[idIns].nombre,tipoIns,array[i].idOrquesta);
                }
                else
                {
                    printf("\nID: %d\nNombre: %s\nApellido: %s\nId Orquesta: %d\n*Este musico no toca ningun instrumento*",
                           array[i].idOrquesta,array[i].nombre,array[i].apellido,array[i].idOrquesta);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}


void musico_mock(Musico arrayMusico[], int size,int *contadorId)                      //cambiar musico
{
    //*******************************************************************
    arrayMusico[0].idUnico=1;
    arrayMusico[0].isEmpty=0;
    arrayMusico[0].edad=30;
    arrayMusico[0].idOrquesta=1;
    arrayMusico[0].idInstrumento=2;
    strcpy(arrayMusico[0].nombre,"Mus1");
    strcpy(arrayMusico[0].apellido,"AMus1");
   // *contadorId=*contadorId +1;

    arrayMusico[1].idUnico=2;
    arrayMusico[1].isEmpty=0;
    arrayMusico[1].edad=20;
    arrayMusico[1].idOrquesta=2;
    arrayMusico[1].idInstrumento=5;
    strcpy(arrayMusico[1].nombre,"Mus2");
    strcpy(arrayMusico[1].apellido,"AMus2");
    //*contadorId=*contadorId +1;

    arrayMusico[2].idUnico=3;
    arrayMusico[2].isEmpty=0;
    arrayMusico[2].edad=25;
    arrayMusico[2].idOrquesta=4;
    arrayMusico[2].idInstrumento=2;
    strcpy(arrayMusico[2].nombre,"Mus3");
    strcpy(arrayMusico[2].apellido,"AMus3");
    //*contadorId=*contadorId +1;

    arrayMusico[3].idUnico=4;
    arrayMusico[3].isEmpty=0;
    arrayMusico[3].edad=27;
    arrayMusico[3].idOrquesta=4;
    arrayMusico[3].idInstrumento=1;
    strcpy(arrayMusico[3].nombre,"Mus4");
    strcpy(arrayMusico[3].apellido,"AMus4");
    //*contadorId=*contadorId +1;


    arrayMusico[4].idUnico=5;
    arrayMusico[4].isEmpty=0;
    arrayMusico[4].edad=22;
    arrayMusico[4].idOrquesta=1;
    arrayMusico[4].idInstrumento=3;
    strcpy(arrayMusico[4].nombre,"Mus5");
    strcpy(arrayMusico[4].apellido,"AMus5");

    arrayMusico[5].idUnico=6;
    arrayMusico[5].isEmpty=0;
    arrayMusico[5].edad=35;
    arrayMusico[5].idOrquesta=3;
    arrayMusico[5].idInstrumento=4;
    strcpy(arrayMusico[5].nombre,"Mus6");
    strcpy(arrayMusico[5].apellido,"AMus6");
    *contadorId = 6;
}

