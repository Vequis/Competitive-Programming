#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<int> fila;
    int op;
    int id;

    while (cin >> op) {
        if(op==0){
            break;
        }

        if(op==1) {
            cin>>id; //Lemos o id da pessoa que chegou
            fila.push(id); // Add no final da fila
        } else if (op==2) {
            fila.pop(); //O caixa atendee a pessoa na frente
        }
    }

    //Ap�s o caixa quebrar queremos saber as pessoas que ainda est�o na fila.
	while(!fila.empty()){ //Enquanto a fila n�o for vazia
		int p = fila.front(); //Pego a pessoa na frente da fila e imprimo
		cout<<p<<" ";

		fila.pop(); //Removo a pessoa que est� na frente da fila.
	}
}
