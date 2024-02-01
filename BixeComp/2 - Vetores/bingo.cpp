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

int n, b;
vi v;

int main(){_

    while (cin >> n >> b && (n!=0 && b!=0)){
        v = vi(n+1);

        for (int i=0; i<b; i++) {
            int num;
            cin >> num;
            v[num]=1;
        }

        if (!v[0]) {
            cout << "N" << endl;
            continue;
        }
        for (int i=1; i<=n; i++){
            if (!v[i]){
                bool ok = false;
                for (int j=i+1; j<=n; j++) {
                    if(v[j] && v[j-i]) ok = true;
                }
                if (!ok) {
                    cout << "N" << endl;
                    break;
                }
            }

            if (i==n) cout << "Y" << endl;
        }

        v.clear();
    }

    return 0;
}