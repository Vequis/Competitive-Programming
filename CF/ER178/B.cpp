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

    vi v(n+1);
    vi maximo(n+1); // representa o maximo valor entre 0 e i

    maximo[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        maximo[i] = max(maximo[i-1], v[i]);
    }

    vi resp(n+1);
    int soma = 0;
    for (int k=1; k<=n; k++) {
        if (k!=1) soma += v[n+2-k];
        cout << soma + maximo[n+1 - k] << ' ';
    }
    cout << endl;
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