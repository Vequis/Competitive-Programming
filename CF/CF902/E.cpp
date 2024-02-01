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

int adj[212345];
int escolha[212345];
int grau[212345];

signed main(){_

    int n;
    cin >> n;

    memset(escolha, -1, sizeof(escolha));
    memset(grau, 0, sizeof(grau));

    for(int i = 1; i<= n; i++) {
        int u;
        cin >> u;
        adj[i] = u;
        grau[u]++;
    }

    queue<int> fila;
    int processados = 0;
    int escolhidos = 0;
    for(int i = 1; i <=n; i++) {
        if (grau[i] == 0) {
            fila.push(i);
        }

    }

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();

        escolha[u] = 1;
        escolhidos++;
        int v = adj[u];
        //escolha : 0 -> circulado , 1 -> fica na array
        if (escolha[v] == -1) {//vai ser -1 ou 0
            escolha[v] = 0;
            grau[adj[v]]--;
            processados++;
            if(grau[adj[v]] == 0 and escolha[adj[v]] == -1) fila.push(adj[v]);
        }
    }


    //Analisar ciclos;

    for(int i = 1; i <= n; i++) {
        if (escolha[i] == -1) {
            int tamciclo = 1;

            int itr = adj[i];
            while(itr != i) {
                tamciclo++;
                itr = adj[itr];

            }

            if (tamciclo % 2 == 0) {
                escolhidos += tamciclo/2;
                escolha[i] = 1;
                int itr = adj[i];
                escolha[adj[i]] = escolha[i] ^ 1;
                while(itr != i) {
                    escolha[adj[itr]] = escolha[itr] ^ 1;
                    itr = adj[itr];
                }
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << escolhidos << endl;
    for(int i = 1; i<= n; i++) {
        // cout << escolha[i] << endl;
        if (escolha[i] == 1) cout << adj[i] << ' ';
    }
    cout << endl;
 
    return 0;
}
