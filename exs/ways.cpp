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

int n;
ll soma, parc, resp;
vi v, dp;

int main(){_

    cin >> n;
    v = vi(n+1);
    dp = vi(n+1);

    for (int i=1; i<=n; i++) {
        cin >> v[i];
        soma+=v[i];
    }

    if(soma%3){
        cout << 0 << endl;
        return 0;
    }

    soma/=3;

    for (int i=1; i<=n; i++){
        parc+=v[i];
        dp[i] = dp[i-1];
        if (parc==soma) dp[i]++;
    }

    parc=0;
    for (int i=n; i>=3; i--){
        parc+=v[i];
        if (parc==soma) {
            resp+=dp[i-2];
        }
    }

    cout << resp << endl;

    return 0;
}