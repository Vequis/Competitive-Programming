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

int v[4];
int time1, time2, resp = INT_MAX;

signed main(){_

    cin >> v[0];
    time1+=v[0];
    for(int i=1; i<4; i++){
        cin >> v[i];
        time2+=v[i];
    }

    for(int i=1; i<4; i++){
        time2-=v[i];
        time1+=v[i];
        resp = min(resp, abs(time2-time1));
        time2+=v[i];
        time1-=v[i];
    }

    cout << resp << endl;

    return 0;
}
