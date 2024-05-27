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

vi ancestrais;
int pais[112345];
vi filhos[112345];
vii queries[112345];
int respostas[112345];

vi dfs(int node, vii carregados) {
    vi geracoes_atual;
    vii v;
    for (ii x : carregados) {
        if (x.fs == 0) respostas[x.sc]++;
        else v.eb(x.fs - 1, x.sc);
    }

    for (ii x : queries[node]) {
        if (x.fs == 0) respostas[x.sc]++;
        else v.eb(x.fs - 1, x.sc);
    }

    for (int viz : filhos[node]) {
        dfs(viz, v);
    }

    return geracoes_atual;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <=n; i++) {
        pais[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        int pai;
        cin >> pai;
        if (pai == 0) ancestrais.pb(i);
        else {
            pais[i] = pai;
            filhos[pai].eb(i);
        }
    }

    int q;
    cin >> q;


    for (int i = 1; i <=q; i++) {
        int v, p;
        cin >> v >> p;
        int vit = v;
        int pit = p;
        int flager = 0;

        while(pit > 0) {
            if (pais[vit] == -1) { 
                pit = 0;
                flager = 1;
            } else {
                vit = pais[vit];
                pit--;
            }
        }

        if (!flager) queries[vit].eb(p, i);
    }

    vii v;
    for (int x : ancestrais) dfs(x, v);

    for (int i = 1; i <= q; i++) {
        if (respostas[i] != 0) cout << respostas[i] - 1 << ' ';
        else {cout << respostas[i] << ' ';}
    }
    cout << endl;
}



signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}