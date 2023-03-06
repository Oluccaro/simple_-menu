#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int *opt){
    int option;
    do
    {
      printf("\n%s\n","Digite uma das opções abaixo: ");
      printf("%s\n", "1 - Digite uma nova data de nascimento.");
      printf("%s\n", "2 - Verifique a condição para votação.");
      printf("%s\n", "3 - Imprima na tela o último mês inserido em formato texto");
      printf("%s\n", "4 - Encerre o programa");
      printf("\n");
      scanf(" %d", &option);        
    } while (option<1 || option>4);
    *opt = option;
}

void podeVotar(int ano){
    int idade = 2022-ano;
    if(idade<16){
        printf("%s\n", "Não pode votar");
    } else if(idade>=16 && idade < 18){
        printf("%s\n", "Voto facultativo");
    } else if(idade>=18 && idade <70) {
        printf("%s\n","Voto obrigatório");
    } else {
        printf("%s\n","Voto facultativo");
    }
}

int recebeData(int *dia, int *mes, int *ano){
    char data[20];
    int d, m, a;
    printf("\nInsira o um valor para a data no formato DD/MM/AAAA: ");
    scanf("%d/%d/%d", &d,&m,&a);
    *dia=d;
    *mes=m;
    *ano=a;

    printf("%d%d%d",d,m,a);
    return m;
    
}

void imprimeMes(int mes){
    char *nomesMes[]={"Janeiro","Fevereiro", "Março", "Abril", "Maio", "Junho", 
    "Julho", "Agosto", "Setembro", "Outubro","Novembro", "Dezembro"};
    printf("%s", nomesMes[mes-1]);
}

int main(int argc, char const *argv[])
{
    char dma[20];
    int dia, mes, ano, opt;
    
    dia = atoi(argv[1]);
    mes = atoi(argv[2]);
    ano = atoi(argv[3]);

    do
    {
        menu(&opt);
        switch (opt)
        {
        case 1: 
            recebeData(&dia, &mes, &ano);
            break;
        case 2:
            podeVotar(ano);
            break;
        case 3:
            imprimeMes(mes);
        default:
            break;
        }
    } while (opt!=4);   
    
    printf("Tchau!\n");


}
