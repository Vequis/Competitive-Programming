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
#define MODN 998244353
#define int long long // -> solução divina

using namespace std;

string s;

signed main(){_

    cin >> s;

    int potatual = 1;
    int resp1 = 0;
    int cor = 0;
    for(int i=sz(s) - 1; i>=0; i--){
        resp1 = (resp1 + (potatual * (s[i] - '0') )%MODN )%MODN;
        potatual = (potatual * 9)%MODN;
        if(i!=0) cor+=(potatual)%MODN;
    }
    if(s[0]!='1') resp1+=cor;

    cin >> s;

    potatual = 1;
    int resp2 = 0;
    cor = 0;
    for(int i=sz(s) - 1; i>=0; i--){
        resp2 = (resp2 + (potatual * (s[i] - '0') )%MODN )%MODN;
        potatual = (potatual * 9)%MODN;
        if(i!=0) cor+=(potatual)%MODN;
    }

    if(s[0]!='1') resp2+=cor;

    cout << resp2 << ' ' << resp1 << endl;

    return 0;
}
