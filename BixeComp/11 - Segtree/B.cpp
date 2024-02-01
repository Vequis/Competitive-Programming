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

int a[MAX];
int tree[4*MAX + 1];

void build(int node, int tl, int tr){
    if(tl == tr){
        tree[node] = a[tl];
    } else {
        int tm = tl + (tr-tl)/2;

        build(2*node, tl, tm);
        build(2*node+1, tm+1, tr);

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int tl, int tr, int l, int r){
    if( r <tl or tr < l) return INT_MAX;
    if(l<=tl && tr<=r){
        return tree[node];
    }

    int tm = tl+(tr-tl)/2;
    int p1 = query(2*node, tl, tm, l, r);
    int p2 = query(2*node+1, tm+1, tr, l, r);

    return min(p1, p2);
}

signed main(){_

    int t;
    cin >> t;

    int cnt = 1;

    while(t--){
        int n, q;
        cin >> n >> q;

        for(int i=1; i<=n; i++){
            cin >> a[i];
        }

        build(1, 1, n);

        cout << "Scenario #" << cnt << ':' << endl;

        for(int i=0; i<q; i++){
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl;
        }
        
        cnt++;
    }

    return 0;
}
