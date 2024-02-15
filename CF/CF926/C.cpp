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

    int ant = 1;
    int k, x, a;
    cin >> k >> x >> a;

    int soma = 1;
    int guard = a - 1;
    for(int i = 2; i <= x+1; i++) {
        if (i == x+1) {
            if (guard > 0 and (k-1)*guard > soma) cout << "YES" << endl;
            else cout << "NO" << endl;
            return;
        }

        int cur = (soma)/(k-1) + 1;
        soma += cur;

        if (cur > guard) {
            cout << "NO" << endl;
            return;
        }

        guard -= cur;
        // cout << cur << ' ' << soma << ' ' << guard << ' ' << i << endl;
    }

    cout << "YES" << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
