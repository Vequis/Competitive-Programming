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

vii laptops;
int n, a ,b;

int main(){_

    cin >> n;
    laptops = vii(n);

    for (int i=0; i<n; i++){
        cin >> a >> b;
        laptops[i] = {a,b};
    }

    sort(all(laptops));

    bool happy = false;
    for (int i=1; i<n; i++){
        if (laptops[i].second < laptops[i-1].second){
            happy = true;
            break;
        }
    }

    if (happy){
        cout << "Happy Alex" << endl;
    } else {
        cout << "Poor Alex" << endl;
    }

    return 0;
}