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

// a b c
// remove b if they are consecutive

int a[212345];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <=n; i++) cin >> a[i];
    a[n+1] = 0;

    int last_val = -10;
    int resp = 1;
    for (int i = 1; i <= n; i++) {
        if (i != 1 and a[i] > a[i-1] + 1) resp++;

        while(a[i] == a[i+1])i++;

        if (last_val == a[i] - 1 and a[i] + 1 == a[i+1]) {
            resp++;
            last_val = -1;
        } else {
            last_val = a[i];
        }
    }

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