#include <iostream>
#include <vector>

using namespace std;

vector<int> V;
int cont = 0;

int busca(int chave){
    for(int i=0; i<V.size(); i++){
        if (V[i] == chave)
            return i;
    }

    return -1; //NIL
}

int BuscaBinaria(int chave){
    int ini = 0, fim = V.size() - 1;

    while(ini<=fim){
        int mid = (ini + fim)/2;
        if (V[mid] == chave) return mid;
        if (V[mid] > chave) fim = mid-1;
        else ini = mid+1;
    }

    return -1;
}

void InsertionSort(){
    for(int j=1; j<V.size(); j++){
        int chave = V[j];
        int i = j-1;

        while(i >= 0 && V[i] > chave){
            cont++;
            V[i+1] = V[i];
            i = i-1;
        }

        V[i+1] = chave;
    }
}

void SelectionSort(){
    for(int i = 0; i < V.size() - 1; i++){
        int menor = i;

        for(int j = i + 1; j < V.size(); j++){
            if (V[j] < V[menor]){
                menor = j;
            }
        }

        swap(V[i], V[menor]);
    }
}

int main(){
    for(int i=9; i>=4; i--){
        V.push_back(i);
    }

    InsertionSort();

}
