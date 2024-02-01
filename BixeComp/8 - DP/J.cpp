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

int acr[212345];
int a[212345];
int result[212345];
int n, m;

signed main(){_

    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> a[i];

    sort(a+1, a+1+n);

    for(int i=1; i<=m; i++){
        acr[i-1] = a[i];
        result[i] = result[i-1] + acr[i-1];
    }

    for(int i=m+1; i<=n; i++){
        acr[(i-1)%m]+=a[i];
        result[i] = result[i-1] + acr[(i-1)%m];
    }

    for(int i=1; i<=n; i++) cout << result[i] << ' ';
    cout << endl;

    return 0;
}
