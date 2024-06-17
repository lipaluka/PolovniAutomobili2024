#define _CRT_SECURE_NO_WARNINGS
#include"header.h"


void pregledAutomobila() {
	FILE* auti = fopen("auti.txt", "r");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	AUTO mobil;
	char buffer[256];
	while (fscanf(auti, "%d\n", &mobil.id) == 1) {

		fgets(mobil.marka, sizeof(mobil.marka), auti);
		mobil.marka[strcspn(mobil.marka, "\n")] = '\0'; 

		fgets(mobil.model, sizeof(mobil.model), auti);
		mobil.model[strcspn(mobil.model, "\n")] = '\0'; 

		fgets(mobil.karoserija, sizeof(mobil.karoserija), auti);
		mobil.karoserija[strcspn(mobil.karoserija, "\n")] = '\0'; 

		fgets(mobil.pogon, sizeof(mobil.pogon), auti);
		mobil.pogon[strcspn(mobil.pogon, "\n")] = '\0'; 

		fgets(mobil.motor, sizeof(mobil.motor), auti);
		mobil.motor[strcspn(mobil.motor, "\n")] = '\0'; 

		fgets(mobil.boja, sizeof(mobil.boja), auti);
		mobil.boja[strcspn(mobil.boja, "\n")] = '\0'; 

		fscanf(auti, "%d\n", &mobil.konji);
		fscanf(auti, "%d\n", &mobil.newtonm);
		fscanf(auti, "%d\n", &mobil.kilometraza);
		fscanf(auti, "%d\n", &mobil.godiste);
		fscanf(auti, "%d\n", &mobil.cijena);

		printf("ID: %d\n", mobil.id);
		printf("Marka: %s\n", mobil.marka);
		printf("Model: %s\n", mobil.model);
		printf("Karoserija: %s\n", mobil.karoserija);
		printf("Pogon: %s\n", mobil.pogon);
		printf("Motor: %s\n", mobil.motor);
		printf("Boja: %s\n", mobil.boja);
		printf("Konjske snage: %d\n", mobil.konji);
		printf("Newton-metri: %d\n", mobil.newtonm);
		printf("Kilometraza: %d\n", mobil.kilometraza);
		printf("Godiste: %d\n", mobil.godiste);
		printf("Cijena: %d EUR\n", mobil.cijena);
		printf("---------------------------------\n");
	}

	fclose(auti);
}

void pretraziAute() {
	FILE* auti = fopen("auti.txt", "r");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	printf("Izaberi kriterij pretrage:\n");
	printf("1. ID\n2. Marka\n");
	enum pretraga {
		ID = 1,
		MARKA
	};
	enum pretraga izbor;
	char unos[15];
	scanf("%14s", unos);
	getchar();
	if (strcmp(unos, "id") == 0)
		izbor = ID;
	else if (strcmp(unos, "marka") == 0)
		izbor = MARKA;
	else {
		printf("Krivi izbor\n");
		fclose(auti);
		return;
	}

	AUTO mobil;
	int id;
	char marka[20];
	int found = 0;

	switch (izbor) {
	case ID:
		printf("Unesi ID automobila: ");
		scanf("%d", &id);
		while (fscanf(auti, "%d", &mobil.id) == 1) {
			fgetc(auti); 

			fgets(mobil.marka, sizeof(mobil.marka), auti);
			mobil.marka[strcspn(mobil.marka, "\n")] = '\0';

			fgets(mobil.model, sizeof(mobil.model), auti);
			mobil.model[strcspn(mobil.model, "\n")] = '\0';

			fgets(mobil.karoserija, sizeof(mobil.karoserija), auti);
			mobil.karoserija[strcspn(mobil.karoserija, "\n")] = '\0';

			fgets(mobil.pogon, sizeof(mobil.pogon), auti);
			mobil.pogon[strcspn(mobil.pogon, "\n")] = '\0';

			fgets(mobil.motor, sizeof(mobil.motor), auti);
			mobil.motor[strcspn(mobil.motor, "\n")] = '\0';

			fgets(mobil.boja, sizeof(mobil.boja), auti);
			mobil.boja[strcspn(mobil.boja, "\n")] = '\0';

			fscanf(auti, "%d\n%d\n%d\n%d\n%d\n", &mobil.konji, &mobil.newtonm, &mobil.kilometraza, &mobil.godiste, &mobil.cijena);

			if (mobil.id == id) {
				found = 1;
				printf("Automobil pronadjen:\n");
				printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\nCijena: %d(EUR)\n",
					mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
					mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste, mobil.cijena);
				break;
			}
		}
		if (!found) {
			printf("Automobil (ID %d) nije pronadjen.\n", id);
		}
		break;

	case MARKA:
		printf("Unesi marku automobila: ");
		scanf("%19s", marka);
		while (fscanf(auti, "%d", &mobil.id) == 1) {
			fgetc(auti); 

			fgets(mobil.marka, sizeof(mobil.marka), auti);
			mobil.marka[strcspn(mobil.marka, "\n")] = '\0';

			fgets(mobil.model, sizeof(mobil.model), auti);
			mobil.model[strcspn(mobil.model, "\n")] = '\0';

			fgets(mobil.karoserija, sizeof(mobil.karoserija), auti);
			mobil.karoserija[strcspn(mobil.karoserija, "\n")] = '\0';

			fgets(mobil.pogon, sizeof(mobil.pogon), auti);
			mobil.pogon[strcspn(mobil.pogon, "\n")] = '\0';

			fgets(mobil.motor, sizeof(mobil.motor), auti);
			mobil.motor[strcspn(mobil.motor, "\n")] = '\0';

			fgets(mobil.boja, sizeof(mobil.boja), auti);
			mobil.boja[strcspn(mobil.boja, "\n")] = '\0';

			fscanf(auti, "%d\n%d\n%d\n%d\n%d\n", &mobil.konji, &mobil.newtonm, &mobil.kilometraza, &mobil.godiste, &mobil.cijena);

			if (strcmp(mobil.marka, marka) == 0) {
				found = 1;
				printf("Automobil pronadjen:\n");
				printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\nCijena: %d(EUR)\n",
					mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
					mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste, mobil.cijena);
			}
		}
		if (!found) {
			printf("Automobili marke %s nisu pronadjeni.\n", marka);
		}
		break;

	default:
		printf("Nepostojeci izbor.\n");
		break;
	}

	fclose(auti);
}

