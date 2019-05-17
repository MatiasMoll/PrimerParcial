#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo; //1=Cuerdas, 2=Viento-Madera,3=Viento-Metal, 4=Percusion
}Instrumento;


#endif // INSTRUMENTO_H_INCLUDED

int instrumento_Inicializar(Instrumento array[], int size);                                    //cambiar instrumento
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);                    //cambiar instrumento
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);                    //cambiar instrumento
int instrumento_alta(Instrumento array[], int size, int* contadorID);                          //cambiar instrumento
int instrumento_tipo(Instrumento unaInstrumento,char* tiposStr);
int instrumento_listar(Instrumento array[], int size);                     //cambiar instrumento
void instrumento_mock(Instrumento arrayInstrumento[], int size,int *contadorId);
