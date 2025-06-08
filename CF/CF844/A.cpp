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

int a[123];

// bool is_perfect(int n) {
//     int lo = 1, hi = n, md;
//     md = lo + (hi - lo)/2;

//     // find last element such that i*i <= n
//     while(lo < hi) {
//         md = lo + (hi - lo)/2;
//         if (md*md == n) return true;
//         else if (md*md < n) lo = md+1;
//         else hi = md;

//         cout << md << endl;
//     }

//     if (lo*lo == n) return true;
//     return false;
// }

void solve() {
    int n;
    cin >> n;

    set<int> candidates;
    for (int i = 1; i <=n; i++) cin >> a[i];
    for (int i = 1; i <=n; i++) {
        for (int j = i+1; j<=n; j++) {
            int delta = abs(a[i] - a[j]);

            for (int d = 1; d*d <= delta; d++) {
                if (delta % d == 0 and (delta/d + d)%2 == 0) {
                    int q = (delta/d + d)/2;
                    int x = q*q - max(a[i], a[j]);
                    if (x >= 0) candidates.insert(x);

                    int dx = delta/d;
                    q = (delta/dx + dx)/2;
                    x = q*q - max(a[i], a[j]);
                    if (x >= 0)candidates.insert(x);

                    // cout << a[i]+x << ' ' << a[j]+x << endl;
                }
            }
        }
    }

    int resp = 1;
    for (int x : candidates) {
        int cur = 0;
        for (int i = 1; i <=n; i++) {
            int c = llround(sqrtl(a[i] + x));
            cur += (c*c == (a[i] + x));
        }
        resp = max(resp, cur);
        // cout << cur << ' ' << x << endl;
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