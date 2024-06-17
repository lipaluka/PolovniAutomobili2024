#define _CRT_SECURE_NO_WARNINGS

#include"header.h"

enum IzborKorisnik {
	PREGLED = 1,
	PRETRAGA,
	KMU,
	KMS,
	GODU,
	GODS,
	CIJU,
	CIJS,
	KAROSERIJA,
	KUPOVINA,
	IZLAZ
};


void izborKorisnik() {
	enum IzborKorisnik izbor;
	char unos[15];
	printf("!Korisnicki Izbornik!\n");
	printf("[1] Pregled svih automobila 'pregled'\n");
	printf("[2] Pretrazivanje automobila 'pretraga'\n");
	printf("[3] Sortiranje automobila (kilometraza - UZLAZNO) 'kmu'\n");
	printf("[4] Sortiranje automobila (kilometraza - SILAZNO) 'kms'\n");
	printf("[5] Sortiranje automobila (godiste - UZLAZNO) 'godu'\n");
	printf("[6] Sortiranje automobila (godiste - SILAZNO) 'gods'\n");
	printf("[7] Sortiranje automobila (cijena - UZLAZNO) 'ciju'\n");
	printf("[8] Sortiranje automobila (cijena - SILAZNO) 'cijs'\n");
	printf("[9] Pretraga automobila po obliku karoserije 'karoserija'\n");
	printf("[10] Kupovina automobila 'kupovina'\n");
	printf("[11] Izlaz iz programa 'izlaz'\n");
	printf("/////////////////////////////////\n");
	printf("Unesite vas izbor: ");
	scanf("%14s", unos);
	if (strcmp(unos, "pregled") == 0)
		izbor = PREGLED;
	else if (strcmp(unos, "pretraga") == 0)
		izbor = PRETRAGA;
	else if (strcmp(unos, "kmu") == 0)
		izbor = KMU;
	else if (strcmp(unos, "kms") == 0)
		izbor = KMS;
	else if (strcmp(unos, "godu") == 0)
		izbor = GODU;
	else if (strcmp(unos, "gods") == 0)
		izbor = GODS;
	else if (strcmp(unos, "ciju") == 0)
		izbor = CIJU;
	else if (strcmp(unos, "cijs") == 0)
		izbor = CIJS;
	else if (strcmp(unos, "karoserija") == 0)
		izbor = KAROSERIJA;
	else if (strcmp(unos, "kupovina") == 0)
		izbor = KUPOVINA;
	else if (strcmp(unos, "izlaz") == 0)
		izbor = IZLAZ;
	else {
		printf("Krivi unos!!");
		return izborKorisnik();
	}


	FILE* auti = NULL;
	AUTO* mobil = NULL;
	int broj;
	char karoserija[15];

	switch (izbor) {
	case PREGLED:
		auti = fopen("auti.txt", "r");
		if (auti == NULL) {
			perror("Greska pri otvaranju datoteke");
			break;
		}
		pregledAutomobila();
		fclose(auti);
		break;
	case PRETRAGA:
		auti = fopen("auti.txt", "r");
		if (auti == NULL) {
			perror("Greska pri otvaranju datoteke");
			break;
		}
		pretraziAute();
		fclose(auti);
		break;
	case KMU:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po kilometrazi (UZLAZNO)\n");
		sortirajKilometrazaUzlazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case KMS:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po kilometrazi (SILAZNO)\n");
		sortirajKilometrazuSilazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case GODU:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po godistu (UZLAZNO)\n");
		sortirajGodisteUzlazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case GODS:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po godistu (SILAZNO)\n");
		sortirajGodisteSilazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case CIJU:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po cijeni (UZLAZNO)\n");
		sortirajCijenuUzlazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case CIJS:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po cijeni (SILAZNO)\n");
		sortirajCijenuSilazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case KAROSERIJA:
		scanAuto(&mobil, &broj);
		pretragaPoKaroseriji(mobil, broj);
		free(mobil);
		break;
	case KUPOVINA:
		kupovinaAutomobila();
		break;
	case IZLAZ:
		if (krajPrograma() == 0) {
			printf("Kraj programa, stisnite bilo koju tipku\n");
			getchar();
			getchar();
			exit(0);
		}
		else {
			printf("Za povratak na pocetni izbornik pritisnite bilo koju tipku\n");
			getchar();
			getchar();
			return;
		}
	default:
		printf("Krivi unos!\n");
		return;
	}
	exit(0);
}