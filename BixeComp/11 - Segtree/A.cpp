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


ii tree[4*MAX + 1]; //O segundo valor representa a operação no segmento
//0 para or
//1 para xor
int a[MAX];

int op(int a, int b){
    int resp = 0;
    int prod = 1;

    while(a>0 or b>0){
        int atual = (a%2)||(b%2);
        resp+=atual*prod;

        a = (a>>1);
        b = (b>>1);
        prod*=2;
    }

    return resp;
}

int pote(int a, int b){ //a^b
    if(b==0) return 1;

    int prod = a;
    int resp = 1;

    while(b>0){

        if(b%2){
            resp*=prod;
        }

        b = (b/2);
        prod*=prod;
    }

    return resp;
}

void build(int node, int tl, int tr){

    if(tl==tr){
        tree[node] = {a[tl], 1};
    } else {

        int tm = tl + (tr-tl)/2;
        build(2*node, tl, tm);
        build(2*node + 1, tm+1, tr);

        ii a = tree[2*node];
        ii b = tree[2*node + 1];
        
        if(a.sc == 0){
            tree[node] = {a.fs^b.fs, 1};
        } else {
            tree[node] = {op(a.fs, b.fs), 0};
        }
    }

}

void update(int node, int tl, int tr, int idx, int val){
    if( tl == tr ){
        a[idx] = val;
        tree[node] = {val, 1};
    } else {
        int tm = tl + (tr-tl)/2;

        if(tl <= idx and idx <= tm){
            update(2*node, tl, tm, idx, val);
        } else {
            update(2*node+1, tm+1, tr, idx, val);
        }

        ii a = tree[2*node];
        ii b = tree[2*node + 1];
       
        if(a.sc == 0){
            tree[node] = {a.fs^b.fs, 1};
        } else {
            tree[node] = {op(a.fs, b.fs), 0};
        }
    }

}

signed main(){_

    int n, m;
    cin >> n >> m;

    int tam = pote(2, n);

    for(int i=1; i<=tam; i++){
        cin >> a[i];
    }

    build(1, 1, tam);

    for(int i=0; i<m; i++){
        int pos, val;
        cin >> pos >> val;
        update(1, 1, tam, pos, val);

        cout << tree[1].fs << endl;
    }

    return 0;
}

