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

int fat[212345];

int sum(int a, int b) { return (a+b)%MODN; }
int mult(int a, int b) { return (a*b)%MODN; }
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
//So funciona se MODN for primo
int modinv(int x) {
    return power(x, MODN-2);
}
int mdc(int a, int b) {
    if (a < b) swap(a,b);
    else if (b == 0) return a;
    return mdc(b, a%b);
}
int comb(int n, int k) {
    return mult(fat[n], mult(modinv(fat[n-k]), modinv(fat[k])));
}

int n, m, k;
int tp;
int pa(int i, int k) {
    return mult(power(m, i), mult(power((tp - m + MODN)%MODN, k - i), comb(k, i)));
}

void solve() {
    cin >> n >> m >> k;

    tp = (n*(n-1)/2)%MODN;

    int soma = 0;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int f;
        cin >> f;
        soma = sum( soma, f);
    }

    // cout << tp << endl;

    int resp = 0;
    for (int i = 0; i<=k; i++) {
        int novo = mult(pa(i, k), mult((mult(i, soma) + i*(i-1)/2)%MODN, modinv(power(tp, k))));
        cout << novo << endl;
        resp = sum(resp, novo);
    }

    cout << resp << endl;
}

signed main(){_

    fat[0] = 1;
    for(int i = 1; i <= 212340; i++) fat[i] = mult(fat[i-1], i);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
