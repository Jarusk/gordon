#include <stdio.h>
#include <string.h>

int build(char* name){
  printf("%s\n", name);
  FILE* fp;
  char* tmp = strtok(name,'.');
  printf("%s\n",tmp);
  //tmp = strcat(tmp,'.c');
  //fp = fopen(tmp,"w");
  //head(fp);
  //fclose(fp);
}

int head(FILE* out){
  int result;
  result = fprintf(out, "#include <stdio.h>\n");
  return result;
}
