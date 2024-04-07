#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 4

char codice[L];
char tentativo[L];
char posizioni[L];
char numeri[L];
int i, j, k, m1, m2;
int pos=0, num=0, wr=0, check=0, doppi=0;

//generazione codice
void genera()
{
    srand(time(NULL));

    for (i = 0; i < L; i++)
        codice[i] = rand() %10+48;

    printf("%s\n", codice);
}

//inserimento tentativo
void inserimento()
{
    printf("Inserire tentativo: ");
    scanf("%s", tentativo);
}

//pos = 0
int zero()
{
    //verifica valori doppi nel tentativo
    for(i=0;i<L;i++)
    {
        printf("%c[i] == %c[j]\n", tentativo[i], tentativo[j]);
        if(tentativo[i] == tentativo[j])
        {
            printf("Sono uguali\n");
            tentativo[i] = tentativo[3];
            printf("cambia valore: %s\n", tentativo);
            tentativo[3] = 'A';
            printf("carattere A: %s\n", tentativo);
            check = 1;
        }
        j++;
    }
}

    printf("check = %d\n", check);

    //senza numeri doppi
    if(!check)
    {
        for(i=0;i<L;i++)
        {
            for(j=0;j<L;j++)
            {
                if(tentativo[i] == codice[j])
                    num++;
                else
                    wr++;
            }
        }
    }
    //con numeri doppi
    else
    {
        for(i=0;i<L-1;i++)
        {
            for(j=0;j<L;j++)
            {
                if(tentativo[i] == codice[j])
                    num++;
                else
                    wr++;
            }
        }
    }

    //4S
    if(!num)
    {
        printf("Nessuno dei numeri inseriti è presente nel codice\n");
        printf("Numeri non presenti: %c\n", wr);
        return 0;
    }
    //1NUM
    else if(num == 1)
    {
        printf("%d numero inserito è presente nel codice\n", num);
        printf("Numeri non presenti: %c\n", wr);
        return 0;
    }
    //1NUM,2NUM.3NUM,4NUM
    else
    {
        printf("%d dei numeri inseriti sono presenti nel codice\n", num);
        printf("Numeri non presenti: %c\n", wr);
        return 0;
    }

/*//pos = 1
void one()
{
    for(i=0;i<L;i++)
    {
        for(j=0;j<L;j++)
        {
            if(tentativo[i] == codice[i] && )
        }
    }
}*/

int main()
{
    // dichiarazione variabili

    // generazione codice
    genera();

    // inserimento tentativo
    inserimento();

    //conta pos
    for(i=0;i<L;i++)
    {
        if(tentativo[i] == codice[i])
        {
            pos++;
            printf("Pos aumenta\n");
        }
    }

    switch(pos)
    {
        case 0:
        zero();
        break;
        case 1:
        //one();
        break;
        case 2:
        //two();
        break;
        case 3:
        //three();
        break;
        case 4:
        //four();
        break;
    }

    return 0;
}