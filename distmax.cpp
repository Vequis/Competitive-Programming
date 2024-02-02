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
#define int long long

using namespace std;

vii v;

signed main(){_

    int n;
    cin >> n;

    // int minx, maxx, miny, maxy;
    // cin >> minx >> maxx >> miny >> maxy;
    int minx = INT_MAX;
    int maxx= -1;
    int miny=INT_MAX;
    int maxy=-1;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.eb(x, y);
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    int resp = -1;

    vii pivos = {{minx, miny}, {minx, maxy}, {maxx, miny}, {maxx, maxy}};

    for(int c = 0; c < 4; c++) {

        int curmin = INT_MAX;
        int curmax = -1;
        for(int i = 0; i < n; i++) {
            int cur = abs(pivos[c].fs - v[i].fs) + abs(pivos[c].sc - v[i].sc);

            curmin = min(curmin, cur);
            curmax = max(curmax, cur);
        }

        // cout << curmax << ' ' << curmin << endl;

        resp = max(resp, curmax - curmin);

    }

    cout << resp << endl;


    return 0;
}
