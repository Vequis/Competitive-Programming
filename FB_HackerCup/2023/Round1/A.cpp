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

int l[112345];
int r[112345];

signed main(){_

    int t;
    cin >> t;

    int caseCont = 1;

    while(t--) {
        int n;
        cin >> n;

        vi v;
        for(int i=0; i<n; i++) {
            int num;
            cin >> num;
            v.eb(num);
        }

        sort(all(v));

        if (n%2 == 0) {
            cout << "Case #" << caseCont << ": ";
            cout << fixed;
            cout << setprecision(7);
            cout << (((v[n-1] + v[n-2]) - (v[0] + v[1]))/2.0) << endl;
            caseCont++;
        } else {
            l[1] = v[1] - v[0];
            for(int i = 3; i< n; i+=2) l[i] = max(l[i-2], (v[i] - v[i-1]));
            r[n] = 0;
            for(int i = n-2; i >= 0; i-=2) r[i] = max(r[i+2], (v[i+1] - v[i]));
        
            int minimo = INF;
            int pivomin = -1;
            for(int pivo = 1; pivo <=n-2; pivo+=2) {
                int cur = v[pivo + 1] - v[pivo - 1];
                if (pivo != 1) cur = max(cur, l[pivo-2]);
                if (pivo!=n-2) cur = max(cur, r[pivo+2]);


                // cout << pivo << ' '<< cur << endl;

                if (cur <= minimo and pivo!=n-2) {
                    minimo = cur;
                    pivomin = pivo;
                } else if (cur < minimo and pivo == n-2) {
                    minimo = cur;
                    pivomin = pivo;
                }
            }

            // cout <<pivomin << endl;
            cout << "Case #" << caseCont << ": ";
            cout << fixed;
            cout << setprecision(7);
            if (pivomin == 1) {
                cout << (((v[n-1] + v[n-2]) - (v[0] + v[2]))/2.0) << endl;
            } else if (pivomin == n-2) {
                cout << (((v[n-1] + v[n-3]) - (v[0] + v[1]))/2.0) << endl;
            } else {
                cout << (((v[n-1] + v[n-2]) - (v[0] + v[1]))/2.0) << endl;
            }
            caseCont++;
        }

        // cout << (cnt + mini)/2.0 << endl;
    }

    return 0;
}
