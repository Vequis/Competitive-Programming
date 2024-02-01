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

int a, b;
int optodos;
int resp;

signed main(){_

    int t;
    cin >> t;

    while(t--){
        cin >> a >> b;

        optodos = 0;

        if((a-1)%4 == 0) optodos = a-1;
        else if ((a-1)%4 == 1) optodos = 1;
        else if ((a-1)%4 == 2) optodos = a;
        else optodos = 0;

        resp = a;

        if(optodos == b){
            resp+=0;
        } else if((optodos ^ a) == b){
            resp += 2;
        } else if(optodos != b){
            resp += 1;
        }

        cout << resp << endl;
    }
    return 0;
}
