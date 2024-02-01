#include <iostream>
#include "Heap.h";

using namespace std;

int vetor[111];

int main() {
	//for (int i = 7; i >= 0; i--) {
		//vetor[7 - i] = i;
	//}

	vetor[0] = 9;
	vetor[1] = 8;
	vetor[2] = 7;
	vetor[3] = 3;
	vetor[4] = 2;
	vetor[5] = 4;


	Heap* h = new Heap(6, vetor);

	//h->imprimir();

	//h->MaxHeapify(0);
	//h->imprimir();

	//h->BuildMinHeap();
	h->HeapSort();
	h->imprimir();
}