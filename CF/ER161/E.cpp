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

vi resp;

void solve() {
    int n;
    cin >> n;
    n--;
    resp.clear();

    int inicio = 21000;

    int pot = 2;
    int cont = 1;
    while (2*pot - 1 <= n) {
        pot *= 2;
        cont++;
    }

    while(n > 0) {

        while (n >= pot - 1) {
            n-= (pot - 1);
            // cout << pot-1 << endl;
            for(int i = 0; i < cont; i++) {
                resp.pb(inicio + i);
            }
            inicio -= 1000;
        }
        pot/=2;
        cont--;
    }

    cout << sz(resp) << endl;
    for (int x : resp) cout << x << ' ';
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
