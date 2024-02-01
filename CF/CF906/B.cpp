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

    string s, te;
    cin >> s;
    cin >> te;

    char last = 'a';

    int deuruim = 0;

    for(int i = 1; i < m; i++) {
        if (te[i] == te[i-1]) {
            deuruim = 1;
        }
    }

    char fst = te[0];
    char lst = te[sz(te) - 1];

    last = 'a';
    for(int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            if (s[i] == fst or fst!=lst or deuruim) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    return;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
