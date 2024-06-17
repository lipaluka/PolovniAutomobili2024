#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

int adminPrijava(ADMIN* admin) {
	ADMIN prijava;
	printf("Unesi korisnicko ime: ");
	scanf("%49s", prijava.ime);
	printf("Unesi lozinku: ");
	scanf("%49s", prijava.lozinka);

	if (strcmp(prijava.ime, admin->ime) == 0 && strcmp(prijava.lozinka, admin->lozinka) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
enum IzborAdmin {
	DODAVANJE = 1,
	BRISANJE,
	UREDI,
	IZLAZ
};

int izborAdmin() {
	enum IzborAdmin izbor;
	srand((unsigned)time(NULL));
	size_t pokusaji = 0;
	ADMIN admin = { "Luka2502", "123321" };

	while (adminPrijava(&admin) == 0 && pokusaji < 3) {
		pokusaji++;
		printf("Pogresno ime ili lozinka, pokusajte ponovno!!\n");
		if (pokusaji == 3) {
			printf("Iskoristili ste sve pokusaje, pokusajte ponovno kasnije\n");
			exit(0);
		}
	}

	if (pokusaji < 3) {
		printf("Uspjesna prijava, dobrodosao %s\n", admin.ime);
	}

	char unos[15];
	printf("ADMINISTRATORSKI IZBORNIK\n");
	printf("[1] Dodavanje Automobila 'dodaj'\n");
	printf("[2] Brisanje Automobila 'brisi'\n");
	printf("[3] Uredjivanje Automobila 'uredi'\n");
	printf("[4] Izlaz iz Programa 'izlaz'\n");
	printf("Unesite vas izbor: ");
	scanf("%14s", unos);

	FILE* auti = NULL;
	AUTO mobil;

	if (strcmp(unos, "dodaj") == 0)
		izbor = DODAVANJE;
	else if (strcmp(unos, "brisi") == 0)
		izbor = BRISANJE;
	else if (strcmp(unos, "uredi") == 0)
		izbor = UREDI;
	else if (strcmp(unos, "izlaz") == 0)
		izbor = IZLAZ;
	else {
		printf("Krivi unos!!");
		return izborAdmin();
	}

	switch (izbor) {
	case DODAVANJE:
		dodajAuto();
		break;
	case BRISANJE:
		obrisiAuto();
		break;
	case UREDI:
		urediAuto();
		break;
	case IZLAZ:
		if (krajPrograma() == 0) {
			printf("Kraj programa, stisnite bilo koju tipku\n");
			getchar();
			getchar();
			exit(0);
		}
		else {
			printf("Za povratak u pocetni izbornik pritisnite bilo koju tipku.");
			getchar();
			return 0;
		}
	default:
		printf("Nepostojeci izbor!\n");
		break;
	}

	exit(0);
	return 0;
}