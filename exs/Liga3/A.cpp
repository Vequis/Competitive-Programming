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

int k, a , b;

int main(){_

    cin >> k >> a >> b;

    if (max(a,b) - min(a,b) >= k){
        cout << "EH SUFICIENTE" << endl;
    } else {
        cout << "NAO EH SUFICIENTE" << endl;
    }

    return 0;
}