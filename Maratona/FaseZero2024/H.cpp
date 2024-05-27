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

bool ehprimo(int n) {
    if (n==1) return false;
    for (int i = 2; i*i<=n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    int x = (n)/2;
    int flag = 0;
    while(x > 0 and !flag) {
        if (!ehprimo(x) and !ehprimo(n-x) and x != n-x) {
            cout << x << ' ' << n-x << endl;
            return;
        }
        x--;
    }
    cout << -1 << endl;
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