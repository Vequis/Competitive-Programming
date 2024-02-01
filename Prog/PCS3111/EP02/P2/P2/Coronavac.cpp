#include "Coronavac.h"
#include <stdexcept>
#include <iostream>

using namespace std;

static int contLotes = 1;
static int contDoses = 1;

Coronavac::Coronavac(int dataFabricacao) : Vacina(dataFabricacao)
{
    this->dose = contDoses;
    this->lote = contLotes;

    contDoses++;

    if (contDoses == LOTE_MAX + 1) {
        contDoses = 1;
        contLotes++;
    }

}

Coronavac::~Coronavac()
{
}

int Coronavac::getDataProximaDose(int dataAplicacao)
{
    if (dataAplicacao <= 0) {
        throw new invalid_argument("Vacina ainda nao foi aplicada");
    }
    return dataAplicacao + INTERVALO;
}

void Coronavac::imprimir()
{
    cout << "Coronavac, ";
    Vacina::imprimir();
}

int Coronavac::getValidade() {
    if (dataFabricacao < 100) {
        return dataFabricacao + 200;
    }
    else {
        return dataFabricacao + 300;
    }
}
