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

using namespace std;

int dp[100010], n;

ll a, b, c, d, e;
int mult(int x, int y){
    d = x;
    e = y;
    int ans = (d*e)%MODN;
    return ans;
}

int f(int n){
    if (dp[n] != -1) return dp[n];
    int ans;
    a = f(n-1);
    b = f(n-2);
    c = f(n-3);
    ans = (mult(4, b))%MODN; 
    ans = (ans + a)%MODN ;
    ans = (ans + mult(2, c) )%MODN;
  
    dp[n] = ans;
    return dp[n];
}

int main(){_

    cin >> n;

    dp[0] = 1; dp[1] = 1; dp[2] = 5;

    for (int i=3; i<=n; i++){
        dp[i] = -1;
    }

    cout << f(n) << endl;

    return 0;
}