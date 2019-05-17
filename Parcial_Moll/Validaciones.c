#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

int VAL_Name(char* cadena)
{
    int i;
    int retorno = TRUE;
    for(i=0;i<strlen(cadena)-1;i++)
    {
        if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}

int VAL_Int(char* cadena)
{
  int retorno = 0;

  return retorno;
}

int VAL_Edad(char* cadena, int minimo, int maximo)
{
    int retorno = FALSE;
    int buffer;
    buffer = atoi(cadena);
    if(buffer!=0)
    {
        if(buffer>=minimo && buffer<=maximo)
        {
            retorno = TRUE;
        }

    }

    return retorno;
}

int VAL_Direccion(char* cadena)
{
    int retorno = 1;
    int i;
    if(cadena != NULL)
    {
        for(i=0;i<=strlen(cadena)-1;i++)
        {
            if((cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A' || cadena[i]>'Z')&&(cadena[i]< '0' || cadena[i]>'9')&& isspace(cadena[i])&&cadena[i]=='�')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int VAL_Cuil(char* cadena)
{
    int retorno = 1;
    if(cadena != NULL)
    {
        retorno = 0;
    }
    return retorno;
}

int VAL_Sexo(char buffer)
{
    int retorno = 1;
    buffer = tolower(buffer);
    if(buffer != 'f' && buffer !='m')
    {
        retorno = 0;
    }
    return retorno;
}
