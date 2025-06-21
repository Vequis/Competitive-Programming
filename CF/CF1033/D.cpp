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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int soma(int a, int b) { return (MODN + a+b)%MODN; }
int mult(int a, int b) { return ( a % MODN * (b % MODN))%MODN; }
int power(int a, int b) {
    int resp = 1;
    int pot = a;
    while(b > 0) {
        if (b & 1) resp = mult(resp, pot);
        pot = mult(pot, pot);
        b/=2;
    }
    return resp;
}

int modinv(int x) {
    return power(x, MODN-2);
}

int fat(int x) {
    int resp = 1;
    for (int i = 1; i <= x; i++) resp = mult(resp, i);
    return resp;
}

int nCr(int n, int k) { // combinação n a k
    
    if (k > n-k) k = n-k;

    // k is small
    int resp = 1;
    for (int i = n; i>n-k; i--) resp = mult(resp, i);

    return mult(resp, modinv(fat(k)));
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    int n = k*(a-1) + 1;

    int m = mult(b-1, mult(k, nCr(n, a)));
    m = soma(m, 1);

    cout << n%MODN << ' ' << m << endl;
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