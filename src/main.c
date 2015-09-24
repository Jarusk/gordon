#include <stdio.h>
#include "helper.h"

int main(int argc, char const *argv[]) {
  if(argc<2){
    printf("Need input file.\n");
    return 1;
  }
  int i;
  build(argv[1]);
  return 0;
}
