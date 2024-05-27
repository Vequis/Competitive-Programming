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

int mdc(int a, int b){
    if (b > a) swap(a, b);
    if (b==0)return a;
    return mdc(b, a%b);
}

int mmc(int a, int b) {
    return a*b/mdc(a, b);
}

void solve() {
    int n;
    cin >> n;
    vi v;
    map<int, int> f;
    map<int, int> pr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.pb(x);
    }

    sort(all(v));

    for (int i = 0; i < n; i++) {
        int x = v[i];

        // cout << endl;
        map<int, int> newf = f;
        for (ii p : f) {

            // x : elemento do f -> p.fs
            // f[x] -> maior numero de elementos que possu usar para formar x -> p.sc
            //
            // cout << p.fs << ' ' << p.sc << endl;
            newf[mmc(x, p.fs)] = p.sc + 1;
        }

        f = newf;

        if (f[x] == 0) f[x] = 1;
        pr[x] = 1;

        // a - {a}
        // b - {a, b, ab}
        // c - {a, b, c, ab, bc, ac, abc}
        // d - x + x + 1

        // cout << endl;
        // cout << "DEBUG: " << v[i] << endl;
        // for(ii p : f) {
        //     cout << p.fs << ' ' << p.sc << endl;
        // }
    }

    int resp = 0;
    for (ii p : f) {
        // cout << p.fs << ' ' << p.sc << endl;
        if (pr[p.fs] == 0) {
            resp = max(resp, p.sc);
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