#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap(int tamanhoMaximo, int vetor[]) : tamanhoMaximo(tamanhoMaximo) {
	tamanhoHeap = tamanhoMaximo;
	for (int i = 0; i < tamanhoMaximo; i++) {
		v[i] = vetor[i];
	}
}

Heap::~Heap() {
}

//0-indexado

int Heap::Pai(int i) {
	return (i - 1) / 2;
}

int Heap::FilhoDireita(int i) {
	return 2 * i + 1;
}

int Heap::FilhoEsquerda(int i) {
	return 2 * i + 2;
}

int Heap::MaiorFilho(int i) {
	if (v[FilhoDireita(i)] < v[FilhoEsquerda(i)]) return FilhoEsquerda(i);
	else return FilhoDireita(i);
}

void Heap::MaxHeapify(int i) {
	int l = FilhoEsquerda(i);
	int r = FilhoDireita(i);

	int maior = i;

	if (l < tamanhoHeap && v[l] > v[i]) {
		maior = l;
	}

	if (r < tamanhoHeap && v[r] > v[maior]) {
		maior = r;
	}

	if (maior != i) {
		int temp = v[i];
		v[i] = v[maior];
		v[maior] = temp;
		this->MaxHeapify(maior);
	}
}

void Heap::BuildMaxHeap() {
	for (int i = Pai(tamanhoMaximo); i >= 0; i--) {
		MaxHeapify(i);
	}
}

void Heap::HeapSort() {
	cout << "Vetor inicial:" << endl;
	this->imprimir();

	BuildMaxHeap();

	cout << "Heap construido: " << endl;
	this->imprimir();
	cout << endl;

	tamanhoHeap = tamanhoMaximo;

	for (int i = tamanhoMaximo - 1; i >= 1; i--) {
		int temp = v[0];
		v[0] = v[i];
		v[i] = temp;

		tamanhoHeap = tamanhoHeap - 1;

		MaxHeapify(0);

		this->imprimir();
	}
}

int Heap::topo() {
	return v[0];
}

void Heap::imprimir() {
	for (int i = 0; i < tamanhoMaximo; i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
}
