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

vi v;
int n, c;

bool verifica(int d) {
    int it = 0;
    int cont = c;

    for (int i = 0; i < n; i++) {
        if (v[i] >= it) {
            cont--;
            it = v[i] + d;
            if (cont == 0) return 1;
        }
    }

    return 0;
}

void solve() {
    v.clear();
    cin >> n >> c;
    v = vi(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(all(v));

    int ini = 0, fim = v[n-1] + 1, mid;

    while(ini < fim) {
        mid = ini + (fim - ini)/2;
        if (verifica(mid)) fim = mid;
        else ini = mid + 1;
    }

    cout << ini << endl;
}

signed main(){_
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }

    return 0;
}
