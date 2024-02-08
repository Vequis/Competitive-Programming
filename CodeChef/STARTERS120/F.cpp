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
#define MODN 998244353
#define int long long // -> solução divina


int power(int a, int b) {
    int resp = 1;
    int pot = a;
    
    while (b > 0) {
        if (b % 2) resp = (resp*pot)%MODN;
        pot = (pot*pot)%MODN;
        b/=2;
    }

    return resp;
}

int modinv(int n) {
    return power(n, MODN-2);
}

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

vi invs(const vi &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    vi b(n);
    int v = 1;
    for (int i = 0; i < n; ++i) {
        b[i] = v;
        v = (v * a[i]) % m;
    }
    // cout << v << endl;
    int x = modinv(v);
    // cout << x << '*' <<  endl;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<int>(x) * b[i] % m;
        x = static_cast<int>(x) * a[i] % m;
    }
    return b;
}

signed main(){_


    vi fat(1000001);
    fat[0] = 1;

    for(int i = 1; i <=1000000; i++) {
        fat[i] = (fat[i-1]*i)%MODN;
        // fatinv[i] = modinv(fat[i]);
    }

    vi fatinv = invs(fat, MODN);
    fatinv[0] = 1;

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        // cout << power(n, k) << endl;

        if (k==0) {
            cout << 1 << endl;
            continue;
        }

        int soma = power(2, n - 1);


        cout << power(soma, k) << endl;
    }

    return 0;
}
