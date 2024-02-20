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

vii queries;
set<int> sett;
int coords[612345];
int sweepadd[612345];
int sweepmin[612345];
map<int, int> id;

void solve() {

    int n;
    cin >> n;
    queries.clear();

    id.clear();
    sett.clear();

    for(int i = 1; i <=n; i++) {
        int a;
        cin >> a;
        queries.eb(a + 1, a+i);
        sett.insert(a+1);
        sett.insert(a+i);
    }

    int t = 1;
    for(int x : sett) {
        coords[t] = x;
        id[x] = t;
        sweepadd[t] = 0;
        sweepmin[t] = 0;
        t++;
    }

    for(ii p: queries) {
        sweepadd[id[p.sc]]++;

        sweepmin[id[p.fs]]++;
    }

    int falt = n;
    int cur = 0;
    int last = -1;
    int acum = 0;
    for(int i = t - 1; i>=1; i--) { 
        if (cur == 0 and sweepadd[i] > 0) last = coords[i];
        cur += sweepadd[i];

        cout << coords[i] << ' ' << cur << endl;

        acum += sweepmin[i];
        if (cur > 0 and cur - acum <= 0) {
            for(int j = last; j>=coords[i]; j--) {
                // cout << j << ' ';
                falt--;
                acum--;
                if (falt == 0) {
                    cout << endl;
                    return;
                }
                cur--;
                if (cur == 0) break;
            }
        }
    }
    cout << endl;
    // cout << 'f' << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
