#include "Cadastro.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Implementar

Cadastro::Cadastro(string nomePosto)
{
	if (nomePosto.empty())
		throw new invalid_argument("Nome de posto invalido");

	this->nomePosto = nomePosto;

	passaportes = new vector<Passaporte*>();
}

Cadastro::~Cadastro()
{
	for (int i = 0; i < (int)passaportes->size(); ++i) {
		delete passaportes->at(i);
	}

	delete passaportes;

	cout << "Cadastro destruido" << endl;
}

string Cadastro::getNomePosto()
{
	return this->nomePosto;
}

void Cadastro::adicionarPassaporte(Passaporte* passaporte)
{
	passaportes->push_back(passaporte);
}

vector<Passaporte*>* Cadastro::getPassaportes()
{
	return this->passaportes;
}

void Cadastro::imprimir()
{
	cout << nomePosto << endl;
	cout << passaportes->size() << endl;

	for (int i = 0; i < (int)passaportes->size(); ++i) {
		passaportes->at(i)->imprimir();
	}
}
