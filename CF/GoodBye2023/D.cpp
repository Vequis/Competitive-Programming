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

map<vi, int> f;

void solve() {
    int n;
    cin >> n;

    if (n==1) {
        cout << 1 << endl;
        return;
    }

    vector<string> resp;
    resp.pb("169");
    resp.pb("196");
    resp.pb("961");
    for (int i = 5; i<=n; i+=2) {
        for (int j = 0; j < sz(resp); j++) {
            resp[j] = resp[j] + "00";
        }

        string s = "1";
        for (int j = 1; j < i-1; j++) {
            // s = s + "0";
            if (j == i/2) s = s + "6"; 
            else s = s + "0";
        }
        s = s + "9";
        resp.pb(s);

        s = "9";
        for (int j = 1; j < i-1; j++) {
            // s = s + "0";
            if (j == i/2) s = s + "6"; 
            else s = s + "0";
        }
        s = s + "1";
        resp.pb(s);
    }

    for (string s:resp) cout << s << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
