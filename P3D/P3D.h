//######################################################//
// P3D V 2.0											//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 01/03/2020                                           //
// Creacion                                             //
//######################################################//

#pragma once

#ifdef BUILDING_DLL
#define DLLIMPORT __declspec(dllexport) 
#else
#define DLLIMPORT __declspec(dllimport) 
#endif

#ifdef _DEBUG
#pragma comment (lib, "SimConnectDebug.lib")
#pragma comment (lib, "Archivo_d.lib")
#pragma comment (lib, "Funciones_d.lib")
#else
#pragma comment (lib, "SimConnect.lib")
#pragma comment (lib, "Archivo.lib")
#pragma comment (lib, "Funciones.lib")
#endif


#include <Windows.h>	
#include <string>		
using namespace std;	

class P3D {
public:
	virtual bool Connect() = 0;								// return true if conect ok
	virtual void Disconnect() = 0;
	virtual void ScreenMessage(std::string Message) = 0;	// to send message to the P3D Screen
	virtual void ListBoardSimu() = 0;						// return list of elemento from board to simulator
};

extern DLLIMPORT P3D* New_P3D();