#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

int main() {
	FILE* auti = fopen("auti.txt", "a+");
	fclose(auti);
	izborGlavni();
	return 0;
}