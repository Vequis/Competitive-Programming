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
#define MODN 998244353
#define int long long // -> solução divina

using namespace std;

map<int, int> f;
map<int, int> memo;

int inv(int n) {
    if (n <= 1) return n;
    return (MODN - (MODN/n)*inv(MODN%n)%MODN)%MODN;
}

void solve() {
    int n;
    cin >> n;

    int qtd = 0;
    int qtdinv2 = inv(n);
    qtdinv2 = (qtdinv2*qtdinv2)%MODN;

    while(n--) {
        int k;
        cin >> k;
        qtd+=k;
        int ki = k;
        while(k--) {
            int a;
            cin >> a;
            f[a]++;

            memo[a] = (memo[a] + inv(ki))%MODN;
        }
    }

    int resp = 0;
    for(ii p : f) {
        // int cur = memo;
        // cout << p.sc << ' ' << qtd;
        int cur = (p.sc * qtdinv2) %MODN;
        cur = (cur * memo[p.fs]) %MODN;
        resp = (resp + cur)%MODN;
    }

    // cout << inv(18) << endl;
    // cout << 7*inv(18) << endl;
    // cout << 7*inv(18)%MODN << endl;

    cout << resp << endl;

}

signed main(){_
    int t;
    // cin >> t;
    t = 1;

    while(t--) {
        solve();
    }

    return 0;
}
