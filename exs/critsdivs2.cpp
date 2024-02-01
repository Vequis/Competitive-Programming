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

int n, soma, ultimos;
int v[] = {4, 9, 25};
int u[3];
string s;

signed main(){_

    cin >> s;

    for(int i=0; i<sz(s); i++){
        soma+=(s[i] - '0');
    }

    ultimos = 10*(s[sz(s) - 1] - '0') + (s[sz(s) - 2] - '0');

    u[0] = ultimos;
    u[1] = soma;
    u[2] = ultimos;

    for(int i=0; i<3; i++){
        if(u[i]%v[i]){
            cout << "N" << endl;
        } else {
            cout << "S" << endl;
        }
    }

    return 0;
}
