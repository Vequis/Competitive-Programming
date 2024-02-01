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

    int n;
    cin >> n;

    int memo[2][2];

    memo[1][1] = 1;
    memo[0][1] = 0;


    for(int i = 2; i <= n; i++) {
        memo[0][0] = memo[0][1];
        memo[1][0] = memo[1][1];

        memo[0][1] = (3*memo[1][0])%MODN;
        memo[1][1] = (2*memo[1][0] + memo[0][0])%MODN;
    }

    cout << memo[0][1] << endl;

    return 0;
}
