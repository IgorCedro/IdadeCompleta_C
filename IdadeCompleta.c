#include<stdio.h>
#include<locale.h>

int totaldias(int ano, int mes)
{
    int bis, qnt, max;

    //Calcula se o ano � bissexto
    bis = ano % 4;
    //Calcula se o ano � par
    qnt = mes % 2;

    //Se o mes for fevereiro
    if (mes == 2)
    {
        //Se o ano � bissexto
        if(bis == 0)
        {
            max = 29;//Fevereiro tem 29 dias
        }
        else//Se n�o
        {
            max = 28;//Fevereiro tem 28 dias
        }
    }
    else if(mes < 8)//Se o mes for menor que 8
    {
        if(qnt == 0)//Se o mes for par
        {
            max = 30;//Tem 30 dias
        }
        else//Se n�o
        {
            max = 31;//Tem 31 dias
        }
    }
    else//Se o mes for maior ou igual a 8
    {
        if(qnt == 0)//Se o mes for par
        {
            max = 31;//Tem 31 dias
        }
        else//Se n�o
        {
            max = 30;//Tem 30 dias
        }
    }

    return max;
}
main()
{
/*
	Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.
*/

    setlocale(LC_ALL, "Portuguese");

    //Declara��o de vari�veis
    int continuar, max;
    int diaN, mesN, anoN, diaA, mesA, anoA, diaF, mesF, anoF;

    //Loop para repetir o programa
    do
    {
        //Entrada da data de nascimento
        do
        {
            printf("Digite o ANO do seu nascimento: \n");
            scanf("%d",&anoN);
        }
        while(anoN < 0);

        do
        {
            printf("Digite o M�S do seu nascimento: \n");
            scanf("%d",&mesN);
        }
        while(mesN <= 0 || mesN > 12);

        //Calcula o m�ximo de dias no m�s
        max = totaldias(anoN, mesN);

        do
        {
            printf("Digite o DIA do seu nascimento: \n");
            scanf("%d",&diaN);
        }
        while(diaN <= 0 || diaN > max);


        printf("\n");//Pula a linha


        //Entrada da data atual
        do
        {
            printf("Digite o ANO atual: \n");
            scanf("%d",&anoA);
        }
        while(anoA < 0);

        do
        {
            printf("Digite o M�S atual: \n");
            scanf("%d",&mesA);
        }
        while(mesA <= 0 || mesA > 12);

        //Calcula o m�ximo de dias no m�s
        max = totaldias(anoA, mesA);

        do
        {
            printf("Digite o DIA atual: \n");
            scanf("%d",&diaA);
        }
        while(diaA <= 0 || diaA > max);

        //Opera��es
        anoF = anoA - anoN;
        mesF = mesA - mesN;
        diaF = diaA - diaN;

        //Calcula o m�ximo de dias no m�s
        max = totaldias(anoF, mesF);

        if (diaF < 0)
        {
            diaF += max;
            mesF--;
        }
        if (mesF < 0)
        {
            mesF += 12;
            anoF--;
        }

        printf("\n");//Pula a linha

        //Exibi��o
        printf("Sua idade �: %d anos, %d meses, %d dias \n", anoF, mesF, diaF);

        printf("\n");//Pula a linha

        //Loop para validar a sa�da do programa
        do
            {
                printf("Se deseja continuar, digite '1'. \n");
                printf("Se deseja sair, digite '0'. \n");
                scanf("%d",&continuar);
            }
        while(continuar !=0 && continuar !=1);//Verifica se o n�mero � diferente de 0 e 1

        system("cls");//Limpa a tela
    }
    while(continuar==1);//Programa reinicia se a variaver 'continuar' ter valor 1
}
