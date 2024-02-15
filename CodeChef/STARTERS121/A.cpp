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

int a[1123];

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <=n; i++) {
        cin >> a[i];
    }

    if (n > 4 or n == 1) {
        cout << "YES" << endl;
    } else if (n == 3) {
        if (a[1] > a[3]) swap(a[1], a[3]);

        if (a[1] <= a[2] and a[2] <= a[3]) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else if (n==2) {
        if (a[1] <= a[2]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
