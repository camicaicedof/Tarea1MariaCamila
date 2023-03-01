#include<stdio.h>
int main(){
    int cantidadCasos, i;
    scanf("%d",&cantidadCasos);
    while (cantidadCasos != 0){
        int centroX, centroY, coordX, coordY;
        scanf("%d", &centroX);
        scanf("%d",&centroY);
        for (i=0;i < cantidadCasos;i++){
            scanf("%d",&coordX);
            scanf("%d",&coordY);
            if (coordX > centroX && coordY > centroY){
                printf("NE\n");
            }
            else if (coordX > centroX && coordY < centroY){
                printf("SE\n");
            }
            else if (coordX < centroX && coordY > centroY){
                printf("NO\n");
            }
            else if (coordX < centroX && coordY < centroY){
                printf("SO\n");
            }
            else if (coordX == centroX || coordY == centroY){
                printf("divisa\n");
            }
        }
        scanf("%d",&cantidadCasos); 
        }
    return 0;
}