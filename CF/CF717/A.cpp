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

int t, n, k, in;
vector<int> v;

int main(){_

    cin >> t;

    while(t--){
        cin >> n >> k;
        v = vi(n);
        for (int i=0; i<n; i++){
            cin >> v[i];
        }

        in = 0;

        for (int i=0; i<k; i++){
            while(v[in]==0){
                in++;
                if(in==n-1){break;}
            }
            if (in==n-1){
                break;
            }
            v[in]--;
            v[n-1]++;

        }

        for (int i=0; i<n; i++){
            cout << v[i];
            if(i!=n-1) cout << ' ';
        }
        cout << endl;

        v.clear();
    }

    return 0;
}