#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main() {
  char string_origem[20];
  char string_destino[40];

  puts("Digite a primeira string: ");
  gets(string_destino);
  puts("Digite a segunda string: ");
  gets(string_origem);
  
  strcat(string_destino, string_origem);
  
  puts("\n%s\n", string_destino ); 
  return 0;  
}
