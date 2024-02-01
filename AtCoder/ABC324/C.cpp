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

    int k;
    cin >> k;

    string tl;
    cin >> tl;

    vi resp;

    for(int i = 0; i < k; i++) {
        string s;
        cin >> s;

        if (s == tl) resp.eb(i + 1);
        else if (sz(s) == sz(tl) + 1) {
            int ptra, ptrb;
            ptra = 0;
            ptrb = 0;

            for(int j = 0; j < sz(tl); j++) {
                if (tl[ptra] == s[ptrb]) {
                    ptra++;
                    ptrb++;

                    
                } else {
                    ptrb++;
                    j--;
                }

                if (ptrb - ptra > 1) break;
                else if (j == sz(tl) - 1) resp.eb(i + 1);
            }
        } else if (sz(s) == sz(tl) - 1) {
            int ptra, ptrb;
            ptra = 0;
            ptrb = 0;

            for(int j = 0; j < sz(s); j++) {
                if (s[ptra] == tl[ptrb]) {
                    ptra++;
                    ptrb++;

                    
                } else {
                    ptrb++;
                    j--;
                }

                if (ptrb - ptra > 1) break;
                else if (j == sz(s) - 1) resp.eb(i + 1);
            }
        } else if (sz(s) == sz(tl)) {
            int ptra, ptrb;
            ptra = 0;
            ptrb = 0;
            int diff = 0;

            for(int j = 0; j < sz(tl); j++) {
                if (tl[ptra] == s[ptrb]) {
                    ptra++;
                    ptrb++;
                } else {
                    diff++;
                    ptra++;
                    ptrb++;
                }

                if (diff > 1) break;
                else if (j == sz(tl) - 1) resp.eb(i + 1);
            }
        } 


    }

    cout << sz(resp) << endl;
    for(int x : resp) cout << x << ' ';
    cout << endl;

    return 0;
}
