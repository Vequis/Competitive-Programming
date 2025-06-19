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

int dez_elevado(int n) {
    if (n==0) return 1;
    int resp = 1;
    for (int i = 0; i < n; i++) {resp*=10;}
    return resp;
}

int f(int a, int b, int n) {
    if (n < 0) return 0;
    int pot = dez_elevado(n);
    int c = a/pot;
    int d = b/pot;

    if (d >= c + 2) return 0;
    else if (c == 0 and d == 0) return f(a, b, n-1);
    else if (c != 0 and d == c) return 2 + f(a, b, n-1);
    else return 1 + f(a, b, n-1);
}

void solve() {
    int l, r;
    cin >> l >> r;

    cout << f(l, r, 10) << endl;
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