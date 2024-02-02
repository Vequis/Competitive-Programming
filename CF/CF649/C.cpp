#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main(){
 
    int n;
    cin >> n;
 
    queue<int> fila;
 
    vector<int> a;
    vector<int> b;
    int duplicadas = 0;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        a.push_back(num);
 
 
        if (i>0){
            if (num==a[i-1]) duplicadas+=2;
            for (int j=a[i-1]+1; j<a[i]; j++){
                fila.push(j);
            }
        }
    }
 
    if (n==1 and a[0] == 0) {
        cout << 1 << endl;
        return 0;
    }

    if (fila.size() < duplicadas) {
        for (int i= a[n-1] + 1; i <= (a[n-1] + 1 + (duplicadas - fila.size())); i++) fila.push(i);
    }
 
    if (a[0] == 0) {
        b.push_back(fila.front());
        fila.pop();
    }
    else b.push_back(0);
 
    if (a[0] >= 2) {
        cout << -1 << endl;
        return 0;
    }
 
    for (int i=1; i<n; i++){
        if (a[i] > i+1){
            cout << -1 << endl;
            return 0;
        }
        else if (a[i] != a[i-1]){
            b.push_back(a[i-1]);
        } else {
            b.push_back(fila.front());
            fila.pop();
        }
    }
 
    for (int i=0; i<n; i++) cout << b[i] << " ";
 
    return 0;
}
