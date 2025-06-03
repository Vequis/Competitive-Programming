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


// Ver inversões do problema original
// se havia inversão i, j, a[i]>a[j]
// então não havera mais se R <= a[j] ou a[i] <= L
// Basta então contar quantas inversões tem o a[j] < R

// mas e no caso de 1 e N por ex ser uma inversão, vou estar tirando 2x


#define maxn 212345

int a[maxn];
int tree[4*maxn + 1];

//tree 1-indexado se n me engano
//a tbm

void build(int node, int tl, int tr){
    if(tl == tr){
        tree[node] = 0;
    } else {
        int tm = tl + (tr - tl)/2;

        build(2*node, tl, tm);
        build(2*node+1, tm+1, tr);

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int tl, int tr, int idx, int val){
    if(tl == tr){
        tree[node] = val;
    } else {
        int tm = tl + (tr - tl)/2;

        if(tl <= idx && idx <= tm){
            update(2*node, tl, tm, idx, val);
        } else {
            update(2*node+1, tm+1, tr, idx, val);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int sum(int node, int tl, int tr, int l, int r){
    if(r < tl || tr < l) return 0;
    if(l<=tl && tr <= r) return tree[node];

    int tm = tl + (tr - tl)/2;

    int p1 = sum(2*node, tl, tm, l, r);
    int p2 = sum(2*node+1, tm+1, tr, l, r);

    return p1+p2;
}

int inv_com_maior_iguala[212345];
int inv_com_menor_iguala[212345];
int psamaior[212345];
int psamenor[212345];


void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <=n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 1; i <=n; i++) {
        inv_com_menor_iguala[a[i]] = sum(1, 1, n, a[i]+1, n);
        // cout << i << ' ' << a[i] << ' ' << inv_com_menor_iguala[a[i]] << endl;
        update(1, 1, n, a[i], 1);
    }

    build(1, 1, n);

    for (int i = n; i>=1; i--) {
        inv_com_maior_iguala[a[i]] = sum(1, 1, n, 1, a[i]-1);
        update(1, 1, n, a[i], 1);
        // cout << i << ' ' << a[i] << ' ' << inv_com_maior_iguala[a[i]] << endl;
    }

    psamaior[0] = 0; // quantas inversões tem o maior  numero menor ou igual a i
    for (int i = 1; i <=n; i++) psamaior[i] = psamaior[i-1] + inv_com_maior_iguala[i];

    // for (int i = 1; i <=n; i++) cout << inv_com_maior_iguala[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <=n; i++) cout << psamaior[i] << ' ';
    // cout << endl;

    psamenor[n+1] = 0; // quantas inversões tem o menor numero maior ou igual a i
    for (int i = n; i >= 1; i--) psamenor[i] = psamenor[i+1] + inv_com_menor_iguala[i];

    // for(int i = 1; i<=n; i++){
    //     cout << psamenor[i] << ' ';
    // }
    // cout << endl;

    while(q--) {
        int l, r;
        cin >> l >> r;

        if (l == r) {
            cout << 0 << endl;
            continue;
        }

        // cout << psamaior[l] << ' ' << psamenor[r] << endl;
        cout << psamaior[n] - psamaior[l] - psamenor[r] << endl;
    }
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}