#include"factory.h"
#include"klasa.h"

extern volatile int usageCount;

KlasaFactory::KlasaFactory() {
	m_ref = 0;
	m_lock = 0;
	usageCount++;
	};
	

KlasaFactory::~KlasaFactory() {
	usageCount--;
	};

	
ULONG STDMETHODCALLTYPE KlasaFactory::AddRef() {
	InterlockedIncrement(&m_ref);
	return m_ref;
	};


ULONG STDMETHODCALLTYPE KlasaFactory::Release() {
	ULONG rv = InterlockedDecrement(&m_ref);
	if (m_ref == 0)
		delete this;
	return rv;
	};


HRESULT STDMETHODCALLTYPE KlasaFactory::QueryInterface(REFIID id, void **ptr) {
	if(ptr == NULL) return E_POINTER;
	if(IsBadWritePtr(ptr, sizeof(void *))) return E_POINTER;
	*ptr = NULL;
	if(id == IID_IUnknown) *ptr = this;
	if(id == IID_IClassFactory) *ptr = this;
	if(*ptr != NULL) { AddRef(); return S_OK; };
	return E_NOINTERFACE;
	};


HRESULT STDMETHODCALLTYPE KlasaFactory::LockServer(BOOL v) {
	if(v) m_lock++; 
	else m_lock--;
	return S_OK;
	};


HRESULT STDMETHODCALLTYPE KlasaFactory::CreateInstance(IUnknown *outer, REFIID id, void **ptr) {
	Klasa *k;
	if(ptr == NULL) return E_POINTER;
	if(IsBadWritePtr(ptr, sizeof(void *))) return E_POINTER;
	*ptr = NULL;
	if(id == IID_IUnknown || id == IID_IKlasa) {
		k = new Klasa();
		if(k == NULL) return E_OUTOFMEMORY;
		k->AddRef();
		*ptr = k;
		return S_OK;
		};
	return E_NOINTERFACE;
	};
