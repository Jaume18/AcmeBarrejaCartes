#include <iostream>
#include "PilaCartes.h"
#include "Carta.h"


using namespace std;
PilaCartes::PilaCartes()
{
    a_cim=NULL;
}

PilaCartes::PilaCartes(const PilaCartes& o){
    a_cim = NULL;
    copia(o);
}

PilaCartes::~PilaCartes() {
    allibera();
}


bool PilaCartes::buida() const{

    return a_cim==NULL;

}

Carta PilaCartes::cim() const{

    return a_cim ->c;

}

void PilaCartes::empila(Carta c){

    Node* nou = new Node;
    nou->c=c;
    nou->seg = a_cim;
    a_cim=nou;

}

void PilaCartes::desempila(){

    Node* aux = a_cim;
    a_cim = a_cim ->seg;
    delete aux;

}

/*PilaCartes PilaCartes::retornaPila(Baralla &b){
    Carta c;
    PilaCartes p;
    c=b.partirBaralla();
    c.mostrar();
    p.empila(c);
    return p;


}*/

void PilaCartes::mostrar(){

    Node *aux = a_cim;

    while(aux!=NULL){

        aux->c.mostrar();
        aux=aux->seg;

    }

}

PilaCartes& PilaCartes::operator=(const PilaCartes& o) {
    if (this != &o) {
        allibera();
        copia(o);
        }
    return *this;
}


void PilaCartes::allibera() {
    while (!buida()) {
        Node* aux = a_cim;
        a_cim = a_cim->seg;
        delete aux;
    }
}

void PilaCartes::copia(const PilaCartes& o){

    if (!o.buida()) {
        Node *p, *q, *aux;
        p = new Node;
        a_cim = p;
        aux = o.a_cim;
        p->c = aux->c;
        p->seg = NULL;
        q = p;
        aux = aux->seg;
        while (aux!=NULL) {
            p = new Node;
            q->seg = p;
            p->c = aux->c;
            p->seg = NULL;
            q = p;
            aux = aux->seg;
        }
    }
}




