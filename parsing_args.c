#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char * line){
  char **arguments = (char **)calloc(6, sizeof(char *));
  int i = 0;
  while(i < sizeof(arguments)){
    arguments[i] = strsep(&line," ");
    i++;
  }
  arguments[i] = NULL;
  return arguments;
}

int main(){
  char line[100] = "wow-this-is-cool";
  char *s1 = line;
  printf("[%s]\n", strsep(&s1, "-")); //[wow]
  printf("[%s]\n", s1); //[this-is-cool]
  printf("\n");
  
  char line2[] = "ls -l -a";
  char *s2 = line2;
  char **args = parse_args(line2);
  execvp(args[0], args);
}
