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

// fazer mais casos
// Algum dia da minha vida eu vou comentar isso

// O(N log N)
vector<int> compress(const vector<int>& a) {
    vi sorted = a;
    sort(all(sorted));
    sorted.erase(unique(all(sorted)), sorted.end());

    vi compressed;
    for (int val : a) {
        // 1 - indexado
        int idx = 1 + lower_bound(all(sorted), val) - sorted.begin();
        compressed.pb(idx);
    }

    return compressed;
}

// int val[212345];
char op[212345];
vi f;

#define maxn 212345

int tree[4*maxn + 1];

//1-indexado se n me engano

void build(int node, int tl, int tr){
    if(tl == tr){
        tree[node] = f[tl];
    } else {
        int tm = tl + (tr - tl)/2;

        build(2*node, tl, tm);
        build(2*node+1, tm+1, tr);

        tree[node] = tree[2*node] + tree[2*node+1];
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

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int sum(int node, int tl, int tr, int l, int r){
    if(r < tl || tr < l) return 0;
    if(l<=tl && tr <= r) return tree[node];

    int tm = tl + (tr - tl)/2;

    int p1 = sum(2*node, tl, tm, l, r);
    int p2 = sum(2*node+1, tm+1, tr, l, r);

    return p1+p2;
}

// vou considerar que sempre tem mais que k em tree[node]
// tratando a condição la embaixo
int query_kth(int node, int tl, int tr, int k) {

    if (tl == tr) {
        return tl;
    }

    int tm = tl + (tr - tl)/2;
    if (tree[2*node] >= k) {
        return query_kth(2*node, tl, tm, k);
    } else {
        return query_kth(2*node + 1, tm+1, tr, k - tree[2*node]);
    }
}


void solve() {
    int t;
    cin >> t;

    vi v(t);
    vi original_values(t);

    for (int i = 0; i < t; i++) {
        cin >> op[i];
        cin >> v[i];
        original_values[i] = v[i];
    }    

    v = compress(v);
    int max_value = -1;
    for (int i=0; i<t; i++) max_value=max(max_value, v[i]);

    f = vi(max_value + 1);

    build(1, 1, max_value);

    map<int, int> map_back;
    for (int i = 0; i <t; i++) map_back[v[i]] = original_values[i];

    for (int i = 0; i < t; i++) {
        if (op[i] == 'I') {
            if (f[v[i]] == 0) {
                f[v[i]] = 1;
                update(1, 1, max_value, v[i], 1);
            }
        } else if (op[i] == 'D') {
            if (f[v[i]]) {
                f[v[i]] = 0;
                update(1, 1, max_value, v[i], 0);
            }
        } else if (op[i] == 'K') {
            if (tree[1] < original_values[i]) {
                cout << "invalid" << endl;
            } else {
                cout << map_back[query_kth(1, 1, max_value, original_values[i])] << endl;
            }
        } else if (op[i] == 'C') {
            cout << sum(1, 1, max_value, 1, v[i] - 1) << endl;
        }
    }
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