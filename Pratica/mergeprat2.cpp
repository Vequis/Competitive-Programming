#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

// merge - crivo - euclides - binsearch

vector<int> vetor;
vector<int> aux;

void merge_sort(int ini, int fim) {
    int media = (ini + fim) /2;

    if (ini == fim) return;

    merge_sort(ini, media);
    merge_sort(media+1, fim);

    int j= media+1;

    for (int i=ini, i<=media; i++){
        while(vetor[j] < vetor[i]){
            aux.push_back(vetor[j]);
            j++;
        }

        aux.push_back(vetor[i]);
    }
    while(j<=fim) {
        aux.push_back(vetor[j]); 
        j++;
   }

   for (int i=ini; i<= fim; i++) vetor[i] = aux[i-ini];
}

int nums[100100];
vector<int> primos;

void crivo(int n) {
    for (int i=2; i<= n; i++) {
        if (nums[i] == 0) {
            primos.push_back(i);
            int limite = (n/i);
            if (limite<=i){ for (int j=i*i; j<=limite*i; j+= i) nums[j] = 1;}
        }
    }
}

int mdc(int a, int b){
    if (b>a) return mdc(b,a);
    else if (b==0) return a;
    else return mdc(b,a%b);
}

int bin_search(int n){
    int ini = 0;
    int fim = vetor.size();

    int ind = -1;

    while(ini<= fim) {
        int meio = (ini+fim)/2;
        if (vetor[meio] == n) {
            ind = meio;
            break;
        } else if (vetor[meio] > n){
            fim = meio-1;
        } else {
            ini = meio+1;
        }
    }

    return ind;
}