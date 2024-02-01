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
        int n, m;
        cin >> n >> m;

        if(m==1) {
            cout << 0 << endl;
        } else if (n >= m) {
            cout << m << endl;
        } else {
            cout << n+1 << endl;
        }

        for(int i = 0; i < min(m-1, n); i++) {
            int itr = i;
            for(int j = 0; j < m; j++) {
                cout << itr << ' ';
                itr = (itr + 1)%m;
            }
            cout << endl;
        }

        for(int i = m-1; i < n; i++) {
            for(int j = 0; j < m; j++) cout << j << ' ';
            cout << endl;
        }
    }

    return 0;
}
