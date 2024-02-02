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

signed main(){_


    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    
    if ((ya == yb) and ((xa < xb and xc < xb) or (xa > xb and xc > xb))) {
        cout << abs(yc - yb) + abs(xc - xb) + 3 + abs(xb - xa) << endl;
    } else if ((xa == xb) and ((ya < yb and yc < yb) or (ya > yb and yc > yb))) {
        cout << abs(yc - yb) + abs(xc - xb) + 3 + abs(yb - ya) << endl;
    }
    else {
        int cnt = abs(xb - xc) + abs(yb - yc);
        if (xb != xc and yb != yc) cnt += 2;
        
        int var = 1000000000000000007;
        if (xb < xc) {
            var = min(var, abs(ya-yb) + abs(xb-1-xa));
        } else if (xb > xc) {
            var = min(var, abs(ya-yb) + abs(xb+1-xa));
        }

        
        if (yb < yc) {
            var = min(var, abs(xa-xb) + abs(yb-1-ya));
        } else if (yb > yc) {
            var = min(var, abs(xa-xb) + abs(yb+1-ya));
        }

        cout << cnt + var << endl;
    } 
    return 0;
}
