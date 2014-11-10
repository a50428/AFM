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
    /*.....*/

    LoadUsers(&lu2);
    printf("%s\t %d\n", lu2[0].nome, lu2[0].idade);
    return 0;
}
