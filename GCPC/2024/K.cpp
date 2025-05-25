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
    string s;
    cin >> s;

    string comm;
    cin >> comm;

    int hor = 0;
    int vert = 0;

    for (char c : comm) {
        if (c == 'h') hor = (hor + 1) % 2;
        if (c == 'v') vert = (vert + 1) % 2;
        if (c == 'r') {
            hor = (hor + 1) % 2;
            vert = (vert + 1) % 2;
        }
    }

    if (hor) {
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == 'b') s[i] = 'd';
            else if (s[i] == 'd') s[i] = 'b';
            else if (s[i] == 'p') s[i] = 'q';
            else if (s[i] == 'q') s[i] = 'p';
        }
    }

    if (vert) {
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == 'b') s[i] = 'p';
            else if (s[i] == 'p') s[i] = 'b';
            else if (s[i] == 'd') s[i] = 'q';
            else if (s[i] == 'q') s[i] = 'd';
        }
    }

    if (hor) {
        for (int i = sz(s) - 1; i>=0; i--) cout << s[i];
        cout << endl;
    } else cout << s << endl;
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