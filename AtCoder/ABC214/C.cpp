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

int v[2][212345];
int resp[212345];

signed main(){_

    int n;
    cin >> n;

    int minimo = INT_MAX;
    int indmin;

    for(int i=1; i<=n; i++){
        cin >> v[0][i];
    }

    for(int i=1; i<=n; i++){
        cin >> v[1][i];
        if(v[1][i] < minimo){
            minimo = v[1][i];
            indmin = i;
        }
    }

    resp[indmin] = v[1][indmin];

    for(int i=1; i<=n; i++){
        if(i!=1){
            if(resp[i-1]!=0){
                resp[i] = min(v[1][i], resp[i-1] + v[0][i-1]);
            }
        } else {
            if(resp[n] != 0){
                resp[i] = min(v[1][i], resp[n] + v[0][n]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(i!=1){
            if(resp[i-1]!=0){
                resp[i] = min(v[1][i], resp[i-1] + v[0][i-1]);
            }
        } else {
            if(resp[n] != 0){
                resp[i] = min(v[1][i], resp[n] + v[0][n]);
            }
        }
    }

    for(int i=1; i<=n; i++) cout << resp[i] << endl;

    return 0;
}
