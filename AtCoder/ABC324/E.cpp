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

string v[512345];

map<int, int> pref;
map<int, int> suff;
int prefmax[512345];

signed main(){_

    int n;
    cin >> n;

    string t;
    cin >> t;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v[i + 1] = s;
    }

    for(int i = 1; i <= n; i++) {
        int ptrt = 0;
        int ptrs = 0;

        prefmax[i] = 0;
        for(int j = 0;j < sz(v[i]); j++) {
            if (ptrt < sz(t) and v[i][j] == t[ptrt]) {
                prefmax[i]++;
                ptrt++;
            }
        }

        ptrt = sz(t) - 1;
        int cont = 0;
        suff[0]++;
        for(int j = sz(v[i]) - 1; j>= 0; j--) {
            if (ptrt >= 0 and v[i][j] == t[ptrt]) {
                cont++;
                suff[cont]++;
                ptrt--;
            }
        }


    }
    
    // for(int i = 0; i <= sz(t); i++) cout << suff[i] << endl;
    // for(int i = 1; i<= n; i++) cout << prefmax[i] << endl;

    int resp = 0;
    for(int i = 1; i <= n; i++) {
        resp += suff[(int)(sz(t)) - prefmax[i]];
    }

    cout << resp << endl;

    // cout << t.substr(0, 3) << endl;
    // cout << t.substr(1, 1 + 3) << endl;

    return 0;
}
