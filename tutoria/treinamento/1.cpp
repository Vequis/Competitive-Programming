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
const int MAX = 1e7;

using namespace std;

int pai[MAX];

void init(int n) {
    for (int i=0; i<=n; i++){
        pai[i] = i;
    }
}

int find(int u){
    if (u==pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void uniao(int u, int v){
    v = find(v);
    u = find(u);
    pai[v] = u;
}

struct aresta{
    int u,v;
    int w;
};

aresta arestas[MAX];

int n, m;

int cmp(aresta a, aresta b){
    return a.w < b.w;
}

int u, v, w;

int kruskal(){
    int ans = 0;
    sort(arestas, arestas + m, cmp);


    for (int i=0; i<m; i++){
        u = arestas[i].u;
        v = arestas[i].v;
        w = arestas[i].w;

        if (find(u) != find(v)){
            ans+=w;
            uniao(u,v);
        }
    }

    return ans;
}

int main(){_

    cin >> n >> m;

    init(n);

    for (int i=0; i<m; i++){
        int a,b,c;  
        cin >> a >> b >> c;
        arestas[i] = {a,b,c};
    }

    cout << kruskal() << endl;

    return 0;
}