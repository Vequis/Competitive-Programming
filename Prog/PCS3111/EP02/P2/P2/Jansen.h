#ifndef JANSEN_H
#define JANSEN_H

#include "Vacina.h"

class Jansen : public Vacina {
public:
    Jansen(int dataFabricacao);
    virtual ~Jansen();
    virtual void imprimir();

    virtual int getValidade();
private:
    const static int LOTE_MAX = 3;
};

#endif // JANSEN_H
