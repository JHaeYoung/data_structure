#include <stdio.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS


int main() {
	char* words[100];
	int n = 0;
	unsigned int buffer[100];

	while (n < 4 && scanf_s("%s", buffer,sizeof(buffer)) != EOF)
	{
		words[n] = buffer;
		n++;
	}

	for (int i = 0; i < 4; i++) {
		printf("%s\n", words[i]);
	}

	return 0;
}
