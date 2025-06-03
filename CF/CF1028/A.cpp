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

int mdc(int a, int b) {
    if (a < b) swap(a, b);
    if (b==0) return a;
    return mdc(b, a%b);
}

void solve() {
    int n;
    cin >> n;

    vi v(n);
    int g;
    for (int i = 0; i < n; i++) cin >> v[i];

    g = v[0];
    for (int i = 0; i < n; i++) g = mdc(g, v[i]);

    int qtg = 0;
    for (int i = 0; i < n; i++) {
        if (g == v[i]) qtg++;
    }

    if (qtg > 0) {
        cout << n - qtg << endl;
        return;
    }

    int resp = INF;
    sort(all(v));

    for (int j = 0; j < n; j++) {

        int nec = 0;
        int cur = v[j];
        for (int i = 0; i <n; i++) {
            int h = mdc(cur, v[i]);
            if (h != cur) {
                nec++;
                cur = h;
            }

            if (cur == g) break;
        
        }
        // cout << nec << endl;
        resp = min(resp, n-1 + nec);
    }

    cout << resp << endl;
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