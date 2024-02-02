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

signed main(){

    int t;
    cin >> t;

    while(t--) {_
        int n;
        cin >> n;

        vii ops;

        int cont = 0;

        int mask[4123];
        int charmask[4123];
        int lmask[4123];
        int rmask[4123];
        for (int i = 0; i < 4123; i++) {
            mask[i] = 0;
            charmask[i] = 0;
            lmask[i] = 0;
            rmask[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            // getline(cin, s);


            for (int j = 0; j < n; j++){
                char c;
                cin >> c;
                int bit = c - '0';
                charmask[j] = bit;
            }

            //desloca l e r
            for (int j = 0; j < n-1; j++) {
                lmask[j] = lmask[j+1];
            }
            lmask[n-1] = 0;
            for (int j = n-1; j > 0; j--) {
                rmask[j] = rmask[j-1];
            }
            rmask[0] = 0;

            for (int j = 0; j < n; j++) {
                mask[j] = mask[j] ^ lmask[j] ^ rmask[j];
                // cout << mask[i];
            }
            //mask xor l xor r

            for (int j = 0; j < n; j++) {
                int res = charmask[j] ^ mask[j];
                if (res) {
                    mask[j] ^= 1;
                    rmask[j] ^= 1;
                    lmask[j] ^= 1;
                    cont++;
                }
            }
            // cout << endl;
        }

        cout << cont << endl;
    }

    return 0;
}
