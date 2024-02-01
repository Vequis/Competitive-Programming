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

map<string, int> m;
map<string, int>:: iterator it;

string assassino, vitima;

int main(){_

    while (cin >> assassino >> vitima){
        if (m[assassino]!=-1) m[assassino]++;
        m[vitima] = -1;
    }

    cout << "HALL OF MURDERERS" << endl;
    for (it = m.begin(); it!=m.end(); it++){
        if (it->sc!= -1) { 
            cout << it->fs << " " << it->sc << endl;
        }
    }

    return 0;
}