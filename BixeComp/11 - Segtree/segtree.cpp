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

void build(int node, int tl,  int tr){
    if(tl==tr){
        tree[node] = A[tl];
    } else {
        int mid = tl + (tr-tl)/2;

        build(2*node, tl, mid);
        build(2*node+1, mid+1, tr);

        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

void update(int node, int tl, int tr, int idx, int val){
    if (tl == tr){

        //folha
        A[idx] += val;
        tree[node] += val;
    } else {
        int tm = tl + (tr - tl)/2;

        if(tl <= idx and idx <= tm){
            update(2*node, tl, tm, idx, val);
        } else {
            update(2*node+1, tm+1, tr, idx, val);
        }

        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

int query(int node, int tl, int tr, int l, int r){

    if(r<tl or tr < l){
        return 0;
    }

    if(l<=tl and tr<=r){
        return tree[node];
    }

    int tm = tl+(tr-tl)/2;
    int p1 = query(2*node, tl, tm, l, r);
    int p2 = query(2*node + 1, tm+1, tr, l, r);
    return (p1 + p2);
}

signed main(){_

    return 0;
}
