#include "../include/unistd.h"


int main(int argc, char ** argv){
		long result = write(1,"Hello\n",7);
		printf("%ld\n%d\n",result,brk(0));
		exit(0);
}

