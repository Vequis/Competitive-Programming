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

    //Após o caixa quebrar queremos saber as pessoas que ainda estão na fila.
	while(!fila.empty()){ //Enquanto a fila não for vazia
		int p = fila.front(); //Pego a pessoa na frente da fila e imprimo
		cout<<p<<" ";

		fila.pop(); //Removo a pessoa que está na frente da fila.
	}
}
