// Função menu_2()
// Função que implementa as operações do Menu 2 (Listar/Pesquisar)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// Função menu_2
int menu_2()
{

    char op; // variável de opção para o menu

	system("chcp 1252>null"); //CODEPAGE PT

	// MENU PRINCIPAL
	printf("+         LISTAR / PESQUISAR        +\n\n");
	printf("| 1.Listar Resultados por Equipa    |\n");
	printf("| 2.Listar Plantel de Equipa        |\n");
	printf("| 3.Pesquisar Jogadores por Idade   |\n");
	printf("| 4.Pesquisar Jogadores por Posição |\n");
	printf("| 0.Sair                            |\n");
	printf("\n");

	op=getchar(); // ou getch(); em windows

	system("clear"); //system("cls");
	switch (op) {
		case '1':
				result_eq(); // chama função menu Listar Resultados por Equipa
				break;
		case '2':
				plantel_eq(); // chama função menu Listar Plantel de Equipa
				break;
		case '3':
				pesq_idade(); // chama função menu Pesquisar Jogadores por Idade
				break;
		case '4':
				pesq_pos(); // chama função menu Pesquisar Jogadores por Posição
				break;
		case '0':
				break; // sai do programa
	}

	getchar(); //system("pause");


return 0;


}

