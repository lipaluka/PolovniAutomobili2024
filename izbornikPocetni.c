#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

enum Izbor {
	KORISNIK = 1,
	ADMINISTRATOR,
	KRAJ
};

void izborGlavni() {
	enum Izbor izbor;
	char unos[15];

	while (1) {
		printf("Dobrodosli u aplikaciju!!\n");
		printf("Prilikom odabira potrebno je upisati rijec u navodnicima\n");
		printf("1. Korisnicki izbornik 'korisnik'\n");
		printf("2. Administratorski izbornik 'admin'\n");
		printf("3. IZLAZ IZ PROGRAMA 'izlaz'\n");
		printf("/////////////////////////////////\n");
		scanf("%14s", unos);

		if (strcmp(unos, "korisnik") == 0)
			izbor = KORISNIK;
		else if (strcmp(unos, "admin") == 0)
			izbor = ADMINISTRATOR;
		else if (strcmp(unos, "izlaz") == 0)
			izbor = KRAJ;
		else {
			printf("Nepostojeci izbor\n");
			continue;
		}

		switch (izbor) {
		case KORISNIK:
			izborKorisnik();
			break;
		case ADMINISTRATOR:
			izborAdmin();
			break;
		case KRAJ:
			if (krajPrograma() == 0) {
				printf("Kraj programa, stisnite bilo koju tipku\n");
				getchar();
				getchar();
				return;
			}
			else {
				printf("Za povratak na pocetni izbornik pritisnite bilo koju tipku\n");
				getchar();
				getchar();
			}
			break;
		default:
			printf("Nepostojeci izbor\n");
			break;
		}
	}
}