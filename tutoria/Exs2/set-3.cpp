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

using namespace std;

string st;
int n;
set<string> especies;

int main(){_

    while(1){
        cin >> n;
        if (!n) break;

        for (int i=0; i<n; i++){
            cin >> st;
            sort(all(st));

            especies.insert(st);
        }

        cout << sz(especies) << endl;

        especies.clear();

    }

    return 0;
}