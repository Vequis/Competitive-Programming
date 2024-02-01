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
#define MODM 50515093
#define int long long // -> solução divina

using namespace std;

signed main(){

    int s[11234];
    int f[11234];
    int b[11234];
    s[0] = 290797;
    s[1] = 629527;
    f[0] = 290797;
    f[1] = 629527;
    b[0] = 0;
    b[1] = 0;


    for (int i = 1; i <= 10; i++) {
        s[i] = (s[i-1] * s[i-1])%MODM;

        if (f[i-1] > s[i]) {
            b[i] = b[i-1] + f[i] - 2*f[i-1] + f[i-2];
            f[i] = f[i-1] + s[i] - s[i-1];
        } else {
            f[i] = s[i];
            b[i] = b[i-1];
        }

        cout << s[i] << ' ' << f[i] << ' '  << b[i] << endl;
    }


    return 0;
}
