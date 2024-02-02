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

map<string, int> f;

int x,n;
string nome;

int main(){_

    cin >> n;
    while (cin >> nome){
        cout << f[nome] << endl; //Já é suficiente para criar uma chave para qualquer nome digitado;

        //if (f.count(nome)  Pode ser 1 ou 0,) { f[nome]++} Só ira mexer em uma chave se ela ja existir

        if (nome == "francisco" || nome == "francisco"){
            f[nome]++;
        }
    }

    f.clear();

    //O map guarda o nome em ordem crescente
    //O acesso tem compl O(logn)

    return 0;
}