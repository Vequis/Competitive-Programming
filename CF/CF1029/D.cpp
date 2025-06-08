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
    
    vi v(n+1);

    for (int i = 1; i<=n; i++) cin >> v[i];

    int delta = v[2] - v[1];
    if ((v[1] - delta) % (n+1)) {
        cout << "NO" << endl;
        return;
    } 

    int b = (v[1] - delta)/(n+1);
    int a = delta + b;

    if (a <0 or b < 0) {
        cout << "NO" << endl;
        return;
    }

    // cout << a << ' ' << b << endl;

    for (int i = 1; i <=n; i++) {
        // cout << '*' << v[i] << ' ' << a*i + b*(n + 1 - i) << endl;
        if (v[i] != (a*i + b*(n+1 - i))) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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