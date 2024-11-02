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

    map<int, ii> sch;

    for (int i = 0; i < n ;i++) {
        int a, b;
        cin >> a >> b;

        sch[i+1] = {a, b};
    }

    int q;
    cin >> q;

    while(q--) {
        int t, d;

        cin >> t >> d;

        ii p = sch[t];

        d = d;

        cout << d + (p.fs + p.sc - d % p.fs) % p.fs << endl;
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