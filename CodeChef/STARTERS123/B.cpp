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

int soma;
vi v;
int n, q;

void solvee(int x1) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j<n; j++) {
            if (2*soma - (v[i] + v[j]) == x1) {
                cout << v[i] << ' ';
                for(int k=0; k < n; k++) {
                    if (k!= i and k!=j) cout << v[k] << ' ';
                }
                cout << v[j] << endl;

                return;
            }
        }
        if (i == n-1) {
            cout << -1 << endl;
        }
    }
}

void solve() {

    cin >> n >> q;
    v.resize(n);
    soma = 0;
    f.clear();
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        soma +=v[i];
        f[v[i]]++;
    }

    while(q--) {
        int x, x1;
        cin >> x;
        x1 = x;
        // x-=soma;
        // if (x <= 0) {
        //     cout << -1 << endl;
        // }

        // x-=soma;
        // if (x >=0) {
        //     cout << -1 << endl;
        // }
        // int y = abs(x);

        solvee(x1);

    }


}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
