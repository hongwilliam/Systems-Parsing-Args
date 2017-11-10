#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char * line){
  char ** arguments;
  int i = 0;
  while (line != NULL){
    char * arg_component = strsep(&line, " ");
    arguments[i] = arg_component;
    i += 1;
  }

  return arguments;
}

int main(){
  char line[100] = "wow-this-is-cool";
  char *s1 = line;
  printf("[%s]\n", strsep(&s1, "-")); //[wow]
  printf("[%s]\n", s1); //[this-is-cool]

  char line2[100] = "ls -l -a";
  char *s2 = line2;
  char ** args = parse_args(line2);
  execvp(args[0], args);
}
