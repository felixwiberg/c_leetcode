#include <stdio.h>
#include <stdlib.h>

int c[32];
int d[32];

int fast_d2b(int x, int y, int *c, int *d){
	int i;
	int res = 0;
	for(i=0;i<32;i++){
		*(c) = (x >> i) & 0x1;
		*(d) = (y >> i) & 0x1;
		res += abs(*c - *d);
		d++;
		c++;
	}
	return res;
}

int hammingDistance(int x, int y) {
	int res = 0;
	res = fast_d2b(x, y, c, d);
	return res;
}

int main(){
	int hamming_distance = 0;
	int x = 1;
	int y = 21309589;
	hamming_distance = hammingDistance(x, y);
	printf("The hamming distance between %d and %d is %d\n", x, y, hamming_distance);

	return 0;
}
