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

    int t;
    cin >> t;

    while(t--) {
        string a, b;
        cin >> a >> b;

        bool resp = 0;

        for (int i = 0; i < sz(a) - 1; i++) {
            if (a[i] == '0' and b[i] == '0' and a[i+1] == '1' and b[i+1] == '1') {
                resp = 1;
                break;
            }
        }

        if(resp) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
