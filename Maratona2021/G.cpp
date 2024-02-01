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

    // string s;
    // cin >> s;

    // int dp[212345];
    // dp[sz(s)] = 1;

    // for(int i = sz(s) - 1; i>=0; i--) {
    //     if (s[i] == 'B') dp[i] = dp[i+1];
    //     else dp[i] = dp[i+1] + dp[i+2];
    // }

    // cout << dp[0] << endl;

    int n;
    cin >> n;

    int fib[2134];

    fib[0] = 0;
    fib[1] = 1;

    int ptr = 1;
    while(fib[ptr] <= n) {
        ptr++;
        fib[ptr] = fib[ptr-1] + fib[ptr-2];
    }

    // cout << ptr << endl;
    // cout << fib[ptr] << endl;

    int num = n;

    if(num == 1) {
        cout << "B" << endl;
        return 0;
    }

    string resp = "";

    for(int i = ptr-1; i>=3; i--) {
        while(num%fib[i] == 0) {
            string aux = "";
            for (int j = 0; j < i-2; j++) aux = aux + "A";
            aux = aux + "B";

            resp = resp + aux;

            num/=fib[i];

            // cout << num << ' ' << fib[i] << endl;
        }
    }

    if (num != 1) cout << "IMPOSSIBLE" << endl;
    else cout << resp << endl;

    return 0;
}
