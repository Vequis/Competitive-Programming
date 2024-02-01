#include <bits/stdc++.h>

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

using namespace std;

int n, m;
vi v;
int k,l;
int num;
map <int,int> f;

int main(){_

    while(cin >> n >> m){

        for (int i=0; i<n; i++){
            cin >> num;
            v.eb(num);
            f[num]++;
        }

        for (int i=0; i<m; i++){
            cin >> k >> l;

            if (k>n or f[l] < k) {
                cout << 0 << endl;
                continue;
            }

            for (int j=0; j<n; j++){
                if (v[j] == l){
                    k--;
                    if (!k) {
                        cout << j+1 << endl;
                        break;
                    }
                }

            }
        }
    }

   return 0;
}