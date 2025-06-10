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

vii pieces;

int memo[612][612];
 
int dp(int w, int h) { // min que da desperdicar pra usar com essa area
    if (w == 0 or h == 0) return 0;

    if (memo[w][h] != -1) return memo[w][h];

    int resp = w * h;

    for (ii p : pieces) {

        if (p.fs > w or p.sc > h) continue; 
        resp = min(dp(w-p.fs, p.sc) + dp(w, h-p.sc), resp);
        resp = min(dp(p.fs, h-p.sc) + dp(w-p.fs, h), resp);
    }

    return memo[w][h] = resp;
}

void solve() {
    int w, h;
    cin >> w >> h;
    
    int n;
    cin >> n;

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j<=h; j++) {
            memo[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        pieces.eb(a, b);
    }

    cout << dp(w, h) << endl;
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