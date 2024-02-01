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

ll v[1123456];
ll psa[1123456];
int t, n;
ll  menor = MODN, maior = INT_MIN;

int main(){_

    cin >> t;
    while(t--){
        cin >> n;
        psa[0] = 0;
        
        menor = 0;
        ll resp = 0;
        ll contmin=1;
        maior = INT_MIN;
        for (int i=1; i<=n; i++){
            cin >> v[i];
            psa[i] = psa[i-1] + v[i];

            if (psa[i] - menor > maior){
                resp=0;
                maior = psa[i] - menor;
            } 
            if (psa[i]-menor == maior) resp+=contmin;

            if (psa[i] == menor) contmin++;
            if (psa[i] < menor) {
                menor= psa[i];
                contmin=1;
            }

            // cout << i << ' ' << psa[i] << ' ' << maior << ' ' << endl;
        }

        cout << maior << ' ' << resp << endl;
    }

    return 0;
}