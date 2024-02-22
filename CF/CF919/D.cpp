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

set<int> indices;
map<int, int> val;

int find(int n) { // Elemento menor ou igual a n no set
    auto it = indices.lower_bound(n);
    if (it == indices.end()) it--;
    else if ((*it) != n) it--;

    return (*it);
}

void solve() {
    indices.clear();
    val.clear();

    int n, q;
    cin >> n >> q;

    int limite = 1e18;

    int tam = 0;
    while(n--) {
        int op, x;
        cin >> op >> x;

        if (op == 1) {
            tam++;
            val[tam] = x;
            indices.insert(tam);
        } else {
            if (tam > limite/(x+1)) tam = limite + 1;
            else tam = tam*(x + 1);   
        }
    }

    while(q--) {
        int x;
        cin >> x;

        while(1) {
            int f = find(x);
            // cout << '*' << f << ' ' << x << endl;
            x = x%f;
            if (x == 0) {
                cout << val[f] << ' ';
                break;
            }
        }
    }
    cout << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
