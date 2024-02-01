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
// #define int long long // -> solução divina

using namespace std;

int W, H, x1, Y1, x2, Y2, w, h; 
int l, c;

signed main(){_

    int t;
    cin >> t;
    while(t--){
        cin >> W >> H;
        cin >> x1 >> Y1 >> x2 >> Y2;

        l = abs(x1-x2) + 1;
        c = abs(Y1-Y2) + 1;

        cin >> w >> h;

        if(l + w > W && c + h > H){
            cout << -1 << endl;
        } else {
            int dx, dY;
            if(l+w > W){
                dx = 0;
            } else {
                dx = max(0, w - max(x1-1, W-x2));
            }

            if(c+h > H){
                dY = 0;
            } else {
                dY = max(0, h - max(Y1-1, H-Y2));
            }

            if(dx!=0 and dY!=0){
                cout << fixed;
                cout << setprecision(7) <<  min(dx, dY);
            } else if(dx==0){
                cout << fixed;
                cout << setprecision(7) << dY << endl;
            } else {
                cout << fixed;
                cout << setprecision(7) << dx << endl;
            }

            // double resp = sqrt(dx*dx + dY*dY);

            // cout << resp << endl;
        }
    }

    return 0;
}
