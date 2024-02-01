#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int v[4];
    int soma = 0;
    int atual, outro;
    int resp = INT_MAX;

    for(int i=0; i<4; i++){
        cin >> v[i];
        soma+=v[i];
    }

    for(int i=1; i<4; i++){
        atual = (v[0] + v[i]);
        outro = soma - atual;   
        resp = min(resp, abs(outro - atual));
    }

    cout << resp << endl;


    return 0;
}