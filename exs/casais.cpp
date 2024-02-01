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

int dp[1000007];

int MODN = 1000000007;

int func(int n){
    if (n==0) return 1;
    if (n==1) return 2;
    if (dp[n] >-1) return dp[n];
    ll ans = 0;
    ans = ((2LL*n)%MODN * func(n-1))%MODN;  
    ans = (ans + (((4*n*(n-1))%MODN) * func(n-2))%MODN )%MODN;
    dp[n] = ans;
    return ans;
}

int n;

int main(){_

    cin >> n;

    for (int i=n; i>=0; i--){
        dp[i] = -1;
    }

    cout << func(n) << endl;

    return 0;
}