// Projeto Modulo Temático LTIC
// AFM - Software gestão para Associação de Futebol do Montenegro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Definição das estruturas de dados

#define J 101 // definição de constante global para nº jogadores
#define E 101 // definição de constante global para nº equipas
#define R 101 // definição de constante global para nº resultados

typedef struct{

    int num_cc;
    char nome[80];
    char morada[80];
    char telefone[9];
    int idade;
    int ano_entrada;
    char pos[50];
    int ativo;

} jogador; // estrutura para variável do tipo jogador

typedef jogador listajog[J]; // array de estruturas tipo jogador tamanho J

listajog jog; // variável do tipo array

typedef struct{

    int id;
    char nome[80];
    int lista[26]; // array inteiro que guarda o [id] de 25 jogadores (1-25)
    int ativo;

} equipa; // estrutura para variável do tipo equipa

typedef equipa listaequip[E]; // array de estruturas tipo jogador tamanho E

listaequip equip; // variável do tipo array

typedef struct{

    int id;
    char equipa_a[80];
    char equipa_b[80];
    int golos_a;
    int golos_b;
    int marcadores[21]; // array inteiro que guarda o [id] de 20 marcadores (1-20)
    char data[10];
    char local[80];
    int ativo;

} resultado; // estrutura para variável do tipo resultado

typedef resultado listaresult[R]; // array de estruturas tipo resultado tamanho R

listaresult result; // variável do tipo array


#include "menu_1.c"
#include "menu_2.c"
//#include "menu_3.c"
//#include "menu_4.c"

// #################################################################

/*void gotoxy(int x, int y) // função gotoxy()
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}*/

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
    printf("\n\tFicheiro salvo com sucesso!\n");
    getchar();
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
    printf("\n\tFicheiro carregado com sucesso!\n");
    getchar();
}


// Função menu_4

int menu_4(void)
{
    int op;


    	do{
        system("clear");
        printf("\n");
        printf("+       Menu 4       +\n\n");
        printf("| 1.Salvar dados     |\n");
        printf("| 2.Carregar dados   |\n");
        printf("| 0.Sair             |\n");
        printf("\n");

        scanf("%d", &op); //op=getchar(); // ou getch(); em windows

         // ou system("cls"); em windows
        switch (op) {
            case 1:
                    salva_jogadores(jog); //menu_1(); // chama função menu Inserir/Editar
                    getchar();
                    break;
            case 2:
                    carrega_jogadores(&jog);//menu_2(); // chama função menu Listar/Pesquisar
                    getchar();
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
                    system ("clear"); // chama função menu Carregar/Salvar
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

