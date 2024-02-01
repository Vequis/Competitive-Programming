#include "Vacina.h"
#include <stdexcept>
#include <iostream>

using namespace std;
// Implementar

Vacina::Vacina(int dataFabricacao) 
{
    if (dataFabricacao <= 0) {
        throw new invalid_argument("Data de fabricacao da vacina invalida");
    }
    else {
        this->dataFabricacao = dataFabricacao;
    }

    lote = 0;
    dose = 0;
    validade = 0;
}

Vacina::~Vacina()
{
}

int Vacina::getLote()
{
    return this->lote;
}

int Vacina::getDataFabricacao()
{
    return this->dataFabricacao;
}

void Vacina::imprimir(){
    cout    << "Lote: " << getLote()
            << ", Fabricacao: " << getDataFabricacao();
}
