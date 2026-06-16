#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int RA;
    float notas[3];
    int frequencia;
} Aluno;

void imprimeMenu();
void inserir(Aluno[], int, int);
void remover(Aluno[], int, int);
void visualizarTodos(Aluno[], int);
int buscar(Aluno[], int, int);
void mostraAluno(Aluno[], int, int);

int main()
{
    Aluno turma[40];
    int op=0, n=0, ra;
    do{
        imprimeMenu();
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nDigite o RA: ");
                scanf("%d", &ra);
                if(buscar(turma, n, ra)==-1){
                    inserir(turma, n, ra);
                    n++;
                }
                else{
                    printf("Esse aluno já foi inserido!");
                }
                
                break;
            case 2:
                printf("\nDigite o RA: ");
                scanf("%d", &ra);
                remover(turma, n, ra);
                break;
            case 3:
                visualizarTodos(turma, n);
                break;
            case 4:
                printf("\nDigite o RA: ");
                scanf("%d", &ra);
                mostraAluno(turma, n, ra);
                break;
            case 5:
                printf("\nSaindo do sistema!\n");
                break;
        }
    } while(op!=5);
}

void imprimeMenu(){
    printf("\n\nMenu:\n\n");
    printf("1- inserir novo aluno\n");
    printf("2- remover aluno\n");
    printf("3- visualizar todos os aluno\n");
    printf("4- buscar aluno pelo RA\n");
    printf("5- sair do sistema\n\n");
    printf("Digite uma das opções: ");
}

void inserir(Aluno turma[], int n, int ra){
    turma[n].RA = ra;
    printf("Digite o nome: ");
    getchar();
    fgets(turma[n].nome, sizeof(turma[n].nome), stdin);
    turma[n].nome[strlen(turma[n].nome)-1] = '\0';
    
    for(int i=0; i<3; i++){
        printf("Digite a %dº nota: ", i+1);
        scanf("%f", &turma[n].notas[i]);
    }
    
    printf("Digite a frequencia: ");
    scanf("%d", &turma[n].frequencia);
}

void remover(Aluno turma[], int n, int ra){
    int posicao = buscar(turma, n, ra);
    if(posicao==-1)
        printf("Aluno nao encontrado");
    else{
        for(int i = posicao; i < n-1; i++){
            turma[i] = turma[i+1];
        }
        n--;
        printf("Aluno removido com sucesso!\n");
    }
}

void visualizarTodos(Aluno turma[], int n){
    for(int i=0; i<n; i++){
        printf("\nALUNO %d:\n", i+1);
        printf("Nome: %s\n", turma[i].nome);
        printf("RA: %d\n", turma[i].RA);
        for(int j=0; j<3; j++){
            printf("Nota %.2f: %d\n",j+1, turma[i].notas[j]);
        }
        printf("Frequência: %d\n", turma[i].frequencia);
    }
}

int buscar(Aluno turma[], int n, int ra){
    int posicaoEncontrado = -1;
    for(int i=0; i<n; i++){
        if(turma[i].RA==ra){
            posicaoEncontrado = i;
            return posicaoEncontrado;
        }
    }
    if(posicaoEncontrado==-1){
        return -1;
    }
}

void mostraAluno(Aluno turma[], int n, int ra){
    int posicao = buscar(turma, n, ra);
    if(posicao!=-1){
        printf("Nome: %s\n", turma[posicao].nome);
        printf("RA: %d\n", turma[posicao].RA);
        for(int j=0; j<3; j++){
            printf("Nota %.2f: %d\n",j+1, turma[posicao].notas[j]);
        }
        printf("Frequência: %d\n", turma[posicao].frequencia);
    }
}

