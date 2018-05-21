#include<windows.h>

DEFINE_GUID(IID_IDodawanie,0xa6f06f76, 0x9384, 0x47a7, 0x9a, 0x29, 0x7c, 0xb2, 0x8f, 0x58, 0xf0, 0x8b);
DEFINE_GUID(CLSID_Dodawanie,0xd5062ca1, 0x743b, 0x4748, 0xa9, 0xf, 0xf9, 0x4d, 0x92, 0x55, 0x7b, 0xef);


class IDodawanie : public IUnknown {
public:
	virtual HRESULT STDMETHODCALLTYPE Stworz(int *tab, int licznik) = 0;
	virtual HRESULT STDMETHODCALLTYPE Wynik(int *val) = 0;
};