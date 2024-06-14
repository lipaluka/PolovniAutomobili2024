#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

int usporediKilometrazuUzlazno(const void* a, const void* b) {
	int a1 = ((AUTO*)a)->kilometraza;
	int a2=((AUTO*)b)->kilometraza;
	return razlika(a1, a2);
}
void sortirajKilometrazaUzlazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediKilometrazuUzlazno);
}

int usporediKilometrazuSilazno(const void* a, const void* b) {
	int a1 = ((AUTO*)a)->kilometraza;
	int a2 = ((AUTO*)b)->kilometraza;
	return razlika(a2, a1);
}
void sortirajKilometrazuSilazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediKilometrazuSilazno);
}

int usporediGodisteUzlazno(const void* a, const void* b) {
	int a1 = ((AUTO*)a)->godiste;
	int a2 = ((AUTO*)b)->godiste;
	return razlika(a1, a2);
}
void sortirajGodisteUzlazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediGodisteUzlazno);
}

int usporediGodisteSilazno(const void* a, const void* b) {
	int a1 = ((AUTO*)a)->godiste;
	int a2 = ((AUTO*)b)->godiste;
	return razlika(a2, a1);
}
void sortirajGodisteSilazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediGodisteSilazno);
}

int usporediCijenuUzlazno(const void* a, const void* b) {
	int a1 = ((AUTO*)a)->cijena;
	int a2 = ((AUTO*)b)->cijena;
	return razlika(a1, a2);
}
void sortirajCijenuUzlazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediCijenuUzlazno);
}

int usporediCijenuSilazno(const void* a, const void* b) {
	int a1 = ((AUTO*)a)->cijena;
	int a2 = ((AUTO*)b)->cijena;
	return razlika(a2, a1);
}
void sortirajCijenuSilazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediCijenuSilazno);
}