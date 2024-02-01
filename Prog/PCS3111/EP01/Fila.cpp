Fila::Fila(int tamanho){
    this->tamanho = tamanho;
    inicio = 0;
    fim = 1;
    qtde_alocados = 0;
    Datagrama **elementos = new Datagrama*[tamanho];
}

Fila::~Fila(){
    delete[] elementos;
}

bool Fila::enqueue(Datagrama* d){
    if (fim == inicio){
        //if(qtde_alocados = tamanho)
        //Overflow
    } else {
        elementos[fim] = d;

        fim++;
        if (fim == tamanho) fim = 0;
    }
}

Fila::Datagrama* dequeue(){
    if (this->isEmpty()){
        //Underflow
    } else {
        inicio = inicio+1;
    }
}
bool isEmpty(){
    return (inicio+1)%this->tamanho == fim;
}
int getSize(){
    //return qtde_alocados;
}

//Refatorar tal função posteriormente
void imprimir(){
    for(int i=inicio; i!=fim;i = (i+1)%tamanho){
        cout << elementos[i]->data << endl;
    }
    cout << elementos[fim]->data << endl;
}