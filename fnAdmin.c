#define _CRT_SECURE_NO_WARNINGS
#include"header.h"



void dodajAuto() {
	FILE* auti = fopen("auti.txt", "r+");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	AUTO mobil;
	int trenutniID;

	int maxID = 0;
	while (fscanf(auti, "%d\n", &trenutniID) == 1) {
		maxID = trenutniID;

		char buffer[256];
		for (int i = 0; i < 11; i++) {
			fgets(buffer, sizeof(buffer), auti);
		}
	}

	mobil.id = maxID + 1;


	while (1) {
		printf("\nUnesi marku: ");
		clearInputBuffer();
		fgets(mobil.marka, sizeof(mobil.marka), stdin);
		mobil.marka[strcspn(mobil.marka, "\n")] = '\0'; 

		if (strlen(mobil.marka) > 0) {
			break;
		}
		else {
			printf("Neispravan unos! Marka ne smije biti prazna.\n");
		}
	}


	while (1) {
		printf("\nUnesi model: ");
		fgets(mobil.model, sizeof(mobil.model), stdin);
		mobil.model[strcspn(mobil.model, "\n")] = '\0'; 

		if (strlen(mobil.model) > 0) {
			break;
		}
		else {
			printf("Neispravan unos! Model ne smije biti prazan.\n");
		}
	}


	while (1) {
		printf("\nUnesi karoseriju: ");
		scanf("%14s", mobil.karoserija);
		for (int i = 0; mobil.karoserija[i] != '\0'; i++) {
			mobil.karoserija[i] = tolower(mobil.karoserija[i]);
		}

		if (strcmp(mobil.karoserija, "limuzina") == 0 || strcmp(mobil.karoserija, "hatchback") == 0 ||
			strcmp(mobil.karoserija, "coupe") == 0 || strcmp(mobil.karoserija, "kabrio") == 0 ||
			strcmp(mobil.karoserija, "suv") == 0 || strcmp(mobil.karoserija, "crossover") == 0 ||
			strcmp(mobil.karoserija, "hyper") == 0 || strcmp(mobil.karoserija, "monovolumen") == 0 ||
			strcmp(mobil.karoserija, "karavan") == 0 || strcmp(mobil.karoserija, "ostalo") == 0) {
			break;
		}
		else {
			printf("Neispravan unos za karoseriju!\n");
		}
	}


	while (1) {
		printf("\nUnesi pogon: ");
		scanf("%9s", mobil.pogon);
		for (int i = 0; mobil.pogon[i] != '\0'; i++) {
			mobil.pogon[i] = tolower(mobil.pogon[i]);
		}

		if (strcmp(mobil.pogon, "prednji") == 0 || strcmp(mobil.pogon, "zadnji") == 0 || strcmp(mobil.pogon, "4x4") == 0) {
			break;
		}
		else {
			printf("Neispravan unos za pogon!\n");
		}
	}


	while (1) {
		printf("\nUnesi motor: ");
		clearInputBuffer();
		fgets(mobil.motor, sizeof(mobil.motor), stdin);
		mobil.motor[strcspn(mobil.motor, "\n")] = '\0'; 

		if (strlen(mobil.motor) > 0) {
			break;
		}
		else {
			printf("Neispravan unos! Motor ne smije biti prazan.\n");
		}
	}


	while (1) {
		printf("\nUnesi boju: ");
		fgets(mobil.boja, sizeof(mobil.boja), stdin);
		mobil.boja[strcspn(mobil.boja, "\n")] = '\0'; 

		if (strlen(mobil.boja) > 0) {
			break;
		}
		else {
			printf("Neispravan unos! Boja ne smije biti prazna.\n");
		}
	}

	while (1) {
		printf("\nUnesi broj konjskih snaga: ");
		if (scanf("%d", &mobil.konji) == 1 && mobil.konji >= 0 && mobil.konji <= 4000) {
			break;
		}
		else {
			printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
			clearInputBuffer();
		}
	}

	while (1) {
		printf("\nUnesi broj njutn metara: ");
		if (scanf("%d", &mobil.newtonm) == 1 && mobil.newtonm >= 0 && mobil.newtonm <= 4000) {
			break;
		}
		else {
			printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
			clearInputBuffer();
		}
	}

	while (1) {
		printf("\nUnesi kilometrazu: ");
		if (scanf("%d", &mobil.kilometraza) == 1 && mobil.kilometraza >= 0) {
			break;
		}
		else {
			printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
			clearInputBuffer();
		}
	}

	while (1) {
		printf("\nUnesi godiste: ");
		if (scanf("%d", &mobil.godiste) == 1 && mobil.godiste >= 1800 && mobil.godiste <= 2025) {
			break;
		}
		else {
			printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
			clearInputBuffer();
		}
	}

	while (1) {
		printf("\nUnesi cijenu: ");
		if (scanf("%d", &mobil.cijena) == 1 && mobil.cijena >= 0) {
			break;
		}
		else {
			printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
			clearInputBuffer();
		}
	}

	fseek(auti, 0, SEEK_END);
	fprintf(auti, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",
		mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
		mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste, mobil.cijena);

	fclose(auti);
}

