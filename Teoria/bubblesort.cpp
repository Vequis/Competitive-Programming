#include <iostream>

using namespace std;
#define MAXN 1010

int n, vetor1[MAXN], vetor2[MAXN];
int vetorzao[2*MAXN];

/*void bubble_sort() {

    int ordenado = 0;

    while(ordenado==0){
        ordenado = 1;
        for (int i=1; i<n; i++){
            if (vetor[i-1] > vetor[i]){
                ordenado = 0;
                int temp = vetor[i];
                vetor[i] = vetor[i-1];
                vetor[i-1] = temp;
            }
        }
    }
}*/

void merge_sort() {
    int pt1 = 0;
    int pt2 = 0;
    int tam = 0;

    for (pt1; pt1<n; pt1++){

        while (vetor2[pt2] < vetor1[pt1] && pt2<n){
            vetorzao[tam] = vetor2[pt2];
            pt2++;
            tam++;
        }
        vetorzao[tam] = vetor1[pt1];
        tam++;
    }
    while(pt2<n){
        vetorzao[tam] = vetor2[pt2];
        pt2++;
        tam++;
    }
}

int main() {
    cin >> n;

    for (int i=0; i<n; i++) cin >> vetor1[i];
    for (int i=0; i<n; i++) cin >> vetor2[i];

    merge_sort();

    for (int i=0; i<2*n; i++) cout << vetorzao[i] << " ";
    cout << endl;
    return 0;
}
