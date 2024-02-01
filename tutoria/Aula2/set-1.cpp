#include <bits/stdc++.h>

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

//Executar código g++ set-1.cpp
//g++ set-1.cpp -o do;

using namespace std;

//Util para eliminar repetições

set<int> cj;
//É praticamente um conjunto, guarda apenas uma copia do conteudo, guarda-as ordenadamente;
set<int>:: iterator it;
int n, x;

int main(){_
    cin >> n;

    for (int i=n-1; i>=0; i--){
        cin >> x;
        cj.insert(x);
    }

    // for (auto num : cj){
    for (it = cj.begin(); it!=cj.end(); it++){
        int num = (*it);
        cout << (*it) << endl;
    }

    cout << "tamanho: " << sz(cj) << endl;

    cout << cj.count(3) << endl; // Isso é meio inutil, pq o set so guarda uma vez

    cj.clear(); cout << "tmnh" << sz(cj) << endl;

    cout << "1º elemento: " << (*cj.begin()) << endl;

    //Existe também o find-> retorna o iterador;
    cj.erase(cj.find(3));

    return 0;
}