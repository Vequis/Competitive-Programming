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

int v[11];
vi adj[11];
vii adjr[11];

void verifica(int a, int b, int c) {
    if (v[a] == v[b]) {
        adj[a].pb(c);
        adj[b].pb(c);
        adjr[c].eb(a, b);
        // cout << a << ' ' << b << endl;
    }
    swap(b, c);
    if (v[a] == v[b]) {
        adj[a].pb(c);
        adj[b].pb(c);
        adjr[c].eb(a, b);
        // cout << a << ' ' << b << endl;
    }
    swap(a, c);
    if (v[a] == v[b]) {
        adj[a].pb(c);
        adj[b].pb(c);
        adjr[c].eb(a, b);
        // cout << a << ' ' << b << endl;
    }
}

int vis[11];

signed main(){

    int permutation[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 1; i <= 9; i++) {
        cin >> v[i];
    }

    verifica(1, 2, 3);
    verifica(4, 5, 6);
    verifica(7, 8, 9);

    verifica(1, 4, 7);
    verifica(2, 5, 8);
    verifica(3, 6, 9);

    verifica(1, 5, 9);
    verifica(3, 5, 7);
    
    int cont = 0;
    int validos = 0;
    do {
        cont++;
        bool deuruim = 0;
        for(int i = 0; i <= 8; i++) {
            vis[permutation[i]] = cont;
            for (int j : adj[permutation[i]]) {
                if (vis[j] < cont) {
                    for (ii p : adjr[j]) {
                        if (vis[p.fs] == cont and vis[p.sc] == cont ) {
                            deuruim = 1;
                            break;
                        }
                    }
                }
            }


        }


        if(!deuruim) validos++;
        // cout << validos << endl;
    } while(next_permutation(permutation, permutation+9));

    long double resposta = (double)validos/362880.0;

    cout << setprecision(13);
    cout << fixed;
    cout << resposta << endl;

    return 0;
}
