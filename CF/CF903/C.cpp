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

string grid[1123];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) cin >> grid[i];

        int resp = 0; 
        for(int i = 0; i < n/2; i++) {
            
            for (int j = 0; j < n/2; j++) {
                int maximo = -1;
                int a, b;
                a = i; b = j;
                maximo = max(maximo, (int)(grid[a][b] - 'a'));
                a = n-1-j; b = i;
                maximo = max(maximo, (int)(grid[a][b] - 'a'));
                a = n-1-i; b = n-1-j;
                maximo = max(maximo, (int)(grid[a][b] - 'a'));
                a = j; b = n-1-i;
                maximo = max(maximo, (int)(grid[a][b] - 'a'));


                a = i; b = j;
                resp += maximo - (grid[a][b] - 'a');
                a = n-1-j; b = i;
                resp += maximo - (grid[a][b] - 'a');
                a = n-1-i; b = n-1-j;
                resp += maximo - (grid[a][b] - 'a');
                a = j; b = n-1-i;
                resp += maximo - (grid[a][b] - 'a');

                // cout << resp << endl;
            }
        }

        cout << resp << endl;
    }

    return 0;
}
