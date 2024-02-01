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

    fila.push("0"); nivel["0"] = 1;
    fila.push("1"); nivel["1"] = 1;
    for (int i=0; i<n; i++){
        s = fila.front();fila.pop();

        cout << i+1 << "  " << s << " // " << "nivel " << nivel[s] << endl;

        if (s[sz(s)-1] == '0'){
            fila.push(s+"0");
            nivel[s+"0"] = nivel[s]+1;
            fila.push(s+"1");
            nivel[s+"1"] = nivel[s]+1;
        } else {
            fila.push(s+"0");
            nivel[s+"0"] = nivel[s]+1;
        }
    }

    //Não da pra iterar
    return 0;
}