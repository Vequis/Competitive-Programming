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
    
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {

        if (i+1 < n and s[i] > s[i+1]) {
            int idxmenor = i+1; // primeiro indice onde s[i] <= s[idx]
            while(idxmenor < n and s[i] >= s[idxmenor]) {
                idxmenor++;
            }

            for (int j = i+1; j<idxmenor; j++) cout << s[j];
            cout << s[i];
            for (int j = idxmenor; j<n; j++) cout << s[j];
            cout << endl;
            return;
        } else {
            cout << s[i];
        }
    }
    cout << endl;
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