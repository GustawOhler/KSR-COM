#include<windows.h>
#include"klasa.h"


extern volatile int usageCount;


Klasa::Klasa() {
	m_ref = 0;
	Stck = new int[100];
	counter = 0;

	usageCount++;
	};


Klasa::~Klasa() {
	usageCount--;
	};


ULONG STDMETHODCALLTYPE Klasa::AddRef() {
	InterlockedIncrement(&m_ref);
	return m_ref;
	};


ULONG STDMETHODCALLTYPE Klasa::Release() {
	ULONG rv = InterlockedDecrement(&m_ref);
	if (m_ref == 0)
		delete this;
	return rv;
	};


HRESULT STDMETHODCALLTYPE Klasa::QueryInterface(REFIID iid, void **ptr) {
	if(ptr == NULL) return E_POINTER;
	if(IsBadWritePtr(ptr, sizeof(void *))) return E_POINTER;
	*ptr = NULL;
	if(iid == IID_IUnknown) *ptr = this;
	if(iid == IID_IKlasa) *ptr = this;
	if(*ptr != NULL) { AddRef(); return S_OK; };
	return E_NOINTERFACE;
	};


HRESULT STDMETHODCALLTYPE Klasa::Push(int val) {
	if (Stck[counter] = val) {
		counter++;
		return S_OK;
	}
	else
		return E_FAIL;
	};


HRESULT STDMETHODCALLTYPE Klasa::PopEx(int *val) {
	counter--;
	if (*val = Stck[counter]) {
		return S_OK;
	}
	else
		return E_FAIL;
	};


int STDMETHODCALLTYPE Klasa::Pop() {
	counter--;
	return (int) Stck[counter];
	};
