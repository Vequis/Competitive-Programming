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

vi v;
void solve() {

    int n;
    cin >> n;
    v.clear();
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.eb(a);
    }

    sort(all(v));

    if (v[0] != v[1]) {
        cout << "YES" << endl;
        return;
    }
    int x = v[0];

    for(int i = n-1; i>1; i--) {
        // cout << i << ' ' << v[i] << ' ' << x << endl;
        if (v[i]%x != 0 and v[i]%x != x) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
