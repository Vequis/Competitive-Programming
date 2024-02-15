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

//ax + by = g = mdc(a,b)
int gcd_extended(int a, int b, int& x, int& y) {
    if (a < b) return gcd_extended(b, a, y, x);
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_extended(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd_extended(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int modinv(int a, int m) {
    int x, y;
    int g = gcd_extended(a, m, x, y);
    if (g != 1) {
        return -1;
    }
    else {
        x = (x % m + m) % m;
        return x;
    }
}

int inv(int a) {
    int m = MODN;
    return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
} // MOD primo
vi allinv(int m) {
    vi invs(m);
    invs[1] = 1;
    for(int a = 2; a < m; ++a)
        invs[a] = m - (long long)(m/a) * invs[m%a] % m;
}
vi inverting_all(const vi &a, int m) {
    int n = a.size();
    if (n == 0) return {};
    vi b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    int x, y;
    gcd_extended(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}

signed main(){_

    int x, y;
    // cin >> x >> y;

    cout << gcd_extended(355, 269, x, y) << endl;
    // cout << x << ' ' << y << endl;
    // 

    return 0;
}
