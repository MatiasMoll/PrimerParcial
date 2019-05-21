#include "Instrumento.h"
#include "Orquesta.h"
#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int edad;
    int idOrquesta;
    int idInstrumento;
    char apellido[TEXT_SIZE];
}Musico;



#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico array[], int size);                                    //cambiar musico
int musico_buscarEmpty(Musico array[], int size, int* posicion);                    //cambiar musico
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarIdOrquesta(Musico array[], int size, int valorBuscado, int* posicion);                    //cambiar musico
int musico_alta(Musico array[], int size, int* contadorID);                          //cambiar musico
int musico_baja(Musico array[], int sizeArray);
int musico_bajaPorOrquesta(Musico array[],int* posABorrar);                                      //cambiar musico
int musico_modificar(Musico array[], int sizeArray);
int musico_mostrarDatosPersonales(Musico array[],int sizeArray);                            //cambiar musico
int musico_ordenarApellido(Musico *array, int sizeArray);
int musico_listarUnMusico(Musico unMusico,Orquesta* arrayOrquesta,int sizeOrquesta,Instrumento* arrayInstrumento,int sizeInstrumento);
int musico_listar(Musico array[],Instrumento arrayI[],int sizeI, int size);                 //cambiar musico
void musico_mock(Musico arrayMusico[], int size,int *contadorId);                      //cambiar musico

