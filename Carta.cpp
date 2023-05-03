#include <iostream>
#include "Carta.h"

using namespace std;
const int Carta::INFLUENCIA[] = {1,2,3,4,5};
const char Carta::MAGIA[] = {'b','o','p','r','t','v'};
const char Carta::GERMANO[] ={'c','g','s'};


Carta::Carta()
{
    a_influencia = 1;
    a_magia='b';
    a_germano='c';
}

Carta::Carta(char magia, int influ,char germano){

    a_magia=MAGIA[magia];
    a_influencia=INFLUENCIA[influ];
    a_germano=GERMANO[germano];

}


void Carta::mostrar(){

    cout<<"[" << a_magia << a_influencia << a_germano <<"]";
}





