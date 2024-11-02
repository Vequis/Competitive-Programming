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
    cin >>n;

    vi a(n);
    vi b(n-1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; i++) cin >> b[i];

    sort(all(a));
    sort(all(b));

    int comprado = 0;
    int resp = 0;

    for (int i = n-1; i >= 1; i--) {
        if (a[i - comprado] > b[i - 1]) {
            if (comprado) {
                cout << -1 << endl;
                return;
            } else {
                resp = a[i];
                comprado = 1;
                i++;
            }
        }
    }

    if (!comprado) resp = a[0];

    cout << resp << endl;
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