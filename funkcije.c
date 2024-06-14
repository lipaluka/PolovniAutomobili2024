#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

int krajPrograma() {
	int kraj;
	char unos[3];
	printf("Jeste li sigurni da zelite izaci?\n");
	scanf("%2s", unos);

	if (strcmp(unos, "da") == 0 || strcmp(unos, "DA") == 0 || strcmp(unos, "Da") == 0) {
		kraj = 0;
	}
	else if (strcmp(unos, "ne") == 0 || strcmp(unos, "NE") == 0 || strcmp(unos, "Ne") == 0) {
		kraj = 1;
	}
	else {
		printf("Trebate unijeti da ili ne!!");
		return krajPrograma();
	}
	return kraj;
}
int var = 12;
void scanAuto(AUTO** mobil, int* broj) {
    FILE* auti = fopen("auti.txt", "r");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    AUTO temp;
    *broj = 0;

    while (fscanf(auti, "%d\n", &temp.id) == 1) {
        fgets(temp.marka, sizeof(temp.marka), auti);
        fgets(temp.model, sizeof(temp.model), auti);
        fgets(temp.karoserija, sizeof(temp.karoserija), auti);
        fgets(temp.pogon, sizeof(temp.pogon), auti);
        fgets(temp.motor, sizeof(temp.motor), auti);
        fgets(temp.boja, sizeof(temp.boja), auti);
        fscanf(auti, "%d\n%d\n%d\n%d\n%d\n", &temp.konji, &temp.newtonm, &temp.kilometraza, &temp.godiste, &temp.cijena);
        (*broj)++;
    }
    rewind(auti);

    *mobil = (AUTO*)malloc(*broj * sizeof(AUTO));
    if (*mobil == NULL) {
        perror("Greska pri alokaciji memorije");
        fclose(auti);
        return;
    }

   
    for (int i = 0; i < *broj; i++) {
        fscanf(auti, "%d\n", &(*mobil)[i].id);
        fgets((*mobil)[i].marka, sizeof((*mobil)[i].marka), auti);
        fgets((*mobil)[i].model, sizeof((*mobil)[i].model), auti);
        fgets((*mobil)[i].karoserija, sizeof((*mobil)[i].karoserija), auti);
        fgets((*mobil)[i].pogon, sizeof((*mobil)[i].pogon), auti);
        fgets((*mobil)[i].motor, sizeof((*mobil)[i].motor), auti);
        fgets((*mobil)[i].boja, sizeof((*mobil)[i].boja), auti);
        fscanf(auti, "%d\n%d\n%d\n%d\n%d\n", &(*mobil)[i].konji, &(*mobil)[i].newtonm, &(*mobil)[i].kilometraza, &(*mobil)[i].godiste, &(*mobil)[i].cijena);

        (*mobil)[i].marka[strcspn((*mobil)[i].marka, "\n")] = '\0';
        (*mobil)[i].model[strcspn((*mobil)[i].model, "\n")] = '\0';
        (*mobil)[i].karoserija[strcspn((*mobil)[i].karoserija, "\n")] = '\0';
        (*mobil)[i].pogon[strcspn((*mobil)[i].pogon, "\n")] = '\0';
        (*mobil)[i].motor[strcspn((*mobil)[i].motor, "\n")] = '\0';
        (*mobil)[i].boja[strcspn((*mobil)[i].boja, "\n")] = '\0';
    }

    fclose(auti);
}

void printAuto(const AUTO* mobil, int broj) {
	for (int i = 0; i < broj; i++) {
		printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonmetri: %d\nKilometraza: %d\nGodiste: %d\nCijena: %d(EUR)\n\n",
			mobil[i].id, mobil[i].marka, mobil[i].model, mobil[i].karoserija,
			mobil[i].pogon, mobil[i].motor, mobil[i].boja, mobil[i].konji,
			mobil[i].newtonm, mobil[i].kilometraza, mobil[i].godiste, mobil[i].cijena);
	}
}

void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void trimNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

