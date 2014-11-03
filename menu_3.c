#include <stdio.h>




// MENU estatisticas


int menu_1(void)
{
	
printf("Média de golos por jogo\n");

getch();
}
int menu_2(void)
{

printf("Qual a equipa?\n");

getch();
}
int menu_3(void)
{

printf("Melhor marcador\n");
getch();
}
int main()
{


	int op; // variÃ¡vel de opÃ§Ã£o para o menu

	system("chcp 1252>null"); //CODEPAGE PT

	// MENU ESTATISTICAS
	do{
		system ("cls");
        printf("+     Estatisticas     +\n\n");
        printf("| 1.Média de golos por jogo   |\n");
        printf("| 2.Média de idades por equipa |\n");
        printf("| 3.Melhor marcador     |\n");
        printf("| 0.Sair             |\n");
        printf("\n");

        scanf("%d", &op); //op=getchar(); // ou getch(); em windows

         // ou system("cls"); em windows
        switch (op) {
            case 1:
                    menu_1(); // chama função media de golos
                    break;
            case 2:
                    menu_2(); // chama função media de idades
                    break;
            case 3:
                    menu_3(); // chama função melhor marcador
                    break;

            case 0:
                   break;
                   //break; // sai do programa
        }


	} while (op !=0 );//getchar(); //system("pause");


}
