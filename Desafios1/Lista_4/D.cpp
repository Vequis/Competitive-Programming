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

int a[10];

string memo[1123456];

bool amaiorqueb(string a, string b) {
    if (b == "-1") return true;
    if (sz(a) != sz(b)) return sz(a) > sz(b);

    for (int i = 0; i < sz(a); i++) {
        if (a[i] != b[i]) return a[i] > b[i];
    }

    return 1;
}

void solve() {
    int v;
    cin >> v;

    for (int i = 1; i <=9; i++) cin >> a[i];

    for (int i = 0; i <=v; i++) memo[i] = "-1";

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j<=9; j++) {
            if (i - a[j] >= 0) {
                if (memo[i - a[j]] != "-1") {
                    string s = memo[i - a[j]];
                    char c = (char)('0' + j);
                    s.pb(c); 
                    //cout << i << ' '<<  s << endl;
                    if (amaiorqueb(s, memo[i])) memo[i] = s;
                    //cout << memo[i] << endl;
                } else {
                    string s = "";
                    char c = (char)('0' + j);
                    s.pb(c); 
                    // cout << i << ' '<<  s << endl;
                    if (amaiorqueb(s, memo[i])) memo[i] = s;
                    // cout << memo[i] << endl;
                }
            }
        }
    }

    cout << memo[v] << endl;
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