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

int part(int n, int max){
    if(n==0) return 1;
    if(max==1) return 1;
    if(n<0) return 0;

    // int resp = 0;
    // for(int i=1; i<=max; i++){
    //     resp+=part(n-i, i);
    // }

    // return resp;

    return part(n, max-1) + part(n-max, max);
}

signed main(){_

    int n, m;
    cin >> n >> m;
    cout << part(n,m) << endl;

    return 0;
}
