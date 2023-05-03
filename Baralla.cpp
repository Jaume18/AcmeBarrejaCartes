#include <iostream>
#include "Baralla.h"
#include "Carta.h"
using namespace std;
Baralla::Baralla()
{
    a_llavor=0;
    a_n=0;
    a_max=10;
    reserva();
}

Baralla::Baralla(int llavor){

    a_llavor=llavor;
    crea_baralla();

}
Baralla::Baralla(const Baralla &b){
    copia(b);
}

/*Baralla::~Baralla(){

    allibera();
}*/

Baralla &Baralla::operator=(const Baralla &b){

    if(this != &b){
        allibera();
        copia(b);
    }
    return *this;

}

void Baralla::crea_baralla() {

     for(int i=0; i<MAX_MAGIA; i++){
        for(int j=0;j<MAX_GERMANO;j++){
            for(int k=0; k<MAX_INFLU;k++){
                Carta c(i,k,j);
                afegir(c);
            }
        }
    }

}

int Baralla::aleatori(int rang){
    int aleatori;
    a_llavor = (a_llavor*1103515245)+12345;
    aleatori = ((a_llavor/32)%32768)%rang;
    return aleatori;
}

void Baralla::afegir(const Carta &c){

    if (a_n == a_max) expandeix();
    a_t[a_n] = c;
    a_n++;

}


void Baralla::mostrar(){

    for(int i=0; i<a_n;i++){
        a_t[i].mostrar();
    }
}

void Baralla::barrejar(){


    for(int i=a_n-1; i>0;i--){
        int pos = aleatori(i+1);
        intercanvi(a_t[pos],a_t[i]);

    }

}

void Baralla::intercanvi(Carta &c1, Carta &c2){

    Carta aux;
    aux=c1;
    c1=c2;
    c2=aux;
}

Carta Baralla::partirBaralla(int pos){
        return a_t[pos];
}
void Baralla::eliminarCarta(int pos){


}

int Baralla::returnMeitat(){
    return a_n/2;

}

void Baralla::allibera(){

    delete []a_t;

}


void Baralla::copia(const Baralla &b){

    a_n = b.a_n;
    a_max = b.a_max;
    reserva();
    for(int i=0; i<a_n; i++){
        a_t[i] = b.a_t[i];
    }
}

void Baralla::reserva(){

    a_t=new Carta[a_max];

}



void Baralla::expandeix(){
    Carta *aux = a_t;
    a_max = 2*a_max;
    reserva();
    for(int i=0; i<a_n; i++){
        a_t[i] = aux[i];
    }
    delete[] aux;

}


