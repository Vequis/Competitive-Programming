#ifndef CORONAVAC_H
#define CORONAVAC_H

#include "Vacina.h"

class Coronavac : public Vacina {
public:
    Coronavac(int dataFabricacao);
    virtual ~Coronavac();
    static int getDataProximaDose (int dataAplicacao);
    virtual void imprimir();

    virtual int getValidade();
private:
    const static int LOTE_MAX = 2;

    const static int INTERVALO = 28;
};

#endif // CORONAVAC_H
