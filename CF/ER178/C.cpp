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

// Se bob tem a carta N e mais de 1 carta -> Bob
// Se bob tem só 1 carta e é N -> Alice
// Se ALice tem a carta N e so 1 carta-> Bob
// Se Alice tem a carta N e a carta N-1 -> Alice
// Se aLice tem a carta 1 e a carta N -> Alice


void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = '$' + s;

    int qtdb = 0;
    for (int i = 1; i <=n; i++) qtdb = qtdb + (s[i] == 'B');
    int qtda = n - qtdb;

    if (s[n] == 'B') {
        cout << ((qtdb > 1) ? "Bob" : "Alice") << endl;
    } else {
        if (qtda == 1) cout << "Bob" << endl;
        else if (s[n-1] == 'A' or s[1] == 'A') cout << "Alice" << endl;
        else cout << "Bob" << endl;
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