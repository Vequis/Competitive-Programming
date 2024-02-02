#include <iostream>
#include <algorithm>

using namespace std;

struct pais{
    int num;
    int ouro = 0;
    int prata = 0;
    int bronze = 0;
};

int comparaPais(pais a, pais b){
    if (a.ouro != b.ouro) return a.ouro>b.ouro;
    else if(a.prata != b.prata) return a.prata>b.prata;
    else if(a.bronze != b.bronze) return a.bronze>b.bronze;
    else return a.num<b.num;
}

int main(){
    int n,m;
    cin >> n >> m;
    pais v[n];

    int o,p,b;
    for (int i=0;i<m;i++) {
        cin >> o >> p >> b;
        v[o-1].ouro++;
        v[p-1].prata++;
        v[b-1].bronze++;
    }

    for (int i=0;i<n;i++){
        v[i].num = i+1;
    }

    sort (v,v+n,comparaPais);

    for (int i=0;i<n;i++){
        cout << v[i].num << " ";
    }

    cout << endl;
    return 0;
}
