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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vii arestas = vii(m+1);
    priority_queue<ii, vii, greater<ii>> pq;

    int desconexos = n;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        int t;
        cin >> t;

        arestas[i] = {a, b};

        pq.push({t, i});
    }

    int grau[112345];
    for (int i = 1; i <=n; i++) grau[i] = 0; 

    int te = 0;
    while(!pq.empty() and desconexos > k) {
        ii p = pq.top(); pq.pop();

        if (grau[arestas[p.sc].sc] == 0) {
            grau[arestas[p.sc].sc]++;
            desconexos--;
            te+=p.fs;
        }
    }

    while(!pq.empty()) pq.pop();
    arestas.clear();

    cout << te << endl;
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