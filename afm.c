// Projeto Modulo Temático LTIC
// AFM - Software gestão para Associação de Futebol do Montenegro

#include <stdio.h>
#include <math.h>
// #include "menu_1.c"
// #include "menu_2.c"
// #include "menu_3.c"

int main ()
{
	char op; // variável de opção para o menu

	//system("chcp 1252>null"); //CODEPAGE PT

	// MENU PRINCIPAL
	printf("+     Gestão AFM     +\n\n");
	printf("| 1.Inserir/Editar   |\n");
	printf("| 2.Listar/Pesquisar |\n");
	printf("| 3.Estatisticas     |\n");
	printf("| 4.Carregar/Salvar  |\n");
	printf("| 0.Sair             |\n");
	printf("\n");

	op=getchar();

	system("clear"); //system("cls");
	switch (op) {
		case '1':
				printf("| 1.Inserir/Editar   |\n"); // chama função menu Inserir/Editar
				break;
		case '2':
				printf("| 2.Listar/Pesquisar |\n"); // chama função menu Listar/Pesquisar
				break;
		case '3':
				printf("| 3.Estatisticas     |\n"); // chama função menu Estatisticas
				break;
		case '4':
				printf("| 4.Carregar/Salvar  |\n"); // chama função menu Carregar/Salvar
				break;
		case '0':
				break; // sai do programa
	}

	getchar(); //system("pause");


}

