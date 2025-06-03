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

#define maxn 512345

int resp[maxn]; // guarda a resposta
int tree[4*maxn + 1];

int a[maxn];
//1-indexado se n me engano

void build(int node, int tl, int tr){
    if(tl == tr){
        tree[node] = resp[tl];
    } else {
        int tm = tl + (tr - tl)/2;

        build(2*node, tl, tm);
        build(2*node+1, tm+1, tr);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}

void update(int node, int tl, int tr, int idx, int val){
    if(tl == tr){
        tree[node] = val;
    } else {
        int tm = tl + (tr - tl)/2;

        if(tl <= idx && idx <= tm){
            update(2*node, tl, tm, idx, val);
        } else {
            update(2*node+1, tm+1, tr, idx, val);
        }

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int tl, int tr, int l, int r){
    if(r < tl || tr < l) return 0;
    if(l<=tl && tr <= r) return tree[node];

    int tm = tl + (tr - tl)/2;

    int p1 = query(2*node, tl, tm, l, r);
    int p2 = query(2*node+1, tm+1, tr, l, r);

    return max(p1, p2);
}

void solve() {
    int n, d, r;
    cin >> n >> d >> r;
    
    for (int i = 1; i <=n; i++) cin >> a[i];

    vii v;
    for (int i = 1; i <=n; i++) {
        v.eb(a[i], i);
    }

    sort(all(v));

    build(1, 1,n);
    int resposta = -1;
    for (int i = 0; i < n; i++) {
        int idx_ant = v[i - d].sc;
        if (i>=d) {
            update(1, 1, n, idx_ant, resp[idx_ant]);
        }
        int idx = v[i].sc;

        resp[idx] = 1 + query(1, 1, n, max(1LL, idx - r), min(n, idx+r));
        resposta = max(resposta, resp[idx]);
    }
    cout << resposta-1 << endl;
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