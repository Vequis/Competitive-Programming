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

int a[212345];
int b[212345];
int n;

bool is_valid(int x) {
    int saldo = 0;
    
    for (int i = 1; i<=n; i++) {
        if (a[i] > x) return false;
        if (a[i] + b[i] > x) {
            saldo += x - (a[i] + b[i]);
        } else {
            saldo += (x - (a[i] + b[i])) / 2;
        }
    }

    return saldo >= 0;
}

void solve() {
    cin >> n;

    for (int i = 1; i <=n; i++) cin >> a[i];
    for (int i = 1; i <=n; i++) cin >> b[i];

    int lo = 1, hi = 2*INF;
    int mid;

    while(lo < hi) {
        mid = lo + (hi - lo)/2;
        // cout << mid << ' ' << is_valid(mid) << endl;
        if (is_valid(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
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