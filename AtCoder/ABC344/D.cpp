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

vector<string> v[1123];
map<string, int> memo;

int ehprefixo(string t, string s) {
    if (sz(s) > sz(t)) return 0;

    for (int i = 1; i <= sz(s); i++) {
        if (s[sz(s) - i] != t[sz(t) - i]) return 0;
    }

    return 1;
}

int dp(int n, string t) {
    int resp = INF;
    if (n <= 0) return INF;

    

    for (string x : v[n]) {
        if (ehprefixo(t, x)) {
            int d = dp(n-1, ...);
            if (d != INF) resp = min(resp, 1 + d);
        }
    }

    resp = min(resp, dp(n-1, t));
    return resp;

}

void solve() {
    string t;
    cin >> t;   
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++ ) {
        int m;
        cin >> m;
        while(m--) {
            string s;
            cin >> s;
            v[i].eb(s);
        }
    }


}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}