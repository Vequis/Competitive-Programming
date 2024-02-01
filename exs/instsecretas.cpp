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
#define int long long // -> solução divina

using namespace std;

int num, tamanho, dir, last, var;

signed main(){_

    cin >> num;
    while(num!=99999){
        tamanho = num%1000;
        num/=1000;
        dir = num%10;
        num/=10;
        dir+=num%10;

        if(dir==0){
            var = last;
        } else if (dir%2){
            var = -1;
            last = -1;
        } else {
            var = 1;
            last = 1;
        }

        if(var == -1){ // 
            cout << "left " << tamanho << endl;
        } else {
            cout << "right " << tamanho << endl;
        }

        cin >> num;
    }

    return 0;
}
