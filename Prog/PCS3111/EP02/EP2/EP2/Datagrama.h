#ifndef DATAGRAMA_H
#define DATAGRAMA_H

#include <string>
#include "Segmento.h"

using namespace std;

class Datagrama {
private:
    int origem, destino;
    Segmento* conteudo;
public:
    Datagrama(int origem, int destino, Segmento* dado);
    virtual ~Datagrama();
    
    virtual int getOrigem();
    virtual int getDestino();
    virtual Segmento* getSegmento();

    virtual void imprimir();
};

#endif
