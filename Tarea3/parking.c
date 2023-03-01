#include<stdio.h>
int main(){
    int casos, i, j;
    scanf("%d",&casos);
    for (i=0; i<casos;i++) {
        int cantidad, num, resultado, menor=110;
        int mayor=0;
        scanf("%d",&cantidad);
        for (j=0; j<cantidad; j++){
            scanf("%d", &num);
            if (num>mayor){
                mayor=num;
            }
            if (num<menor){
                menor=num;
            }
            }
        resultado=((mayor-menor)*2);
        printf("%d\n",resultado);
        }
    return 0;
    }

    
