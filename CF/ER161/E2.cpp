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

vi f(int n) {
    if (n==1) return vi(0);
    if (n%2 == 1) {
        vi a = f(n-1);
        a.pb(-sz(a));
        return a;
    } else {
        vi a = f(n/2);
        a.pb(sz(a));
        return a;
    }
}

void solve() {
    int n;
    cin >> n;
    vi a = f(n);

    cout << sz(a) << endl;
    for(int x : a) cout << x << ' ';
    cout << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
