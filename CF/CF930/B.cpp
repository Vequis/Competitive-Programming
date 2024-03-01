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

map<string, int> f;

void solve() {

    int n;
    cin >> n;

    string s;

    cin >> s;
    // grid[0] = s;
    string pref;
    pref = s[0];
    for(int i = 1; i < n; i++) {
        pref = pref + s[i];
    }


    cin >> s;
    // grid[1] = s;
    string suff;
    suff = s[n-1];
    string minimo = (pref + s[n-1]);
    f[minimo]++;
    int cont = 1;
    for(int i = n-2; i >= 0; i--) {
        suff = s[i] + suff;
        pref.pop_back();

        if ((pref + suff) < minimo) {
            cont = 1;
            minimo = (pref + suff);
        } else if ((pref + suff) == minimo) cont++;
    }

    cout << minimo << endl;
    cout << cont << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
