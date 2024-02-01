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

int tree[4000005][3];
int a[1000000];
string s;

void build(int node, int tl, int tr){
    if(tl==tr){
        if(s[tl-1] == '('){
            tree[node][1] = 1;
        } else if (s[tl-1] == ')') {
            tree[node][2] = 1;
        }
    } else {
        int tm = tl + (tr-tl)/2;

        build(2*node, tl, tm);
        build(2*node+1, tm+1, tr);

        int corretos = min(tree[2*node][1], tree[2*node+1][2]);

        tree[node][0] = corretos + tree[2*node][0] + tree[2*node+1][0];
        tree[node][1] = tree[2*node][1] + tree[2*node+1][1] - corretos;
        tree[node][2] = tree[2*node][2] + tree[2*node+1][2] - corretos;
    }
}

pair<int, ii> query(int node, int tl, int tr, int l, int r, int lado){

    if(r<tl or tr < l){
        return {0, {0, 0}};
    }

    if(l<=tl and tr<=r){
        return {tree[node][0], {tree[node][1], tree[node][2]}};
    }

    int tm = tl+(tr-tl)/2;
    pair<int, ii> p1 = query(2*node, tl, tm, l, r, 0);
    pair<int, ii> p2 = query(2*node + 1, tm+1, tr, l, r, 1);

    int corretos = min(p1.sc.fs, p2.sc.sc);

    // cout << node << ' ' << tl << ' ' << tr << ' ' << (p1.fs + p2.fs) + corretos << endl;
    return {(p1.fs + p2.fs) + corretos, {p1.sc.fs + p2.sc.fs - corretos, p1.sc.sc + p2.sc.sc - corretos}};
}

signed main(){_

    cin >> s;

    int tam = sz(s);

    int m;

    cin >> m;

    build(1, 1, tam);
  
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        cout << 2*query(1, 1, tam, a, b, 0).fs << endl;
    }

    return 0;
}
