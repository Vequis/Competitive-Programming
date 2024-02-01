#include<bits/stdc++.h>

#define endl '\n'
#define int long long 
#define INDEF 1265126
using namespace std;

int l, c, n;
int mat[200][200];
int nvarlinha[300];
int vallinha[300];
vector<int> adj[1000];
int tamadj[1000];
queue<int> fila;
int resp[1000];
stack<int> pilha[1000];
vector<pair<int, int> > teste;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> l >> c;

    for(int i=0; i<=1000; i++) resp[i] = INDEF;

    for(int i=1; i<=l; i++){
        for(int j=1; j<=c; j++){
            string s;
            cin >> s;

            mat[i][j] = (s[0] - 'a')*26 + ((s[1]-'a')+ 1);
        }
        cin >> vallinha[i];
    }


    for(int i=1; i<=c; i++) cin >> vallinha[l+i];

    for(int i=1; i<=l; i++){
        for(int j=1; j<=c; j++){
            int atual = mat[i][j];
            if(pilha[atual].empty() || pilha[ atual ].top() != i){
                adj[atual].push_back(i);
                pilha[ atual ].push(i);

                nvarlinha[i]++;
            }
        }
    }

    for(int i=1; i<=c; i++){
        for(int j=1; j<=l; j++){
            int atual = mat[j][i];
            if(pilha[atual].empty() || pilha[atual].top() != i+l){
                adj[mat[j][i]].push_back(i+l);
                pilha[atual].push(l+i);
                
                nvarlinha[l+i]++;
            }
        }
    }


    for(int i=1; i<=l+c; i++) {
        if(nvarlinha[i] == 1) fila.push(i);
    }

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();

        int somadet = 0;
        int coef = 0;
        int id;

        if(nvarlinha[u] < 1) continue; //Completamente determinada

        id = -1;

        if(u<=l){
            for(int i=1; i<=c; i++){
                if(resp[ mat[u][i] ] != INDEF){
                    somadet += resp[ mat[u][i] ];
                } else {
                    id = mat[u][i];
                    coef++;
                }
            }
        } else {
            for(int i=1; i<=l; i++){
                if(resp[ mat[i][u-l] ] != INDEF){
                    somadet += resp[ mat[i][u-l] ];
                } else {
                    id = mat[i][u-l];
                    coef++;
                }
            }
        }

        resp[id] = (vallinha[u] - somadet)/coef;
        teste.push_back({id, resp[id]});

        for(int x : adj[id]){
            nvarlinha[x]--;
            if(nvarlinha[x] == 1){
                fila.push(x);
            }
        }
    }

    sort(teste.begin(), teste.end());

    for(pair<int, int> p : teste){
        string s;
        s+= (char)((p.first - 1)/26 + 'a');
        s+= 'a' + (p.first-1)%26;
        cout << s << ' ' << p.second << endl; 
    }

    return 0;
}