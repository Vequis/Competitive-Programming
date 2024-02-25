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

int p[1123456];
int c[1123456];
map<int, int> f;

void solve() {
    int n, k;
    cin >> n >> k;
    

    for(int i = 0; i < n; i++) {
        cin >> p[i];
        // p[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
        // c[i] = i;       
    }

    for(int i = 0; i < n; i++) {
        c[i] += p[i];
        f[c[i]%k]++;
        if (f[c[i]%k] > 1 or c[i]%k > n-1) {
            cout << "N" << endl;
            return;
        }
    }

    cout << "S" << endl;
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
