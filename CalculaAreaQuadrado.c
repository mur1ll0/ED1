#include <stdio.h>
#include <math.h>

void calcula_quadrado (float *Medida, float *Area, float *Perimetro){

  *Area=((*Medida) * (*Medida));
  *Perimetro=(*Medida*4);
}
void calcula_quadrado (float *Medida, float *Area, float *Perimetro);

int main (){
  float Medida=0,Area=0,Perimetro=0;
    puts("Digite a medida do Quadrado ( aqui vamos considerar que o Quadrado possui os 4 lados iguais)");
    scanf("%f",&Medida);
    calcula_quadrado(&Medida,&Area,&Perimetro);
    printf("Area {%.2f} Perimetro {%.2f}\n",Area, Perimetro);
  return 0;
}
