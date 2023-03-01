#include<stdio.h>
#include<stdlib.h>
void candado(){
    int inicio, primero, segundo, tercero, vueltas=1080, flag=1;
    scanf("%d",&inicio);
    scanf("%d",&primero);
    scanf("%d",&segundo);
    scanf("%d",&tercero);
    while (flag==1){
        int final, operaciones, resta1, resta2, resta3;
        if (inicio>=primero){
            resta1=inicio-primero;
        }
        else {
            resta1=40-(primero-inicio);
        }
        if (segundo>=primero){
            resta2=segundo-primero;
        }
        else{
            resta2=40-(primero-segundo);
        }
        if (segundo>=tercero){
            resta3=segundo-tercero;
        }
        else {
            resta3=40-(tercero-segundo);
        }
        operaciones=(resta1+resta2+resta3)*9;
        final=vueltas+operaciones;
        printf("%d\n",final);
        scanf("%d",&inicio);
        scanf("%d",&primero);
        scanf("%d",&segundo);
        scanf("%d",&tercero);
        if(inicio==0 && primero==0 && segundo==0 && tercero==0){
            flag=0;
        }
    }    
}
int main(){
    candado();
}