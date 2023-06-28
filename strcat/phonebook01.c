#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 100
#define  CAPACITY 100
char* names[CAPACITY];
char* numbers[CAPACITY];
int n = 0;

void load() {
	char fileName[BUFFER_SIZE];
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];

	scanf_s("%s", fileName, sizeof(fileName));

	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	while (fscanf_s(fp, "%s", buf1) != EOF) {
		fscanf_s(fp, "%s", buf2);
		names[n] = _strdup(buf1);
		numbers[n] = _strdup(buf2);
		n++;
	}
	fclose(fp);
}

void save() {
	char fileName[BUFFER_SIZE];
	char temp[BUFFER_SIZE];

	scanf_s("%s", temp, sizeof(temp));
	scanf_s("%s", fileName, sizeof(fileName));

	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%s %s\n", names[i], numbers[i]);
	}
	fclose(fp);
}

void add() {
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf_s("%s", buf1,sizeof(buf1));
	scanf_s("%s", buf2,sizeof(buf2));

	int i = n - 1;
	while (i >= 0 && strcmp(names[i], buf1) > 0) {
		names[i + 1] = names[i];
		numbers[i + 1] = numbers[i];
		i--;
	}
	names[i + 1] = _strdup(buf1);
	numbers[i + 1] = _strdup(buf2);
	n++;
	printf("%s was added successfully.\n", buf1);

}

void find() {
	char buf1[BUFFER_SIZE];
	scanf_s("%s", buf1, sizeof(buf1));

	int index = search(buf1);
	if(index ==-1)
		printf("No person named '%s' exists.\n", buf1);
	else
		printf("%s\n", numbers[index]);
	
}
int search(char* name) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, names[i]) == 0)
			return i;
	}
	return -1;
}

void removePerson() {
	char buf1[BUFFER_SIZE];
	scanf_s("%s", buf1, sizeof(buf1));

	int index = search(buf1);
	if (index == -1) {
		printf("No person named '%s' exists\n", buf1);
		return;
	}
	int j = index;
	for (; j < n - 1; j++) {
		names[j] = names[j + 1];
		numbers[j] = numbers[j + 1];
	}
	n--;
	printf("'%s' was deleted successfully \n", buf1);
}

void status() {
	for (int i = 0; i < n; i++) {
		printf("%s %s\n", names[i], numbers[i]);
	}
	printf("total %d person.\n", n);
}

int main() {

	char command[BUFFER_SIZE];

	while(1) {
		printf("$ ");
		scanf_s("%s", command, sizeof(command));

		if (strcmp(command, "add") == 0)
			add();
		else if (strcmp(command, "find") == 0)
			find();
		else if (strcmp(command, "remove") == 0)
			removePerson();
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "read") == 0)
			load();
		else if (strcmp(command, "save") == 0)
			save();

	}

	return 0;
}