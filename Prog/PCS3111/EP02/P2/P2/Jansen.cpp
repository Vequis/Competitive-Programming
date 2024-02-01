#include "Jansen.h"
#include <stdexcept>
#include <iostream>

using namespace std;

static int contLotes = 1;
static int contDoses = 1;

Jansen::Jansen(int dataFabricacao) : Vacina(dataFabricacao)
{
    this->dose = contDoses;
    this->lote = contLotes;
 
    contDoses++;

    if (contDoses == LOTE_MAX + 1) {
        contDoses = 1;
        contLotes++;
    }
}

Jansen::~Jansen()
{

}

void Jansen::imprimir()
{
    cout << "Jansen, ";
    Vacina::imprimir();
}

int Jansen::getValidade() {
    return 100 * (this->lote) + dataFabricacao;
}