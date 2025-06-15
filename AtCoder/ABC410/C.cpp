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
    
    vi v(n);
    for (int i = 0; i < n; i++) v[i] = i+1;

    int acc_shift = 0;
    while(q--) {
        int op;
        cin >> op;

        int p, k, x;
        if (op == 1) {
            cin >> p;
            cin >> x;
            p--;
            int idx = (p + acc_shift) % n;

            v[idx] = x;
        } else if (op == 2) {
            cin >> p;
            p--;
            int idx = ( p + acc_shift) % n;

            cout << v[idx] << endl;
        } else {
            cin >> k;
            acc_shift = (acc_shift + k) % n;
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