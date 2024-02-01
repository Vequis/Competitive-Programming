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

queue<int> fila;
int n;

int main(){_

    cin >> n;

    while(n!=0){
        for (int i=1; i<=n; i++){
            fila.push(i);
        }

        cout << "Discarded cards:";
        while(sz(fila)> 1){            

            cout << " " << fila.front();
            if (sz(fila) > 2) cout << ","; 

            fila.pop();
            fila.push(fila.front());
            fila.pop();

        }
        cout << endl;

        cout << "Remaining card: " << fila.front() << endl;;
        fila.pop();

        cin >> n;
    }

    return 0;
}