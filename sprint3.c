#include <stdio.h>

int main()
{
    int valor ;

    while(true)
    {
        
        printf("Qual é o valor: ");
        while (scanf("%d", &valor)!= 1)
        {
        
            while(getchar()!= '\n');                      

            printf("Inválido, escreva apenas números!\n");
            printf("Qual é o valor: ");
            
        }

        if(valor != -1)
        {
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
        else
        {
            return 0;
        }
    }
}