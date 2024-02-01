#include<bits/stdc++.h>
#include<vector>
#define maxn 51234
#define fs first
#define sc second

using namespace std;

pair< pair<int, int>, pair<int, int> > v[maxn];
vector<int> adj[maxn];
bool vis[maxn];
int nivel[maxn];
int grande[maxn];

int dfs(int node){

    int resp = 0;

    for (int w : adj[node]){
        if (!vis[w]){
            vis[w] = 1;
            nivel[w] = nivel[node] + 1;
            dfs(w);
            int atual = v[w].fs.fs + 1;
            int cont = v[w].fs.sc;

            resp = max(resp, atual);

            if (atual == v[node].fs.fs){
                v[node].fs.sc += cont;
                grande[node]++;
            } else if (atual == v[node].sc.fs){
                v[node].sc.sc += cont;
            } else if (atual > v[node].fs.fs){
                grande[node] = 1;
                v[node].sc = v[node].fs;
                v[node].fs = {atual, cont};
            } else if (atual > v[node].sc.fs){
                v[node].sc = {atual, cont};
            }
        }
    }

    return resp;
}

int main(){
    int n;

    cin >> n;

    for(int i=1; i<=n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        v[i] = {{0, 1}, {0, 1}};
    }

    vis[1] = 1;
    nivel[1] = 1;
    dfs(1);

    // for(int i=1; i<=n; i++){
    //     cout << v[i].fs.fs << ' ' << v[i].fs.sc << ' ' << v[i].sc.fs << ' ' << v[i].sc.sc << endl;
    // }

    int maior = 0;
    int resp = 0;
    for(int i = 1; i<=n; i++){
        int atual;
        int mult;
        if(grande[i] == 1){
            atual = v[i].fs.fs + v[i].sc.fs + 1;
            mult = v[i].fs.sc * v[i].sc.sc;
        } else {
            atual = 2*v[i].fs.fs + 1;
            mult = v[i].fs.sc * (v[i].fs.sc - 1) / 2;
        }
        
        if (atual == maior){
            resp += mult;
        } else if (atual > maior){
            maior = atual;
            resp = mult;
        }
    }

    cout << maior << endl;
    cout << resp << endl;
}
