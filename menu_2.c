// Função menu_2()
// Função que implementa as operações do Menu 2 (Listar/Pesquisar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função Resultados por equipa
int result_eq()
{
    int i;


        system("clear");
        for (i=0;i<=10;i++)
            {
                printf("Indice: %d\n", i);
                printf("\n\tCC: %d", jog[i].num_cc);
                printf("\n\tNome: %s", jog[i].nome);
                printf("\n\tMorada: %s", jog[i].morada);
                printf("\n\tTelefone: %d", jog[i].telefone);
                printf("\n\tIdade: %d", jog[i].idade);
                printf("\n\tAno de Entrada: %d", jog[i].ano_entrada);
                printf("\n\tPosição: %s", jog[i].pos);
            }

    getchar();
}




// Função menu_2
int menu_2()
{

    int op = '\n'; // variável de opção para o menu

	//system("chcp 1252>null"); //CODEPAGE PT

	// MENU PRINCIPAL
	system("clear");
	printf("+         LISTAR / PESQUISAR        +\n\n");
	printf("| 1.(lista 10 jogadores)Listar Resultados por Equipa    |\n");
	printf("| 2.Listar Plantel de Equipa        |\n");
	printf("| 3.Pesquisar Jogadores por Idade   |\n");
	printf("| 4.Pesquisar Jogadores por Posição |\n");
	printf("| 0.Sair                            |\n");
	printf("\n");

	while(op == '\n')
        scanf("%c",&op);

	switch (op) {
		case '1':
				result_eq(); // chama função menu Listar Resultados por Equipa
				break;
		case '2':
				//plantel_eq(); // chama função menu Listar Plantel de Equipa
				break;
		case '3':
				//pesq_idade(); // chama função menu Pesquisar Jogadores por Idade
				break;
		case '4':
				//pesq_pos(); // chama função menu Pesquisar Jogadores por Posição
				break;
		case '0':
				break; // sai do programa
	}

	getchar(); //system("pause");


return 0;


}

