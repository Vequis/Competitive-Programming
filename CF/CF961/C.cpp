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
    cin >> n;

    int ant = 0;

    vi v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }       

    int resp = 0;
    for (int i =2; i <=n; i++) {
        if (v[i-1] == 1) {
            ant = 0;
            continue;
        }

        if (v[i] == 1) {
            cout << -1 << endl;
            return;
        }
        int y = ceil( ant - log2( log(v[i]) / log(v[i-1]) )) ;
        y = max(0LL, y);
        resp += y;
        ant = y;
        //cout << y << endl;
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