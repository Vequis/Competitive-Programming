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

int n, num;

vi resp = vi(3);

int main(){_

    cin >> n;
    while(n--){
        cin >> num;
        if (num%2==0) resp[0]++;
        if (num%3==0) resp[1]++;
        if (num%4==0) resp[2]++;
    }

    for (int i=0; i<3; i++){
        cout << resp[i] << endl;
    }

    return 0;
}