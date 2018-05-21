#include"iklasa.h"

class Klasa: public IKlasa {
public:
	Klasa();
	~Klasa();
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void **ptr);
	virtual HRESULT STDMETHODCALLTYPE Push(int val);
	virtual HRESULT STDMETHODCALLTYPE PopEx(int *val);
	virtual int STDMETHODCALLTYPE Pop();

private:

	volatile ULONG m_ref;
	int *Stck;
	unsigned int counter;

	};
