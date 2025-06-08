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

int k;
int n;

int memo[1123456];

int dp(int x) {
    if (x<=k) return 1;
    if (memo[x] != -1) return memo[x];


    int resp = INF;
    for (int i = 2; i*i<=x and i <= k; i++) {
        if (x%i == 0) {
            if (i<=k) resp = min(resp, 1 + dp(x/i));
            if (x/i<=k) resp = min(resp, 1 + dp(i));
        }
    }

    // cout << x << ' ' << resp << endl;
    return memo[x] = resp;
}

int mdc(int a, int b) {
    if (a < b) swap(a, b);
    if (b==0) return a;
    return mdc(b, a%b);
}

void solve() {
    // testar se precisa passar por todos os divisores, ou se só o maior ja basta   

    int a, b;
    cin >> a >> b >> k;

    int g = mdc(a, b);

    for (int i = 1; i <=max(a/g, b/g); i++) memo[i] = -1;

    int x = dp(a/g);
    int y = dp(b/g);

    if (a/g==1) x=0;
    if (b/g==1) y=0;

    if (x == INF or y == INF) {
        cout << -1 << endl;
    } else {
        cout << x + y << endl;
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