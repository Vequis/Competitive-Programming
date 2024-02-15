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

vi primos;
int vis[412345];

void crivo(int n) {
    primos.pb(2);
    for(int i = 3; i <=n; i+=2) {
        if (!vis[i]) {
            primos.pb(i);
            for(int j = i*i; j<=n; j+=i) vis[j] = 1;
        }
    }
}

void solve(){
    int n;
    cin >> n;

    if (n%2 == 1) {
        cout << 1 << ' ';
        n--;
    }

    for(int i = 0; n > 0; i++) {
        cout << primos[i] << ' ' << primos[i] << ' ';
        n-=2;
    }
    cout << endl;
}

signed main(){_
    int t;
    cin >> t;

    crivo(212345);
    // cout << sz(primos) << endl;

    while(t--) {
        solve();
    }

    return 0;
}
