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
#define int long long

using namespace std;

signed main(){_

    int t;
    cin >> t;
    while(t--) {
        int n;
        int k;
        cin >> n >> k;
        string s;
        cin >> s;

        vi pares;
        vi impares;
        vi v;
        for (char c : s) v.pb(c-'a');


        if (k%2) {
            for (int i = 0; i < n; i++) {
                if (i%2) {
                    impares.pb(v[i]);
                } else {
                    pares.pb(v[i]);
                }
            }
            sort(all(pares));
            sort(all(impares));
            for (int i = 0; i < n; i++) {
                if (i%2) {
                    cout << (char)('a' + impares[i/2]);
                } else {
                    cout << (char)('a' + pares[i/2]);
                }
            }
            cout << endl;
        } else {
            sort(all(v));
            for (int i = 0; i < n - k + 1; i++) {
                cout << (char)('a' + v[i]);
            }

            for (int i = n-k+1; i < n; i++) {
                if (i%2) {
                    impares.pb(v[i]);
                } else {
                    pares.pb(v[i]);
                }
            }

            sort(all(pares));
            sort(all(impares));
            // cout << endl;
            // cout << '*' << sz(pares) << ' ' << sz(impares) << endl;
            for (int i = n-k+1; i < n; i++) {
                int x = i - n + k - 1;

                if (i%2) {
                    // cout << impares[x/2] << endl;
                    cout << (char)('a' + impares[(x)/2]);
                } else {
                    // cout << pares[x/2] << endl;
                    cout << (char)('a' + pares[x/2]);
                }
            }
            cout << endl;
        }
    }

    return 0;
}
