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
#define maxn 512345

using namespace std;

int a[maxn];
int tree[4*maxn + 1];

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
        a[idx] = val;
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
    if(r < tl || tr < l) return -1;
    if(l<=tl && tr <= r) return tree[node];

    int tm = tl + (tr - tl)/2;

    int p1 = query(2*node, tl, tm, l, r);
    int p2 = query(2*node+1, tm+1, tr, l, r);

    return max(p1, p2);
}

signed main(){_

    int n;
    cin >> n;

    int d;
    cin >> d;

    for(int i = 1; i <=n; i++) {
        a[i] = 0;
    }

    build(1, 1, 512345);

    int resp = 0;
    for(int i = 1; i <=n; i++) {

        int num;
        cin >> num;
        a[i] = num;

        int l = max(1LL, num - d);
        int r = min(500000LL, num + d);

        int x = query(1, 1, 500000LL, l, r);
        resp = max(resp, x + 1);

        update(1, 1, 500000LL, num, x + 1);
    }   

    cout << resp << endl;


    return 0;
}
