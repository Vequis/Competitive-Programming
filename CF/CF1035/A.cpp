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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

void solve() {
    int a, b, x, y;
    cin >> a >> b>> x >> y;
    
    if (b < a-1) {
        cout << -1 << endl;
        return;
    }
    if (b == a-1 and a%2) {
        cout << y << endl;
        return;
    } else if (b==a-1 and a%2 == 0) {
        cout << -1 << endl;
        return;
    }

    if (a == b) {
        cout << 0 << endl;
        return;
    }

    int delta = b-a;
    int pares = (b-1)/2 - (a-1)/2 ;
    delta-=pares;

    // cout << delta << ' ' << pares << endl;

    cout << delta * x + pares * min(x, y) << endl;
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