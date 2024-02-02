#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int x;
    cin >> x;
    int n;
    cin >> n;

    int vetor[n];
    for (int i=0; i<n; i++){cin >> vetor[i];}

    sort(vetor, vetor+n);

    int ind = 0;
    for (int i=0; i<n; i++)
        if (vetor[i] >= x) {
            ind = i;
            break;
        }

    int resp = x;
    for (int i=1; i<=max(ind-n, n-ind); i++){

        if (ind-i >=0 ){
            if (vetor[ind-i] != x-i){
                resp = x-i;
                break;
            }
        } else if (ind+i<=n-1){
            if (vetor[ind + i] != x+i){
                resp = x+i;
                break;
            }
        }

    }

    cout << resp << endl;
    return 0;

}