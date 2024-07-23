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
    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(all(v));

    int cur = 0;
    for (int i = n-1; i >=0; i--) {
        if (i == n-1 or v[i] == v[i+1]) cur++;
        else {
            if (cur % 2) {
                cout << "YES" << endl;
                return;
            } else {
                cur = 1;
            }
        }

        if (i == 0) {
            if (cur % 2) {
                cout << "YES" << endl;
                return;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
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