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

map<string, string> idiomas;
int n,m;
string nome = "", pais;

int main(){_

    cin >> n;

    for (int i=0; i<n; i++){
        string p, trad = "";
        cin >> p;
        cin.ignore();
        getline(cin, trad);
        idiomas[p] = trad;
    }

    cin >> m;
    for (int i=0; i<m ; i++){
        cin.ignore();
        getline(cin, nome);
        cout << nome << endl;

        cin >> pais;
        cout << idiomas[pais] << endl;
        
        cout << endl;

        nome = "";
    }

    return 0;
}