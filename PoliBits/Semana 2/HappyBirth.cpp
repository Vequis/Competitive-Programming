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

signed main(){_

    int n;
    cin >> n;

    //vou simular burramente

    int ano = 1867;
    int dia = 0;

    while(ano < 1867 + n) {
        dia = (dia + 1)%7;
        ano++;
        if (ano % 4 == 0 and ano %100 != 0) dia = (dia + 1)%7; 
        if (ano % 400 == 0) dia = (dia + 1)%7;
    }

    if (dia==0) {
        cout << "Sunday" << endl;
    } else if (dia==1) {
        cout << "Monday" << endl;
    } else if (dia==2) {
        cout << "Tuesday" << endl;
    } else if (dia==3) {
        cout << "Wednesday" << endl;
    } else if (dia==4) {
        cout << "Thursday" << endl;
    } else if (dia==5) {
        cout << "Friday" << endl;
    } else if (dia==6) {
        cout << "Saturday" << endl;
    }

    return 0;
}
