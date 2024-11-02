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

vi adj[n+1];
int a[n+1];
priority_queue<ii> pq;
int caminho[n+1];
int resp[];
int soma[];

void dfs(int node) {

    int filhomaispesado = -1;

    for (int v : adj[node]) {
        dfs(v);

        if (filhomaispesado == -1 or (resp[v] >= resp[filhomaispesado] and caminho[v] < caminho[filhomaispesado])) {
            if (filhomaispesado != -1) {
                pq.push({resp[filhomaispesado], caminho[filhomaispesado]});
                filhomaispesado = v;
            }
        }
    }

    caminho[node] = caminho[filhomaispesado] + 1;
    soma[node] = soma[filhomaispesado] + a[node];
    resp[node] = resp[filhomaispesado] + soma[filhomaispesado] + a[node];
}

void solve() {
    int n;
    cin >> n;


    for(int i = 1; i<=n; i++) {
        int p;
        cin >> p;
        adj[p].pb(i);
    }

    for (int i = 1; i <=n; i++) {
        cin >> a[i];
    }

    dfs(0);
    pq.push({resp[0], caminho[0]});

    int usados = 0;

    while(!pq.empty()) {
        ii p = pq.top(); pq.pop();

        resp += p.fs;
        
    }
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}