// Projeto Modulo Temático LTIC
// AFM - Software gestão para Associação de Futebol do Montenegro

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "menu_1.c"
// #include "menu_2.c"
// #include "menu_3.c"
// #include "menu_4.c"

// Cabeçalhos das funções de "menu_1.c"

int menu_1(void);


int menu_4(void);

// Definição das estruturas de dados

#define J 100

typedef struct{

    int num_cc[9];
    char nome[50];
    char morada[50];
    char telefone[9];
    int idade;
    int ano_entrada[4];
    char pos[20];

} jogador;

typedef jogador listajog[J];


// Função salva_jogador
void salva_jogador(listajog lj){
int i;
FILE *f = fopen("jogador.bin", "wb");

    if (f == NULL)
    {
        fprintf(stderr, "salva_jogador:: Nao e possivel abrir para escrita.\n");
        exit(1);
    }
    fwrite(lj, sizeof(lj[i]), J, f );
    fclose(f);
}



void carrega_jogador(listajog *lj){
int i;
FILE *f = fopen("jogador.bin", "rb");

    if (f == NULL)
    {
        fprintf(stderr, "carrega_jogador:: Nao e possivel abrir para leitura.\n");
        exit(1);
    }
    fread(lj, sizeof(lj[i]), J, f );
    fclose(f);
}


// Função menu_4

int menu_4(void)
{

    listajog lj1, lj2;

    lj1[0].idade = 10;
    strcpy(lj1[0].nome, "Cristiano Ronaldo");
    salva_jogador(lj1);


    carrega_jogador(&lj2);
    printf("%s\t %d\n", lj2[0].nome, lj2[0].idade);
    return 0;
}
// MAIN
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

	op=getchar(); // ou getch(); em windows

	system("clear"); // ou system("cls"); em windows
	switch (op) {
		case '1':
				printf("| 1.Inserir/Editar   |\n");
				menu_1(); // chama função menu Inserir/Editar
				break;
		case '2':
				printf("| 2.Listar/Pesquisar |\n"); // chama função menu Listar/Pesquisar
				break;
		case '3':
				printf("| 3.Estatisticas     |\n"); // chama função menu Estatisticas
				break;
		case '4':
				printf("| 4.Carregar/Salvar  |\n"); // chama função menu Carregar/Salvar
				menu_4();
				break;
		case '0':
				break; // sai do programa
	}

	getchar(); //system("pause");


}


/* CODIGO DO PROFESSOR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct{
    int idade;
    char nome[N];
} User;

typedef User ListUsers[N];

void SaveUsers(ListUsers lu){
int i;
FILE *f = fopen("user.bin", "wb");

    if (f == NULL)
    {
        fprintf(stderr, "SaveUsers:: Nao e possivel abrir para escrita.\n");
        exit(1);
    }
    fwrite(lu, sizeof(lu[i]), N, f );
    fclose(f);
}



void LoadUsers(ListUsers *lu){
int i;
FILE *f = fopen("user.bin", "rb");

    if (f == NULL)
    {
        fprintf(stderr, "LoadUsers:: Nao e possivel abrir para leitura.\n");
        exit(1);
    }
    fread(lu, sizeof(lu[i]), N, f );
    fclose(f);
}



int main()
{

    ListUsers lu, lu2;
    lu[0].idade = 10;
    strcpy(lu[0].nome, "Quim Ze");
    SaveUsers(lu);


    LoadUsers(&lu2);
    printf("%s\t %d\n", lu2[0].nome, lu2[0].idade);
    return 0;
}

*/

