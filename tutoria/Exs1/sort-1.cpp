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

int n,m;
vii tempos;
int num;

int main(){_

    cin >> n >> m;
    tempos = vii(n+1);

    for (int i=1; i<=n; i++){
        tempos[i] = {0, i};
        for (int j=1; j<=m; j++){
            cin >> num;
            tempos[i]= {tempos[i].first+num, tempos[i].second}; 
        }
    }

    sort(1+all(tempos));

    for (int i=1; i<=3; i++){
        cout << tempos[i].second << endl;
    }

    return 0;
}