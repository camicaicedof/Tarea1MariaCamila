#include<stdio.h>

void finish(){
    int cantCasos,i;
    scanf("%d",&cantCasos);
    for (i=0;i<cantCasos;i++){
        int arr[100001], arr2[100001],j,n,k,m,l=0,flag=1,contador1=0,contador2=0,contador3,contador4=-1,flag2=1;
        scanf("%d",&n);
        for (j=0;j<n;j++){
            scanf("%d",&arr[j]);
            contador1+=arr[j];
        }
        for(k=0;k<n;k++){
            scanf("%d",&arr2[k]);
            contador2+=arr2[k];
        }
        if (contador2>contador1){
                printf("Case %i: Not Possible\n",i+1);
                flag=0;
            }
        while(l<n && flag==1){
            contador3=arr[l]-arr2[l];
            if (contador3>=0){
                flag2=1;
                contador4=0;
                m=l;
                while(m<n && flag2==1){
                    contador4+=arr[m]-arr2[m];
                    if (contador4<0){
                        flag2=0;
                    }
                    m++;
                }
            }
            if (contador4>=0){
                printf("Case %i: Possible from station %i\n",i+1,l+1);
                flag=0;
            }
            l++;
        }
    }
}
int main(){
    finish();
    return 0;
}