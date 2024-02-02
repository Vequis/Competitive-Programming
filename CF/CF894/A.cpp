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
        int n, m;
        cin >> n >> m;

        string s[25];
        
        int cont[4];
        int resp = 0;

        for (int i = 0; i < 4; i++) cont[i] = 50;

        for (int i = 0; i < n; i++) cin >> s[i];

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (s[i][j] == 'v') {
                    cont[0] = min(cont[0], j);
                }
                
                if (s[i][j] == 'i' and cont[0] < j) {
                    cont[1] = min(cont[1], j);
                }
                if (s[i][j] == 'k' and cont[1] < j) {
                    cont[2] = min(cont[2], j);
                }
                if (s[i][j] == 'a' and cont[2] < j) {
                    cont[3] = min(cont[3], j);
                    resp = 1;
                }

            }
            // cout << cont[1] << endl;
        }

        if (resp) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
