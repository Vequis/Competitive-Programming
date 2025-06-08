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
#define maxn 212345

using namespace std;

int pai[maxn];

int INFLL = INF;
int peso[maxn];

int maior[maxn];
int menor[maxn];

int find(int x){
    if(pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int a, int b, int w){
    a = find(a);
    b = find(b);

    int maximo = w;
    int minimo = min(menor[a], menor[b]);
    minimo = min(w, minimo);

    if(a==b) return;

    if(peso[a] > peso[b]) pai[b] = a;
    if(peso[a] < peso[b]) pai[a] = b;
    if(peso[a] ==peso[b]){
        pai[a] = b;
        peso[b]++;
    }

    maior[a] = maximo;
    maior[b] = maximo;
    menor[b] = minimo;
    menor[a] = minimo;
    // pai[a] = b;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, ii>> edges;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        edges.pb({w, {a, b}});
    }

    for (int i = 1; i <=n; i++) {
        pai[i] = i;
        maior[i] = -1;
        menor[i] = INFLL;
    }

    sort(all(edges));

    int resp = INFLL;
    for (auto ed : edges) {
        int w = ed.fs;
        int a = ed.sc.fs;
        int b = ed.sc.sc;

        // cout << w << ' ' << a << ' ' << b << endl;

        join(a, b, w);

        int x = find(1);
        int y = find(n);

        // cout << x << ' ' << y << endl;
        if (x == y) {
            int cur = menor[x] + maior[x];
            resp = min(resp, cur);
        }
    }

    cout << resp << endl;
}

signed main(){_
    int t;
    cin >> t;
    INFLL *= INF;

    while(t--) {
        solve();
    }

    return 0;
}
