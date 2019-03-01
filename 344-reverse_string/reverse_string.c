#include <stdio.h>

void reverseString(char* s, int sSize) {
	char tmp;

	for(int i = 0; i<sSize/2; i++){
		if((int)s[i] != (int)s[sSize-i]){
			tmp = s[sSize-i-1];
			s[sSize-i-1] = s[i];
			s[i] = tmp;
		}
	}
}

int main(){
	char string[] = "aadfah";
	reverseString(string, 6);
	puts(string);
	return 0;
}
