#include <stdio.h>




// MENU estatisticas
int medgolos (void)
{
    int a,b,numgolos=0, numjogos=0,i,aux=0;
    float media;
    for (i=0;i<R;i++)
        {
            if  (result[i].ativo==1)
              {
              a=result[i].golos_a;
              b=result[i].golos_b;
              numgolos=a+b;
              aux=aux+numgolos;
              numjogos++;
                }
         }
    media=(float)aux/numjogos;

    printf("media de golos por jogo �: %.2f",media);
    getchar();
getchar();
menu_3();
}



int menu_3()
{


	int op; // variável de opção para o menu

	system("chcp 1252>null"); //CODEPAGE PT

	// MENU ESTATISTICAS
	do{
		//system ("cls");
        printf("+     Estatisticas     +\n\n");
        printf("| 1.M�dia de golos por jogo   |\n");
        printf("| 2.M�dia de idades por equipa |\n");
        printf("| 3.Melhor marcador     |\n");
        printf("| 0.Sair             |\n");
        printf("\n");

        scanf("%d", &op); //op=getchar(); // ou getch(); em windows

         // ou system("cls"); em windows
        switch (op) {
            case 1:
                    medgolos(); // chama fun��o media de golos
                    break;
            case 2:
                    menu_2(); // chama fun��o media de idades
                    break;
            case 3:
                    menu_3(); // chama fun��o melhor marcadord
                    break;

            case 0:
                   break;
                   //break; // sai do programa
        }


	} while (op !=0 );//getchar(); //system("pause");


}
