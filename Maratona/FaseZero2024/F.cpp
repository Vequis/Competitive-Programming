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

int dp(int n, int m, int h) {
    if (n == 0 and m == 0 and h == 0) return 1;
    if (h < 0) return 0;
    if (h > n) return 0;
    return dp(n-1, m, h-1) + dp(n, m-1, h+1);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int m = sz(s);

    int openBefore = 0, closeAfter = 0;

    int remainingOpen = 0;
    for(int i = 0; i < m; i++) {
        if (s[i] == ')') {
            if (remainingOpen > 0) remainingOpen--;
            else {
                openBefore++;
            }
        } else remainingOpen++;
    }

    closeAfter = remainingOpen;
    int resp = 0;

    for (int k = 0; k+m <= n; k++) {
        if (k < openBefore) continue;
        int l = n - k - m;
        if (l < closeAfter) break;

        for (int i = 0; ; i++) {
            if ((k - openBefore - i < 0) or (l - closeAfter - i < 0)) break;

            int f1 = (k - openBefore - i);
            int f2 = (l - closeAfter - i);
            if (f1%2 or f2%2) continue;
            f1/=2;
            f2/=2;
            
            resp += dp(openBefore+i + f1, f1, openBefore+i+f1) * dp(closeAfter+i+f2, f2, closeAfter+i+f2);
        }

        cout << resp << endl;
    }

    cout << resp << endl;


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