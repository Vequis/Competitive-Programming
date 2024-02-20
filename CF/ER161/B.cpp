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

map<int, int> f;

void solve() {

    f.clear();
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        f[a]++;
    }

    int acum = 0;
    int resp = 0;
    for(ii p : f) {
        int x = p.sc;
        int cur = x*(x - 1)/2;
        if (x >= 3) {
            resp += x*(x-1)*(x-2)/6;
        }
        resp += x*(x - 1)/2*acum;
        // cout << p.fs << ' ' << p.sc << endl;
        acum += p.sc;
    }

    cout << resp << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
