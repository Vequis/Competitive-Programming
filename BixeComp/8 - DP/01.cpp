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

vi h;
int memo[112345];
int n, num;

int dp(int x){
    if(memo[x] != -1) return memo[x];

    memo[x] = min(dp(x-1) + abs(h[x] - h[x-1]), dp(x-2) + abs(h[x] - h[x-2]));
    return memo[x];
}

signed main(){_

    cin >> n;

    memset(memo, -1, sizeof(memo));

    h = vi(n+1);
    for(int i=1; i<=n; i++){
        cin >> num;
        h[i] = num;
    }


    memo[1] = 0;
    memo[2] = abs(h[2] - h[1]);
  
    cout << dp(n) << endl;

    return 0;
}
