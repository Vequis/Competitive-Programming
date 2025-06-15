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

#define maxn 212345

int a[maxn];
int tree[4*maxn + 1];

//1-indexado se n me engano
int v[maxn];

void build(int node, int tl, int tr){
    if(tl == tr){
        tree[node] = a[tl];
    } else {
        int tm = tl + (tr - tl)/2;

        build(2*node, tl, tm);
        build(2*node+1, tm+1, tr);

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int tl, int tr, int idx, int val){
    if(tl == tr){
        a[idx] = val;
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

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <=n; i++) {
        cin >> v[i];
    }

    int resp = 0;
    for (int i = 1; i < n; i++) {
        a[i] = min(v[i], v[i+1]);
        resp += a[i];
    }

    while(q--) {
        int idx, val;
        cin >> idx >> val;

        v[idx] = val;

        if (idx == 1) {
            resp += min(v[idx], v[idx+1]) - a[idx];
            a[idx] = min(v[idx], v[idx+1]);
        } else if (idx == n) {
            resp += min(v[idx], v[idx-1]) - a[idx-1];
            a[idx-1] = min(v[idx], v[idx-1]);
        } else {
            resp += min(v[idx], v[idx+1]) - a[idx];
            a[idx] = min(v[idx], v[idx+1]);
            resp += min(v[idx], v[idx-1]) - a[idx-1];
            a[idx-1] = min(v[idx], v[idx-1]);
        }


        cout << resp << endl;

        // for (int i = 1; i <=n-1; i++) cout << a[i] << ' ';
        // cout << endl; 
    }
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
