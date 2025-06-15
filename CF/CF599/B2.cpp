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
    int n;
    cin >> n;
    
    string s, t;
    cin >> s;
    cin >> t;

    vii trocas;

    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;

        for (int j = i+1; j<n; j++) {
            if (s[i] == s[j]) {
                swap(s[j], t[i]);
                trocas.eb(j + 1, i+1);
                break;
            } else if (s[i] == t[j]) {
                swap(s[i], t[i]);
                trocas.eb(i+1, i+1);
                swap(s[i], t[j]);
                trocas.eb(i + 1, j+1);
                break;
            }
        }
        if (s[i] != t[i]) {
            cout << "No" << endl;
            return;
        } 
    }

    cout << "Yes" << endl;
    cout << sz(trocas) << endl;
    for (ii p : trocas) {
        cout << p.fs << ' ' << p.sc << endl;
    }

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