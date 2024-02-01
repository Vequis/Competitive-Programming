#include <bits/stdc++.h>
using namespace std;
 
int tab[2000][200000];
int n, soma=0, tirado = 0;

int subsetSum(int a[], int n, int sum)
{
    if (sum == 0)
        return 1;
         
    if (n <= 0)
        return 0;
   
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
   
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else
    {

        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
                       subsetSum(a, n - 1, sum - a[n - 1]);
    }
}

int a[2000];

int main()
{
    memset(tab, -1, sizeof(tab));
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> a[i];
        soma+=a[i];
        if (a[i]%2==1 and tirado == 0) tirado = i+1;
    }    

    if(soma%2==1) {
        cout << 0 << endl;
        return 0;
    }

    if (subsetSum(a, n, soma/2)){
        if (tirado!=0){
            cout << 1 << endl;
            cout << tirado << endl;
        } else {
            while(tirado==0){
                for (int i=0; i<n; i++){
                    a[i]/=2;
                    if (a[i]%2==1 and tirado == 0) tirado = i+1;
                }    
            }

            cout << 1 << endl;
            cout << tirado << endl;
        }
    } else{
        cout << 0 << endl;
    }

    return 0;
}

//100
//47 46 170 75 9 173 32 43 199 146 87 195 183 41 69 60 147 3 50 176 179 88 121 15 144 117 142 101 98 145 79 5 116 125 13 17 102 68 180 53 107 191 64 73 164 37 3 166 60 10 172 172 149 142 98 27 11 200 129 7 135 124 60 32 54 121 188 89 187 142 183 104 34 127 28 110 119 19 158 96 110 33 199 54 83 83 166 139 68 130 188 93 54 131 155 30 37 177 120 163
