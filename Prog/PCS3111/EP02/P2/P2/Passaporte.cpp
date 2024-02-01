#include "Passaporte.h"
#include <stdexcept>
#include <iostream>
#include "Jansen.h"
#include "Coronavac.h"

using namespace std;
// Implementar

Passaporte::Passaporte(string nome)
{
	if (nome.empty()) {
		throw new invalid_argument("Nome de usuario invalido");
	}
	this->nome = nome;

	qtdeVacinas = 0;

	vacinas = new Vacina * [MAXIMO_VACINAS];
	aplicacoes = new int[MAXIMO_VACINAS];
}

Passaporte::~Passaporte()
{
	delete[] vacinas;
	delete[] aplicacoes;

	cout << "Passaporte " << nome << " destruido" << endl;
}

string Passaporte::getNome()
{
	return this->nome;
}

bool Passaporte::aplicaVacina(Vacina* v, int dataAplicacao)
{
	if (v == NULL)
		throw new invalid_argument("Vacina invalida");

	if (dataAplicacao <= 0)
		throw new invalid_argument("Data de aplicacao de vacina invalida");

	if (this->getQuantidadeVacinas() == MAXIMO_VACINAS - 1) {
		return false;
	}

	if (v->getValidade() < dataAplicacao)
		throw new logic_error("Data de validade de vacina vencida");

	Jansen* j = dynamic_cast<Jansen*>(v);
	if (j != NULL && this->getQuantidadeVacinas() > 0) {
		throw new logic_error("Numero maximo de vacinas excedido");
	}

	aplicacoes[qtdeVacinas] = dataAplicacao;
	vacinas[qtdeVacinas] = v;
	qtdeVacinas++;

	int i = qtdeVacinas - 1;
	while (i > 0 && aplicacoes[i] < aplicacoes[i - 1]) {
		troca(i, i - 1);
	}

	return true;
}

void Passaporte::troca(int i, int j) {
	int temp = aplicacoes[i];
	aplicacoes[i] = aplicacoes[j];
	aplicacoes[j] = temp;

	Vacina* tmp = vacinas[i];
	vacinas[i] = vacinas[j];
	vacinas[j] = tmp;
}

Vacina** Passaporte::getVacinas()
{
	return this->vacinas;
}

int* Passaporte::getDataAplicacoes()
{
	return this->aplicacoes;
}

int Passaporte::getQuantidadeVacinas()
{
	return this->qtdeVacinas;
}

void Passaporte::imprimir()
{
	cout << nome << endl;
	cout << this->getQuantidadeVacinas() << endl;

	for (int i = 0; i < qtdeVacinas; ++i) {
		Jansen* j = dynamic_cast<Jansen*>(vacinas[i]);
		Coronavac* c = dynamic_cast<Coronavac*>(vacinas[i]);

		cout << "Dose: " << i + 1 << ", ";
		if (j != NULL) j->imprimir();
		if (c != NULL) c->imprimir();
		cout << ", Aplicacao: " << aplicacoes[i];
		cout << endl;
	}
}

