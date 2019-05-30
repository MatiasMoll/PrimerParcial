#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "utn.h"
#include "Get.h"
#define MAX_CHAR_TIPO 20

int buscarRepetidos(int* array,int valor,int sizeArray)
{
    int retorno = 0;
    int i;
    if(array != NULL && valor >= 0)
    {
        for(i=0; i<=sizeArray; i++)
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

int initArray(int* array, int size)
{
    int retorno = -1;
    int i;
    if(array != NULL && size > 0)
    {
        for(i=0;i<=size;i++)
        {
            array[i] = -1;
        }
        retorno = 0;
    }
    return retorno;
}

int informes_arrayIdNoRepetidos(Musico* arrayMusico, int sizeMusico,int* arrayResultado,int sizeArrayResultado)
{
    int retorno = -1;
    int i;
    int j=0;
    if(arrayMusico != NULL && sizeMusico > 0)
    {
        initArray(arrayResultado,sizeArrayResultado);
        for(i=0;i<sizeMusico;i++)
        {
            if(arrayMusico[i].isEmpty)
                continue;
            else if(!buscarRepetidos(arrayResultado,arrayMusico[i].idOrquesta,sizeMusico))
            {
                arrayResultado[j] = arrayMusico[i].idOrquesta;
                j++;
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informes_musicosPorOrquesta(Musico* arrayMusico, int sizeMusico,Orquesta* array, int sizeOrquesta, int* arrayResultado, int sizeArrayResultado)
{
    int retorno = -1;
    int arrayIdUnico[sizeMusico];
    int contador;
    int j;
    int i;
    if(arrayMusico != NULL && array != NULL &&arrayResultado!=NULL&& sizeMusico > 0 && sizeOrquesta >0)
    {
        initArray(arrayResultado,sizeArrayResultado);
        informes_arrayIdNoRepetidos(arrayMusico,sizeMusico,arrayIdUnico,sizeMusico);
        for(i=0; arrayIdUnico [i] != -1 ;i++)
        {
            contador = 0;
            for(j=0;j<sizeMusico;j++)
            {
                if(arrayMusico[j].isEmpty)
                    continue;
                else if(arrayIdUnico[i] == arrayMusico[j].idOrquesta)
                {
                    contador++;
                }
            }
            arrayResultado[i] = contador;
        }
        retorno = 0;
    }
    return retorno;
}

int informes_orquestaMenosSeisMusicos(Musico* arrayMusico, int sizeMusico,Orquesta* array, int sizeOrquesta)
{
    int retorno = -1;
    int arrayContador[sizeMusico];
    int arrayId[sizeMusico];
    int posId;
    int i;
    if(arrayMusico != NULL && array != NULL && sizeMusico > 0 && sizeOrquesta > 0)
    {
        informes_arrayIdNoRepetidos(arrayMusico,sizeMusico,arrayId,sizeMusico);
        informes_musicosPorOrquesta(arrayMusico,sizeMusico,array,sizeOrquesta,arrayContador,sizeMusico);
        for(i=0;arrayContador[i]!=-1;i++)
        {
            if(arrayContador[i]<6)
            {
                orquesta_buscarID(array,sizeOrquesta,arrayId[i],&posId);
                orquesta_listarUnaOrquesta(array[posId]);
            }
        }
        retorno =0;
    }
    return retorno;
}
int informes_orquestaMenosMusicos(Musico* arrayMusico, int sizeMusico,Orquesta* array, int sizeOrquesta)
{
    int retorno = -1;
    int arrayContador[sizeMusico];
    int arrayId[sizeMusico];
    int arrayIdMenosMusicos[sizeOrquesta];
    int minimo;
    int posId;
    int i;
    int j=0;
    if(arrayMusico != NULL && array != NULL && sizeMusico > 0 && sizeOrquesta > 0)
    {
        initArray(arrayIdMenosMusicos,sizeOrquesta);
        informes_arrayIdNoRepetidos(arrayMusico,sizeMusico,arrayId,sizeMusico);
        informes_musicosPorOrquesta(arrayMusico,sizeMusico,array,sizeOrquesta,arrayContador,sizeMusico);
        for(i=0;arrayContador[i]!=-1;i++)
        {
            if(i == 0)
            {
                minimo = arrayContador[i];
                arrayIdMenosMusicos[j] = arrayId[i];
                j++;
            }else if(arrayContador[i]<minimo)
                {
                    initArray(arrayIdMenosMusicos,sizeOrquesta);
                    j=0;
                    minimo = arrayContador[i];
                    arrayIdMenosMusicos[j] = arrayId[i];
                    j++;
                }else if(arrayContador[i]==minimo)
                    {
                        arrayIdMenosMusicos[j] = arrayId[i];
                        j++;
                    }
        }
        for(i=0;arrayIdMenosMusicos[i]!=-1;i++)
        {
            orquesta_buscarID(array,sizeOrquesta,arrayIdMenosMusicos[i],&posId);
            orquesta_listarUnaOrquesta(array[posId]);
        }
        printf("\nTodas las orquestas listadas poseen %d musicos\n",minimo);
        retorno =0;
    }
    return retorno;
}
int informes_orquestasCompletas(Orquesta* array, int sizeOrquesta, Musico* arrayMusico, int sizeMusico, Instrumento* arrayIns, int sizeIns)
{
    int retorno = -1;
    int arrayContador[sizeMusico];
    int arrayId[sizeOrquesta];
    int contadorViento;
    int contadorCuerda;
    int contadorPercusion;
    int j;
    int i;
    int posIdMusico;
    int posIdIns;
    if(array != NULL && arrayMusico != NULL && arrayIns != NULL && sizeOrquesta > 0 && sizeIns > 0 && sizeMusico > 0)
    {
        informes_arrayIdNoRepetidos(arrayMusico,sizeMusico,arrayId,sizeOrquesta);
        informes_musicosPorOrquesta(arrayMusico,sizeMusico,array,sizeOrquesta,arrayContador,sizeMusico);
        for(i=0;arrayContador[i]!=-1;i++)
        {
            if(arrayContador[i]>=9)
            {
                contadorViento = 0;
                contadorCuerda = 0;
                contadorPercusion = 0;
                do{
                    musico_buscarIdOrquesta(arrayMusico,sizeMusico,arrayId[i],&posIdMusico);
                    instrumento_buscarID(arrayIns,sizeIns,arrayMusico[posIdMusico].idInstrumento,&posIdIns);
                    switch(arrayIns[posIdIns].tipo)
                    {
                        case 1:
                            contadorCuerda++;
                            break;
                        case 2:
                        case 3:
                            contadorViento++;
                            break;
                        case 4:
                            contadorPercusion++;
                            break;
                    }
                    j++;
                }while(j!=arrayContador[i]);
                if(contadorCuerda>=4 && contadorViento>=4 && contadorPercusion>=1)
                {
                    orquesta_listarUnaOrquesta(array[arrayId[i]]);
                }
            }
        }
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
        for(i=0; i<=sizeArray; i++)
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
        for(i=0; i<=sizeMusico; i++)
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


int informes_instrumentosPorOrquesta(int idOrquestaBuscada, Instrumento* arrayIns, int sizeIns, Musico* arrayMusico, int sizeMusico)
{
    int retorno = -1;
    int posIns;
    int i;
    if(idOrquestaBuscada>=0 && arrayIns != NULL && sizeIns>0 && arrayMusico != NULL && sizeMusico>0)
    {
        for(i=0; i<=sizeMusico; i++)
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

int informes_promedioInstrumentos(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta, float* promedio)
{
    int retorno = -1;
    int i;
    float contadorIns = 0;
    float contadorOrquestas = 0;
    if(arrayMusico != NULL && sizeMusico> 0 && arrayOrquesta != NULL && sizeOrquesta > 0)
    {
        for(i=0; i<sizeMusico; i++)
        {
            if(arrayMusico[i].isEmpty)
                continue;
            else
            {
                contadorIns++;
            }
        }
        for(i=0; i<sizeOrquesta; i++)
        {
            if(arrayOrquesta[i].isEmpty)
                continue;
            else
            {
                contadorOrquestas++;
            }
        }
        *promedio = contadorIns/contadorOrquestas;

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
        for(i=0; i<=sizeM; i++)
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

