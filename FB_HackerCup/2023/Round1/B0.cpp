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

int v[4123456];
//max:3188646

signed main(){_

    int memo[200];

    memset(memo, -1, sizeof(memo));
    memset(v, 0, sizeof(v));

    memo[1] = 1;
    memo[0] = 1;

    for(int i = 2; i <=41; i++) {

        int cur = -1;
        for(int j = 1; i - j >= 0; j++) {
            cur = max(cur, memo[i-j]*(j));
        }

        memo[i] = cur;
        cout << i << ' ' << memo[i] << endl;
    }

    return 0;
}
