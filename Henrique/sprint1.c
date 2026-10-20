#include <stdio.h>
int main()
{
    int valor ;
    printf("Qual é o valor: ");   
    scanf("%d", &valor);
    if (0 <= valor && valor >= 1023)
    {
        float temp = 260*valor/1023.00 - 20.00;
    
        printf("%.2fºC\n", temp);

    }
    else
    {
        printf("O valor é invalido\n");
    }
}

// O stor fez um ciclo while, para q enquanto n fosse entre 0 e 1023 continuava a perguntar, em vez do if e do else, em adiçao tambem ve se há lá coisas q n sejam numeros