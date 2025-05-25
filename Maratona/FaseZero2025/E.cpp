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
    int n, k;
    cin >> n >> k;

    // int ninit = n;

    vi divs;

    if (n == 1) {
        cout << k + 1 << endl;
        return;
    }

    if (k == 1) {
        cout << 2 << endl;
        return;
    }

    for (int i = 2; i*i<=n; i++) {
        while(n%i == 0) {
            divs.pb(i);
            n/=i;
        }
    }   

    if (n != 1) divs.pb(n);

    int resp = 1;

    int index = 0;
    int p = divs[0];

    while(k > 0) {
        if (index < sz(divs)) p = divs[index];
        else {
            resp = resp + resp*k;
            k = 0;
        }

        if (k >= p - 1){
            resp = resp * p;
            k -= (p-1);
            index++;
        } else {
            resp = resp * (k + 1);
            k = 0;
        }
    }

    cout << resp << endl;

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