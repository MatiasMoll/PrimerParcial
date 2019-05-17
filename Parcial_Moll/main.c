#include <stdio_ext.h>
#include <stdlib.h>
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "utn.h"
#define QTY_ARRAY_ORQUESTA 50
#define QTY_ARRAY_MUSICO 1000
#define QTY_ARRAY_INSTRUMENTOS 20

int main()
{
    Orquesta array[QTY_ARRAY_ORQUESTA];
    orquesta_Inicializar(array,QTY_ARRAY_ORQUESTA);
    int contadorIdorquesta=0;
    orquesta_mock(array,QTY_ARRAY_ORQUESTA,&contadorIdorquesta);


    Musico arrayMusico[QTY_ARRAY_MUSICO];
    musico_Inicializar(arrayMusico,QTY_ARRAY_MUSICO);
    int contadorIdMusico=0;
    musico_mock(arrayMusico,QTY_ARRAY_MUSICO,&contadorIdMusico);
    int posMusico;

    Instrumento arrayInstrumento[QTY_ARRAY_INSTRUMENTOS];
    instrumento_Inicializar(arrayInstrumento,QTY_ARRAY_INSTRUMENTOS);
    int contadorIdInstrumento=0;
    instrumento_mock(arrayInstrumento,QTY_ARRAY_INSTRUMENTOS,&contadorIdInstrumento);


    int primeraOpcion;
    int opcion;
    do
    {
    __fpurge(stdin);
    utn_getUnsignedInt("\n1-Menu Orquesta\n2-Menu Musico\n3-Menu Instrumento\n4-Salir\nIngrese su opcion: ","\nOpcion Invalida.",1,sizeof(int),1,4,1,&primeraOpcion);
    switch(primeraOpcion)
    {
    case 1:
        do
        {
            __fpurge(stdin);
            utn_getUnsignedInt("\n\n-------MENU ORQUESTA-------\n\n1) Alta \n2) Baja \n3) Listar\n4)Salir\nIngrese la opcion: ",                   //cambiar
                               "\nError",1,sizeof(int),1,4,1,&opcion);
            switch(opcion)
            {
            case 1: //Alta
                __fpurge(stdin);
                if(orquesta_alta(array,QTY_ARRAY_ORQUESTA,&contadorIdorquesta))
                {
                    orquesta_listar(array,QTY_ARRAY_ORQUESTA);
                }
                break;

            case 2:
                __fpurge(stdin);
                orquesta_baja(array,QTY_ARRAY_ORQUESTA);
                break;

            case 3:
                __fpurge(stdin);
                orquesta_listar(array,QTY_ARRAY_ORQUESTA);                   //cambiar
                break;
            }
        }
        while(opcion!=4);
        break;
    case 2:
        do
        {
            __fpurge(stdin);
            utn_getUnsignedInt("\n\n-------MENU MUSICO-------\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar\n5)Salir\nIngrese su opcion: ",                   //cambiar
                               "\nError",1,sizeof(int),1,5,1,&opcion);
            switch(opcion)
            {
            case 1:
                __fpurge(stdin);
                if(musico_alta(arrayMusico,QTY_ARRAY_MUSICO,&contadorIdMusico))
                {
                    musico_buscarID(arrayMusico,QTY_ARRAY_MUSICO,contadorIdMusico,&posMusico);
                    orquesta_listar(array,QTY_ARRAY_ORQUESTA);
                    __fpurge(stdin);
                    if(!utn_getSignedInt("\nIngrese ID de su orquesta: ","ID Invalido",1,2,0,QTY_ARRAY_ORQUESTA,2,&arrayMusico[posMusico].idOrquesta)&&
                    !instrumento_listar(arrayInstrumento,QTY_ARRAY_ORQUESTA)&&
                    !utn_getSignedInt("\nIngrese ID de su instrumento: ","ID Invalido",1,2,0,QTY_ARRAY_INSTRUMENTOS,2,&arrayMusico[posMusico].idInstrumento))
                    {
                        printf("Musico Cargado Exitosamente!");

                    }

                }
                break;

            case 2:
                __fpurge(stdin);
                musico_mostrarDatosPersonales(arrayMusico,QTY_ARRAY_MUSICO);
                musico_modificar(arrayMusico,QTY_ARRAY_MUSICO);
                break;

            case 3:
                __fpurge(stdin);
                musico_mostrarDatosPersonales(arrayMusico,QTY_ARRAY_MUSICO);
                musico_baja(arrayMusico,QTY_ARRAY_MUSICO);
                break;

            case 4:
                musico_listar(arrayMusico,arrayInstrumento,QTY_ARRAY_INSTRUMENTOS,QTY_ARRAY_MUSICO);
                break;

            case 5:
                break;
            }
        }
        while(opcion!=5);
        break;

    case 3:
        do
        {
            __fpurge(stdin);
            utn_getUnsignedInt("\n\n-------MENU INSTRUMENTOS-------\n\n1) Alta \n2) Listar\n3)Salir\nIngrese su opcion: ",                   //cambiar
                               "\nError",1,sizeof(int),1,3,1,&opcion);
            switch(opcion)
            {
            case 1:
                __fpurge(stdin);
                instrumento_alta(arrayInstrumento,QTY_ARRAY_INSTRUMENTOS,&contadorIdInstrumento);                   //cambiar
                break;
            case 2:
                instrumento_listar(arrayInstrumento,QTY_ARRAY_INSTRUMENTOS);                   //cambiar
                break;

            case 3:
                break;
            }
        }
        while(opcion!=3);

    }
    }while(primeraOpcion!=4);

    return 0;
}

