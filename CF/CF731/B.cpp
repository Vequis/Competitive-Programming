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

int q, ini, fim;
string s;

signed main(){_

    cin >> q;
    while(q--){
        cin >> s;

        int n = sz(s);

        ini = 0, fim=n-1;

        int cont=0;

        while(ini<=fim){
            cont++;
            if(s[ini] == ('a' + n - cont)){
                ini++;
            } else {
                if(s[fim] == ('a' + n - cont)){
                    fim--;
                } else {
                    break;
                }
            }
        }

        if(ini>fim) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
