#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 4

char codice[L];
char tentativo[L];
int i, j, k;
int pos, num, doppi, doppi_c;

//genera codice casuale
void genera()
{
    //inizializzazione funzione rand
    srand(time(NULL));

    //genera codice
    for(i=0;i<L;i++)
        codice[i] = rand()%10+48;
}

//inserimento tentativo
void try()
{
    printf("Inserire tentativo: ");
    scanf("%s", tentativo);
}

//calcola pos
void posizioni()
{
    for(i=0;i<L;i++)
    {
        for(j=1;j<L;j++)
        {
            if(tentativo[i] == codice[j] && i == j)
            {
                tentativo[i] = 'P';
                pos++;
            }
        }
    }
}

void zero()
{
    //controllo doppi
    for(i=0;i<L;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(tentativo[i] == tentativo[j])
                tentativo[i] = 'A';
        }
    }

    printf("tentativo senza doppi: %s\n", tentativo);

    //conta num
    for(i=0;i<L;i++)
    {
        doppi_c = 0;
        for(j=0;j<L;j++)
        {
            if(tentativo[i] == codice[j])
            {
                for(k=0;k<j;k++)
                {
                    if(codice[j] == codice[k])
                        doppi_c = 1;
                }

                if(!doppi_c)
                {
                    num++;
                    printf("num aumenta\n");
                }
            }
        }
    }

    if(!num)
        printf("Nessuno dei numeri inseriti è presente nel codice\n");
    else if(num == 1)
        printf("%d dei numeri inseriti è presente nel codice\n", num);
    else
        printf("%d dei numeri inseriti sono presenti nel codice\n", num);
}

void one()
{
    printf("%s\n", tentativo);
}

int main()
{
    //genera codice da indovinare
    genera();
    printf("%s\n", codice);

    //inserimento tentativo
    try();

    //calcola posizioni
    posizioni();

    switch(pos)
    {
        case 0:
        zero();
        break;
        one();
        default:
        printf("pos != 0 && pos != 1\n");
    }

    return 0;
}