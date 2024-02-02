    #include <iostream>

    using namespace std;

    int main(){

        int n;
        cin >> n;

        int vetor[n+1];

        for (int i=1; i<=n; i++) cin >> vetor[i];

        int pos = 1;
    
        int dMax = 0;
        for (int i=1; i<=n; i++){
            int d = i-1 + vetor[i] + vetor[1];
            if (d>dMax)  {
                dMax = d;
                pos = i;
            }
        }

        int dE = 0;
        int dD = 0;
        for (int i=1; i<=pos-1; i++){
            int d = (pos - i) + vetor[pos] + vetor[i];
            if (d>dE) dE = d;
        }

        for (int i=pos+1; i<=n; i++){
            int d = (i-pos) + vetor[pos] + vetor[i];
            if (d>dD) dD = d;
        }

        int dFinal = max(dE, dE);
        dFinal = max(dFinal, dE+dD - 2*vetor[pos]);

        cout << dFinal << endl;
    }