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

bool confere(string s, int k) {
    for (int i = 0; i < k; i++) {
        if (i != 0 and s[i] != s[i-1]) return false;
    }

    for (int i = k; i<sz(s); i++) {
        if (s[i] == s[i-k]) return false;
    }

    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if (confere(s, k)) {
        cout << n << endl;
        return;
    }

    int actualcont = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 or s[i] == s[i-1]) {
            actualcont++;
            // if (actualcont > k) {
            //     string a = s.substr(0, i +1-k);
            //     reverse(all(a));
            //     string b = s.substr(i+1-k, n - i-1 + k);

            //     cout << a << ' ' << b << endl;
            //     string sc = b + a;

            //     if (confere(sc, k)) {
            //         cout << i+1-k << endl;
            //         return;
            //     } else {
            //         cout << -1 << endl;
            //         return;
            //     }
            // }
        } else {
            if (actualcont < k) {
                string a = s.substr(0, i);
                reverse(all(a));
                string b = s.substr(i, n - i);
                // cout << a << ' ' << b << endl;
                string sc = b + a;

                if (confere(sc, k)) {
                    cout << i << endl;
                    return;
                } else {
                    cout << -1 << endl;
                    return;
                }
            } else if (actualcont > k) {
                string a = s.substr(0, i-k);
                reverse(all(a));
                string b = s.substr(i-k, n - i + k);

                // cout << a << ' ' << b << endl;
                string sc = b + a;

                if (confere(sc, k)) {
                    cout << i-k << endl;
                    return;
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
            actualcont = 1;
        }

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