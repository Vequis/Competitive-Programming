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

int maxv, maxc;
int contv, contc;
int cont[26];
int cnt;

signed main(){_

    int t;
    cin >> t;
    while(t--){
        string s;

        cin >> s;

        cnt++;
        maxv = maxc = 0;
        contv = contc = 0;

        for(int i=0; i<26; i++) cont[i] = 0;

        for(int i = 0; i<sz(s); i++){
            char c = s[i];
            cont[s[i] - 'A']++;

            if ( (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U') ){
                if(cont[s[i] - 'A'] > maxv) maxv = cont[s[i] - 'A'];
                contv++;
            } else {
                if(cont[s[i] - 'A'] > maxc) maxc = cont[s[i] - 'A'];
                contc++;
            }
        }

        cout << "Case #" << cnt << ": ";
        cout << min(contc + (contv - maxv)*2, contv + 2*(contc - maxc) ) << endl;
    }

    return 0;
}
