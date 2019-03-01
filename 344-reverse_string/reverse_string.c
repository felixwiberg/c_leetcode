#include <stdio.h>

void reverseString(char* s, int sSize) {
	char tmp;

	for(int i = 0; i<sSize/2; i++){
		if(s[i] != s[sSize-i-1]){
			tmp = s[sSize-i-1];
			s[sSize-i-1] = s[i];
			s[i] = tmp;
		}
	}
}

int main(){
	char charArray[] ={ 'e', 'b', 'c', 'd', 'e' }; 	
	reverseString(charArray, 5);
	for(int i = 0; i<5; i++){
		printf("%c",charArray[i]);
	}
	return 0;
}
