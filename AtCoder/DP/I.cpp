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

#define double long double

double p[3123][3123];
int n;
double pl[3123];

signed main(){_

    cin >> n;
    for(int i = 1; i <=n; i++) cin >> pl[i];

    p[0][0] = 1;
    p[0][1] = 1;

    for(int i = 1; i <= n; i++) {
        
        p[i][0] = p[i-1][0]*(pl[i]);
        for(int j = 1; j <= i-1; j++) {
            p[i][j] = p[i-1][j]*(pl[i]) + p[i-1][j-1]*(1.0-pl[i]); 
        }
        p[i][i] = p[i-1][i-1]*(1.0 - pl[i]);
    }

    double resp = 0;
    for(int i = n/2 + 1; i<=n; i++) {
        resp+=p[n][i];
    }

    cout << fixed;
    cout << setprecision(12);
    cout << 1.0- resp << endl;

    return 0;
}
