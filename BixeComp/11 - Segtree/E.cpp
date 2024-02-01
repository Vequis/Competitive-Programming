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

const int maxn = 3e5 + 10;
int tree[4*maxn + 1];
int A[maxn];
int resp[maxn];

void update(int node, int tl, int tr, int l, int r, int winner){
    if(r<tl or tr<l) return;
    if(tree[node] != 0) return;

    if (tl == tr){
        if(tl!=winner){
            tree[node] = winner;
        }
    } else {
        int tm = tl + (tr - tl)/2;

        if(l<=tl && tr<=r){
            if(tl<=winner && winner<=tm){
                update(2*node, tl, tm, l, r, winner);
                if(tree[2*node+1]==0) tree[2*node+1] = winner;
            } else if (tm+1<=winner && winner<=tr) {
                update(2*node+1, tm+1, tr, l, r, winner);
                if(tree[2*node]==0) tree[2*node] = winner;
            } else {
                if(tree[node]==0)tree[node] = winner;
            }
        } else {
            update(2*node, tl, tm, l, r, winner);
            update(2*node+1, tm+1, tr, l, r, winner);

            if(tree[2*node]==0 || tree[2*node+1]==0) tree[node] = 0;
            else tree[node] = -1;
        }
    }
}

int pai(int node){
    if(node==1){
        return 0;
    }

    if(tree[node] == 0){
        return pai(node/2);
    } else {
        return tree[node];
    }
}

void imprime(int node, int tl, int tr){
    if(tl == tr){
        cout << pai(node) << ' ';
    } else {
        int tm = tl + (tr-tl)/2;

        imprime(2*node, tl, tm);
        imprime(2*node+1, tm+1, tr);
    }
}

signed main(){_

    int n, m, l, r, winner;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> l >> r >> winner;
        update(1,1,n,l,r,winner);

    }

    imprime(1,1,n);
    return 0;
}
