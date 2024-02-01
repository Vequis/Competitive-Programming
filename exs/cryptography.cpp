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

int r;

struct mat{
    int el[2][2];
};

mat mult(mat a, mat b){
    mat result;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            int num = ((a.el[i][0]*b.el[0][j])%r + (a.el[i][1]*b.el[1][j])%r )%r;
            result.el[i][j] = num;
        }
    }
    return result;
}

const int maxn = 3e5;
mat tree[4*maxn + 1];
mat A[maxn];

void build(int node, int tl,  int tr){
    if(tl==tr){
        tree[node] = A[tl];
    } else {
        int mid = tl + (tr-tl)/2;

        build(2*node, tl, mid);
        build(2*node+1, mid+1, tr);

        tree[node] = mult(tree[2*node], tree[2*node + 1]);
    }
}

mat ident(){
    mat resp;
    resp.el[0][0] = 1;
    resp.el[0][1] = 0;
    resp.el[1][0] = 0;
    resp.el[1][1] = 1;

    return resp;
}

mat query(int node, int tl, int tr, int l, int r){

    if(r<tl or tr < l){
        return ident();
    }

    if(l<=tl and tr<=r){
        return tree[node];
    }

    int tm = tl+(tr-tl)/2;
    mat p1 = query(2*node, tl, tm, l, r);
    mat p2 = query(2*node + 1, tm+1, tr, l, r);
    return mult(p1, p2);
}

signed main(){_

    int n, m;
    cin >> r >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> A[i].el[0][0] >> A[i].el[0][1];
        cin >> A[i].el[1][0] >> A[i].el[1][1];
    }

    build(1, 1, n);

    for(int i=1; i<=m; i++){
        int l, r;
        cin >> l >> r;
        mat resp = query(1, 1, n, l, r);

        cout << resp.el[0][0] << ' ' << resp.el[0][1] << endl;
        cout << resp.el[1][0] << ' ' << resp.el[1][1] << endl;
        cout << endl;
    }

    return 0;
}
