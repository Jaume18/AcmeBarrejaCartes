#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"


class Baralla
{
     public:
        Baralla();
        Baralla(int llavor);
        ~Baralla();
        Baralla(const Baralla &b);
        Baralla& operator=(const Baralla &b);
        int aleatori(int rang);
        void crea_baralla();
        void afegir(const Carta &c);
        void mostrar();
        void barrejar();
        void eliminarCarta(int pos);
        void intercanvi(Carta &c1, Carta &c2);
        Carta partirBaralla(int pos);
        int returnMeitat();

    private:

        unsigned a_llavor;

        int a_n;
        int a_max;
        Carta *a_t;


        //Pre: --; Post: memòria alliberada
        void allibera();
        //Pre: memòria alliberada; Post: aquesta taula és còpia de la taula t
        void copia(const Baralla &b);
        //Pre: --; Post: memòria reservada per a_max Punt2D
        void reserva();
        void elimina();
        void expandeix();
};

#endif // BARALLA_H
