#include <stdio.h>
#include <string.h>

int numJewelsInStones(char* J, char* S){	
	int count = 0;
	int ascii[256] = {0};

	for(int i = 0; i < strlen(S); i++){
		ascii[(int)S[i]]++;
	}
	for(int i = 0; i < strlen(J); i++){
		count += (int)ascii[J[i]];
	}
	printf("%d",count);
}

int main(){
	int j = numJewelsInStones("csDfgV", "asdGgbAStyY");
	return 0;
}
