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

using namespace std;

int t, n;
int m, c;
vector<vector<int>> v;

int main(){_

    cin >> t; 

    for (int i = 0; i<t; i++){
        cin >> m >> c;
        v = vector< vector<int> >(m);

        for (int j=0; j<c; j++){
            int num;
            cin >> num;

            v[num%m].push_back(num);
        }
    
        for (int j=0; j<m; j++){
            cout << j << " -> ";
            for (int k=0; k<v[j].size(); k++){
                cout << v[j][k] << " -> ";
            }
            cout << "\\" << endl;
        }

        if (i!=t-1) cout << endl;
        v.clear();
    }

    return 0;
}