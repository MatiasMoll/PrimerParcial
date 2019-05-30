#include <stdio_ext.h>
#include <stdlib.h>
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "utn.h"
#include "Get.h"

int buscarRepetidos(int* array,int valor,int sizeArray);
int initArray(int* array, int size);
int informes_arrayIdNoRepetidos(Musico* arrayMusico, int sizeMusico,int* arrayResultado,int sizeArrayResultado);
int informes_musicosPorOrquesta(Musico* arrayMusico, int sizeMusico,Orquesta* array, int sizeOrquesta, int* arrayResultado,int sizeArrayResultado);
int informes_orquestaMenosSeisMusicos(Musico* arrayMusico, int sizeMusico,Orquesta* array, int sizeOrquesta);
int informes_listarOrquestasLugar(Orquesta* array, char* lugarIndicado, int sizeArray);
int informes_musicosMenoresDeVeinticinco(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta,Instrumento* arrayInstrumento, int sizeInstrumento);
int informes_instrumentosPorOrquesta(int idOrquestaBuscada, Instrumento* arrayIns, int sizeIns, Musico* arrayMusico, int sizeMusico);
int informes_orquestaMenosMusicos(Musico* arrayMusico, int sizeMusico,Orquesta* array, int sizeOrquesta);
int informes_musicosNoDeViento(Musico* arrayM, int sizeM, Instrumento* arrayIns, int sizeIns);
int informes_promedioInstrumentos(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta, float* promedio);
