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

int func_p(int n) {
    return n*(n+1)/2;
}

signed main(){

    int s0;
    
    int s[112345];
    s[0] = 290797;
    int dif[112345];

    int resp = 0;

    dif[0] = s[0];
    cout << s[0] << endl;
    for (int i = 1; i<=10; i++) {
        s[i] = (s[i-1] * s[i-1])%MODM;
        dif[i] = s[i] - s[i-1];
        
        int j = i - 1;
        while(dif[i] < 0) {
            int p = func_p(i - j);

            if (dif[j]*(i-j) > (abs(dif[i]))) {
                int d = i - j ;

                int q = abs(dif[i])/d;
                resp += d*q;

                int k = d - (dif[i]%d);
                resp += ((2*d - k + 1) * k) / 2;

                dif[j+k] = 1;
                dif[j] -= q + 1;
                
                
                dif[i] = 0;
            } else {
                resp += p * dif[j];
                dif[i] += (i-j)*dif[j];
                dif[j] = 0;
                j--;
                cout << '*' << resp << endl;
                cout << dif[i] << endl;
            }
        }

        cout << s[i] << ' ' << dif[i] << ' ' << resp << endl;
    }

    return 0;
}
