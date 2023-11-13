#include <stdio.h>
#include <locale.h>

struct Pino
{
    int pilha[3];
};

struct Pino p[3];
int topo[3];

void preencherOrigem();
void empilhar(int x);
int desempilhar();
int condicaoVitoria();
void exibirNivel(int nivel);
void exibir();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    topo[2] = topo[1] = -1;
    int vitoria = 0;
    int x;

    preencherOrigem();
    exibir();

    printf("Torre de Hanoi\n");
    printf("Objetivo: Seu objetivo é inserir os números no terceiro pino \n");
    printf("de forma que,de cima para baixo, estejam em ordem crescente.\n\n");
    printf("Regra: Você não pode colocar um número maior acima de um número menor em nenhum momento do jogo.\n");
    printf("Boa sorte!\n");

    while (vitoria != 1)
    {
        x = desempilhar();
        empilhar(x);
        vitoria = condicaoVitoria();
        exibir();
    }

    printf("Parabéns, você venceu!\n");

    return 0;
}

void preencherOrigem()
{
    p[0].pilha[0] = 3;
    p[0].pilha[1] = 2;
    p[0].pilha[2] = 1;
    topo[0] = 2;
}

void empilhar(int x)
{
    int pino;
    printf("Escolha o pino para empilhar (1, 2 ou 3): ");
    scanf("%d", &pino);
    printf("\n");

    if (pino < 1 || pino > 3)
    {
        printf("Número inválido. Escolha um pino válido (1, 2 ou 3).\n");
        empilhar(x);
        return;
    }

    pino--; // Ajuste para índice de array (1, 2 ou 3) para (0, 1 ou 2)

    if (p[pino].pilha[topo[pino]] > x || p[pino].pilha[topo[pino]] == 0)
    {
        topo[pino]++;
        p[pino].pilha[topo[pino]] = x;
    }
    else
    {
        printf("Não é possível empilhar aqui. Tente novamente.\n");
        empilhar(x);
    }
}

int desempilhar()
{
    int pino, x;
    printf("Escolha o pino para desempilhar (1, 2 ou 3): ");
    scanf("%d", &pino);
    printf("\n");

    if (pino < 1 || pino > 3)
    {
        printf("Número inválido. Escolha um pino válido (1, 2 ou 3).\n");
        return desempilhar();
    }

    pino--; // Ajuste para índice de array (1, 2 ou 3) para (0, 1 ou 2)

    if (p[pino].pilha[topo[pino]] == -1)
    {
        printf("Pino vazio, não é possível desempilhar. Tente novamente.\n");
        return desempilhar();
    }

    x = p[pino].pilha[topo[pino]];
    p[pino].pilha[topo[pino]] = 99;
    topo[pino]--;
    return x;
}

void exibirNivel(int nivel)
{
    for (int i = 0; i < 3; i++)
    {
        if (p[i].pilha[nivel] == 99 || p[i].pilha[nivel] == 0)
        {
            printf("[ ]\t");
        }
        else
        {
            printf("[%d]\t", p[i].pilha[nivel]);
        }
    }
    printf("\n");
}

void exibir()
{
    for (int i = 2; i >= 0; i--)
    {
        exibirNivel(i);
    }
}

int condicaoVitoria()
{
    if (p[2].pilha[0] == 3 && p[2].pilha[1] == 2 && p[2].pilha[2] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// cd C:\Users\vinicius.silva\Torre de Hanoi
// gcc -o torre_de_hanoi main.c
// torre_de_hanoi.exe
