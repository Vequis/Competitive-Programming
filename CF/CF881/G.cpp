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
#define MODN 998244353
#define int long long // -> solução divina
#define maxn 2123456

using namespace std;

struct aresta{
    int peso;
    int a, b;
};


bool comp(aresta a, aresta b){
    return a.peso < b.peso;
}

int n, m;
aresta arestas[maxn];
int pai[maxn];
int peso[maxn];
int tam[maxn];
aresta mst[maxn]; //Aqui guardaremos a arvore

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]); //path compression
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(peso[a] > peso[b]) {
        pai[b] = a;
        peso[a] += peso[b];
    }
    else if(peso[a] < peso[b]) {
        pai[a] = b;
        peso[b] += peso[a];
    }
    else {
        pai[b] = a;
        peso[a]+=peso[b];
    }
}

int s;

int power(int a, int b) {
    int resp = 1;
    int pot = a;

    while(b > 0) {
        if (b%2) resp= (resp*pot)%MODN;
        pot = (pot*pot)%MODN;
        b/=2;
    }
    return resp;
}

int kruskalmod() {
    for (int i = 1; i <= n; i++) pai[i] = i;
    for (int i = 1; i <= n; i++) peso[i] = 1;

    sort(arestas+1, arestas+1+n-1, comp);

    int size = 0;

    int resp = 1;

    for (int i=1; i<=n-1; i++) {
        int a = arestas[i].a;
        int b = arestas[i].b;
        if(find(a) != find(b)){
            // cout << a << ' ' << find(a) << ' ' << peso[find(a)] << endl;
            // cout << b << ' ' << find(b) << ' ' << peso[find(b)] << endl;

            int base = (s - arestas[i].peso + 1)%MODN;
            int expo = (peso[find(a)]*peso[find(b)] - 1);
            resp = (resp*power(base, expo))%MODN;
            // cout << resp << ' ';
            // resp = (resp + power(base, expo) - 1);
            // cout << base << ' ' << expo << ' ' << resp << endl;
            join(a,b);
            // mst[++size] = arestas[i];
            // if(size==n-1) return;
        }
    }

    return resp;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        cin >> s;   

        for(int i=1; i<=n-1; i++){
            int u, v, w;
            cin >> u >> v >> w;

            arestas[i].peso = w;
            arestas[i].a = u;
            arestas[i].b = v;
        }

        cout << kruskalmod() << endl;
    }

    return 0;
}
