#ifndef CARTA_H
#define CARTA_H

static const int MAX_MAGIA=6;
static const int MAX_INFLU=5;
static const int MAX_GERMANO=3;

class Carta
{
    public:
        Carta();
        Carta(char a_magia,int a_influencia,char a_germano);
        Carta creaCarta();
        void mostrar();




    private:

        char a_magia;
        int a_influencia;
        char a_germano;

        static const int INFLUENCIA[];
        static const char MAGIA[];
        static const char GERMANO[];


};

#endif // CARTA_H
