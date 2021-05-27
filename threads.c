#include <stdio.h> // biblioteca da linguagem C que será usada para retorno de algumas mensagens e para a função principal
#include <stdlib.h> // Com a utilização da função exit(), usaremos esta função para chamala
#include <pthread.h> /*a biblioteca define estruturas de dados e atributos para configurar os threads. 
De modo geral, esses atributos são passados como argumentos para os parâmetros das funções*/
 
/*Rotina que será executada*/
void * routine(void *arg);
 
int main (int argc, char *argv[])
{
    pthread_t thread_id; // instanciamento do dado ser inicializado na criação da threads, 1° paramentro da função pthread_create
    void * thread_res; //instanciamento do ponteiro thread_res
    int rstatus; // variável criada para recerber o retorno da função pthread e fazer as devidas verificações
    
    /*tenta iniciar o thread, indicando a função 'routine' e passando como argumento a string "Minha primeira Thread!"*/
    rstatus = pthread_create (&thread_id, NULL, routine, (void*)("Minha primeira Thread!")); // estrutura principal da função "int pthread_create (pthread_t *thread, pthread_attr_t *attr, void *(*start_ routine) (void *), void *arg);"
 
    
    if(rstatus != 0)/*verificar se ocorreu algum erro na chamada de pthread_create*/
    { //abertura da condicional
        printf ("Erro ao criar o thread.\n"); // escreve na tela uma mensagem de erro caso a phtread_create não seja criada
        exit(EXIT_FAILURE); // finaliza o código com a função exit para mostrar o erro
    }
 
    printf ("Thread criado com sucesso!\n"); // Se a phtread_create for sucesso há a escrita da mesnagem dessa linha
 
    
    rstatus = pthread_join (thread_id, &thread_res); /*aguarda finalização do thread identificado por thread_id. O retorno é passado pelo ponteiro thread_res dando seguencia ao código*/
 
    /*verificar se ocorreu algum erro na chamada de pthread_join*/
    if(rstatus != 0)
    {
        printf ("Erro ao aguardar finalização do thread.\n");
        exit(EXIT_FAILURE);
    }
 
    /*exibe o valor de retorno da função 'routine'*/
    printf ("Thread finalizado! Retorno = %s\n", (char *)thread_res);
 
    return 0;
}
 
void * routine(void *arg)
{
    /*exibe o argumento recebido*/
    printf("Argumento: %s\n", (char *)arg);
 
    /*finaliza a função retornando o argumento que foi recebido*/
    pthread_exit(arg);
}