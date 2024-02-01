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

int v[112345];
signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int last = 1;

        int resp = 0;

        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
        for(int i = 1; i <= n; i++) {
            int a;
            cin >> a;

            int pot = 1;
            int cont = 0;
            while(a*pot < last) {
                pot *= 2;
                cont++;
            }

            if (last < a and i!= 1) {
                pot = 1;
                while(last*pot <= a) {
                    pot *= 2;
                    cont++;
                }
                if (i != 2) {
                    v[i] = max(0LL, v[i-1] - cont + 1);
                    // if (last*pot != a) v[i]++;
                }
            } else {
                v[i] = v[i-1] + cont;
            }

            resp += v[i];
            // cout << i << ' ' << v[i] << endl;
            last = a;
        }

        cout << resp << endl;
    }

    return 0;
}
