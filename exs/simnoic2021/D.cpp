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
#define maxn 312345

using namespace std;

int pai[maxn];
int peso[maxn];
queue<ii> fila;
vii resp;

int find(int node){
    if(pai[node] == node) return node;
    return pai[node] = find(pai[node]);
}

void join(int a, int b){

    a = find(a);
    b = find(b);

    if(a==b) return;

    if(peso[a] < peso[b]) pai[a] = b;
    if(peso[a] > peso[b]) pai[a] = b;
    if(peso[a] ==peso[b]) {
        peso[a]++;
        pai[b] = a;
    }
}

void kruskal(){

    while(!fila.empty()){


        ii aresta = fila.front();
        fila.pop();

        if(find(aresta.fs) == find(aresta.sc)){
            resp.pb(aresta);
        } else {
            join(aresta.fs, aresta.sc);
        }

    }
}

signed main(){_

    int n, m;

    cin >> n >> m;

    for(int i=1; i<=n; i++) pai[i] = i;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        fila.push({u,v});
    }

    kruskal();

    cout << sz(resp) << endl;

    for(ii p : resp){
        cout << p.fs << ' ' << p.sc << endl;
    }

    return 0;
}
