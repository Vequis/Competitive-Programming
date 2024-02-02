#include <iostream>
#include <cmath>
#include<algorithm>

using namespace std;

struct bacteria{
    double logBacFim;
    int id;
};

bool ordem(bacteria a,bacteria b){
    return a.logBacFim>b.logBacFim;
}

int main() {
    int n;
    cin >> n;
    bacteria v[n];

    for (int i=0; i<n; i++) {
        int d,c;
        cin >> d >> c;
        v[i].logBacFim = c*log(d);
        v[i].id = i;
    }

    sort(v,v+n,ordem);

    cout << v[0].id << endl;
    return 0;
}
