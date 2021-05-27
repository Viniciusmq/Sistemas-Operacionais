#include <stdio.h>   // insportação da biblioteca stdio da linguagem C para utilização de printf no codigo
#include <stdlib.h> //por parte da stdlib estamos utilizando a função exit (0)
#include <sys/types.h> //esse biblioteca consiste na importação das funçoes de frok e excve que usaremos no código para os processos UNIX
#include <unistd.h> // importação para uso do frok em conjunto com a biblioteca anterior

int main(void)  // instanciação da função main para inicialização e execução do código
{
    int i;  // declaração de uma variável i que serusada para leitura de inteiro;
    pid_t pid; //declaração da variável pid do tipo pid_t (significa identificação de processo e é usado para representar ids de processo)

    if ((pid = fork()) < 0) // uma condicional que ao receber o retorno do fork() e for menor que 0  irá executar seu processo interno, a frok() tem como função
    { // abre a condição 
        perror("fork"); //A função perror mapeia o erro numérico, contido na variável global errno, para uma mensagem de erro. Em seguida, a função imprime essa mensagem de erro na saída de erro padrão (stderr).
        exit(1); //função que executa uma finalização da execução do código
    }//fecha a condição
    if (pid == 0)  // nesta função estamos verificando se o pid é igual a 0
    {
        //O código aqui dentro será executado no processo filho
        printf("pid do Filho: %d\n", getpid());
    }
    else
    {
        //O código neste trecho será executado no processo pai
        printf("pid do Pai: %d\n", getpid());
    }


    printf("Esta regiao sera executada por ambos processos\n\n"); // mensagem de finalização
    exit(0); //finalização do código
}