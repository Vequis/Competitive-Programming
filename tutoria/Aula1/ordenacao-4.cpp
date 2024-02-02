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

struct pessoa{
    int id;
    double alt;
    string nome;
}

vi v;
int n, a , b;
vector< pessoa > pessoas;

int ordem(pessoa a, pessoa b){ //Retorna true se não tem que trocar
    if (a.id != b.id) return a.id < b.id; //Pensa que o a tem que ser menor e tem que estar na direita
    if (a.alt != b.alt) return a.alt < b.alt;
    else return a.nome < b.nome;

    //Se eu quiser ordenar por indice, posso usar stable sort (estavel) stable_sort
}

int main(){_
    //Ordenar por crescente idade, depois por crescente altura, depois crescente por nome
    
    cin >> n;
    pessoas = vector<pessoas>(n);

    for (int i=0; i<n; i++){
        cin >> pessoas[i].nome >> pessoas[i].id >> pessoas[i].alt;
    }

    stable_sort(all(pessoas), ordem);

    for (int i=0; i<n; i++){
        cout << pessoas[i].nome << " " <<  pessoas[i].id << " " << pessoas[i].alt << endl;
    }

    cout << endl;

    pessoas.clear();

    return 0;
}