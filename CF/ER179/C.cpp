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

int a[512345];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <=n; i++) {
        cin >> a[i];
    }

    a[n+1] = -1;
    int resp = INF;
    resp *= INF;
    for (int i = 1; i <=n; i++) {
        int acum = 1;
        while(a[i] == a[i+1]) {
            i++;
            acum++;
        }

        resp = min(resp, (n - acum) * a[i]);
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