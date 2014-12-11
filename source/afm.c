// Projeto Modulo Temático LTIC
// AFM - Software gestão para Associação de Futebol do Montenegro
// "afm.c"

/* !
* \ file menu_1.c
* \ brief Projeto Modulo Temático LTIC 2014/15 "afm.c"
* \ details "afm.c" Ficheiro principal do programa, implementa o menu principal, as estruturas de dados e a inicialização de variáveis
* \ author Valter António
* \ date 01 dez 2014
* \ bug sem erros detetados
* \ version 0.1
* \ copyright GNU Public License.
*/

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
    char telefone[10];
    int idade;
    int ano_entrada;
    int pos_list;
    char pos[50];
    int ativo;
    int golos; // guarda o nº golos do jogador
    int eq; // guarda o inteiro do id da equipa à qual pertence.

} jogador; // estrutura para variável do tipo jogador

typedef jogador listajog[J]; // array de estruturas tipo jogador tamanho J

listajog jog; // variável do tipo array

typedef struct{

    int id;
    char nome[80];
    int lista[26]; // array inteiro que guarda o [id] de 25 jogadores (1-25)
    int vitorias; // acumulador
    int empates; // acumulador
    int derrotas; // acumulador
    int ativo;

} equipa; // estrutura para variável do tipo equipa

typedef equipa listaequip[E]; // array de estruturas tipo jogador tamanho E

listaequip equip; // variável do tipo array

typedef struct{

    int id;
    int equipa_a; // guarda o ID da equipa A
    int equipa_b; // guarda o ID da equipa B
    int golos_a;
    int golos_b;
    int marcadores[21]; // array inteiro que guarda o [id] de 20 marcadores (1-20)
    int marcados[21];
    char data[15];
    char local[50];
    int ativo;

} resultado; // estrutura para variável do tipo resultado

typedef resultado listaresult[R]; // array de estruturas tipo resultado tamanho R

listaresult result; // variável do tipo array

//inclusão de ficheiros locais
#include "menu_1.c"
#include "menu_2.c"
#include "menu_3.c"

// ! init
/* *
* funcao que inicializa as estruturas de dados
* \ param void
* \ return int
*/
int init(void) // função para inicializar as 3 estruturas de dados
{
    int i,j,k,m;

    for (i=0;i<J;i++)
        {
             jog[i].num_cc=0;
             jog[i].golos=0;
        }
    for (j=0;j<E;j++)
        {
             equip[i].id=0;
             for (m=0;m<26;m++) equip[j].lista[m]=0;
             equip[i].vitorias=0;
             equip[i].empates=0;
             equip[i].derrotas=0;
        }
    for (k=0;k<R;k++)
        {
             result[i].id=0;
             result[i].golos_a=0;
             result[i].golos_b=0;
        }

    return 0;
}

// ! salva_dados
/* *
* funcao que salva (guarda) os registos das estruturas de dados
* \ param lj : listajog
* \ param le : listaequip
* \ param lr : listaresult
* \ return int
*/
void salva_dados(listajog lj,listaequip le,listaresult lr){
int i;
FILE *fj = fopen("jogadores.bin", "wb");
FILE *fe = fopen("equipas.bin", "wb");
FILE *fr = fopen("resultados.bin", "wb");

    if (fj == NULL )
    {
        printf("\n\tErro! Ficheiro de dados inexistente!");
        getchar();
        return;
    }
    fwrite(lj, sizeof(jogador), J, fj );
    fclose(fj);
    fwrite(le, sizeof(equipa), E, fe );
    fclose(fe);
    fwrite(lr, sizeof(resultado), R, fr );
    fclose(fr);
    printf("\n\tFicheiro de dados salvo com sucesso!\n");
    getchar();
}

// ! carrega_dados
/* *
* funcao que carrega os registos das estruturas de dados
* \ param lj : listajog
* \ param le : listaequip
* \ param lr : listaresult
* \ return int
*/
int carrega_dados(listajog *lj,listaequip *le,listaresult *lr){
int i;
FILE *fj = fopen("jogadores.bin", "rb");
FILE *fe = fopen("equipas.bin", "rb");
FILE *fr = fopen("resultados.bin", "rb");

    if (fj == NULL )
    {
        printf("\n\tErro! Ficheiro de dados inexistente!");
        getchar();
        return;
    }
    fread(lj, sizeof(jogador), J, fj );
    fclose(fj);
    fread(le, sizeof(equipa), E, fe );
    fclose(fe);
    fread(lr, sizeof(resultado), R, fr );
    fclose(fr);
    printf("\n\tFicheiro de dados carregado com sucesso!\n");
    getchar();
}

// ! menu_4
/* *
* funcao que implementa o Menu 4 (Salvar/Carregar Dados)
* \ param void
* \ return int
*/
int menu_4(void)
{
    int op;


    	do{
        system("clear");
        printf("+       Menu 4       +\n\n");
        printf("| 1.Salvar dados     |\n");
        printf("| 2.Carregar dados   |\n");
        printf("| 0.Sair             |\n");
        printf("\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                    salva_dados(jog,equip,result);
                    getchar();
                    break;
            case 2:
                    carrega_dados(&jog,&equip,&result);
                    getchar();
                    break;
            case 0:
                    break; // sai do menu
        }


	} while (op!=0);

    return;
}

// ! menu_principal
/* *
* funcao que implementa o Menu Principal do programa
* \ param void
* \ return int
*/
int menu_principal()
{
	int op; // variável de opção para o menu

	init(); //inicializa as estruturas de dados a zero

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
        scanf("%d", &op);
        fflush(stdin);
        switch (op) {
            case 1:
                    menu_1(); // chama função menu Inserir/Editar
                    break;
            case 2:
                    menu_2(); // chama função menu Listar/Pesquisar
                    break;
            case 3:
                    menu_3(); // chama função menu Estatisticas
                    break;
            case 4:
                    system ("clear"); // chama função menu Carregar/Salvar
                    menu_4();
                    break;
            case 0:
                    break;
        }
	} while (op!=0);
}

int main()
{
    menu_principal();
}
// FIM DO PROGRAMA #############################################################
