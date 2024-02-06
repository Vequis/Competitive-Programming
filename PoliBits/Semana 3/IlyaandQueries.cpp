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

int psa[112345];

signed main(){_

    string s;
    cin >> s;

    psa[0] = 0;
    for (int i = 0; i < sz(s) - 1; i++) {
        if (s[i] == s[i+1]) {
            psa[i + 1] = psa[i] + 1;
        } else psa[i+1] = psa[i];
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << psa[r - 1] - psa[l-1] << endl;
    }

    return 0;
}
