#include <stdio.h>
#include <math.h>

int main()
{
    int valor ;
    int repeticoes;
    float temp;
    float media;
    float somatemp = 0.0;
    float min = 190;
    float max = -10;
    float somadist = 0.0;
    float desvio;

    printf("Quantas repetições:");


    while (scanf("%d", &repeticoes)!= 1 || repeticoes <= 0 && repeticoes != -1)
    { 
        while(getchar()!= '\n');                      
        printf("Inválido, escreva apenas números positivos!\n");
        printf("Quantas repetições: ");    
    }
    if(repeticoes == -1) 
    {
        return 0;
    }
    else
    {
        int todosval[repeticoes];
        float todostemp[repeticoes];       

        for (int i = 0; i < repeticoes; i++)
        {
            do
            {                
                printf("Qual é o valor: ");

                
                while (scanf("%d", &valor)!= 1 || (valor < 0 && valor != -1) || (valor > 1023))
                {               
                    while(getchar()!= '\n');                      

                    printf("Inválido, escreva apenas números de 0 a 1023!\n");
                    printf("Qual é o valor: ");            
                }

                if(valor == -1)
                {
                    return 0;
                }
                else
                {
                    temp = 260*valor/1023.00 - 20.00;
                    if (-10 <= temp && temp <= 190)
                    {
                        printf("Valor: %.2fºC\n", temp);

                        todosval[i] = valor ;
                        todostemp[i] = temp ;

                    }
                    else
                    {
                        printf("O valor está fora da gama\n");
                    }
                }
            } while (-10 > temp || temp > 190);
        }    

        //media min e max
        for (int i = 0; i < repeticoes; i++)
        {
            somatemp += todostemp[i];

            if(min > todostemp[i])
            {
                min = todostemp[i];
            } 
            if(max < todostemp[i])
            {
                max = todostemp[i];
            }            
        }
        media = somatemp/repeticoes;

        //desvio
        for (int i = 0; i < repeticoes; i++)
        {
            somadist += pow(todostemp[i] - media, 2);
        }
        desvio = sqrt(somadist / repeticoes);


        printf("\nLista de todos os valores lidos:(%d)\n", repeticoes);
        for (int i = 0; i < repeticoes; i++)
        {
            printf("%d --> %.2fºC\n", todosval[i], todostemp[i]); 
        }
        printf("\nMédia:%.2fºC\n", media);
        printf("Minimo:%.2fºC\n", min);
        printf("Máximo:%.2fºC\n", max);
        printf("Desvio:%.2fºC\n", desvio);
    }    
}
