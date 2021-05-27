#include <unistd.h> // biblioteca usada para importar as funções do comando execve
 

int main(void) { // inicialização da função principal main que executará todo o corpo do código
  char *binaryPath = "/bin/bash"; //definição do caminho do pacote binario a ser usado pelo primeiro parametro da função execve, O primeiro parâmetro deve ser o caminho de um binário executável ou um script.
  char *const args[] = {binaryPath, "-c", "echo \"Visit $HOSTNAME:$PORT from your browser.\"", NULL}; /*O primeiro parâmetro deve ser o caminho de um binário executável ou um script.
O segundo deve ser uma matriz de ponteiros de um personagem (char * Matriz []), e o último ponteiro tem de ser definido como NULL.*/
  char *const env[] = {"HOSTNAME=www.linuxhint.com", "PORT=8080", NULL}; /*O terceiro parâmetro deve ser um ambiente.*/
 
  execve(binaryPath, args, env); /*a função do sistema pega o caminho do arquivo binário executável (binaryPath), o segundo argumento é uma matriz que vc pode passar
  para execução*/
 
  return 0; // retorna 0 para finalização
  // Como podemos ver o execve reune 3 parametros para realizar uma ação conjunta e retornar um texto final que seria a união dos 3 parametros informados.
}