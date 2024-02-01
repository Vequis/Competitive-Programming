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

int cont[110], contnegativos[110];

//Nesse problema, basta ver que se todos os números aparecem menos
// de 3 vezes é possivel dividir em seq estritamente crescentes ou decr;

int main(){_

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        if(num>=0) cont[num]++;
        else contnegativos[-num]++;
    }

    for (int i=0; i<=100; i++){
        if (cont[i] >=3 or contnegativos[i]>=3) {
            cout << "No" << endl;
            break;
        }

        if(i==100){
            cout << "Yes" << endl;
        }
    }

    return 0;
}