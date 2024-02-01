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
// #define int long long // -> solução divina

using namespace std;

int minsoma[210000];
int maxsoma[210000];
int mini[210000];
int maxi[210000];
int atual[210000];
int acum[210000];
int minimo = 0;
int maximo = 1;
vi adj[212345];

void dfs(int node) {

    for(int v : adj[node]) {
        int auxmin = minimo;
        int auxmax = maximo;
        minimo = min(minimo, acum[v]);
        maximo = max(maximo, acum[v]);

        // cout << v << ' ' << minimo << ' ' << maximo << endl;

        maxsoma[v] = max(maxsoma[node], acum[v] - minimo);
        minsoma[v] = min(minsoma[node], acum[v] - maximo);
        dfs(v);

        mini[node] = min(mini[v] + atual[node], mini[node]);
        maxi[node] = max(maxi[v] + atual[node], maxi[node]);

        minimo = auxmin;
        maximo = auxmax;
    }
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int tam = 1;

        minsoma[1] = 0;
        maxsoma[1] = 1;
        atual[1] = 1;

        vector<pair<ii, int>> queries;

        for(int i = 0; i < n; i++) {
            char op;
            cin >> op;
            int a, b;
            cin >> a >> b;

            if(op == '+') {
                atual[++tam] = b;
                acum[tam] = acum[a] + b;
                adj[a].pb(tam);
            } else {
                int c;
                cin >> c;

                queries.eb(a, b, c);
            }
        }

        maximo = 1;
        minimo = 0;
        dfs(1);

        for(pair<ii, int> p : queries) {

            // cout << p.fs << ' ' << maxsoma[p.fs] << ' ' << atual[p.fs] << '*' << ' ' <<minsoma[p.fs] << endl;

            if (minsoma[p.fs.sc] - acum[p.fs.fs] <= p.sc and p.sc <= maxsoma[p.fs.sc] - acum[p.fs.fs]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } 

        queries.clear();
        for(int i = 1; i <=n; i++) adj[i].clear();
    } 


    return 0;
}
