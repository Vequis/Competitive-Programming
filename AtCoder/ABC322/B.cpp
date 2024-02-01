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

signed main(){_

    int suff = 0, pref = 0;

    string itr;

    int n, m;
    cin >> n >> m;

    string mask;
    cin >> mask;
    string s;
    cin >> s;


    for(int i = 0; i < n; i++) {
        itr.pb(s[i]);
    }

    if (itr == mask) pref = 1;

    itr = "";
    for(int i = m-n; i < m; i++) {
        itr.pb(s[i]);
    }

    if (itr == mask) suff = 1;

    if (suff and pref) {
        cout << '0' << endl;
    } else if (pref) {
        cout << '1' << endl;
    } else if (suff) {
        cout << '2' << endl;
    } else {
        cout << '3' << endl;
    }

    return 0;
}
