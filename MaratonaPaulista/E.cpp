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

// resolver com busca binária e etc etc

void solve() {
    int n, d;
    cin >> n >> d;

    vii v;
    for (int i = 0; i < n; i++) {
        int dist, valor;
        cin >> dist >> valor;

        v.eb(dist, valor);
    }

    sort(all(v));

    int cur = v[0].sc;

    vi possibilidades;


    for (int i = 1; i <n; i++) {
        if (v[i].fs - v[i-1].fs > d) {
            possibilidades.pb(cur);
            cur = v[i].sc;
        } else {
            cur += v[i].sc;
        }
    }

    possibilidades.pb(cur);

    sort(all(possibilidades));

    int len_pos = sz(possibilidades);
    if (len_pos == 1) {
        cout << possibilidades[0] << endl;
    } else {
        cout << possibilidades[len_pos-1] + possibilidades[len_pos - 2] << endl; 
    }

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