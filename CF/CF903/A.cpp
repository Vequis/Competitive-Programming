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
        int n;
        cin >> n;
        int m;
        cin >> m;

        string x, s;
        cin >> x;
        cin >> s;

        int ptr = 0;

        int cont = 0;

        int resp = -1;
        for(ptr = 0; ptr < n; ptr++) {

            for(int i = 0; i < m; i++) {
                int ptrr = ptr + i;
                if (s[i] != x[(i + ptr)%n]) {
                    break;
                }

                if (i == m - 1) {
                    resp = (ptr + i)/n;
                }   


            }

            if (resp != -1) break;
        }

        int pot = 0;
        while((1<<pot) <= resp) {
            pot++;
        }

        if (resp == -1) {
            cout << -1 << endl;
        } else if (resp == 0) {
            cout << 0 << endl;
        } else {
            cout << pot << endl;

        }

    }

    return 0;
}
