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

int a[212345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;

        cin >> n;

        int maior = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            maior = max(maior, a[i]);
        }

        if (n == 1 or n >= 4) cout << n*maior << endl;
        else if (n==2) cout << max( 2*(a[0] - a[1]), max(a[0] + a[1], 2*(a[1] - a[0]))) << endl;
        else cout << 
            max(a[0] + a[1] + a[2], max(3*a[0], max(3*a[2], max(3*(a[1] - a[0]) ,max(3*(a[1] - a[2]), max(a[0] + 2*(a[1] - a[2]), a[2] + 2*(a[1] - a[0])))))))
             << endl;
    }

    return 0;
}
