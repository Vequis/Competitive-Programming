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

//dei uma roubadinha olhando o editorial
//pensar que o que multiplica é
//(i - l + 1)
int psa[112345][333];
int pasa[112345][333];

int a[112345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        int q;
        cin >> q;

        for(int i = 1; i <=n; i++) cin >> a[i];

        for (int d = 1; d<=320; d++) {
            for(int i = 1; i <= d; i++) {
                psa[i][d] = a[i];
                pasa[i][d] = a[i];
            }

            for(int i = d+1; i <=n; i++) {
                psa[i][d] = psa[i-d][d] + a[i];
                pasa[i][d] = pasa[i-d][d] + a[i]*((i-1)/d + 1);
            }
        }

        while(q--) {
            int s, d, k;
            cin >> s >> d >> k;
            if (d <= 320) {
                
                int resp = pasa[s + d*(k-1)][d];
                if (s - d > 0) {
                    resp -= pasa[s - d][d];
                    resp -= (psa[s + d*(k-1)][d] - psa[s - d][d]) * ((s-1)/d);
                }

                cout << resp << ' ';

            } else {
                int resp = 0;
                for(int i = 1; i <=k; i++) {
                    resp += a[s + (i-1)*d]*i;
                }

                cout << resp << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}
