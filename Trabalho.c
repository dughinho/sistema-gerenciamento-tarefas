#include <stdio.h>
#include <string.h>
#define Tamanho 50
#define Maximo 100
int quantidade = 0;
void cadastrarTarefa(char Dados[][4][Tamanho]) {
        if (quantidade < Maximo) {
        printf("Titulo: ");
        fgets(Dados[quantidade][0], Tamanho, stdin);
        Dados[quantidade][0][strcspn(Dados[quantidade][0], "\n")] = 0; 

        printf("Descricao: ");
        fgets(Dados[quantidade][1], Tamanho, stdin);
        Dados[quantidade][1][strcspn(Dados[quantidade][1], "\n")] = 0; 

        printf("Prioridade (Alta/Media/Baixa): ");
        fgets(Dados[quantidade][2], Tamanho, stdin);
        Dados[quantidade][2][strcspn(Dados[quantidade][2], "\n")] = 0; 

        printf("Status (Pendente/Concluida): ");
        fgets(Dados[quantidade][3], Tamanho, stdin);
        Dados[quantidade][3][strcspn(Dados[quantidade][3], "\n")] = 0; 

        quantidade++;
    } else {
        printf("Limite de tarefas atingido.\n");
        return;
    }
}
void listarTarefas(char Dados[][4][Tamanho]) {
    if (quantidade == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    printf("Lista de Tarefas:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d. Titulo: %s, Descricao: %s, Prioridade: %s, Status: %s\n", 
        i + 1, Dados[i][0], Dados[i][1], Dados[i][2], Dados[i][3]);
    }
}

void editarTarefa(char Dados[][4][Tamanho], int indice) {
    printf("Editar Tarefa %d:\n", indice + 1);
    printf("Novo Titulo: ");
    fgets(Dados[indice][0], Tamanho, stdin);
    strtok(Dados[indice][0], "\n");
    printf("Nova Descricao: ");
    fgets(Dados[indice][1], Tamanho, stdin);
    strtok(Dados[indice][1], "\n");
    printf("Nova Prioridade (Alta/Media/Baixa): ");
    fgets(Dados[indice][2], Tamanho, stdin);
    strtok(Dados[indice][2], "\n");
    printf("Novo Status (Pendente/Concluida): ");
    fgets(Dados[indice][3], Tamanho, stdin);
    strtok(Dados[indice][3], "\n");
    printf("Tarefa editada com sucesso!\n");
}

void excluirTarefa(char Dados[][4][Tamanho], int indice) {
    for(int i = indice; i < quantidade -1; i++){
        for(int j = 0; j < 4; j++){
            strcpy(Dados[i][j], Dados[i + 1][j]);
        }
        quantidade--;
        printf("Tarefa excluida com sucesso!\n");
    }
}
void salvarTarefasEmArquivo(char Dados[][4][Tamanho]) {
    FILE *arquivo = fopen("tarefas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Titulo: %s\nDescricao: %s\nPrioridade: %s\nStatus: %s\n\n", 
                Dados[i][0], Dados[i][1], Dados[i][2], Dados[i][3]);
    }
    fclose(arquivo);
    printf("Tarefas salvas com sucesso em tarefas.txt!\n");
}
int main(){
    char Dados[Maximo][4][Tamanho];
    int opcao;
    do{
        printf("=== Sistema de Gerenciamento de Tarefas ===\n");
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Editar Tarefa\n");
        printf("4. Excluir Tarefa\n");
        printf("5. Salvar Tarefas em Arquivo\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        int indice = 0;
        if(opcao == 1){
            cadastrarTarefa(Dados);
        }
        else if(opcao == 2){
            listarTarefas(Dados);
        }
        else if(opcao == 3){
            printf("Digite o indice da tarefa a ser editada: ");
            scanf("%d", &indice);
            getchar();
            if(indice >= 1 && indice <= quantidade) {
                editarTarefa(Dados, indice);
            } else {
                printf("Tarefa Invalida!\n");
            }
        }
        else if(opcao == 4){
            printf("Digite o indice da tarefa a ser excluida: ");
            scanf("%d", &indice);
            getchar();
            if(indice >= 1 && indice <= quantidade) {
                excluirTarefa(Dados, indice);
            } else {
                printf("Tarefa Invalida!\n");
            }
        }
        else if(opcao == 5){
            salvarTarefasEmArquivo(Dados);
        }
        else if(opcao == 6){
            printf("Voce escolheu sair.\n");
        }
        else{
            printf("Opcao invalida! Tente novamente.\n");
        }
    }while(opcao != 6);
    
    return 0;
}