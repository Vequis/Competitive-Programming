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
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007

using namespace std;

int ingr[5], t;

int main(){_

    cin >> t;

    while (t--){
        cin >> ingr[0] >> ingr[1] >> ingr[2];
        cin >> ingr[3] >> ingr[4];

        int resp = 0;

        if (ingr[3] > ingr[4]){
            while(ingr[0]>1 && ingr[1]>0) {
                resp+=ingr[3];
                ingr[0]-=2;
                ingr[1]-=1;
            }
            while(ingr[0]>1 && ingr[2]>0) {
                resp+=ingr[4];
                ingr[0]-=2;
                ingr[2]-=1;
            }

            cout << resp << endl;
        } else {
            while(ingr[0]>1 && ingr[2]>0) {
                resp+=ingr[4];
                ingr[0]-=2;
                ingr[2]-=1;
            }
            while(ingr[0]>1 && ingr[1]>0) {
                resp+=ingr[3];
                ingr[0]-=2;
                ingr[1]-=1;
            }

            cout << resp << endl;           
        }
    }

    return 0;
}