#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 4

char codice[L];
char tentativo[L];
int i, j, k, t;
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

//calcola posizioni
void posizioni()
{
    pos = 0;

    for(i=0;i<L;i++)
    {
        if(tentativo[i] == codice[i])
        {
            tentativo[i] = 'P';
            pos++;
        }
    }
}

//calcola numeri
void numeri()
{
    num = 0;

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
                    num++;
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

    //calcola num
    numeri();

    if(!num)
        printf("Nessuno dei numeri inseriti è presente nel codice\n");
    else if(num == 1)
        printf("%d dei numeri inseriti è presente nel codice\n", num);
    else
        printf("%d dei numeri inseriti sono presenti nel codice\n", num);
}

void one()
{
    //calcola num
    numeri();

    num++;

    if(num == 1)
        printf("%d dei numeri inseriti è presente nel codice\n", num);
    else
        printf("%d dei numeri inseriti sono presenti nel codice\n", num);

    printf("di cui %d nella posizione corretta\n", pos);
}

int main()
{
    //genera codice da indovinare
    genera();
    printf("%s\n", codice);

    //inserimento tentativo
    while(pos != 4)
    {    
        try();
        t++;
        printf("%s\n", codice);
        printf("%s\n", codice);
        printf("%s\n", tentativo);
        printf("%s\n", tentativo);

        //calcola pos
        posizioni();

        switch(pos)
        {
            case 0:
            zero();
            break;
            case 1:
            one();
            break;
            default:
            printf("pos != 0 && pos != 1\n");
        }
    }

    return 0;
}