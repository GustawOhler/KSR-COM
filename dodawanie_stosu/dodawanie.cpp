#include<windows.h>
#include"dodawanie.h"
#include<stdio.h>

extern volatile int usageCount;

Dodawanie::Dodawanie() {
	m_ref = 0;
	rv = 0;
	printf("inicjalizacja\n");
	rv = CoCreateInstance(CLSID_Klasa, NULL, CLSCTX_INPROC_SERVER, IID_IKlasa, (void **)&klasa);
	printf("res = %08X (%s)\n", rv, rv == S_OK ? "OK" : "bad");
	if (rv != S_OK) {
		printf("error creating instance gle=%08X %d\n", GetLastError(), GetLastError());
		CoUninitialize();
	};
	il_elementow = 0;
	usageCount++;
};


Dodawanie::~Dodawanie() {
	usageCount--;
};


ULONG STDMETHODCALLTYPE Dodawanie::AddRef() {
	InterlockedIncrement(&m_ref);
	return m_ref;
};


ULONG STDMETHODCALLTYPE Dodawanie::Release() {
	ULONG rv = InterlockedDecrement(&m_ref);
	if (m_ref == 0)
		delete this;
	return rv;
};


HRESULT STDMETHODCALLTYPE Dodawanie::QueryInterface(REFIID iid, void **ptr) {
	if (ptr == NULL) return E_POINTER;
	if (IsBadWritePtr(ptr, sizeof(void *))) return E_POINTER;
	*ptr = NULL;
	if (iid == IID_IUnknown) *ptr = this;
	if (iid == IID_IDodawanie) *ptr = this;
	if (*ptr != NULL) { AddRef(); return S_OK; };
	return E_NOINTERFACE;
};

HRESULT STDMETHODCALLTYPE Dodawanie::Stworz(int *tab, int licznik) {
	il_elementow = licznik;
	for (int i = 0; i < licznik; i++) {
		klasa->Push(tab[i]);
	}
	return S_OK;
};

HRESULT STDMETHODCALLTYPE Dodawanie::Wynik(int *val) {
	int wartosc;
	int suma = 0;
	for (int i = 0; i < il_elementow; i++) {
		klasa->PopEx(&wartosc);
		suma += wartosc;
	}
	*val = suma;
	return S_OK;
};