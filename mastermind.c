#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 4
#define BLUE 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define WHITE 4

int codice[L];
int tentativo[L];
int i,j;

void genera()
{
    for(i=0;i<L;i++)
        codice[i] = rand()%5;
}

void inserimento()
{
    for(i=0;i<L;i++)
    {
        printf("Inserire tentativo: ");
        scanf("%d", &tentativo[i]);
    }
}

int main()
{
    srand(time(NULL));

    //generazione codice
    genera();
    
    //inserimento tentativo
    inserimento();

    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            if(tentativo[i] == codice[i])
            {
                
            }            
        }
    }

    return 0;
}