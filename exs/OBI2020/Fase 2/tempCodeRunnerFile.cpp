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

double vis[11234];
int a[11234];

signed main(){_

    int tam, n;
    cin >> tam >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    sort(a+1, a+n+1);
    vis[1] = a[1] + (a[2] - a[1])/2.0;
    vis[n] = tam - a[n] + (a[n] - a[n-1])/2.0;
    for(int i=2; i<n; i++){
        vis[i] = (a[i+1] - a[i-1])/2;
    }

    sort(vis+1, vis+n+1);

    cout << setprecision(2);
    cout << fixed << vis[1] << endl;

    return 0;
}
