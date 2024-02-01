#include<iostream>

#define N 1000

using namespace std;

class pilha{
public:
    char vetor[N] = {15, 6, 2, 9};
    char t; 

    void criapilha();
    bool empty();
    bool full();
    char pop();
    void push(char k);
    char topo();
};

void pilha::criapilha(){ // O vetor pilha será 0 indexado e t marcará a ultima posição preenchida
    t=4;
}

bool pilha::empty(){ 
    return t==0;
}

bool pilha::full(){
    return t==N;
}

char pilha::pop(){
    if (this->empty()){
        cout << "A pilha já está vazia!" << endl;
        return -1;
    } else {
        return this->vetor[--t];
    }
}

void pilha::push(char k){
    if(this->full()){
        cout << "Underflow!" << endl;
    } else {
        this->vetor[t++] = k;
    }
}

char pilha::topo(){
    if (this->empty()){
        cout << "A pilha está vazia! " << endl;
        return -1;
    } else return vetor[t-1];
}

int main(){
    pilha* pil = new pilha;
    pil-> criapilha();

    string s;
    
    while(cin >> s){
        for(int i=0; i<((int)s.size()); i++){
            pil->push(s[i]);
        }
    
        for(int i=0; i<((int)s.size()); i++){
            s[i] = pil->pop();
        }

        cout << s << ' ';
    }


    return 0;
}