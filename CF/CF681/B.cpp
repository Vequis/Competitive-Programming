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

using namespace std;

int a,b, n, t, ant = -1, tam, cont, ans;
string s;

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){
        cin >> a >> b;
        cin >> s;
        ans = a;
        for (int i=0; i<sz(s); i++){
            if (s[i] == '1'){
                if (ant != -1){
                    cont=min(a,(i-ant+1)*b);
                } else {
                    cont = a;
                }
                ans+=cont;

                cout << i << ' ' << cont << endl;

                ant = i;
                while(s[ant]=='1' and ant<n){
                    ant++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}