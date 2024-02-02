#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> V;

void crivo(){
    for (int i=2; i<=y; i++){
        if (vis[i] == 0){
            primos.push_back(i);
            for (int j=i*i; j<=y; j+=i) vis[j] = 1;
        }
    }
}

int bin_search(int num){
    int ini = 0;
    int fim = primos.size();
    int ind = -1;
    while(ini<=fim){
        int meio = (ini+fim)/2;
        if (primos[meio] == num) {
            ind = meio;
            break;
        } else if (primos[meio] > num) fim = meio-1;
        else ini = meio+1;
    }

    return ind;
}

int main() {

    

}