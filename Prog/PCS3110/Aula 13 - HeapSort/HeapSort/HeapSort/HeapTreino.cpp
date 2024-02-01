#include "HeapTreino.h"
#include <iostream>

using namespace std;

HeapTreino::HeapTreino(int tamanhoMaximo, int vetor[]) {
	this->tamanhoMaximo = tamanhoMaximo;
	this->tamanhoHeap = tamanhoMaximo;
	for (int i = 0; i < tamanhoMaximo; i++) {
		v[i] = vetor[i];
	}
}

HeapTreino::~HeapTreino() {
}

int HeapTreino::Pai(int i) {
	return (i - 1) / 2;
}

int HeapTreino::FilhoDireita(int i) {
	return 2 * i + 1;
}

int HeapTreino::FilhoEsquerda(int i) {
	return 2 * i + 2;
}

void HeapTreino::MaxHeapify(int i) {
	int l = this->FilhoEsquerda(i);
	int r = this->FilhoDireita(i);

	int maior = i;

	if (l < tamanhoHeap && v[l] < v[i]) {
		maior = l;
	}

	if (r < tamanhoHeap && v[r] < v[maior]) {
		maior = r;
	}

	if (maior != i) {
		int temp = v[maior];
		v[maior] = v[i];
		v[i] = temp;
		this->MaxHeapify(maior);
	}
}

void HeapTreino::BuildMaxHeap() {
	for (int i = Pai(tamanhoMaximo - 1); i >= 0; i--) {
		this->MaxHeapify(i);
	}
}

void HeapTreino::HeapSort() {
	BuildMaxHeap();

	for (int i = tamanhoMaximo - 1; i > 0; i--) {
		int temp = v[i];
		v[i] = v[0];
		v[0] = temp;
		
		tamanhoHeap--;

		MaxHeapify(0);
	}
}
