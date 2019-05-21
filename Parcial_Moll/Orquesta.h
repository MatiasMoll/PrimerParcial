
#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo; //0=Sinfonica, 1=Filarmonica, 2=Camara.
    char lugar[TEXT_SIZE];

}Orquesta;


#endif // ORQUESTA_H_INCLUDED
int orquesta_Inicializar(Orquesta array[], int size);                                    //cambiar orquesta
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);                    //cambiar orquesta
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);                    //cambiar orquesta
int orquesta_alta(Orquesta array[], int size, int* contadorID);                          //cambiar orquesta
int orquesta_baja(Orquesta array[], int sizeArray,int id);                                      //cambiar orquesta
int orquesta_listarUnaOrquesta(Orquesta unaOrquesta);
int orquesta_listar(Orquesta array[], int size);
int orquesta_tipo(Orquesta unaOrquesta,char* tiposStr);                      //cambiar orquesta
void orquesta_mock(Orquesta arrayOrquesta[], int size,int *contadorId);                      //cambiar orquesta
