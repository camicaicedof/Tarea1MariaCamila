#include<stdio.h>
#include<stdlib.h>

void jumpers(){
    int cantidad;
    while (scanf("%d",&cantidad) != EOF){
        int arr[3000], flag=1, j=0, resta=0, i;
        for (i=0;i < cantidad;i++){
            scanf("%d", &arr[i]);
        }   
        while (j<cantidad-1 && flag==1){
            resta = abs(arr[j]-arr[j+1]);
            if (resta>=cantidad){
                flag=0;
            }
            j++;
        }
        if (flag==1){
            printf("Jolly");
        }
        else if (flag==0){
            printf("Not jolly");
        }
        printf("\n");
        }
    }
int main(){
    jumpers();
    return 0;
}

