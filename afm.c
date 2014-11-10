// Projeto Modulo Temático LTIC
// AFM - Software gestão para Associação de Futebol do Montenegro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Cabeçalhos das funções de "menu_1.c"


// Definição das estruturas de dados

#define J 101

typedef struct{

    int num_cc;
    char nome[50];
    char morada[50];
    char telefone[9];
    int idade;
    int ano_entrada;
    char pos[20];
    int ativo;

} jogador;

typedef jogador listajog[J];

listajog jog;

#include "menu_1.c"
#include "menu_2.c"
//#include "menu_3.c"
//#include "menu_4.c"

// ################################################

int init(void) // função para inicializar a estrutura jogadores
{
    int i;

    for (i=0;i<J;i++)
        {
             jog[i].num_cc=0;

        }
    return 0;
}

// Função salva_jogador
void salva_jogadores(listajog lj){
int i;
FILE *f = fopen("jogadores.bin", "wb");

    if (f == NULL)
    {
        fprintf(stderr, "salva_jogador:: Nao e possivel abrir para escrita.\n");
        exit(1);
    }
    fwrite(lj, sizeof(jogador), J, f );
    fclose(f);

}



void carrega_jogadores(listajog *lj){
int i;
FILE *f = fopen("jogadores.bin", "rb");

    if (f == NULL)
    {
        fprintf(stderr, "carrega_jogador:: Nao e possivel abrir para leitura.\n");
        exit(1);
    }
    fread(lj, sizeof(jogador), J, f );
    fclose(f);

}


// Função menu_4

int menu_4(void)
{
    int op;
        system("clear");

    	do{

        printf("+       Menu 4       +\n\n");
        printf("| 1.Salvar dados     |\n");
        printf("| 2.Carregar dados   |\n");
        printf("| 0.Sair             |\n");
        printf("\n");

        scanf("%d", &op); //op=getchar(); // ou getch(); em windows

        system("clear"); // ou system("cls"); em windows
        switch (op) {
            case 1:
                    salva_jogadores(jog); //menu_1(); // chama função menu Inserir/Editar
                    printf("\n\tFicheiro Guardado com sucesso!");
                    break;
            case 2:
                    carrega_jogadores(&jog);//menu_2(); // chama função menu Listar/Pesquisar
                    printf("\n\tFicheiro Carregado com sucesso!");
                    break;
            case 0:
                    break; //break; // sai do programa
        }


	} while (op!=0);//getchar(); //system("pause");

    return 0;
}

// MENU PRINCIPAL
int menu_principal()
{


	int op = '\n'; // variável de opção para o menu

	init(); //inicializa estrutura a zero
	//system("chcp 1252>null"); //CODEPAGE PT

	// MENU PRINCIPAL
	do{
        system("clear");
        printf("+     Gestão AFM     +\n\n");
        printf("| 1.Inserir/Editar   |\n");
        printf("| 2.Listar/Pesquisar |\n");
        printf("| 3.Estatisticas     |\n");
        printf("| 4.Carregar/Salvar  |\n");
        printf("| 0.Sair             |\n");
        printf("\n");

        scanf("%d", &op); //op=getchar(); // ou getch(); em windows

        system("clear"); // ou system("cls"); em windows
        switch (op) {
            case 1:
                    menu_1(); // chama função menu Inserir/Editar
                    break;
            case 2:
                    menu_2(); // chama função menu Listar/Pesquisar
                    break;
            case 3:
                    printf("| 3.Estatisticas     |\n"); // chama função menu Estatisticas
                    break;
            case 4:
                    printf("| 4.Carregar/Salvar  |\n"); // chama função menu Carregar/Salvar
                    menu_4();
                    break;
            case 0:
            return;
                    //break; // sai do programa
        }


	} while (1);//getchar(); //system("pause");


}

int main()
{

    menu_principal();

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

