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

int n, t;

bool ord(int n){
    int ant = n%10;
    n/=10;
    while (n>0){
        if(n%10!=ant){
            return false;
        }
        ant = n%10;
        n/=10;
    }
    return true;
}

int dig, divis, resp, aux;
int main(){_

    cin >> t;

    while(t--){
        cin >> n;

        dig = 0;
        aux = n;
        while(aux>0){
            dig++;
            aux/=10;
        }


        divis=0;
        for (int i=0; i<dig; i++){
            divis*=10;
            divis++;
        }

        int resp = (n/divis);
        resp += (dig-1)*9;
        cout << resp << endl;

    }

    return 0;
}