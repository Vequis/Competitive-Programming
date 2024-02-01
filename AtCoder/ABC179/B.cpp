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

vi duplo;
int a, b, n;

int main(){_

    cin >> n;

    duplo = vi(n);

    for (int i=0; i<n; i++){
        cin >> a >> b;
        if (a==b) duplo[i] = 1; 
    }

    for (int i=0; i<n-2; i++){
        if (duplo[i] and duplo[i+1] and duplo[i+2]){
            cout << "Yes" << endl;
            return 0;
        } 
    }

    cout << "No" << endl;

    return 0;
}