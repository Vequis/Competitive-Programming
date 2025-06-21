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
    int n, m;
    cin >> n >> m;
    
    int cur = n*(n+1)/2;
    if (m > cur or m < n) {
        cout << -1 << endl;
        return;
    }
    int delta = cur - m;

    int root = n;

    vii resp;

    for (int i = n; i >= 1; i--) {
        if (delta > 0) {
            root = i-1;

            if (delta < i) {
                resp.eb(i, i-delta);
                delta = 0;
            } else {
                resp.eb(1, i);
                delta -= i-1;
            }
        } else break;
    }

    cout << root << endl;

    for (int i = 1; i < root; i++) cout << i << ' ' << root << endl;

    for (ii p :resp) cout << p.fs << ' ' << p.sc << endl;
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