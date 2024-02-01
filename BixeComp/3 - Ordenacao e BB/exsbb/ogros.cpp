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
// #define int long long -> solução divina?

using namespace std;

int n,m;
vi v, val;

int bb(int x){
    int ini=0, fim = n-1, mid;
    while(ini<fim){
        mid = ini + (fim-ini)/2;
        if (v[mid]>x) fim = mid;
        else ini = mid+1;
    }
    return ini;
}

int main(){_

    cin >> n >> m;

    v = vi(n-1);
    for (int i=0; i<n-1; i++) cin >> v[i];

    val = vi(n);
    for (int i=0; i<n; i++) cin >> val[i];

    for (int i=0; i<m; i++){
        int num;
        cin >> num;
        cout << val[bb(num)] << ' ';
    }

    return 0;
}