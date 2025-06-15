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
    // Não existe um mundo onde eu cconsiga 
    // inverter a ordem de um numero com
    // indice impar (ex: 3º com 2º)

    // 0-indexado - so da pra trocar par com o prox impar
    
    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = n%2; i < n; i+=2) {
        if (i!=n-1) {
            if (v[i] > v[i+1]) swap(v[i], v[i+1]);
        } 
    }

    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;


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