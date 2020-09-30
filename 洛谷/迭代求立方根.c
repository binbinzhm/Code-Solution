#include <stdio.h>
/*
Âå¹È£º 

*/
int main() {
	int n, m;
	char a[105][105];
	int output[105][105] = {0};
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= m;j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	for (i = 0;i <= m+1;i++) {
		a[0][i] = '?';
		a[n+1][i+1] = '?';
	}
	for (i = 0;i <= n+1;i++) {
		a[i][0] = '?';
		a[m+1][0] = '?';
	}
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= m;j++) {
			if (a[i][j] != '*') {
				if (a[i-1][j-1] == '*') output[i][j]++;
				if (a[i-1][j] == '*') output[i][j]++;
				if (a[i-1][j+1] == '*') output[i][j]++;
				if (a[i][j-1] == '*') output[i][j]++;
				if (a[i][j+1] == '*') output[i][j]++;
				if (a[i+1][j-1] == '*') output[i][j]++;
				if (a[i+1][j] == '*') output[i][j]++;
				if (a[i+1][j+1] == '*') output[i][j]++;
			}
		}
	}
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= m;j++) {
			if (a[i][j] != '*') {
				printf("%d", output[i][j]);
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	} 
} 
