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

using namespace std;

vi dp;
int n, k, MODN = 998244353, a, b;
vi dist;

int main(){_

    cin >> n;
    cin >> k;

    dp = vi(n+1);

    for (int i=0; i<k; i++){
        cin >> a >> b;
        for (int j=a; j<=b; j++){
            dist.eb(j);
        }
    }

    sort(all(dist));

    dp[n] = 1;

    for (int i=1; i<=n-1; i++){
        for (int j=0; j<dist.size(); j++){
            if (i - dist[j] < 0) break;

            dp[n-i] = (dp[n-i] + dp[n - i + dist[j]])%MODN;
        }
    }

    cout << dp[1] << endl;

    return 0;
}