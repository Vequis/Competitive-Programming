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

    int resp = 1;
    int cont = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            // cont = 1;
            resp += 1;
        } else {
            resp += i + 1;
        }

        // resp += cont;
    }

    cout << resp << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
