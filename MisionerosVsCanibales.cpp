#include <stdio.h>

typedef struct
{
    int canibales;  // Numero de canibales en el barco
    int misioneros; // Numero de misioneros en el barco
    int ida;        // A true si el barco hace el recorrido de ida, 0 en el caso de vuelta
} Barco;

typedef struct
{
    int canibales;  // Numero de canibales en el barco
    int misioneros; // Numero de misioneros en el barco
} Posicion;

void MoverAlBarco(Posicion * isla, Barco const* barco)
{
    isla->canibales -= barco->canibales;
    isla->misioneros -= barco->misioneros;
}

void MoverALaIsla(Posicion * isla, Barco const* barco)
{
    isla->canibales += barco->canibales;
    isla->misioneros += barco->misioneros;
}
 
void imprimirIsla(Posicion const* posicion)
{
    printf("M:%d C:%d", posicion->misioneros, posicion->canibales);
}
 
void imprimirBarco(Barco const* barco)
{
    if( barco->ida )
    {
        printf("---->> \\_M:%d_C:%d_/       ", barco->misioneros, barco->canibales);
    }
    else
    {
        printf("       \\_M:%d_C:%d_/ <<----", barco->misioneros, barco->canibales);
    }
}

int viajeValido(Posicion const* origen, Posicion const* destino, Barco const* barco)
{
    int toReturn = (origen->misioneros - barco->misioneros >= 0)
                 && (origen->canibales - barco->canibales >= 0);
 
    if( toReturn && origen->misioneros - barco->misioneros != 0 )
        toReturn = (origen->canibales - barco->canibales <= origen->misioneros - barco->misioneros);
    if( toReturn && destino->misioneros + barco->misioneros != 0 )
        toReturn = (destino->canibales + barco->canibales <= destino->misioneros + barco->misioneros);
 
    return toReturn;
}
 
void imprimirEstado(Posicion const* inicio, Posicion const* fin, Barco const* barco)
{
    imprimirIsla(inicio);
    printf(" | ");
    imprimirBarco(barco);
    printf(" | ");
    imprimirIsla(fin);
    printf("\n");
}
 
