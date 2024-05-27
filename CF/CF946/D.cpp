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

    int dup = 0, dhor = 0;

    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') dup++;
        if (s[i] == 'S') dup--;
        if (s[i] == 'W') dhor++;
        if (s[i] == 'E') dhor--;
    }

    if (dhor % 2 or dup % 2) {
        cout << "NO" << endl;
        return;
    }

    int helup = 0, helhor = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'N' or s[i] == 'S') {
            if (helup == dup/2) {
                cout << 'R';
            } else {
                if (s[i] == 'N') helup++;
                else helup--;
                cout << 'H';
            }
        } else {
            if (helhor == dhor/2) {
                cout << 'R';
            } else {
                if (s[i] == 'W') helhor++;
                else helhor--;
                cout << 'H';
            }
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