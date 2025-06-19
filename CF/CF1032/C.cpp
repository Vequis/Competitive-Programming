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
    int n, m;
    cin >> n >> m;
    
    vector<vi> v(n+1, vi(m+1));

    vi cont_col(m+1);
    vi cont_row(n+1);

    int resp = 0;
    set<int> colmax, rowmax;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j<=m; j++) {

            cin >> v[i][j];

            resp = max(resp, v[i][j]);
        }
    }

    int cont_resp = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<=m; j++) {
            if (v[i][j] == resp) {
                cont_col[j]++;
                cont_row[i]++;
                cont_resp++;
            }
        }
    }

    // cout << cont_resp << endl;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<=m; j++) {
            // cout << cont_row[i] + cont_col[j] - (v[i][j] == resp) << endl; 
            if (cont_row[i] + cont_col[j] - (v[i][j] == resp) == cont_resp) {
                cout << resp - 1 << endl;
                return;
            }
        }
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