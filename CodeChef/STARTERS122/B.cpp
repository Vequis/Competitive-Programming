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

    int maximo = 0;
    // n+=5929;
    while((1<<maximo) <= n) maximo++;

    int cmp = 0;
    int resp = INF;
    for (int i = maximo - 1; i>=0; i--) {
        cmp += (1 << i);
        if (cmp >= n) {
            resp = min(resp, cmp - n);
        }
    }

    cout << resp << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
