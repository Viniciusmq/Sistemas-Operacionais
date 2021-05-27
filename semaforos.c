#include <stdio.h> // importa as principais bibliotecas de C para o seu fncinamento.
#include <pthread.h> //podemos obter a biblioteca de semáforos POSIX.
#include <semaphore.h>// para isso importa-se a seguinte biblioteca para usifruir dos comandos da funçẽs de semáforos
#include <unistd.h> //
sem_t mutex;
void* thread(void* arg) { //função que haje como uma thread
   sem_wait(&mutex); //função usada para bloquear uma ação ou deixar em espera
   printf("\nEntered into the Critical Section..\n");
   sleep(3); //espera 3 segundos na execução
   printf("\nCompleted...\n"); //realiza o a escrita na tela da string 
   sem_post(&mutex); // apos realizar o bloqueio pela sem_wait precisa-se realiar o desbloqueio e para isso udamos a função sem_post passando o parâmetro da variável global
}
int main() { // função principal de execução
   sem_init(&mutex, 0, 1); //O semáforo inicializa sem_init () ou sem_open () para a Comunicação entre processos (IPC).
   pthread_t th1,th2; //instacia uma variavel para verificar o valor da thread
   pthread_create(&th1, NULL ,thread, NULL ); // essa função inicia uma nova thread para executar a função void thread, senod a thread 1
   sleep(2); // espera um tempo de 2 segundos no código
   pthread_create(&th2, NULL ,thread, NULL );// executa o mesmo processo da linha 16, mas agora com a variável th2
   //Une thread th1 com a main thread
   pthread_join(th1, NULL );//A função deve suspender a execução do thread th1 de chamada até que o thread de destino termine, a menos que o thread de destino já tenha terminado.
   pthread_join(th2, NULL ); // mesma ação da linha 20
   sem_destroy(&mutex); // finaliza o processo do semáforo
}