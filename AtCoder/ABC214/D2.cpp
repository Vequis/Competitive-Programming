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
#define maxn 112345

using namespace std;

ii arestas[maxn];
ii idarestas[maxn];
int pai[maxn];
int peso[maxn];

int find(int a){
    if(pai[a] == a) return a;
    return pai[a] = find(pai[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);

    if(peso[b] > peso[a]) swap(a, b);

    pai[b] = a;
    peso[a] += peso[b];
}

signed main(){_

    int n;
    cin >> n;

    for(int i=1; i<=n-1; i++){
        int u, v, w;

        cin >> u >> v >> w;

        arestas[i] = {u, v};
        idarestas[i] = {w, i};
    }

    sort(idarestas+1, idarestas+n);

    for(int i=1; i<=n; i++){
        pai[i] = i;
        peso[i] = 1;
    }

    int resp = 0;
    for(int i=1; i<=n-1; i++){
        ii p = arestas[idarestas[i].sc];
        int u, v, w;
        u = p.fs;
        v = p.sc;
        w = idarestas[i].fs;

        resp+= peso[find(u)] * peso[find(v)] * w;

        join(u, v);
    }

    cout << resp << endl;

    return 0;
}
