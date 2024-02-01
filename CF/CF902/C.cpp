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

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if (k > 3) {
            cout << 0 << endl;
        } else if (k == 1) {
            cout << 1 << endl;
        } else if (k==2) {
            cout << min(n-1, m) + m/n << endl;
        } else  {
            int var = m/n;
            var--;
            // cout << max(0, var*(n-1) + m%n) << endl;
            cout << max(0LL, (var*(n-1) + m%n)) << endl;
        }
    }

    return 0;
}
