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
#define MAXN 1112345

using namespace std;

int tree_max[4*MAXN + 1];
int tree_min[4*MAXN + 1];
int a[MAXN];

void build_max(int node, int tl, int tr){
    if(tl == tr){
        tree_max[node] = a[tl];
    } else {
        int tm = tl + (tr - tl)/2;

        build_max(2*node, tl, tm);
        build_max(2*node + 1, tm+1, tr);

        tree_max[node] = max(tree_max[2*node], tree_max[2*node+1]);
    }
}

void update_max(int node, int tl, int tr, int ind, int val){
    if(tl == tr){
        tree_max[node] = max(tree_max[node], val); 
    } else {
        int tm = tl + (tr - tl)/2;

        if(tl <= ind && ind <= tm){
            update_max(2*node, tl, tm, ind, val);
        } else {
            update_max(2*node+1, tm+1, tr, ind, val);
        }

        tree_max[node] = max(tree_max[2*node], tree_max[2*node+1]);
    }
}

int query_max(int node, int tl, int tr, int l, int r){
    if (r < tl or tr < l) return 0;
    if (l <= tl && tr <= r) return tree_max[node];

    int tm = tl + (tr - tl)/2;

    int p1 = query_max(2*node, tl, tm, l, r);
    int p2 = query_max(2*node+1, tm+1, tr, l, r);

    return max(p1, p2);
}

void build_min(int node, int tl, int tr){
    if(tl == tr){
        tree_min[node] = a[tl];
    } else {
        int tm = tl + (tr - tl)/2;

        build_min(2*node, tl, tm);
        build_min(2*node + 1, tm+1, tr);

        tree_min[node] = min(tree_min[2*node], tree_min[2*node+1]);
    }
}

void update_min(int node, int tl, int tr, int ind, int val){
    if(tl == tr){
        tree_min[node] = min(tree_min[node], val);
    } else {
        int tm = tl + (tr - tl)/2;

        if(tl <= ind && ind <= tm){
            update_min(2*node, tl, tm, ind, val);
        } else {
            update_min(2*node+1, tm+1, tr, ind, val);
        }

        tree_min[node] = min(tree_min[2*node], tree_min[2*node+1]);
    }
}

int query_min(int node, int tl, int tr, int l, int r){
    if (r < tl or tr < l) return INT_MAX;
    if (l <= tl && tr <= r) return tree_min[node];

    int tm = tl + (tr - tl)/2;

    int p1 = query_min(2*node, tl, tm, l, r);
    int p2 = query_min(2*node+1, tm+1, tr, l, r);

    return min(p1, p2);
}

signed main(){

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    build_max(1, 1, n);
    build_min(1, 1, n);

    for(int i=1; i<=m; i++){
        int op;
        cin >> op;
        if(op == 1){
            int p, b;
            cin >> p >> b;
            update_max(1, 1, n, b, p);
            update_min(1, 1, n, b, p);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query_max(1, 1, n, a, b) << ' ' << query_min(1, 1, n, a, b) << endl;
        }
    }

    // for(int i=1; i<=26; i++) cout << tree_max[i] << ' ' << tree_min[i] << endl;
    return 0;
}
