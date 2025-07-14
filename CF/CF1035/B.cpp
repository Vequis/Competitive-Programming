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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

void solve() {
    int n;
    cin >> n;

    int px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    
    vi v(n);

    int dist2 = ((px-qx)*(px-qx)) + ((py-qy)*(py-qy));

    for (int i = 0; i < n; i++) cin >> v[i];

    int l = v[0], r = v[0];

    for (int i = 1; i < n; i++) {
        if (l <= v[i] and v[i] <= r) {
            l = 0;
        } else if (v[i] <= l) {
            l = l - v[i];
        } else if (v[i] >= r) {
            l = v[i] - r;
        }
        r = r+v[i];
    }

    if (l*l <= dist2 and dist2 <= r*r) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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