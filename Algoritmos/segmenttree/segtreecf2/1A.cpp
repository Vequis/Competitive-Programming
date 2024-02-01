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

const int maxn = 1e5;
int tree[4*maxn + 1];
int A[maxn];

void update(int node, int tl, int tr, int l, int r, int val){
    if(r < tl or tr < l) return;
    if (tl == tr){
        tree[node] += val;
    } else {
        if(l<=tl && tr<=r) {
            tree[node]+=val;
        } else {
            int tm = tl + (tr - tl)/2;

            update(2*node, tl, tm, l, r, val);
            update(2*node+1, tm+1, tr, l , r, val);
        }

    }
}

int get(int node, int tl, int tr, int idx){
    if(tl==tr){
        return tree[node];
    } else {
        int tm = tl + (tr - tl)/2;

        if(tl <= idx && idx <= tm){
            return tree[node] + get(2*node, tl, tm, idx);
        } else {
            return tree[node] + get(2*node+1, tm+1, tr, idx);
        }
    }
}

signed main(){_
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int op;
        cin >> op;

        if(op==1){
            int l, r, v;
            cin >> l >> r >> v;
            update(1, 1, n, l+1, r, v);
        } else {
            int idx;
            cin >> idx;
            cout << get(1, 1, n, idx+1) << endl;
        }
    }

    return 0;
}
