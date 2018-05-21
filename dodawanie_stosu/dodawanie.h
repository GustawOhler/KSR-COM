#include"idodawanie.h"
#include"E:\studia\ksr\dll\dll\iklasa.h"

class Dodawanie : public IDodawanie {
public:
	Dodawanie();
	~Dodawanie();
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void **ptr);
	virtual HRESULT STDMETHODCALLTYPE Stworz(int *tab, int licznik);
	virtual HRESULT STDMETHODCALLTYPE Wynik(int *val);

private:

	volatile ULONG m_ref;
	HRESULT rv;
	IKlasa *klasa;
	int il_elementow;
};