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

signed main(){

    int n;
    int m;
    cin >> n >> m;

    vi v(n+5);
    int maxi = 0;
    int mini = 0;
    for(int i = 1; i <=n; i++) {
        cin >> v[i];
        maxi += v[i];
        mini = max(mini, v[i]);
    }

    maxi+= n-1;

    int ini = mini;
    int fim = maxi;

    while(ini < fim) {
        int mid = ini + (fim-ini)/2;

        // cout << ini << ' ' << mid << ' ' << fim << endl;

        int cur = 0;
        int cont = 1;
        int flag = 0;
        for(int i = 1; i <= n; i++) {
            // cout << cur << endl;
            if (cur != 0 and cur + 1 + v[i] > mid){
                cont++;
                cur = v[i];

                if(cont > m) break;
            } else {
                cur += (cur!=0) + v[i];
            }

            if (i==n) flag = 1;
        }

        if (flag) fim = mid;
        else ini = mid + 1;
    }

    cout << ini << endl;


    return 0;
}
