#include <stdio.h>

int main()
{
    int valor ;
    printf("Qual é o valor: ");
    while (scanf("%d", &valor)!= 1)
    {
       // print invalido correçao
        while(getchar()!= '\n');                      // so para limpar o buffer
         // {
        printf("Inválido, escreva apenas números!\n");
        printf("Qual é o valor: ");
        // uma }, o while n tem nada la dentro
    }
    if (valor >= 0 && valor <= 1023)
    {
        float temp = 260*valor/1023.00 - 20.00;
        if (-10 <= temp && temp <= 190)
        {
            printf("Valor: %.2fºC\n", temp);
        }
        else
        {
            printf("O valor está fora da gama\n");
        }
    }
    else
    {
        printf("O valor é inválido\n");
    }
}