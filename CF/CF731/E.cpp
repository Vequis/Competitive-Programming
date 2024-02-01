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

int q;
int t[312345];
int ar[312345];
int pos[312345];
int n, k, cnt;

signed main(){_

    cin >> q;

    q++;
    while((q--)>=2){
        cin >> n >> k;

        for(int i=0; i<k; i++){
            int num;
            cin >> num;
            pos[i] = num;
        }

        for(int i=0; i<k; i++){
            int num;
            cin >> num;
            t[pos[i]] = num;
            ar[pos[i]] = q;
        }

        t[0] = INT_MAX;
        for(int i=1; i<=n; i++){
            if(ar[i] == q) {
                t[i] = min(t[i], t[i-1] + 1);
                continue;
            }

            t[i] = t[i-1] + 1;
        }

        t[n+1] = INT_MAX;
        for(int i=n; i>=1; i--){
            t[i] = min(t[i], t[i+1] + 1);
        }

        for(int i=1; i<=n; i++){
            cout << t[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
