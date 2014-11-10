// Função menu_2()
// Função que implementa as operações do Menu 2 (Listar/Pesquisar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função listar resultados por equipa

int result_equip(void)
{

//ir a estrutura dados equipas->resultados e apresentar no ecrã

char equipa[100];

system("clear");
//listar equipas existentes??
printf("Qual a equipa?\n");
scanf("%s",&equipa);
printf("\nA equipa selecionada é %s \n" , equipa);

getchar();
getchar();

return 0;

}

// Função listar jogadores por equipa

int jog_equip(void)
{

//ir a estrutura dados equipas->jogadores e apresentar no ecrã

char equipa[100];

system("clear");
//listar equipas existentes??
printf("Qual a equipa_?\n");
scanf("%s", &equipa);
printf("\nA equipa selecionada é %s \n" , equipa);

getchar();
getchar();

return 0;

}

// Função listar jogadores por idade

int jog_idade(void)
{

//ir a estrutura dados equipas->jogadores e apresentar no ecrã

int idade;

system("clear");
//listar equipas existentes??
printf("Qual a idade?\n");
scanf("%d", &idade);
printf("\nA idade selecionada é %d \n" , idade);

getchar();
getchar();

return 0;

}

// Função listar jogadores por posição

int jog_pos(void)
{

//ir a estrutura dados equipas->jogadores e apresentar no ecrã

char posicao[20];

system("clear");
//listar equipas existentes??
printf("Qual a posição?\n");
scanf("%s", &posicao);
printf("\nA posicao selecionada é %s \n" , posicao);

getchar();
getchar();

return 0;

}
// Função menu_2

int menu_2()
{

    int op; // variável de opção para o menu

	system("chcp 1252>null"); //CODEPAGE PT

	do {

        system("clear");
        printf("+         LISTAR / PESQUISAR        +\n\n");
        printf("| 1. Listar Resultados por Equipa    |\n");
        printf("| 2. Listar Jogadores por Equipa     |\n");
        printf("| 3. Pesquisar Jogadores por Idade   |\n");
        printf("| 4. Pesquisar Jogadores por Posição |\n");
        printf("| 0. Sair                            |\n");
        printf("\n");

        scanf("%d",&op);


	switch (op)
        {
            case 1:
                result_equip(); // chama função menu Listar Resultados por Equipa
				break;
            case 2:
                jog_equip(); //plantel_eq(); // chama função menu Listar Plantel de Equipa
				break;
            case 3:
                jog_idade(); //pesq_idade(); // chama função menu Pesquisar Jogadores por Idade
				break;
            case 4:
                jog_pos(); //pesq_pos(); // chama função menu Pesquisar Jogadores por Posição
				break;
            case 0:
				break; // sai do programa
        }

    } while (op!=0);

	getchar(); //system("pause");


return 0;


}

/*main()
{

menu_2();

}*/
