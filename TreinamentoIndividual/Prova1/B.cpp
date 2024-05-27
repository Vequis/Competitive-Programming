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

vector<string> news;
map<string, string> mp;

void solve() {
    int n;
    cin >> n;

    while(n--) {
        string s, t;
        cin >> s >> t;

        if (mp[s] == "") {
            mp[t] = s;
        } else {
            mp[t] = mp[s];
            mp[s] = "";
        }
    }

    vector<pair<string, string>> v;
    for (pair<string, string> p: mp) {
        if (p.sc != "") {
            v.eb(p);
        }
    }

    cout << sz(v) << endl;

    for (pair<string, string> p: v) {
        if (p.sc != "") {
            cout << p.sc << ' ' << p.fs << endl;
        }
    }

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