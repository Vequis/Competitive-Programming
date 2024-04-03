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

int mdc (int a, int b) {
    if (a < b) swap(a, b);
    if (b==0) return a;
    return mdc(b, a%b);
}

int mmc (int a, int b) {
    return a*b/mdc(a, b);
}

void solve() {
    int n, k;
    cin >> n;

    vi divs;
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            divs.pb(i);
            if (i * i != n) divs.pb(n/i);
        }
    }   

    int resp = INF;
    for (int x : divs) {
        int q = n/x;
        int cur = x*((q+1)/2);
        // cout << x << ' ' << cur << endl;
        resp = min(resp, cur);
    }

    if (resp != INF) {
        cout << resp << ' ' << n - resp << endl;
    } else {
        cout << 1 << ' ' << n-1 << endl;
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