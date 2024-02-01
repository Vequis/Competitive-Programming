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

int result[2][2];
//  atual-0  atual-1 
//  ant-0    ant-1

signed main(){_

    cin >> n;

    result[0][0] = 1;
    result[0][1] = 0;

    for(int i=1; i<=n; i++){
        result[1][0] = ((result[0][1]+result[0][1])%MODN + result[0][1])%MODN;
        result[1][1] = (result[0][0] + (2*result[0][1])%MODN)%MODN;

        result[0][0] = result[1][0];
        result[0][1] = result[1][1];
    }

    cout << result[1][0] << endl;

    return 0;
}