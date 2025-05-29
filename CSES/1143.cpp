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

int a[maxn];
int tree[4*maxn + 1];

//1-indexado se n me engano

// max

void build(int node, int tl, int tr){
    if(tl == tr){
        tree[node] = a[tl];
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

// Find first idx between tl and tr such that a[idx] >= x
int query(int node, int tl, int tr, int x){
    if (tl == tr) {
        if (a[tl] >= x) {
            a[tl] -=x;
            tree[node] = a[tl];
            return tl;
        }
        return 0;
    }
    
    int tm = tl + (tr - tl)/2;

    int resp = 0;
    if (tree[2*node] >= x) {
        resp = query(2*node, tl, tm, x);
    } else if (tree[2*node + 1] >= x) {
        resp = query(2*node + 1, tm+1, tr, x);
    }

    tree[node] = max(tree[2*node], tree[2*node + 1]);

    return resp;
}

signed main(){_

    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <=n; i++) cin >> a[i];
    
    build(1, 1, n);
    
    while(q--){
        int x;
        cin >> x;

      
        int idx = query(1, 1, n, x);
        cout << idx << ' ';
    }
    cout << endl;

    return 0;
}
