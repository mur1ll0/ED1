#include <stdio.h>
#include <stdlib.h>

int * inicial(){
    int * p = (int *)malloc( 5 * sizeof(int)); //aloca memória
    if(p)// testa se alocou mem
        printf("Memoria alocada com sucesso\n");
    else{
        printf("não foi possivel alocar\n" );
        return 0;
    }
    return p;
}
int main () {
    int *p; // cria ponteiro para int
    int EntradaUsuario=1,i=0;

    p = inicial();
    puts("Digite ");
    while(scanf("%d", &EntradaUsuario)){

        p[i]=EntradaUsuario;
        if((i+1)%5==0 && i>1){
                int * pn = realloc(p, (i+1+5) * sizeof(int));
                if(pn!=NULL)
                    p = pn;
                else{
                    puts("\nMemória Insuficiente Entrada Usuario!\n");
                    return 0;
                }
        }
        i++;
        puts("Digite ");
    }

    for (;i>0;i--){
    printf("Posição {%d} Valor {%d}\n",i-1,p[i-1] );
    }


    return 0;
}
