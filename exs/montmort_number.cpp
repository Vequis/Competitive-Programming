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
#define int long long // -> solução divina
// #define MODN 1000000007

#define maxf 1123456

using namespace std;
int MODN = -1;

int fat[maxf];
int fatinv[maxf];

int sum(int a, int b) { return (a+b)%MODN; }
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
//So funciona se MODN for primo
int modinv(int x) {
    return power(x, MODN-2);
}
int mdc(int a, int b) {
    if (a < b) return mdc(b, a);
    else if (b == 0) return a;
    return mdc(b, a%b);
}
int gcd_extended(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_extended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) { // equação diofantina linear
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
int inv(int a) {
    int m = MODN;
    return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
} // MOD primo
vi allinv(int m) { // todos os inversos modulares de 1 a n
    vi invs(m);
    invs[1] = 1;
    for(int a = 2; a < m; ++a)
        invs[a] = m - (long long)(m/a) * invs[m%a] % m;
    return invs;
}
vi inverting_all(const vi &a, int m) { // pega um vetor e inverte todos os numeros em O(?) - mais eficiente
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

void fatorial(int n) { //precalcula fatorial
    fat[0] = 1;
    for(int i = 1; i <=n; i++) fat[i] = mult(fat[i-1], i);
    fatinv[n] = modinv(fat[n]);
	for (int i = n; i >= 1; i--) { fatinv[i - 1] = fatinv[i] * i % MODN; }
}
int nCr(int n, int k) { // combinação n a k
    // return mult(fat[n], mult(modinv(fat[n-k]), modinv(fat[k])));
    return fat[n] % MODN * fatinv[n-k] % MODN * fatinv[k] % MODN;
}

vi primos;
int visitadoscrivo[112345];
void crivo(int n){
    primos.pb(2);
    for(int i=3; i<=n; i+=2){
        if(!visitadoscrivo[i]){
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitadoscrivo[j] = 1;
        }
    }
}

int dp[1123456];
signed main(){_

    int n, m;
    cin >> n >> m;
    MODN = m;

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <=n; i++) {
        dp[i] = (MODN + i - 1) % MODN * (sum(dp[i-1], dp[i-2])) % MODN;
    }

    for(int i = 1; i <=n; i++) cout << dp[i] << ' ';
    cout << endl;

    return 0;
}
