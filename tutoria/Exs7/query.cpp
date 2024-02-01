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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int n, q; 

int psa[1010][1010];

int main(){_

    cin >> n >> q;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            char c;
            cin >> c;
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];

            if (c == '*'){
                psa[i][j] += 1;
            }
        }
    }

    for (int i=0; i<q; i++){
        int xa, xb, ya, yb;

        cin >> ya >> xa >> yb >> xb;

        // cout << psa[yb][xb] << ' ' << psa[yb][xa-1] << ' ' << psa[ya-1][xa] << ' ' << psa[ya-1][xa-1] << endl;

        cout << psa[yb][xb] - psa[yb][xa-1] - psa[ya-1][xb] + psa[ya-1][xa-1] << endl;
        // cout << endl;
    }

    return 0;
}