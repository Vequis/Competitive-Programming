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

void solve() {
    int n, q;
    cin >> n >> q;

    int l = 1;
    int r = 2;
    int resp = 0;

    for (int i = 0; i < q; i++) {
        int t;
        char h;
        cin >> h >> t;

        if (h == 'L') {
            if (min(l , t) < r and r < max(l , t)) {
                resp += min(t, l) + n - max(t, l);
            } else {
                resp += abs(l - t);
            }
            l = t;
        } else {
            if (min(t, r) < l and l < max(t, r)) {
                resp += min(t, r) + n - max(t, r);
            } else {
                resp += abs(t - r);
            }
            r = t;
        }
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