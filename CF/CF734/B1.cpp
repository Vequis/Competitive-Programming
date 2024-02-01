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

int t;
vi v;

signed main(){_

    cin >> t;
    while(t--){
        string s;
        cin >> s;

        v = vi(sz(s));

        for(int i=0; i<sz(s); i++){
            v[i] = (s[i] - 'a');
        }

        sort(all(v));

        int ant, contatual;

        ant = -1;
        int validos = 0;
        for(int i=0; i<sz(v); i++){
            if(v[i] == ant){
                contatual++;
            } else {
                contatual = 1;
            }
            ant = v[i];

            if(contatual > 2) continue;

            validos++;
        }

        cout << validos/2 << endl;

    }

    return 0;
}
