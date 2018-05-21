// dllmain.cpp : Defines the entry point for the DLL application.

#include<windows.h>
#include"dodawanie.h"
#include"factory.h"

volatile int usageCount = 0;


STDAPI DllGetClassObject(REFCLSID cls, REFIID iid, void **rv) {
	DodawanieFactory *f;
	if (cls != CLSID_Dodawanie) { return CLASS_E_CLASSNOTAVAILABLE; };
	if (iid == IID_IClassFactory) {
		f = new DodawanieFactory();
		f->AddRef();
		*rv = f;
		return S_OK;
	};
	return CLASS_E_CLASSNOTAVAILABLE;
};

/*
STDAPI DllRegisterServer() {
};


STDAPI DllUnregisterServer() {
};
*/


STDAPI DllCanUnloadNow() {
	return usageCount > 0 ? FALSE : TRUE;
};


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
};