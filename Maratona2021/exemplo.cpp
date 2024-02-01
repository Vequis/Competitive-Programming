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

int dp(int n) {
    if ( n == 0) return 1;

    if (memo[n] != -1) return memo[n];

    if ( n == 1 && p[i] <= r) return dp(n+1) * (r - p[i] + 1);

    if (p[i] > p)
    return memo[n] = dp(n+1) * (p[i-1] - 
}

signed main(){_

    return 0;
}
