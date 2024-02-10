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

    int t;
    cin >> t;

    while(t--) {

        int h, w, xa, ya, xb, yb;
        cin >> h >> w >> ya >> xa >> yb >> xb;

        if (ya > yb) {
            cout << "Draw" << endl;
            continue;
        } else if (ya == yb and xa != xb) {
            cout << "Draw" << endl;
            continue;
        }

        if ((yb - ya) % 2) {
            //Alice pode ganhar
            if (xa <= xb and (xb - xa) - 1<= max(0LL, abs(yb - ya)/2 - w + xb)) {
                cout << "Alice" << endl;
            } else if (xa > xb and (xa - xb) - 1 <= max(0LL, (yb - ya)/2 - xb + 1)){
                cout << "Alice" << endl;
            } else {
                cout << "Draw" << endl;
            }
        } else {
            //B pode ganhar
            if (xb <= xa and (xa - xb) <= max(0LL, abs(yb - ya)/2 - w + xa)) {
                cout << "Bob" << endl;
            } else if (xb > xa and (xb - xa) <= max(0LL, (yb - ya)/2 - xa + 1)){
                cout << "Bob" << endl;
            } else {
                cout << "Draw" << endl;
            }
        }


    }

    return 0;
}
