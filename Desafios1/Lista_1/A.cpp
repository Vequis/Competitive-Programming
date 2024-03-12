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

vector<int> v;

int bb(int n) {
    int ini = 0, fim = sz(v), mid;

    while(ini < fim) {
        mid = ini + (fim - ini)/2;
        if (v[mid] > n) fim = mid;
        else ini = mid + 1;
    }

    return ini;
}

void solve() {
    int n;
    cin >> n;

    v = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(all(v));

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;
        cout << bb(x) << endl;
    }
}

signed main(){_
    int t;
    //cin >> t;
    t= 1;

    while(t--) {
        solve();
    }

    return 0;
}
