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
    int n;
    cin >> n;
    
    map<int, int> f;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[x]++;
    }

    int sobra = 0;

    for (int i = 0; i < n; i++) {
        if (f[i] <= i) {
            if (sobra > 0 and f[i] > 0) {
                sobra--;
            } else {
                cout << i << endl;
                return;
            }
        } 
        if (f[i] - i - 1 > 0) {
            sobra = f[i] - i - 1;
        } else {
            sobra = 0;
        }
    }
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