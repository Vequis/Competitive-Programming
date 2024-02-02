#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> V;

int bin_search(int n){
    int ini = 0;
    int fim = V.size();

    while(ini<=fim){
        int meio = (ini+fim)/2;
        if (V[meio] == n) return meio;
        else if (V[meio] > n) {
            fim = meio-1;
        } else {
            ini = meio+1;
        }
    }

    return -1;
}

int main(){

    int x;
    cin >> x;
    int n;
    cin >> n;

    for (int i=0; i<n; i++){ 
        int num;
        cin >> num;
        V.push_back(num);
    }

    sort(V.begin(), V.end());

    if (n==0){
        cout << x << endl;
        return 0;
    }

    for (int i=0; i<=1000; i++){
        if (bin_search(x-i) == -1){
            cout << x-i << endl;
            break;
        } else if (bin_search(x+i) == -1){
            cout << x+i << endl;
            break;
        }
    }

    return 0;

}