#include <cstdio>

int primechk[21000];
int fprime[21000];
void preprocess(void)
{
    int i, j;
    for(i=2 ; i<=20000 ; i++)
    {
        primechk[i]=1;
    }
    for(i=2 ; i<=20000 ; i++)
    {
        if(primechk[i]==1)
        {
            fprime[i]=i;
            for(j=2 ; i*j<=20000 ; j++)
            {
                primechk[i*j]=0;
                if(fprime[i*j]==0)
                {
                    fprime[i*j]=i;
                }
            }
        }
    }
}

int main(void)
{
    preprocess();
    int n;
    scanf("%d",&n);
    while(n!=1)
    {
        printf("%d\n",fprime[n]);
        n=n/fprime[n];
    }
}
