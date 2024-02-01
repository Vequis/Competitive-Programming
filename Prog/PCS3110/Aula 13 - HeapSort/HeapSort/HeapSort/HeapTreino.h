#ifndef HEAPTREINO_H
#define HEAPTREINO_H

class HeapTreino {
private:
	int v[111];
	int tamanhoMaximo;
	int tamanhoHeap;
public:
	HeapTreino(int tamanhoMaximo, int vetor[]);
	~HeapTreino();

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

