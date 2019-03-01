#include <stdio.h>
#include <stdlib.h>

int c[32];
int d[32];

void fast_d2b(int x, int *a){
	int i;
	for(i=0;i<32;i++){
		*(a++) = (x >> i) & 0x1;
	}
}

int hammingDistance(int x, int y) {
	int res = 0, i;
	fast_d2b(x, c);
	fast_d2b(y, d);
	for(i = 0; i<32; i++){
		res += abs(c[i]-d[i]);
	}
	return res;
}

int main(){
	int hamming_distance = 0;
	int x = 555;
	int y = 23;
	hamming_distance = hammingDistance(x, y);
	printf("The hamming distance between %d and %d is %d\n", x, y, hamming_distance);

	return 0;
}
