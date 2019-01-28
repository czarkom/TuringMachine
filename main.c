#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pelna_instrukcja {
    int symbol_odczytany;
    int symbol_zmieniony;
    int stan_odczytany;
    int stan_zmieniony;
    char* kierunek;
    struct pelna_instrukcja *kolejna;
} instrukcja;

void turing(instrukcja *zmiany, int tasiemka[])
{
    int j=0;
    instrukcja *instrukcja_obecna;
    int stanik_poczatkowy=0;
    instrukcja_obecna=zmiany;
    while((strcmp(instrukcja_obecna->kierunek,"stop") != 0) && j<6)
    {   instrukcja_obecna=zmiany;
        while((instrukcja_obecna->symbol_odczytany != tasiemka[j]) || (instrukcja_obecna->stan_odczytany != stanik_poczatkowy))
        {
            instrukcja_obecna=instrukcja_obecna->kolejna;
            //if (instrukcja_obecna->kolejna == NULL) break;
        }
        tasiemka[j]=instrukcja_obecna->symbol_zmieniony;
        if (strcmp(instrukcja_obecna->kierunek,"prawo")==0) j++;
        if (strcmp(instrukcja_obecna->kierunek,"lewo")==0) j--;

    }
}


int main()
{
    int tasma[6];
    printf("kupaaaaa Madziulon\n");
    printf("podaj swoja 6 cyfrowa tasme (wpisujac cyfra-enter itd)\n");
    for(int i=0;i<6;i++)
    { scanf("%d",&tasma[i]);
    }

    int warunek_koncowy;

    instrukcja *instrukcja1;
    instrukcja1=malloc(sizeof(instrukcja));
    instrukcja *instrukcja0;
    instrukcja0=instrukcja1;
    while(1)
    {   printf("Podaj symbol i stan odczytany wymagany do wykonania instrukcji\n");
        scanf("%d%d",&instrukcja0->symbol_odczytany,&instrukcja0->stan_odczytany);
        printf("Podaj symbol i stan po wykonaniu instrukcji\n");
        scanf("%d%d",&instrukcja0->symbol_zmieniony,&instrukcja0->stan_zmieniony);
        printf("Podaj kierunek przejscia (prawo/lewo/stop) ");
        instrukcja0->kierunek=malloc(sizeof(char)*5);
        scanf("%s",instrukcja0->kierunek);
        printf("Jesli nie ma wiecej instrukcji wcisnij 77 ");
        scanf("%d",&warunek_koncowy);
        if (warunek_koncowy==77)
        {
            //instrukcja0->kolejna=NULL;
            break;
        }
        printf("\nKolejna instrukcja\n");
        instrukcja0->kolejna=malloc(sizeof(instrukcja));
        instrukcja0=instrukcja0->kolejna;
        }

    turing(instrukcja1,tasma);
    printf("tasma po zmianach: ");
    for(int i=0;i<6;i++)
    {
        printf("%d", tasma[i]);
    }
    return 0;
}


