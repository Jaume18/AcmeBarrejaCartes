#ifndef PILACARTES_H
#define PILACARTES_H
#include "Carta.h"



class PilaCartes
{
    public:
        PilaCartes();
        PilaCartes(const PilaCartes& o);
        //~PilaCartes();
        bool buida() const;
        Carta cim() const;
        void empila(Carta c);
        void desempila();
        //PilaCartes retornaPila(Baralla &b);
        void mostrar();
        PilaCartes& operator=(const PilaCartes& o);



    private:

        struct Node{
            Carta c;
            Node *seg;
        };


        Node *a_cim;

        void copia(const PilaCartes& p);
        void allibera();


};

#endif // PILACARTES_H
