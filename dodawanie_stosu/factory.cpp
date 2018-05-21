#include"factory.h"
#include"dodawanie.h"

extern volatile int usageCount;

DodawanieFactory::DodawanieFactory() {
	m_ref = 0;
	m_lock = 0;
	usageCount++;
};


DodawanieFactory::~DodawanieFactory() {
	usageCount--;
};


ULONG STDMETHODCALLTYPE DodawanieFactory::AddRef() {
	InterlockedIncrement(&m_ref);
	return m_ref;
};


ULONG STDMETHODCALLTYPE DodawanieFactory::Release() {
	ULONG rv = InterlockedDecrement(&m_ref);
	if (m_ref == 0)
		delete this;
	return rv;
};


HRESULT STDMETHODCALLTYPE DodawanieFactory::QueryInterface(REFIID id, void **ptr) {
	if (ptr == NULL) return E_POINTER;
	if (IsBadWritePtr(ptr, sizeof(void *))) return E_POINTER;
	*ptr = NULL;
	if (id == IID_IUnknown) *ptr = this;
	if (id == IID_IClassFactory) *ptr = this;
	if (*ptr != NULL) { AddRef(); return S_OK; };
	return E_NOINTERFACE;
};


HRESULT STDMETHODCALLTYPE DodawanieFactory::LockServer(BOOL v) {
	if (v) m_lock++;
	else m_lock--;
	return S_OK;
};


HRESULT STDMETHODCALLTYPE DodawanieFactory::CreateInstance(IUnknown *outer, REFIID id, void **ptr) {
	Dodawanie *k;
	if (ptr == NULL) return E_POINTER;
	if (IsBadWritePtr(ptr, sizeof(void *))) return E_POINTER;
	*ptr = NULL;
	if (id == IID_IUnknown || id == IID_IDodawanie) {
		k = new Dodawanie();
		if (k == NULL) return E_OUTOFMEMORY;
		k->AddRef();
		*ptr = k;
		return S_OK;
	};
	return E_NOINTERFACE;
};
