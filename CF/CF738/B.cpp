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

signed main(){_

    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        string s;
        cin >> s;

        int primeiro = -1;

        int alterna;
        for(int i=0; i<n; i++){
            if(s[i] != '?' && primeiro == -1) {
                primeiro = i;

            }

            if(s[i] == '?' && primeiro != -1){
                if(alterna==1) {
                    s[i] = 'R';
                } else {
                    s[i] = 'B';
                }

                alterna = alterna^1;
            } else if(s[i] == 'B') {
                alterna = 1;
            } else {
                alterna = 0;
            }
        }

        if(primeiro!=-1){

            if(s[primeiro] == 'B') alterna = 1;
            else alterna = 0;
        } else {
            primeiro = n;
        }

        for(int i=primeiro-1; i>=0; i--){
            if(alterna) s[i] = 'R';
            else s[i] = 'B';

            alterna = alterna^1;
        }

        cout << s << endl;
    }

    return 0;
}
