#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define L 4

char codice[L];
char tentativo[L];
int i, j, k, c, t=1;
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
    printf("\nTentativo %d\n", t);
    printf("Inserire tentativo: ");
    scanf("%s", tentativo);
    t++;
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

//pos = 0
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

    //calcola num
    numeri();

    //stampa risultato
    if(!num)
        printf("Nessuno dei numeri inseriti è presente nel codice\n");
    else if(num == 1)
        printf("%d dei numeri inseriti è presente nel codice\n", num);
    else
        printf("%d dei numeri inseriti sono presenti nel codice\n", num);
}

//pos = 1 || pos = 2 || pos = 3
void one()
{
    //calcola num
    numeri();

    num += pos;

    //stampa risultato
    if(num == 1)
        printf("%d dei numeri inseriti è presente nel codice\n", num);
    else
        printf("%d dei numeri inseriti sono presenti nel codice\n", num);

    printf("di cui %d nella posizione corretta\n", pos);
}

//pos = 4
void four()
{
    //stampa risultato
    printf("Complimenti, hai indovinato il codice segreto!!\nLa combinazione era: ");
    for(i=0;i<L;i++)
        printf("%c", codice[i]);
    printf("\n");
}

int main()
{
    //genera codice da indovinare
    genera();

    while(t <= 10)
    {
        //inserimento
        try();

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
            case 2:
            one();
            break;
            case 3:
            one();
            break;
            case 4:
            four();
            return 0;
            break;
        }
    }

    //stampa risultato
    printf("\nHai esaurito i tentativi\nGioca ancora!!\n");

    return 0;
}