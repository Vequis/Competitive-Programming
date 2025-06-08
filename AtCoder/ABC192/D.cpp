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

//08:34

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;

    int d = -1;
    vi v;
    for (char c : s) {
        int x = (c-'0');
        d = max(d, x);
        v.pb(x);
    }

    int resp = 0;

    for (int i = d+1; 1; i++) {
        int cur = 0;

        int multiplo = 1;
        for (int j=sz(v) - 1; j>=0; j--) {
            cur += multiplo*v[j];
            multiplo*=i;
        }

        if (cur > 0 and cur <= m) {
            resp++;
        } else {
            cout << resp << endl;
            return;
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