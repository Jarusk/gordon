#include <stdio.h>

const char *sep = "----------------------------------------";

int main(int argc, char **argv){
	printf("%s\n            C TYPE SIZES\n%s\n\n",sep,sep);
	printf("       char: %2d bits\n",8*sizeof(char));
	printf("      short: %2d bits\n",8*sizeof(short));
	printf("        int: %2d bits\n",8*sizeof(int));
	printf("       long: %2d bits\n",8*sizeof(long));
	printf("  long long: %2d bits\n",8*sizeof(long long));
	printf("    pointer: %2d bits\n",8*sizeof((void *)0));
}
