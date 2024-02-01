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

set<int> cartas1;
set<int> cartas2;

int n, m, siz;

int main(){_

    cin >> n >> m;

    while(n!=0 and m!=0){
        for (int i=0; i<n; i++){
            int carta;
            cin >> carta;
            cartas1.insert(carta);
        }

        siz = sz(cartas1);

        for (int i=0; i<m; i++){
            int carta;
            cin >> carta;
            cartas1.insert(carta);
            cartas2.insert(carta);
        }

        cout << min( sz(cartas1) - siz, sz(cartas1) - sz(cartas2) ) << endl;
 
        cin >> n >> m;

        cartas1.clear();
        cartas2.clear();
    }

    return 0;
}