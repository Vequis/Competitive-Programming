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

int cont[123];

void solve() {
    int n, q;
    cin >> n >> q;   

    vi x(q);
    for (int i = 0; i < q; i++) cin >> x[i];

    set<ii> cj;
    map<int, int> f;
    for (int i = 1; i <= n; i++) {
        cj.insert({0, i});
        f[i] = 0;
    }

    vi resp(q);
    for (int i = 0; i < q; i++) {
        int qr = x[i];
        if (qr == 0) {
            ii first = *(cj.begin());
            cj.erase(cj.begin());
            resp[i] = first.sc;
            f[first.sc]++;
            cj.insert({f[first.sc], first.sc});
        } else {
            resp[i] = qr;
            cj.erase(cj.find({f[qr], qr}));
            f[qr]++;
            cj.insert({f[qr], qr});
        }
    }

    for (int i = 0; i < q; i++) cout << resp[i] << ' ';
    cout << endl;
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