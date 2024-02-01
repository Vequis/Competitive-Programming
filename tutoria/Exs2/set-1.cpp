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

set<string> lista;
set<string> :: iterator it;
int n;
string aux, item = "";

int main(){_

    cin >> n;
    cin.ignore();

    while(n--){
        getline(cin, aux);
        for (int i=0; i<sz(aux); i++){
            if(aux[i] == ' '){
                lista.insert(item);
                item = "";
            } else {
                item+=aux[i];
            }
        }

        lista.insert(item);
        item = "";

        cout << (*lista.begin());
        lista.erase(*lista.begin());

        for (it = lista.begin(); it!=lista.end(); it++){
            cout << " " << (*it);
        }

        lista.clear();
        
        cout << endl;
    }

    return 0;
}