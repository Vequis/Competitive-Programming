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

    int cont = 0;

    while(t--) {
        cont++;
        cout << "Case #" << cont << ':' << ' ';

        int n;
        cin >> n;
        int k;
        cin >> k;

        map<int, int> f;

        bool deuruim = 0;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            f[a]++;

            if (f[a] > 2) deuruim = 1;
        }


        if (n > 2*k) {
            cout << "NO" << endl;
            continue;
        }
        
        if(deuruim) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        f.clear();
    }

    return 0;
}
