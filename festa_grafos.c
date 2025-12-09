#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONVIDADOS 100
#define MAX_MESAS 50
#define MAX_PESSOAS_MESA 4 //limite de 4 pessoas por mesa

typedef struct {
    char nome[50];
    int id;
} Convidado;

int conflito[MAX_CONVIDADOS][MAX_CONVIDADOS];
int mesas[MAX_MESAS][MAX_CONVIDADOS];
int mesa_tamanho[MAX_MESAS];
Convidado convidados[MAX_CONVIDADOS];
int total_convidados = 0;

//verifica se o convidado pode sentar na mesa m
int pode_sentar(int convidado_id, int m) {
    // 1. REGRA: Se a mesa já tem 4, mao pode sentar.
    //procurar a próxima mesa (m+1).
    if(mesa_tamanho[m] >= MAX_PESSOAS_MESA){
        return 0; 
    }

    //2. REGRA: verifica arestas (conflitos)
    for(int i= 0; i < mesa_tamanho[m]; i++){
        int outro_id = mesas[m][i];
        if(conflito[convidado_id][outro_id]){
            return 0; //tem inimigos, vai para a proxima mesa
        }
    }
    return 1;
}

int organizar_festa(int max_mesas){
    for(int i = 0; i < total_convidados; i++) { //para cada convidado
        int colocado = 0;
        //tenta todas as mesas sequencialmente
        for(int m = 0; m < max_mesas; m++){
            if(pode_sentar(i, m)){ // if c não tem conflito  (e cabe na mesa)
                mesas[m][mesa_tamanho[m]++] = i; //colocar c na mesa i 
                colocado = 1;
                break; // break (ir para o próximo convidado)
            }
        }
        
        if (!colocado) {
            return 0; //return "Impossível organizar..."
        }
    }
    return 1;
}

void adicionar_conflito(int id1, int id2){
    conflito[id1][id2] = 1;
    conflito[id2][id1] = 1;
}

int adicionar_convidado(char nome[]){
    if (total_convidados >= MAX_CONVIDADOS) return -1;
    strcpy(convidados[total_convidados].nome, nome);
    convidados[total_convidados].id= total_convidados;
    return total_convidados++;
}

void imprimir_mesas(int max_mesas){
    printf("\n Convidados organizados\n");
    for(int m = 0; m < max_mesas; m++){
        if(mesa_tamanho[m] > 0){
            printf("Mesa %d: ", m + 1);
            for (int i = 0; i < mesa_tamanho[m]; i++){
                int id = mesas[m][i];
                printf(" %s ", convidados[id].nome);
            }
            printf("\n");
        }
    }
}

int main(){
    memset(conflito, 0, sizeof(conflito)); //inicializa a matriz de conflitos com 0
    memset(mesa_tamanho, 0, sizeof(mesa_tamanho));//inicializa o tamanho das mesas com 0

    int max_mesas;
    printf("Digite o numero maximo de mesas: ");
    scanf("%d", &max_mesas);

    int q_policial, q_bandido, q_devedor, q_agiota;
    int q_fla, q_vasco, q_ex1, q_ex2, q_fof, q_vitima;

    printf("Quantos policias e bandidos? "); 
    scanf("%d %d", &q_policial, &q_bandido);

    printf("Quantos devedores e agiotas? ");
    scanf("%d %d", &q_devedor, &q_agiota);

    printf("Quantos torcedores do flamengo e do vasco? ");
    scanf("%d %d", &q_fla, &q_vasco);

    printf("Quantos ex1 e ex2? ");
    scanf("%d %d", &q_ex1, &q_ex2);

    printf("Quantos fofoqueiros e vitimas? ");
    scanf("%d %d", &q_fof, &q_vitima);

    //organiza convidados na lista
    for(int i = 0; i < q_policial; i++){ char n[50]; sprintf(n, "Policial_%d", i+1); adicionar_convidado(n); }
    for(int i = 0; i < q_bandido; i++){ char n[50]; sprintf(n, "Bandido_%d", i+1); adicionar_convidado(n); }
    
    for(int i = 0; i < q_devedor; i++){ char n[50]; sprintf(n, "Devedor_%d", i+1); adicionar_convidado(n); }
    for(int i = 0; i < q_agiota; i++){ char n[50]; sprintf(n, "Agiota_%d", i+1); adicionar_convidado(n); }
    
    for(int i = 0; i < q_fla; i++){ char n[50]; sprintf(n, "Flamenguista_%d", i+1); adicionar_convidado(n); }
    for(int i = 0; i < q_vasco; i++){ char n[50]; sprintf(n, "Vascaino_%d", i+1); adicionar_convidado(n); }

    for(int i = 0; i < q_ex1; i++){ char n[50]; sprintf(n, "Ex1_%d", i+1); adicionar_convidado(n); }
    for(int i = 0; i < q_ex2; i++){ char n[50]; sprintf(n, "Ex2_%d", i+1); adicionar_convidado(n); }

    for(int i = 0; i < q_fof; i++){ char n[50]; sprintf(n, "Fofoqueiro_%d", i+1); adicionar_convidado(n); }
    for(int i = 0; i < q_vitima; i++){ char n[50]; sprintf(n, "Vitima_%d", i+1); adicionar_convidado(n); }
    
    //cria arestas (conflitos) entre os convidados
    for(int i = 0; i < total_convidados; i++){
        for(int j = i+1; j < total_convidados; j++){
            if (strstr(convidados[i].nome, "Policial") && strstr(convidados[j].nome, "Bandido")) adicionar_conflito(i,j);
            if (strstr(convidados[j].nome, "Policial") && strstr(convidados[i].nome, "Bandido")) adicionar_conflito(i,j);

            if (strstr(convidados[i].nome, "Devedor") && strstr(convidados[j].nome, "Agiota")) adicionar_conflito(i,j);
            if (strstr(convidados[j].nome, "Devedor") && strstr(convidados[i].nome, "Agiota")) adicionar_conflito(i,j);

            if (strstr(convidados[i].nome, "Flamenguista") && strstr(convidados[j].nome, "Vascaino")) adicionar_conflito(i,j);
            if (strstr(convidados[j].nome, "Flamenguista") && strstr(convidados[i].nome, "Vascaino")) adicionar_conflito(i,j);

            if (strstr(convidados[i].nome, "Ex1") && strstr(convidados[j].nome, "Ex2")) adicionar_conflito(i,j);
            if (strstr(convidados[j].nome, "Ex1") && strstr(convidados[i].nome, "Ex2")) adicionar_conflito(i,j);

            if (strstr(convidados[i].nome, "Fofoqueiro") && strstr(convidados[j].nome, "Vitima")) adicionar_conflito(i,j);
            if (strstr(convidados[j].nome, "Fofoqueiro") && strstr(convidados[i].nome, "Vitima")) adicionar_conflito(i,j);
        }
    }

    if(organizar_festa(max_mesas)){
        imprimir_mesas(max_mesas);
        printf("\n mesas que sobraram: %d\n", (max_mesas-1) - (total_convidados + MAX_PESSOAS_MESA -1)/MAX_PESSOAS_MESA);
    } 
    else{
        printf("Impossivel organizar: poucas mesas para muitos conflitos!\n");
    }
    return 0;
}