void obrisiAuto() {
	printf("Unesi ID automobila za brisanje: ");
	int iddel;
	scanf("%d", &iddel);
	getchar(); 

	FILE* auti = fopen("auti.txt", "r");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	FILE* temp = fopen("temp.txt", "w");
	if (temp == NULL) {
		perror("Greska pri otvaranju temp datoteke");
		fclose(auti);
		return;
	}

	int id;
	int trenID = 1;
	int obrisanID = 0;
	while (fscanf(auti, "%d", &id) == 1) {
		fgetc(auti); 
		if (id == iddel) {
			obrisanID = 1;
		
			char buffer[256];
			for (int i = 0; i < 11; i++) {
				fgets(buffer, sizeof(buffer), auti);
			}
			continue;
		}
		if (obrisanID) {
			id = trenID++;
		}
		else {
			trenID = id + 1;
		}
		fprintf(temp, "%d\n", id);
		for (int i = 0; i < 11; i++) {
			char buffer[256];
			if (fgets(buffer, sizeof(buffer), auti)) {
				fputs(buffer, temp);
			}
		}
	}

	fclose(auti);
	fclose(temp);
	remove("auti.txt");
	rename("temp.txt", "auti.txt");

	if (obrisanID) {
		printf("Automobil (ID %d) je obrisan.\n", iddel);
	}
	else {
		printf("Automobil s ID-om %d nije pronaðen.\n", iddel);
	}
}



