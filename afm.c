// Projeto Modulo Tem�tico LTIC
// AFM - Software gest�o para Associa��o de Futebol do Montenegro

#include <stdio.h>
#include <math.h>
// #include "menu_1.c"
// #include "menu_2.c"
// #include "menu_3.c"

int main ()
{
	char op; // vari�vel de op��o para o menu

	//system("chcp 1252>null"); //CODEPAGE PT

	// MENU PRINCIPAL
	printf("+     Gest�o AFM     +\n\n");
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
				printf("| 1.Inserir/Editar   |\n"); // chama fun��o menu Inserir/Editar
				break;
		case '2':
				printf("| 2.Listar/Pesquisar |\n"); // chama fun��o menu Listar/Pesquisar
				break;
		case '3':
				printf("| 3.Estatisticas     |\n"); // chama fun��o menu Estatisticas
				break;
		case '4':
				printf("| 4.Carregar/Salvar  |\n"); // chama fun��o menu Carregar/Salvar
				break;
		case '0':
				break; // sai do programa
	}

	getchar(); //system("pause");


}

