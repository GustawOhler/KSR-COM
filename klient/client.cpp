#include<windows.h>
#include<stdio.h>
#include<conio.h>

#include"E:\studia\ksr\dll\dodawanie_stosu\idodawanie.h"
#include"E:\studia\ksr\dll\dll\iklasa.h"

int main() {
	HRESULT rv;
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	printf("starting\n");
	IDodawanie *k;

	rv = CoCreateInstance(CLSID_Dodawanie, NULL, CLSCTX_INPROC_SERVER, IID_IDodawanie, (void **)&k);
	
	printf("res = %08X (%s)\n", rv, rv == S_OK ? "OK" : "bad");
	if(rv != S_OK) {
		printf("error creating instance gle=%08X %d\n", GetLastError(), GetLastError());
		CoUninitialize();
		return 0;
		};

	int val;
	int licznik = 5;
	int *tablica = new int[licznik];
	tablica[0] = 5;
	tablica[1] = 15;
	tablica[2] = 6;
	tablica[3] = 17;
	tablica[4] = 22;
	k->Stworz(tablica, licznik);


	k->Wynik(&val);	
	printf("%d\n", val);

	k->Release();

	printf("done\n");
	CoUninitialize();
	return 0;
	};
