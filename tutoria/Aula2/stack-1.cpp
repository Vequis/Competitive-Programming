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
#define endl '\n'
#define ll long long int

using namespace std;

queue<string> fila;
map<string, int> nivel;
stack<int> pilha;
// queue<int>::iterator it;// Não existe
int n, x, y;
string cmd;

/*
Só pode usar 0 e 1
não pode colocar ter 11's (ums consecutivos) nas palavras
n-ésima palavra (n<10^6)
0 é a primeira, 1 é a segunda
Estão ordenadas por tamanho depois lexicografica

0, 1, 00, 01, 10, 000, 001, 010, 100, 101...
*/

string s;

int main(){_

    cin >> n;

    //Possui praticamente os mesmos comandos: front, pop, push, 
    //Funciona exatamente como uma pilha: tira e coloca do mesmo lugar;
    //Pode funcionar para transformar algo recursivo em iterativo (??)



    //Não da pra iterar
    return 0;
}