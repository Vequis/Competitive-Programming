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
#define MAX 112345
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int tree[MAX*4 + 1];
int a[MAX];

void build(int node, int tl, int tr){
    if(tl==tr){
        tree[node] = a[tl];
    } else {
        int tm = tl+(tr-tl)/2;

        build(2*node, tl, tm);
        build(2*node+1, tm+1, tr);

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int tl, int tr, int idx, int val){
    if(tl==tr){
        a[tl] += val;
        tree[node] +=val;
    } else {

        int tm = tl + (tr-tl)/2;
        if(tl<= idx && idx <= tm){
            update(2*node, tl, tm, idx, val);
        } else {
            update(2*node+1, tm+1, tr, idx, val);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int tl, int tr, int l, int r){
    if(r < tl or tr < l) return 0;

    if(l<=tl && tr <= r) return tree[node];

    int tm = tl + (tr-tl)/2;
    
    return query(2*node, tl, tm, l, r) + query(2*node+1, tm+1, tr, l, r);
}

signed main(){_

    return 0;
}
