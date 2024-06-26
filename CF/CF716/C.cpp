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

int sum(int a, int b) { return ((a+b)%MODN); }
int mult(int a, int b) { return ((a*b)%MODN); }
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
int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b==0) return a;
    return gcd(b, a%b);
}

signed main(){_

    int n;
    cin >> n;

    int multi = 1;
    vi resp;
    for(int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            multi = multi*i%n;
            resp.pb(i);
        }
    }

    if (multi != 1) cout << sz(resp) - 1 << endl;
    else  cout << sz(resp) << endl;

    // cout << multi << endl;

    for(int x : resp) {
        if (multi != 1 and multi == x) continue;
        cout << x << ' ';
    }

    cout << endl;

    return 0;
}
