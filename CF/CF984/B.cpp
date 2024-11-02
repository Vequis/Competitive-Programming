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
    int n, k;
    cin >> n >> k;

    map<int, int> lucro;
    for (int i = 1; i <=k; i++) {
        int a, b;
        cin >> a >> b;

        lucro[a] += b;
    }   

    vi v;
    for (ii p : lucro) {
        v.pb(p.sc);
    }

    sort(all(v));

    int cont = 1;
    int resp = 0;
    for (int i = sz(v) - 1; (cont <= n) and i>=0; i--) {
        cont++;
        resp += v[i];
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