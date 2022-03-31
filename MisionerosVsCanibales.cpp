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
