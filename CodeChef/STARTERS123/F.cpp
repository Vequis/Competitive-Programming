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

#define maxn 312345

multiset<int> cur;
// multiset<int> 
vi adj[maxn];
int n, k;
int nivel[maxn];
int acum[maxn];
int resp[maxn];
int respx[maxn];

void dfs(int node) {
    int folha = 1;

    // cout << node << endl;
    int maioracum = 0;
    for (int v : adj[node]) {
        if (nivel[v] == -1) {
            folha = 0;
            nivel[v] = nivel[node] + 1;
            dfs(v);
            maioracum = max(maioracum, acum[v]);
        }
    }

    if (folha) cur.insert(nivel[node]);
    else {
        for(auto it = cur.begin(); it != cur.end();) {
            if(*it - nivel[node] > k) {
                // cout << *it << ' ' << node << endl; 
                it = cur.erase(it);
            } else {
                if (*it > k) respx[node]++; 
                if (*it - nivel[node] == k) acum[node]++;
                ++it;
            }
        }
        // cout << node << ' ' << "SAIU" << endl;
        resp[node] = sz(cur) + maioracum;
        // if (node == 2) for(int x : cur) cout << x << ' ';
        // cout << endl;
    }
    acum[node] += maioracum;
    // cout << node << endl;
}

void solve() {

    cin >> n >> k;

    for (int i = 1; i <=n; i++) adj[i].clear();
    cur.clear();
    for (int i = 1; i <=n; i++) nivel[i] = -1;
    for (int i = 1; i <=n; i++) resp[i] = 0;
    for (int i = 1; i <=n; i++) respx[i] = 0;
    for (int i = 1; i <=n; i++) acum[i] = 0;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    nivel[1] = 0;
    for (int v : adj[1]) {
        nivel[v] = 1;
        dfs(v);

        for(auto it = cur.begin(); it != cur.end();) {
            if(*it > k) {
                it = cur.erase(it);
            } else {
                ++it;
            }
        }
        resp[1] += sz(cur);
        cur.clear();
    }

    int respostax = -1;
    for (int i = 2; i <=n; i++) {
        // cout << "*" << i << ' ' << respx[i] << endl;
        respostax = max(respostax, acum[i]);
    }
    resp[1] += respostax;

    // int resposta = -1;
    // for (int i = 1; i <=n; i++) {
    //     // cout << resp[i] << ' ';
    //     resposta = max(resp[i], resposta);
    // }
    cout << resp[1] << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
