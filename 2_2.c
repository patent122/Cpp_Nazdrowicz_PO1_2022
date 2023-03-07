#include <stdio.h>
#include <stdlib.h>

// pojedynczy element listy
struct Element
{
	// warto�� (liczba ca�kowita)
	int wartosc;
	// poprzedni i nast�pny element na li�cie
	struct Element* nastepnik;
	struct Element* poprzednik;
};

// struktura listy
struct Lista
{
	// pocz�tek i koniec listy
	struct Element* poczatek;
	struct Element* koniec;
	// ile element�w dodano
	int rozmiar;
};

// dodaje warto�� na pocz�tek
void DodajNaPoczatek(struct Lista* lista, int wartosc)
{
	struct Element* element = (struct Element*)malloc(sizeof(struct Element));
	element->wartosc = wartosc;
	if (lista->poczatek == NULL)
	{
		lista->poczatek = element;
		lista->koniec = element;
		element->poprzednik = NULL;
		element->nastepnik = NULL;
	}
	else
	{
		element->poprzednik = NULL;
		element->nastepnik = lista->poczatek;
		lista->poczatek->poprzednik = element;
		lista->poczatek = element;
	}
	lista->rozmiar++;
}

// dodaje warto�� na koniec
void DodajNaKoniec(struct Lista* lista, int wartosc)
{
	struct Element* element = (struct Element*)malloc(sizeof(struct Element));
	element->wartosc = wartosc;
	if (lista->koniec == NULL)
	{
		lista->poczatek = lista->koniec = element;
		element->poprzednik = element->nastepnik = NULL;
	}
	else
	{
		element->poprzednik = lista->koniec;
		element->nastepnik = NULL;
		lista->koniec->nastepnik = element;
		lista->koniec = element;
	}
	lista->rozmiar++;
}

// wypisuje list�
void Drukuj(struct Lista* lista)
{
	struct Element* p;
	for (p = lista->poczatek; p != NULL; p = p->nastepnik)
	{
		printf("%d ", p->wartosc);
	}
	printf("\n");
}

// dodaje warto�� przed wybrany element
void DodajPrzed(struct Lista* lista, struct Element* biezacy, int wartosc)
{
	struct Element* element = (struct Element*)malloc(sizeof(struct Element));
	element->wartosc = wartosc;
	element->poprzednik = biezacy->poprzednik;
	element->nastepnik = biezacy;
	biezacy->poprzednik = element;
	if (element->poprzednik == NULL)
	{
		lista->poczatek = element;
	}
	else
	{
		element->poprzednik->nastepnik = element;
	}
	lista->rozmiar++;
}

// dodaje warto�� za wybrany element
void DodajZa(struct Lista* lista, struct Element* biezacy, int wartosc)
{
	struct Element* element = (struct Element*)malloc(sizeof(struct Element));
	element->wartosc = wartosc;
	element->nastepnik = biezacy->nastepnik;
	element->poprzednik = biezacy;
	biezacy->nastepnik = element;
	if (element->nastepnik == NULL)
	{
		lista->koniec = element;
	}
	else
	{
		element->nastepnik->poprzednik = element;
	}
	lista->rozmiar++;
}

// usuwa wybrany element
void Usun(struct Lista* lista, struct Element* biezacy)
{
	if (biezacy->poprzednik == NULL)
		lista->poczatek = biezacy->nastepnik;
	else
		biezacy->poprzednik->nastepnik = biezacy->nastepnik;

	if (biezacy->nastepnik == NULL)
		lista->koniec = biezacy->poprzednik;
	else
		biezacy->nastepnik->poprzednik = biezacy->poprzednik;
	free(biezacy);
	lista->rozmiar--;
}

// usuwa pierwszy element
int UsunZPoczatku(struct Lista* lista)
{
	if (lista->poczatek == NULL)
	{
		return 0;
	}
	struct Element* element = lista->poczatek;
	lista->poczatek = lista->poczatek->nastepnik;
	if (lista->poczatek == NULL)
		lista->koniec = NULL;
	else
		lista->poczatek->poprzednik = NULL;
	free(element);
	lista->rozmiar--;
	return lista->rozmiar;
}

// usuwa ostatni element
int UsunZKonca(struct Lista* lista)
{
	if (lista->koniec == NULL)
	{
		return 0;
	}
	struct Element* element = lista->koniec;
	lista->koniec = lista->koniec->poprzednik;
	if (lista->koniec == NULL)
		lista->poczatek = NULL;
	else
		lista->koniec->nastepnik = NULL;
	free(element);
	lista->rozmiar--;
	return lista->rozmiar;
}

// czy�ci ca�� list�
void UsunWszystko(struct Lista* lista)
{
	while (UsunZPoczatku(lista));
}

// g��wna fuynkcja programu
int main()
{
	// deklaracja listy
	struct Lista lista;
	int ile;

	// inicjalizacja listy
	lista.poczatek = NULL;
	lista.koniec = NULL;
	lista.rozmiar = 0;

	// pobranie informacji od u�ytkownika
	printf("Ile liczb chcesz dodac? ");
	scanf("%d", &ile);

	// p�tla dodaj�ca 'ile' element�w na pocz�tek listy
	for (int i = 0; i < ile; i++)
	{
		DodajNaPoczatek(&lista, i + 1);
	}

	// wypisanie listy
	Drukuj(&lista);
	// zwolnienie pami�ci
	UsunWszystko(&lista);

	// p�tla dodaj�ca 'ile' element�w na koniec listy
	for (int i = 0; i < ile; i++)
	{
		DodajNaKoniec(&lista, i + 1);
	}

	// wypisanie listy
	Drukuj(&lista);
	// zwolnienie pami�ci
	UsunWszystko(&lista);

	return 0;
}