#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "utn.h"
#include "Get.h"
#define MAX_CHAR_TIPO 20

int buscarRepetidos(int* array,int valor)
{
    int retorno = 0;
    int i;
    if(array != NULL && valor >= 0)
    {
       for(i=0;array[i]!='\0';i++)
       {
         if(array[i] == valor)
         {
            retorno = 1;
            break;
         }
       }
    }
    return retorno;
}

int inicializarIdNoRepetido(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta, int* arraySinRepetir)
{
    int retorno = -1;
    int arrayIdOrquesta[sizeMusico];
    int i;
    int j=0;
    if(arrayMusico != NULL && sizeMusico > 0 && arrayOrquesta != NULL && sizeOrquesta > 0)
    {
        for (i=0;i<sizeMusico;i++)
        {
            if(arrayMusico[i].isEmpty)
                continue;
            else if(!buscarRepetidos(arrayIdOrquesta,arrayMusico[i].idOrquesta))
            {
                arrayIdOrquesta[j] = arrayMusico[i].idOrquesta;
                j++;
            }
        }
        arraySinRepetir = arrayIdOrquesta;
        retorno = 0;
    }
    return retorno;
}

int informes_listarOrquestasLugar(Orquesta* array, char* lugarIndicado, int sizeArray)
{
    int retorno = -1;
    int i;
    if(array != NULL && lugarIndicado != NULL && sizeArray > 0)
    {
        for(i=0;i<=sizeArray;i++)
        {
            if(!strcmp(array[i].lugar,lugarIndicado))
            {
                orquesta_listarUnaOrquesta(array[i]);
                retorno = 0;
            }
        }
    }
    return retorno;
}

int informes_musicosMenoresDeVeinticinco(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta,Instrumento* arrayInstrumento, int sizeInstrumento)
{
    int retorno = -1;
    int i;
    if(arrayMusico != NULL && sizeMusico>0)
    {
        for(i=0;i<=sizeMusico;i++)
        {
            if(arrayMusico[i].isEmpty)
                continue;
            else if(arrayMusico[i].edad<25)
            {
                musico_listarUnMusico(arrayMusico[i],arrayOrquesta,sizeOrquesta,arrayInstrumento,sizeInstrumento);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informes_orquestasMenosSeisMusicos(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta)
{
    int retorno = -1;
    int arraySinRepetir[sizeMusico];
    int contador;
    int flag = 1;
    int i;
    if(arrayMusico != NULL && arrayOrquesta != NULL && sizeMusico > 0 && sizeOrquesta > 0)
    {
        inicializarIdNoRepetido(arrayMusico,sizeMusico,arrayOrquesta,sizeOrquesta,arraySinRepetir);
        do{
          for(i=0;arraySinRepetir[i] != '\0';i++)
          {
            if(buscarRepetidos(arraySinRepetir,arrayMusico[i].idOrquesta))
            {
                contador++;
            }

          }

        }while(flag);

        retorno = 0;
    }
    return retorno;
}

int informes_instrumentosPorOrquesta(int idOrquestaBuscada, Instrumento* arrayIns, int sizeIns, Musico* arrayMusico, int sizeMusico)
{
    int retorno = -1;
    int posIns;
    int i;
    if(idOrquestaBuscada>=0 && arrayIns != NULL && sizeIns>0 && arrayMusico != NULL && sizeMusico>0)
    {
        for(i=0;i<=sizeMusico;i++)
        {
            if(arrayMusico[i].isEmpty)
                continue;
            else if (arrayMusico[i].idOrquesta == idOrquestaBuscada)
            {
                instrumento_buscarID(arrayIns,sizeIns,arrayMusico[i].idInstrumento,&posIns);
                instrumento_listarUnInstrumento(arrayIns[posIns]);
                printf("\nNombre del Musico: %s\n",arrayMusico[i].nombre);
            }
            retorno = 0;
        }
    }
    return retorno;
}

int informes_promedioInstrumentos(Instrumento* arrayIns, int sizeIns, Orquesta* arrayOrquesta, int sizeOrquesta, float* promedio)
{
    int retorno = -1;
    int i;
    float contadorIns = 0;
    float contadorOrquestas = 0;
    if(arrayIns != NULL && sizeIns > 0 && arrayOrquesta != NULL && sizeOrquesta > 0)
    {
        for(i=0;i<=sizeIns;i++)
        {
            if(arrayIns[i].isEmpty)
                continue;
            else
            {
                contadorIns++;
            }
        }
        for(i=0;i<=sizeIns;i++)
        {
            if(arrayOrquesta[i].isEmpty)
                continue;
            else
            {
                contadorOrquestas++;
            }
        }
        *promedio = contadorIns / contadorOrquestas;

        retorno = 0;
    }
    return retorno;
}

int informes_musicosNoDeViento(Musico* arrayM, int sizeM, Instrumento* arrayIns, int sizeIns)
{
    int retorno = -1;
    int posIns;
    char tipoString[MAX_CHAR_TIPO];
    int i;
    if(arrayM!=NULL && sizeM>0 && arrayIns != NULL && sizeIns > 0)
    {
        musico_ordenarApellido(arrayM, sizeM);
        for(i=0;i<=sizeM;i++)
        {
            if(arrayM[i].isEmpty)
                continue;
            else
            {
                instrumento_buscarID(arrayIns,sizeIns,arrayM[i].idInstrumento,&posIns);
                if(arrayIns[posIns].tipo != 3 && arrayIns[posIns].tipo != 2)
                {
                    instrumento_tipo(arrayIns[posIns],tipoString);
                    printf("\nNombre: %s\nApellido: %s\nEdad: %d\nNombre Instrumento: %s\nTipo de Instrumento: %s\n",
                            arrayM[i].nombre,arrayM[i].apellido,arrayM[i].edad,arrayIns[posIns].nombre,tipoString);
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

