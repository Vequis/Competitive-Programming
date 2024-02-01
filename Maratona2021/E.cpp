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

int n;
int maxe = 0, maxd = 0;
int ptresq = 0, ptrdir = 0;
int te[112345], td[112345];
int tfim = 0;

signed main(){_

    cin >> n;

    for (int i = 0; i < n; i++) {
        int t, dir;
        cin >> t >> dir;

        if ( dir == 0 ){
            te[maxe] = t;
            maxe++;
        } else {
            td[maxd] = t;
            maxd++;
        }
    }

    int cont = 0;

    while (ptresq < maxe or ptrdir < maxd) {

        int mine, mind;
        
        if (ptresq >= maxe) mine = INT_MAX;
        else mine = te[ptresq];

        if (ptrdir >= maxd) mind = INT_MAX;
        else mind = td[ptrdir];
        
        // cout << mine << ' ' << mind << endl;
        // cout << tfim << endl;

        if (mine < mind) {
            tfim = max(te[ptresq], tfim) + 10;
            ptresq++;
            while (ptresq < maxe && te[ptresq] < tfim) {
                tfim = max(tfim - 10, te[ptresq]) + 10;
                ptresq++;
            }
        } else {
            tfim = max(td[ptrdir], tfim) + 10;
            ptrdir++;
            while (ptrdir < maxd && td[ptrdir] < tfim) {
                tfim = max(td[ptrdir], tfim - 10) + 10;
                ptrdir++;
            }
        }
    }

    cout << tfim << endl;

    return 0;
}
