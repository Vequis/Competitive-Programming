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

int n, t, movs = 0;

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n;
        movs = 0;
        while (n!=1){
            if (n%6 == 0){
                n/=6;
                movs++;
            } else if (n%3==0){
                n*=2;
                movs++;
            } else {
                movs = -1;
                break;
            }
        }
        cout << movs << endl;
    }

    return 0;
}