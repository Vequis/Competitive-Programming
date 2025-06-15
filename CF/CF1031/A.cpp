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
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    
    int aux = k;
    int conta=0;
    if (aux >= a) {
        conta += (aux-a)/x + 1;
        aux -= (conta) * x;
    }
    if (aux >= b) {
        conta += (aux-b)/y + 1;
    }
    
    int resp = conta;
    aux = k;
    conta=0;
    if (aux >= b) {
        conta += (aux-b)/y + 1;
        aux -= (conta) * y;
    }
    if (aux >= a) {
        conta += (aux-a)/x + 1;
    }
    
    
    resp = max(resp, conta);
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