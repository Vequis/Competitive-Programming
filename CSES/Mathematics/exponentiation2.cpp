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

int power(int a, int b, int m) {
    int resp = 1;
    int pot = a;

    while(b>0) {
        if (b & 1) resp = (resp*pot)%m;
        pot = (pot*pot)%m;
        b = (b>>1);
    }

    return resp;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << power(a, power(b, c, MODN-1), MODN) << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;

}
