#include <stdio_ext.h>
#include <stdlib.h>
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "utn.h"
#include "Get.h"

int buscarRepetidos(int* array,int valor);
int inicializarIdNoRepetido(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta,int* arraySinRepetir);
int informes_listarOrquestasLugar(Orquesta* array, char* lugarIndicado, int sizeArray);
int informes_musicosMenoresDeVeinticinco(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta,Instrumento* arrayInstrumento, int sizeInstrumento);
int informes_orquestasMenosSeisMusicos(Musico* arrayMusico, int sizeMusico, Orquesta* arrayOrquesta, int sizeOrquesta);
int informes_instrumentosPorOrquesta(int idOrquestaBuscada, Instrumento* arrayIns, int sizeIns, Musico* arrayMusico, int sizeMusico);
int informes_musicosNoDeViento(Musico* arrayM, int sizeM, Instrumento* arrayIns, int sizeIns);
int informes_promedioInstrumentos(Instrumento* arrayIns, int sizeIns, Orquesta* arrayOrquesta, int sizeOrquesta, float* promedio);
