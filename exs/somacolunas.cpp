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

vector< vector<int> > V(3, vector<int>(3));

vector<int> soma(3);

int main(){_

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cin >> V[i][j];
            soma[j] += V[i][j];
        }
    }

    for (int i=0; i<3; i++){
        cout << "Coluna " << i << ": " << soma[i] << endl; 
    }

    return 0;
}