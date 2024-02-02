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

int memo[112345];
int psa[112345];

signed main(){_

    int n, k;
    cin >> n >> k;

    memo[0] = 1;
    psa[0] = 0;
    for (int i = 1; i <= 112345; i++) {
        if (i < k) memo[i] = memo[i-1];
        else memo[i] = (memo[i-1] + memo[i-k])%MODN;

        psa[i] = (psa[i-1] + memo[i])%MODN;
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        cout << (psa[b] - psa[a-1] + MODN)%MODN << endl;
    }

    return 0;
}