void urediAuto() {
    FILE* auti = fopen("auti.txt", "r");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    FILE* temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Greska pri otvaranju temp datoteke");
        fclose(auti);
        return;
    }

    printf("Unesi ID automobila za uredjivanje: ");
    int idedit;
    scanf("%d", &idedit);
    getchar();

    AUTO mobil;
    int id;
    int found = 0;

    while (fscanf(auti, "%d", &id) == 1) {
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

        fscanf(auti, "%d", &mobil.konji);
        fscanf(auti, "%d", &mobil.newtonm);
        fscanf(auti, "%d", &mobil.kilometraza);
        fscanf(auti, "%d", &mobil.godiste);
        fscanf(auti, "%d", &mobil.cijena);
        fgetc(auti);

        mobil.id = id;  

        if (id == idedit) {
            found = 1;
            printf("Izaberi polje za uredjivanje:\n");
            printf("1. Marka\n2. Model\n3. Karoserija\n4. Pogon\n5. Motor\n6. Boja\n7. Konji 'ks'\n8. Newtonmetri 'nm'\n9. Kilometraza 'km'\n10. Godiste 'god'\n11. Cijena 'cij'\n");

            enum edit {
                MARKA = 1,
                MODEL,
                KAROSERIJA,
                POGON,
                MOTOR,
                BOJA,
                KS,
                NM,
                KM,
                GOD,
                CIJ
            };
            enum edit izborPolja;
            char unos[15];
            scanf("%s", unos);
            getchar();
            if (strcmp(unos, "marka") == 0)
                izborPolja = MARKA;
            else if (strcmp(unos, "model") == 0)
                izborPolja = MODEL;
            else if (strcmp(unos, "karoserija") == 0)
                izborPolja = KAROSERIJA;
            else if (strcmp(unos, "pogon") == 0)
                izborPolja = POGON;
            else if (strcmp(unos, "motor") == 0)
                izborPolja = MOTOR;
            else if (strcmp(unos, "boja") == 0)
                izborPolja = BOJA;
            else if (strcmp(unos, "ks") == 0)
                izborPolja = KS;
            else if (strcmp(unos, "nm") == 0)
                izborPolja = NM;
            else if (strcmp(unos, "km") == 0)
                izborPolja = KM;
            else if (strcmp(unos, "god") == 0)
                izborPolja = GOD;
            else if (strcmp(unos, "cij") == 0)
                izborPolja = CIJ;
            else {
                printf("Krivi izbor\n");
                fclose(auti);
                fclose(temp);
                remove("temp.txt");
                return urediAuto();
            }
            switch (izborPolja) {
            case MARKA:
                printf("Unesi novu marku: ");
                fgets(mobil.marka, sizeof(mobil.marka), stdin);
                mobil.marka[strcspn(mobil.marka, "\n")] = 0;
                break;
            case MODEL:
                printf("Unesi novi model: ");
                fgets(mobil.model, sizeof(mobil.model), stdin);
                mobil.model[strcspn(mobil.model, "\n")] = 0;
                break;
            case KAROSERIJA:
                do {
                    printf("Unesi novu karoseriju: ");
                    fgets(mobil.karoserija, sizeof(mobil.karoserija), stdin);
                    mobil.karoserija[strcspn(mobil.karoserija, "\n")] = 0;
                    for (int i = 0; mobil.karoserija[i] != '\0'; i++) {
                        mobil.karoserija[i] = tolower(mobil.karoserija[i]);
                    }
                    if (strcmp(mobil.karoserija, "limuzina") == 0 || strcmp(mobil.karoserija, "hatchback") == 0 ||
                        strcmp(mobil.karoserija, "coupe") == 0 || strcmp(mobil.karoserija, "kabrio") == 0 ||
                        strcmp(mobil.karoserija, "suv") == 0 || strcmp(mobil.karoserija, "crossover") == 0 ||
                        strcmp(mobil.karoserija, "hyper") == 0 || strcmp(mobil.karoserija, "monovolumen") == 0 ||
                        strcmp(mobil.karoserija, "ostalo") == 0) {
                        break;
                    }
                    else {
                        printf("Neispravan unos za karoseriju!\n");
                    }
                } while (1);
                break;
            case POGON:
                do {
                    printf("Unesi novi pogon: ");
                    fgets(mobil.pogon, sizeof(mobil.pogon), stdin);
                    mobil.pogon[strcspn(mobil.pogon, "\n")] = 0;
                    for (int i = 0; mobil.pogon[i] != '\0'; i++) {
                        mobil.pogon[i] = tolower(mobil.pogon[i]);
                    }
                    if (strcmp(mobil.pogon, "prednji") == 0 || strcmp(mobil.pogon, "zadnji") == 0 || strcmp(mobil.pogon, "4x4") == 0) {
                        break;
                    }
                    else {
                        printf("Neispravan unos za pogon!\n");
                    }
                } while (1);
                break;
            case MOTOR:
                printf("Unesi novi motor: ");
                fgets(mobil.motor, sizeof(mobil.motor), stdin);
                mobil.motor[strcspn(mobil.motor, "\n")] = 0;
                break;
            case BOJA:
                printf("Unesi novu boju: ");
                fgets(mobil.boja, sizeof(mobil.boja), stdin);
                mobil.boja[strcspn(mobil.boja, "\n")] = 0;
                break;
            case KS:
                do {
                    printf("Unesi novi broj konjskih snaga: ");
                    if (scanf("%d", &mobil.konji) != 1) {
                        while (getchar() != '\n'); 
                        printf("Neispravan unos! Unesite broj.\n");
                        continue;
                    }
                    if (mobil.konji >= 0 && mobil.konji <= 4000) break;
                    printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
                } while (1);
                break;
            case NM:
                do {
                    printf("Unesi novi broj newtonmetara: ");
                    if (scanf("%d", &mobil.newtonm) != 1) {
                        while (getchar() != '\n'); 
                        printf("Neispravan unos! Unesite broj.\n");
                        continue;
                    }
                    if (mobil.newtonm >= 0 && mobil.newtonm <= 4000) break;
                    printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
                } while (1);
                break;
            case KM:
                do {
                    printf("Unesi novu kilometrazu: ");
                    if (scanf("%d", &mobil.kilometraza) != 1) {
                        while (getchar() != '\n'); 
                        printf("Neispravan unos! Unesite broj.\n");
                        continue;
                    }
                    if (mobil.kilometraza >= 0) break;
                    printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
                } while (1);
                break;
            case GOD:
                do {
                    printf("Unesi novo godiste: ");
                    if (scanf("%d", &mobil.godiste) != 1) {
                        while (getchar() != '\n'); 
                        printf("Neispravan unos! Unesite broj.\n");
                        continue;
                    }
                    if (mobil.godiste >= 1800 && mobil.godiste <= 2025) break;
                    printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
                } while (1);
                break;
            case CIJ:
                do {
                    printf("Unesi novu cijenu: ");
                    if (scanf("%d", &mobil.cijena) != 1) {
                        while (getchar() != '\n'); // Clear invalid input
                        printf("Neispravan unos! Unesite broj.\n");
                        continue;
                    }
                    if (mobil.cijena >= 0) break;
                    printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
                } while (1);
                break;
            default:
                printf("Nepostojeci izbor.\n");
                break;
            }
        }

      
        fprintf(temp, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",
            mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
            mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste, mobil.cijena);
    }

    fclose(auti);
    fclose(temp);

    if (found) {
        remove("auti.txt");
        rename("temp.txt", "auti.txt");
        printf("Automobil sa ID %d je uredjen.\n", idedit);
    }
    else {
        remove("temp.txt");
        printf("Automobil sa ID %d nije pronadjen.\n", idedit);
    }
}