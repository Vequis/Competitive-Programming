#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> obt;
vector<int> car;
int vetor[10000];
int aux[10000];

int search(int n) {
    int ini = 0;
    int fim = obt.size();

    int resp = -1;

    while(ini<=fim){
        int meio = (ini+fim)/2;

        if (obt[meio] == n) {
            resp = meio;
            break;
        } else if (obt[meio] > n) {
            fim = meio-1;
        } else {
            ini = meio+1;
        }
    }

    return resp;
}

int main(){

    int n, c, m;
    cin >> n >> c >> m;

    for (int i=0; i<c; i++) {
        int num;
        cin >> num;
        car.push_back(num);
    }

    for (int i=0; i<m; i++) {
        int num;
        cin >> num;
        obt.push_back(num);
    }

    sort(obt.begin(), obt.end());

    int falta = 0;
    for (int i=0; i<c; i++){
    
        if (search(car[i]) == -1) falta++;
    
    }

    cout << falta << endl;
    return 0;

}
/*
int search(int n){
    int ini = 0;
    int fim = obt.size();


    int resp = -1;

    while(ini <= fim){
        int meio = (ini+fim)/2;
        if (obt[meio] == n) {
            resp = meio;
            break;
        } else if (obt[meio] > n){
            fim = meio-1;
        } else {
            ini = meio+1;
        }
    }

    return resp;
}
*/
