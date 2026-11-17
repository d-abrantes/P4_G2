#include <stdio.h>
#include <math.h>


float converter(float x)
{
    float y = 260*x/1023.00 - 20.00;
    return y;
}

int verificartemp(float x)
{
    return (-10 <= x && x <= 190);

}

void lervalores(int *sensor, int *indice, int *valor)
{
    printf("Qual é o sensor[1 a 3] e o valor[0 a 1023]: ");
    int y;
    int x; 
    int z; 
    while (scanf("temp%d %d %d", &y, &z, &x)!= 2 || (x < 0 && x != -1) || (x > 1023) || y < 1 || y > 3)
    {               
        while(getchar()!= '\n');                      

        printf("Inválido, escreva apenas números de 0 a 1023!\n");
        printf("Qual é o valor: ");            
    }
    while(getchar()!= '\n');    
    *valor = x;
    *sensor = y;
    *indice = z;
}

float minimo(float x, float *y, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (y[i] < x)
        {
            x = y[i];
        }
    }
    return x;
}

float maximo(float x, float *y, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (y[i] > x)
        {
            x = y[i];
        }
    }
    return x;
}
float calmedia(float *x, int y)
{
    float soma = 0;
    for (int i = 0; i < y; i++)
    {
        soma += x[i];
    }
    return soma / y;
}
float caldesvio(float *pt,float fm, int ir)
{
    float somadist = 0;
    for (int i = 0; i < ir; i++)
    {
        somadist += pow(pt[i] - fm, 2);
    }
    return sqrt(somadist / ir);
}

void resultados(int repeticoes, int *todosval, float *todostemp, float media, float min, float max, float desvio)
{
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


int main()
{
    int valor ;
    int sensor;
    int indice;
    int repeticoes;
    float temp;
    float media;
    float min = 190;
    float max = -10;
    float desvio;

    printf("Quantas repetições:");


    while (scanf("%d", &repeticoes)!= 1 || repeticoes <= 0 && repeticoes != -1)
    { 
        while(getchar()!= '\n');                      
        printf("Inválido, escreva apenas números positivos!\n");
        printf("Quantas repetições: ");    
    }
    while(getchar()!= '\n'); 
    if(repeticoes == -1) 
    {
        return 0;
    }
    else
    {
        int todosval[][repeticoes];
        float todostemp[repeticoes];       

        for (int i = 0; i < repeticoes; i++)
        {
            do
            {                

                lervalores(&valor, &sensor);
                printf("%d", sensor);
                if(valor == -1)
                {
                    return 0;
                }
                else
                {
                    temp = converter(valor);
                    if (verificartemp(temp))
                    {
                        printf("Valor: %.2fºC\n", temp);

                        todosval[sensor-1][i] = valor;
                        todostemp[sensor-1][i] = temp;

                    }
                    else
                    {
                        printf("O valor está fora da gama\n");
                    }
                }
            } while (!verificartemp(temp));
        }    

        //media min e max
        min = minimo(min, todostemp, repeticoes);
        max = maximo(max, todostemp, repeticoes);
        media = calmedia(todostemp, repeticoes);
        //desvio
        desvio = caldesvio(todostemp, media, repeticoes); 


        resultados(repeticoes, todosval, todostemp, media, min, max, desvio);
    }       
}
