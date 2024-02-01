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
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

struct caractere {
    char car;
    int id;
    int freq;
};

struct node {
    int id; 
    int peso;
    int pai;
    int maiorFilho, menorFilho;
    bool eh_maiorFilho;
    bool eh_folha = false;
    char car;
};

bool cmp(caractere a, caractere b) {
    return a.freq < b.freq;
}

vector<node> Huffman(vector<caractere> v) {
    int n = sz(v);

    priority_queue<ii, vii, greater<ii> > fila;
    //pair = {freq, ind}

    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) v[i].id = i;

    int cont_id = n;
    vector<node> nodes;

    for (int i = 0; i < n ; i++) {
        node atual;
        atual.eh_folha = 1;
        atual.peso = v[i].freq;
        atual.car = v[i].car;
        fila.push({v[i].freq, i});

        nodes.pb(atual);
    }

    for (int i = 0; i < n - 1; i++) {
        ii p1 = fila.top();
        fila.pop();

        ii p2 = fila.top();
        fila.pop();

        node atual;

        atual.menorFilho = p1.sc;
        nodes[p1.sc].eh_maiorFilho = 0;
        atual.maiorFilho = p2.sc;
        nodes[p2.sc].eh_maiorFilho = 1;
        
        nodes[p1.sc].pai = n+i;
        nodes[p2.sc].pai = n+i;

        atual.peso = p1.fs + p2.fs;
        fila.push({atual.peso, n + i});

        nodes.pb(atual);
    }

    nodes[2*n - 2].pai = -1;

    return nodes;
}

string decodificar(string s, vector<node> nodes, vector<caractere> v) {
    int n = sz(v);
    int atual = 2*n - 2;

    string resp = "";

    for(int i = 0; i < sz(s); i++) {
        // cout << '*' << atual << endl;
        if (s[i] == '0') {
            atual = nodes[atual].maiorFilho;
        } else {
            atual = nodes[atual].menorFilho;
        }

        if (atual < n) {
            // cout << '*' << '*' << atual  << " -> ";
            resp += nodes[atual].car;
            atual = 2*n - 2;
        } 
    }

    return resp;
}

string codificar(string s, vector<node> nodes, vector<caractere> v) {
    int n = sz(v);
    int atual = 2*n - 2;
    string resp = "";
    stack<char> pilha;
    for (int i = 0; i < sz(s); i++) {
        atual = -1;
        for (int j = 0; j < n; j++) {
            if (nodes[j].car == s[i]) {
                atual = j;
                break;
            }
        }

        if(atual == -1) return "Input invalido";

        while (nodes[atual].pai != -1) {
            if (nodes[atual].eh_maiorFilho) {
                pilha.push('0');
            } else {
                pilha.push('1');
            }

            atual = nodes[atual].pai;
        }

        while(!pilha.empty()) {
            resp += pilha.top();
            pilha.pop();
        }
        resp+='.';
    }

    return resp;
}


signed main(){

    int codigo;
    cout << "Codificar(0) ou Decodificar(1) ou Codificar com Mapa de Frequencias dado(2)?" << endl;
    cin >> codigo;

    if(codigo == 1) {
        int n;
        cin >> n;

        vector<caractere> v;

        for (int i = 0; i < n; i++) {
            caractere atual;
            
            char c;
            int f;
            cin >> c >> f;
            atual.car = c;
            atual.freq = f;

            v.pb(atual);
        }

        vector<node> nodes = Huffman(v);

        string s;
        cin >> s;

        string resp = decodificar(s, nodes, v);

        cout << resp << endl;
    } else if (codigo == 2) {
        int n;
        cin >> n;

        vector<caractere> v;

        for (int i = 0; i < n; i++) {
            caractere atual;
            
            char c;
            int f;
            cin >> c >> f;
            atual.car = c;
            atual.freq = f;

            v.pb(atual);
        }

        vector<node> nodes = Huffman(v);

        string s;
        cin >> s;

        cout << codificar(s, nodes, v) << endl;
    } else {
        vector<caractere> v;
        string s;
        cin >> s;

        map<char, int> mapfreq;
        for(int i = 0; i < sz(s); i++) {
            if (mapfreq[s[i]] == 0) {
                caractere atual;
                atual.car = s[i];
                v.pb(atual);
            }
            mapfreq[s[i]]++;
        }

        for (int i = 0; i < sz(v); i++) {
            v[i].freq = mapfreq[v[i].car];
        }

        vector<node> nodes = Huffman(v);

        string resp = codificar(s, nodes, v);
        cout << resp << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    
}