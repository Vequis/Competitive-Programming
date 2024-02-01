#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int v[111];
int l[111], r[111];

void InsertionSort(int sz) { 
    for (int j = 1; j < sz; i++) {
        int chave = v[j];
        int i = j - 1;

        while (i>=0 && chave < v[i]) {
            v[i+1] = v[i];
            i--;
        }

        v[i+1] = chave;
    }
}

void Merge(int inicio, int fim) {
    int meio = inicio + (fim - inicio) / 2;

    int n1 = 0;
    int n2 = 0;

    for (int i = inicio; i <= meio; i++) {
        l[n1++] = v[i];  
    }
    l[n1] = INT_MAX;

    for (int i = meio + 1; i <= fim; i++) {
        r[n2++] = v[i];
    }
    l[n2] = INT_MAX;

    int i = 0, j = 0;

    for (int k = inicio; k<=fim; k++) {
        if (l[i] < r[j]) {
            v[k] = l[i];
            i++; 
        } else {
            v[k] = r[j];
            j++;
        }
    }
}

void MergeSort(int inicio, int fim) {
    if (inicio == fim ) return;

    int meio = inicio + (fim - inicio) / 2;
    mergesort(inicio, meio);
    mergesort(meio, inicio);
    merge(inicio, fim);
}

void Partition(int inicio, int fim) {
    int menores = 0;
    int pivo = v[fim];

    for (int i = inicio; i < fim; i++) {
        if (v[i] < pivo) {
            swap(v[i], v[inicio + menores]);
            menores++;
        }
    }

    swap(pivo, v[inicio + menores])

    return inicio + menores;
}

void HeapSort(int sz) {
    //BuildMaxHeap();

    for (int i = sz; i >= 1; i--) {
        swap(v[0], v[i - 1]);
        //tamanhoHeap--;
        //MaxHeapify(0);
    }
}

void QuickSort(int inicio, int fim) {
    if (inicio > fim or inicio == fim) return;

    int pos_pivo = Partition(inicio, fim);
    QuickSort(inicio, pos_pivo - 1);
    QuickSort(pos_pivo + 1, fim);
}

signed main(){_

    return 0;
}
