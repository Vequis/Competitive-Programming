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

string s;

bool verify(int start) {
    if (start < 0) return false;
    if (start + 3 >= sz(s)) return false;

    if (s[start] == '1' and s[start+1] == '1' and s[start+2] == '0' and s[start+3] == '0') return true;
    return false;
}

void solve() {
    cin >> s;

    int cont = 0;

    for (int i = 0; i + 3 < sz(s); i++) {
        cont += verify(i);
    }
    int q;
    cin >> q;
    while(q--) {
        int pos, bit;
        cin >> pos >> bit;

        pos--;

        cont -= verify(pos) + verify(pos - 1) + verify(pos - 2) + verify(pos - 3);
        s[pos] = (char)('0' + bit);
        cont += verify(pos) + verify(pos - 1) + verify(pos - 2) + verify(pos - 3);

        cout << (cont > 0 ? "YES" : "NO" ) << endl;

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