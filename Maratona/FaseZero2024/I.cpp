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

int acabadoemx[1123456];
int colar[1123456];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i<=n*m; i++) {
        char c;
        cin >> c;

        colar[i] = (c=='1');
    }

    int soma = 0;
    for(int i = 1; i<=m-1; i++) soma += colar[i];

    colar[0] = 0;
    for (int i = m; i<=n*m; i++) {
        soma += colar[i] - colar[i-m];
        acabadoemx[i] = soma;
    }

    for (int i = 1; i<=m-1; i++) {
        soma += colar[i] - colar[(n-1)*m + i];
        acabadoemx[i] = soma;
    }

    for (int i = 1; i<=m; i++) {
        set<int> cj;
        for (int k = i; k<=n*m; k+=m) {
            cj.insert(acabadoemx[k]);
        }

        if (sz(cj) != n) {
            cout << 'N' << endl;
            return;
        }
        // cj.clear();
    }
    cout << 'S' << endl;

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