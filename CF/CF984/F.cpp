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

int xor_1_R(int r) {
    if (r%4 == 0) return r;
    if (r%4 == 1) return 1;
    if (r%4 == 2) return r+1;
    // if (r%4 == 3) 
    return 0;
}

int k;
int modulo;
int i;
int xor_n_interessantes(int r) {
    int cont = r / modulo + (r%modulo >= k) - 1;
    // if (k== 0) cont--;
    int resp = xor_1_R(cont);
    resp = (resp << i);
    if (cont % 2 == 0) resp += k;

    // cout << r << ' ' << resp << ' ' << cont << endl;
    return resp;
}

void solve() {
    int l, r;
    cin >> l >> r >> i >> k;
    modulo = 1;

    for (int j = 1; j<=i; j++) modulo = (modulo << 1);
    k = k % modulo;
    // for (int i = 1; i <=n; i++) {
    //     x = x xor i;
    //     if (x != xor_1_R(i)) cout << i << endl;
    // }   

    int resp = 0;
    resp = resp xor xor_1_R(r);
    resp = resp xor xor_1_R(l-1);
    resp = resp xor xor_n_interessantes(r); 
    resp = resp xor xor_n_interessantes(l-1);
    cout <<  resp << endl;


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