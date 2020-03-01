#pragma once

#ifdef BUILDING_DLL
#define DLLIMPORT __declspec(dllexport) 
#else
#define DLLIMPORT __declspec(dllimport) 
#endif

#ifdef _DEBUG
#pragma comment (lib, "SimConnectDebug.lib")
#else
#pragma comment (lib, "SimConnect.lib")
#endif

#include <Windows.h>
#include <string>
using namespace std;


class P3D {
public:
	virtual void Connect() = 0;
	virtual void Disconnect() = 0;
};

extern DLLIMPORT P3D* New_P3D();