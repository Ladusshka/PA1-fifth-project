#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct kontakt{
    char* tel;
    char* jm;
    char* kod_jmeno;

};
typedef struct kontakt Kontakt;


void plus(char* stroka, Kontakt* kontakty, int* index_kontakt)
{
    if(stroka[1]!=' ')
    {
        printf("Nespravny vstup.\n");
        return ;
    }
    size_t length = strlen(stroka);
    char* telefon = (char*)malloc(sizeof(char)*length);

    size_t index=0;
    for(size_t i = 2;i<length;i++)
    {
        if(stroka[i] == ' '){break;}
        if(!isdigit(stroka[i]))
        {
            printf("Nespravny vstup.\n");
            free(telefon);
            return ;
        }
        else
        {
            telefon[index] = stroka[i];
            index++;
        }
    }
    telefon[index] = '\0';


    if(index>20)
    {
        printf("Nespravny vstup.\n");
        free(telefon);
        return ;
    }




    if(stroka[index+2] != ' ')
    {
        printf("Nespravny vstup.\n");
        free(telefon);
        return ;
    }


    size_t start_jmena = index+3;
    char* jmeno = (char*)malloc(sizeof(char)*(length));
    size_t index_jmena = 0;


    for(size_t i = start_jmena; i<length;i++)
    {
        if(stroka[i] == '\n'){break;}
        if(!(isalpha(stroka[i]) || stroka[i] == ' '))
        {
            printf("Nespravny vstup.\n");
            free(telefon);
            free(jmeno);
            return ;
        }
        else{
            jmeno[index_jmena] = stroka[i];
            index_jmena++;
        }
    }
    jmeno[index_jmena] = '\0';
    if(jmeno[0] == ' ')
    {
        printf("Nespravny vstup.\n");
        free(telefon);
        free(jmeno);
        return ;
    }
    if(jmeno[index_jmena-1] == ' ')
    {
        printf("Nespravny vstup.\n");
        free(telefon);
        free(jmeno);
        return ;
    }



    //existuje kontakt
    size_t counter = 0;
    for(int i = 0; i<*index_kontakt;i++)
    {
        if((size_t)strlen(kontakty[i].tel) == index)
        {
            counter = 0;
            for(size_t j = 0;j<index && j<strlen(kontakty[i].tel);j++)
            {
                if(kontakty[i].tel[j] == telefon[j])
                {
                    counter++;
                }
            }
            if(counter == index)
            {
                size_t counter2 = 0;
                if((size_t)strlen(kontakty[i].jm) == index_jmena)
                {
                    for(size_t j = 0;j<index_jmena;j++)
                    {
                        if(kontakty[i].jm[j] == jmeno[j])
                        {
                            counter2++;
                        }
                    }

                    if(counter2 == 	index_jmena)
                    {
                        printf("Kontakt jiz existuje.\n");
                        free(telefon);
                        free(jmeno);
                        return ;
                    }

                }


            }


        }

    }


    printf("OK\n");

    kontakty[*index_kontakt].tel = telefon;
    kontakty[*index_kontakt].jm = jmeno;
    size_t length_jmena = strlen(kontakty[*index_kontakt].jm);
    char * kod = (char*)malloc(sizeof(char)*(length_jmena + 1));


    for(size_t i = 0; i<length_jmena;i++)
    {
        if((jmeno[i]>='a' && jmeno[i] <='c') || (jmeno[i] >='A' && jmeno[i]<='C'))
        {
            kod[i] = '2';
        }
        else if((jmeno[i]>='d' && jmeno[i] <='f') || (jmeno[i] >='D' && jmeno[i]<='F'))
        {
            kod[i] = '3';
        }
        else if((jmeno[i]>='g' && jmeno[i] <='i') || (jmeno[i] >='G' && jmeno[i]<='I'))
        {
            kod[i] = '4';
        }
        else if((jmeno[i]>='j' && jmeno[i] <='l') || (jmeno[i] >='J' && jmeno[i]<='L'))
        {
            kod[i] = '5';
        }
        else if((jmeno[i]>='m' && jmeno[i] <='o') || (jmeno[i] >='M' && jmeno[i]<='O'))
        {
            kod[i] = '6';
        }
        else if((jmeno[i]>='p' && jmeno[i] <='s') || (jmeno[i] >='P' && jmeno[i]<='S'))
        {
            kod[i] = '7';
        }
        else if((jmeno[i]>='t' && jmeno[i] <='v') || (jmeno[i] >='T' && jmeno[i]<='V'))
        {
            kod[i] = '8';
        }
        else if((jmeno[i]>='w' && jmeno[i] <='z') || (jmeno[i] >='W' && jmeno[i]<='Z'))
        {
            kod[i] = '9';
        }
        else if(jmeno[i] == ' ')
        {
            kod[i] = '1';
        }


    }
    kod[length_jmena]='\0';

    //printf("%s\n%s\n" , jmeno, kod);

    kontakty[*index_kontakt].kod_jmeno = kod;

    //printf("%s\n%s\n", kontakty[*index_kontakt].jm,kontakty[*index_kontakt].kod_jmeno);
    *index_kontakt = (*index_kontakt) + 1;









}

