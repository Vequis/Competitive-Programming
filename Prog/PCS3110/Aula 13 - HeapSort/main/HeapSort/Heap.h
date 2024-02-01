#ifndef HEAP_H
#define HEAP_H


class Heap {
private:
	int v[111];
	int tamanhoMaximo;
	int tamanhoHeap;
public:
	Heap(int tamanhoMaximo, int vetor[]);
	~Heap();

	int Pai(int i);
	int FilhoDireita(int i);
	int FilhoEsquerda(int i);
	int MaiorFilho(int i);

	void MaxHeapify(int i);
	void BuildMaxHeap();

	void HeapSort();

	int topo();

	void imprimir();
};

#endif
