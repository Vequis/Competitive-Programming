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

int v[212345];
int psa[212345];
ii dpprefix[212345];
ii dpsuffix[212345];

signed main(){_

    int n, k;
    cin >> n >> k;

    int a, b;

    psa[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        psa[i] = psa[i-1] + v[i];
    }

    dpprefix[k-1] = {0,0};
    for(int i = k; i <=n; i++) {
        if (psa[i] - psa[i-k] > dpprefix[i-1].fs) {
            dpprefix[i] = {psa[i] - psa[i-k], i};
        } else {
            dpprefix[i] = dpprefix[i-1];
        }
    }

    dpsuffix[n - k + 1] = {0, 0};
    for(int i = n-k; i >= 1; i--) {
        if (psa[i] - psa[i-k] > dpsuffix[i+1].fs) {
            dpsuffix[i] = {psa[i] - psa[i-k], i};
        } else {
            dpsuffix[i] = dpsuffix[i+1];
        }
    }

    int mid = -1;
    int maior = -1;
    for (int i = 1; i < n; i++) {
        int cur = dpprefix[i].fs + dpsuffix[i+1].fs;
        if ( cur > maior ) {
            mid = i;
            maior = cur;
        }
    }

    cout << dpprefix[mid].sc << ' ' << dpsuffix[mid].sc << endl;

    return 0;
}