void vopros(char* stroka, Kontakt* kontakty, int* index_kontakt)
{
    if(stroka[1]!=' ')
    {
        printf("Nespravny vstup.\n");
        return ;
    }
    size_t length = strlen(stroka);
    if(stroka[length-2] == ' ' || !isdigit(stroka[length-2]))
    {
        printf("Nespravny vstup.\n");
        return ;
    }


    char* cislo = (char*)malloc(sizeof(char)*(length-2));
    size_t index = 0;
    for( size_t i = 2;i<length-1;i++)
    {
        if(!isdigit(stroka[i]))
        {
            printf("Nespravny vstup.\n");
            free(cislo);
            return ;
        }
        else
        {
            cislo[index] = stroka[i];
            index++;
        }
    }

    cislo[index]='\0';


    size_t counter = 0;


    int* indexy = (int*)malloc(sizeof(int) * (*index_kontakt));
    int index_indexu = 0;


    for(int i = 0; i< *index_kontakt; i++)
    {
        counter =0;
        for(size_t j = 0;j<index && j<strlen(kontakty[i].tel);j++)
        {
            if(cislo[j] == kontakty[i].tel[j])
            {
                counter++;
            }
        }
        if(counter == index)
        {
            indexy[index_indexu] = i;
            index_indexu++;
        }
        else
        {
            size_t counter2 =0;
            for(size_t j = 0;j<index && j<strlen(kontakty[i].jm);j++)
            {
                if(cislo[j] == kontakty[i].kod_jmeno[j])
                {
                    counter2++;
                }
            }
            if(counter2 == index)
            {
                indexy[index_indexu] = i;
                index_indexu++;
            }

        }
    }


    if(index_indexu <= 10)
    {
        for(int i = 0; i< index_indexu;i++)
        {
            printf("%s %s\n", kontakty[indexy[i]].tel, kontakty[indexy[i]].jm);

        }
    }


    printf("Celkem: %d\n", index_indexu);

    free(indexy);
    free(cislo);







}
int main()
{
    int endOF;
    int index_kontakt = 0;
    int size_kontakts = 20;
    Kontakt * kontakty = (Kontakt*)malloc(sizeof(Kontakt)*size_kontakts);

    char* stroka = NULL;
    size_t rozmer = 0;




    while (1)
    {

        endOF = getline(&stroka, &rozmer, stdin);
        if( endOF == -1 )
        {
            break;
        }

        if(index_kontakt == size_kontakts-1)
        {
            size_kontakts*=2;

            kontakty = (Kontakt*)realloc(kontakty,sizeof(Kontakt)*size_kontakts);
        }


        if(stroka[0] == '+')
        {
            plus(stroka, kontakty, &index_kontakt);
        }
        else if(stroka[0] == '?')
        {
            vopros(stroka, kontakty, &index_kontakt);
        }
        else
        {
            printf("Nespravny vstup.\n");
        }
        rozmer = 0;
        free(stroka);
        stroka = NULL;

    }

    for(int i =0;i < index_kontakt;i++)
    {
        free(kontakty[i].tel);
        free(kontakty[i].jm);
        free(kontakty[i].kod_jmeno);

    }
    free(kontakty);
    free(stroka);
    return 0;
}