void pretragaPoKaroseriji(AUTO* mobil, int broj) {
	int found;
	char karoserija[50];

	do {
		found = 0;
		printf("Unesite karoseriju: ");
		scanf("%s", karoserija);

		for (int i = 0; i < broj; i++) {
			if (strcmp(mobil[i].karoserija, karoserija) == 0) {
				printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\nCijena: %d(EUR)\n\n",
					mobil[i].id, mobil[i].marka, mobil[i].model, mobil[i].karoserija,
					mobil[i].pogon, mobil[i].motor, mobil[i].boja, mobil[i].konji,
					mobil[i].newtonm, mobil[i].kilometraza, mobil[i].godiste, mobil[i].cijena);
				found = 1;
			}
		}

		if (!found) {
			printf("Nema automobila sa karoserijom: %s. Molimo pokušajte ponovo.\n", karoserija);
		}
	} while (!found);
}


void kupovinaAutomobila() {
	AUTO* mobil;
	int broj;

	
	scanAuto(&mobil, &broj);

	printAuto(mobil, broj);

	printf("Unesi ID automobila koji zelite kupiti: ");
	int kupovinaID;
	scanf("%d", &kupovinaID);
	getchar();

	int found = 0;
	FILE* auti = fopen("auti.txt", "r");
	FILE* temp = fopen("temp.txt", "w");

	if (auti == NULL || temp == NULL) {
		perror("Greska pri otvaranju datoteke");
		free(mobil);
		return;
	}

	char buffer[256];
	int currentID = 1;

	
	for (int i = 0; i < broj; i++) {
		if (mobil[i].id == kupovinaID) {
			found = 1;
			printf("Jeste li sigurni da zelite kupiti automobil (ID %d)? (da/ne): ", kupovinaID);
			char potvrda[3];
			scanf("%2s", potvrda);
			getchar();

			if (strcmp(potvrda, "da") != 0) {
				found = 0;
				exit(0);
			}
			else {
				printf("Automobil sa ID %d je kupljen.\n", kupovinaID);
			}
			break;
		}
	}

	
	if (found) {
		for (int i = 0; i < broj; i++) {
			if (mobil[i].id != kupovinaID) {
				mobil[i].id = currentID++;
				fprintf(temp, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",
					mobil[i].id, mobil[i].marka, mobil[i].model, mobil[i].karoserija,
					mobil[i].pogon, mobil[i].motor, mobil[i].boja, mobil[i].konji,
					mobil[i].newtonm, mobil[i].kilometraza, mobil[i].godiste, mobil[i].cijena);
			}
		}
	}
	else {
		printf("Automobil sa ID %d nije pronadjen ili kupovina nije potvrdjena.\n", kupovinaID);
		return kupovinaAutomobila();
	}

	fclose(auti);
	fclose(temp);

	if (found) {
		remove("auti.txt");
		rename("temp.txt", "auti.txt");
	}
	else {
		remove("temp.txt");
	}

	free(mobil);
}



