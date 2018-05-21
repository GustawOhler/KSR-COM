#include<windows.h>

class DodawanieFactory : public IClassFactory {
public:
	DodawanieFactory();
	~DodawanieFactory();
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID id, void **rv);
	virtual HRESULT STDMETHODCALLTYPE LockServer(BOOL v);
	virtual HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown *outer, REFIID id, void **rv);

private:

	volatile ULONG m_ref;
	volatile ULONG m_lock;

};