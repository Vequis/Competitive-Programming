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

#define CONST 512345
int a[CONST];
int tree[CONST*4 + 1];
int ind[CONST];

void update(int node, int tl, int tr, int idx, int val){
    if(idx < tl || tr < idx) return;
    if(tl==tr){
        tree[node] += val;
    } else {
        int tm = tl + (tr - tl)/2;

        if(tl <= idx && idx <= tm){
            update(2*node, tl, tm, idx, val);
        } else {
            update(2*node + 1, tm+1, tr, idx, val);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int sum(int node, int tl, int tr, int l, int r){
    if(r < tl || tr < l ) return 0;
    else if(l<=tl && tr <= r) return tree[node];

    int tm = tl + (tr - tl)/2;

    int p1 = sum(2*node, tl, tm, l, r);
    int p2 = sum(2*node + 1, tm+1, tr, l, r);
    return p1+p2;
}

int resp[CONST];

signed main(){_

    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int op;
        cin >> op;

        if(op==1){
            int l, r;
            int val;
            cin >> l >> r;
            l++; r++;
            cin >> val;

            update(1, 1, n, l, val);
            update(1, 1, n, r, -val);
        } else {
            int ind;
            cin >> ind;
            ind++;
            cout << sum(1, 1, n, 1, ind) << endl;
        }
    }

    return 0;
}
