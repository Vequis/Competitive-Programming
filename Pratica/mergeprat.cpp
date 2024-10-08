#include <iostream>

using namespace std;

int vetor[100100];
int aux[100100];

void merge_sort(int ini, int fim) {

    int media = (ini+fim)/2;

    if (ini == fim) return;

    merge_sort(ini, media);
    merge_sort(media+1, fim);

    int tam = 0;
    int j = media+1;

    for (int i=ini; i<=media; i++) {

        while (vetor[i] > vetor[j] and j<=fim){
            aux[tam] = vetor[j];
            j++;
            tam++;
        }
        aux[tam] = vetor[i];
        tam++;
    }

    while (j<= fim) {
        aux[tam] = vetor[j];
        j++;
        tam++;
    }

    for (int i=ini; i<= fim; i++) vetor[i] = aux[i-ini];
}

int main() {

    int n;
    cin >> n;

    for (int i=0; i<n; i++) cin>>vetor[i];

    merge_sort(0,n-1);

    for (int i=0; i<n; i++) cout << vetor[i] << " ";

    cout << endl;
    return 0;

}