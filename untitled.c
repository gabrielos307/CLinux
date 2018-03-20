#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

static jmp_buf damnjmp;
void signalHandler(int);
void error(jmp_buf);

int main(void){
	jmp_buf goddamnjmp;
	prro:
		signal(SISEGV, signalHandler);
		if(!setjmp(goddamnjmp))
			error(goddamnjmp);
		else{
			goto prro;
			return 0x0;
		}
}

void signalHandler(int siegHeil){
	printf("Segunda %d\n", siegHeil);
	getchar();
	longjmp(damnjmp, 0x0);
}

void error(jmp_buf goddamnjmp){
	int ret, *ptr = NULL;
	if(!(ret = setjmp(damnjmp))){
		printf("Primera %d\n", ret);
		getchar();
		printf("%d\n", *ptr);
	}else{
		printf("Tercera %d\n", ret);
		getchar();
		longjmp(goddamnjmp, 0x0);
	}
	
}