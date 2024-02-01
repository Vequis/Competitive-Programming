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

int n;
int dp[11][1010];
string s1;
int last[11];

signed main(){_

    cin >> n;
    cin >> s1;

    string s = "c" + s1;

    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++) last[j] = n+1;
        for(int j=n; j>=1; j--){
            if(dp[i-1][j+1] == dp[i][j+1] && s[j] != 'A' - 1 + i){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            if(s[j] < 'A' - 1 + i){
                // dp[i][j] = dp[i][j+1] * 2 + 1;
                dp[i][j] = (dp[i-1][j] - dp[i-1][last[ s[j] - 'A' + 1]]) + dp[i-1][j] + 2*dp[i][last[ s[j] - 'A' + 1]] + 1;
                last[ s[j] - 'A' + 1] = j;
            } else if (s[j] == 'A' - 1 + i){
                dp[i][j] = (dp[i-1][j] - dp[i-1][last[ s[j] - 'A' + 1]]) + dp[i-1][j] + 2*dp[i][last[ s[j] - 'A' + 1]] + 1;

                last[ s[j] - 'A' + 1] = j;
            } else {
                dp[i][j] = dp[i][j+1];
            }

        }

    }

    for(int i=1; i<=10; i++){
        for(int j=1; j<=n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
