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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    set<int> cj_ca;
    set<int> cj_ba;
    set<int> cj_cb;
    set<int> cj_bc;
    int cnt = 0;
    while(m--) {
        cnt++;
        char a, b;
        cin >> a >> b;
        // f[{a, b}]++;

        if (a == 'c' and b == 'a') cj_ca.insert(cnt);
        if (a == 'b' and b == 'a') cj_ba.insert(cnt);
        if (a == 'b' and b == 'c') cj_bc.insert(cnt);
        if (a == 'c' and b == 'b') cj_cb.insert(cnt);
    }

    for (int i = 0; i<sz(s); i++) {
        char c = s[i];
        if (c == 'a') continue;

        if (c == 'b') {
            if (sz(cj_ba) > 0) {
                cj_ba.erase(cj_ba.begin());
                s[i] = 'a';
            } else if (sz(cj_bc) > 0) {
                int idx = *(cj_bc.begin());
                auto ptr = cj_ca.lower_bound(idx);

                if (ptr != cj_ca.end()) {
                    cj_bc.erase(cj_bc.begin());
                    cj_ca.erase(ptr);
                    s[i] = 'a';
                }
            }
        } else {
            if (sz(cj_ca) > 0) {
                cj_ca.erase(cj_ca.begin());
                s[i] = 'a';
            } else if (sz(cj_cb) > 0) {
                int idx = *(cj_cb.begin());
                cj_cb.erase(cj_cb.begin());
                s[i] = 'b';

                auto ptr = cj_ba.lower_bound(idx);
                if (ptr != cj_ba.end()) {
                    cj_ba.erase(ptr);
                    s[i] = 'a';
                }
            }
        }
    }


    cout << s << endl;
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

// aaaaaaaaaaaaaaabbbabcbabbbbabc
// aaaaaaaaaaaaaaabbbabcbabbbbabc