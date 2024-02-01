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

    int d;
    cin >> d;

    bool cancel = 0;

    int respa = 0;
    int respb = 0;
    int minimo = INF;

    for(int i = 0; i < 1123456; i++) {
        if (cancel) break;
        if (i*i > d) cancel = 1;

        float yr = sqrt(d - i*i);
        // cout << d << ' ' << i << ' '<< yr << endl;

        int y = yr;
        if (abs(y*y + i*i - d) < minimo ) {
            minimo = abs(y*y + i*i - d);
            respa = i;
            respb = y;
        }

        y++;
        if (abs(y*y + i*i - d) < minimo ) {
            minimo = abs(y*y + i*i - d);
            respa = i;
            respb = y;
        }
    }

    // cout << respa << ' ' << respb << endl;
    cout << minimo << endl;

    return 0;
}
