#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int m[n], c[n];
    for(int i = 0; i < n; i++){
        cin >> m[i] >> c[i];
    }
    bool a = true;
    for(int i = 0; i < n; i++){
        if(c[i] != c[m[i] - 1]){
            a = false;
        }
    }
    
    if(a == true){
        cout << "Y" << endl;
    }
    else{
        cout << "N" << endl;
    }
}