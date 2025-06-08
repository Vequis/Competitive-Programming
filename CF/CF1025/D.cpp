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

int par[212345]; // menor caminho par ate i
int impar[212345];
vi adj[212345];

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    
    vi v(l);
    for (int i = 0; i < l;  i++) cin>>v[i];
    sort(all(v));

    for (int i = 1; i <=n; i++) adj[i].clear();

    for (int i = 1; i <=m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <=n; i++) {
        par[i] = -1;
        impar[i] = -1;
    }

    int sum = 0;
    for (int x : v) sum+=x;
    int maiorsomapar=-1, maiorsomaimpar=-1;
    for (int i = 0; i < l; i++) {
        int cur = sum - v[i];
        if (cur % 2) {
            maiorsomaimpar = max(maiorsomaimpar, cur);
        } else {
            maiorsomapar = max(maiorsomapar, cur);
        }
    }
    if (sum%2) maiorsomaimpar=max(maiorsomaimpar, sum);
    else maiorsomapar = max(maiorsomapar, sum);

    par[1] = 0;
    queue<ii> fila;
    fila.push({1, 0});

    while(!fila.empty()) {
        ii p = fila.front(); fila.pop();
        int node = p.fs;
        int path = p.sc;

        for (int viz : adj[node]) {
            if (path % 2 and par[viz] == -1) {
                par[viz] = path + 1;
                fila.push({viz, par[viz]});
            } else if (path%2 == 0 and impar[viz] == -1) {
                impar[viz] = path + 1;
                fila.push({viz, impar[viz]});
            }
        }
    }

    for (int i = 1; i <=n; i++) {
        if (i==1) {
            cout << 1;
            continue;
        }

        if (
            (maiorsomaimpar >= impar[i] and maiorsomaimpar!=-1 and impar[i] != -1)
            or
            (maiorsomapar   >= par[i]   and maiorsomapar  !=-1 and par[i] != -1)
        ) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
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