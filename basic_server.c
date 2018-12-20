#include "pipe_networking.h"
#include <stdio.h>
#include <ctype.h>

void mom(char* str){
  int i = 0;
  while(str[i]){
    str[i] = toupper(str[i]);
    i++;
  }
}

int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  while(1){
    char input[100];
    while(read(from_client, input, 100)){
      printf("from client: %s\n", input);
      mom(input);
      strcat(input, "!!");
      write(to_client, input, strlen(input));
    }
  }
}
