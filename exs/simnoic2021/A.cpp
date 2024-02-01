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
#define maxn 312345

using namespace std;

int tree[4*maxn + 1];
int a[maxn];

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

void update(int node, int tl, int tr, int idx){
    if(tl == tr){
        a[tl] = (a[tl] + 1)%2;
        tree[node] = a[tl];
    } else {
        int tm = tl + (tr - tl)/2;

        if(idx<=tm){
            update(2*node, tl, tm, idx);
        } else {
            update(2*node+1, tm+1, tr, idx);
        }

        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

int sum(int node, int tl, int tr, int l, int r){
    if( r < tl || tr < l) return 0;
    if( l <=tl && tr <=r) return tree[node];

    int tm = tl + (tr - tl)/2;

    int p1 = sum(2*node, tl, tm, l, r);
    int p2 = sum(2*node+1, tm+1, tr, l, r);

    return (p1+p2);
}

signed main(){_

    int n, m;
    cin >> n >> m;

    int cont = 0; //Contador de 1;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i] == 1) cont++;
    }

    build(1, 1, n);

    for(int i=0; i<m; i++){
        int idx;
        cin >> idx;

        if(a[idx] == 1){
            cont--;
        } else {
            cont ++;
        }

        update(1, 1, n, idx);


        if(sum(1, 1, n, 1, n-cont) == 0 && sum(1, 1, n, n-cont+1, n) == cont){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
