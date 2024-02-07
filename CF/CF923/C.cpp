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

int a[212345];
int b[212345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        map<int, int> fa;
        map<int, int> fb;

        set<int> cj;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];

            if (a[i] <= k) {
                fa[a[i]]++;
                cj.insert(a[i]);
            }
        }

        for(int i = 1; i <= m; i++) {
            cin >> b[i];

            if (b[i] <= k) {
                fb[b[i]]++;
                cj.insert(b[i]);
            }
        }

        if (sz(cj) == k and sz(fa) + sz(fb) >= k and sz(fa) >= k/2 and sz(fb) >= k/2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
