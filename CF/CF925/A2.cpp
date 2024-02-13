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

vector<string> v;
map<int, string> f;
void solve() {
    int n;
    cin >> n;

    cout << f[n] << endl;
}



signed main(){_

    int t;
    cin >> t;

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                char a = (char)((int)'a' + i);
                char b = (char)((int)'a' + j);
                char c = (char)((int)'a' + k);

                string s = "";
                s += a;
                s += b;
                s += c;
                // v.pb(s);
                if (f[i + j + k + 3] == "") f[i + j + k + 3] = s;

            }
        }
    }

    sort(all(v));

    while(t--) {
        solve();
    }
    return 0;
}
