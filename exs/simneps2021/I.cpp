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

int a[1123], b[1123];
int n, m;

int bb(int x){
    int ini = 1, fim = m+1, mid;
    while(ini<fim){
        mid = ini + (fim - ini)/2;
        if(b[mid] >= x) fim = mid;
        else ini = mid+1;
    }

    return ini;
}

signed main(){_

    cin >> n >> m;

    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];

    int pt1, pt2;

    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    int resp = 0;
    for(int i=1; i<=n; i++){
        resp+=m-(bb(a[i])-1);
    }

    cout << resp << endl;

    return 0;
}