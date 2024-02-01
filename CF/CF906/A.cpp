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

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        map<int, int> f;

        int n;
        cin >> n;

        vi v;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;

            f[a]++;
            v.pb(a);
        }

        int deuruim = 0;
        if(sz(f) > 2) {
            cout << "No" << endl;
        } else {
            for(int x : v) {
                if (f[x] < n/2) {
                    cout << "No" << endl;
                    deuruim = 1;
                }
            }

            if (!deuruim) {
                cout << "Yes" << endl;
            }
        }
    }

    return 0;
}
