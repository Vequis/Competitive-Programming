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

vi a;

signed main(){_

    int t, n;

    cin >> t;

    while(t--){
        cin >> n;

        a = vi(n);

        for(int i = 0; i<n; i++){
            cin >> a[i];
        }

        for(int i = 1; i<n; i++){
            a[i] = a[i] & a[i-1];
            a[i-1] = a[i] & a[i-1];
        }

        for(int i=n-2; i>=0; i--){
            a[i] = a[i] & a[i+1];
            a[i+1] = a[i] & a[i+1];
        }

        sort(all(a));

        cout << a[n-1] << endl;
    }

    return 0;
}
