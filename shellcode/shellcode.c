#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void func(int key){
	char overflowme[32];
	printf("overflow me and get a shell: ");
	gets(overflowme);	// smash me!
	if(key == 0){
		printf("Your doing this wrong...get a shell!");
	}
	else{
		printf("Nah..\n");
	}
}
int main(int argc, char* argv[]){
	func(0xdeadbeef);
	return 0;
}

