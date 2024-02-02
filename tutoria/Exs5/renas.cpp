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

using namespace std;

int soma, aux;

string renas[9] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen","Rudolph"};

int main(){_

    soma = 0;

    for (int i=0; i<9; i++){
        cin >> aux;
        soma = (soma+aux)%9;
    }

    soma = (soma+8)%9;
    
    cout << renas[soma] << endl; 

    return 0;
}