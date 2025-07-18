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
    int n, s;
    cin >>  n >> s;
    
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i!=0) {
            int x = v[i] - v[i-1];
            if (x > s) {
                cout << "No" << endl;
                return;
            }
        } else {
            if (v[0] > s) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
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