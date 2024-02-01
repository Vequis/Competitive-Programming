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
        int m;
        cin >> m;

        string s;
        int tr_count = 0;

        for(int i = 0; i < n; i++) {
            cin >> s;

            for(char c: s) if (c=='^') tr_count++;
        }

        if ((n==1 or m==1) and tr_count > 0) {
            cout << "Impossible" << endl;
            continue;
        } else if (tr_count == 0) {
            cout << "Possible" << endl;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << '.';
                }
                cout << endl;
            }
        } else {
            cout << "Possible" << endl;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << '^';
                }
                cout << endl;
            }
        }




    }

    return 0;
}
