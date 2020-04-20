//######################################################//
// SOCKET  V 1.0										//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 19/04/2020                                           //
// Creacion                                             //
//######################################################//

#pragma once

#ifdef BUILDING_DLL
#define DLLIMPORT __declspec(dllexport) 
#else
#define DLLIMPORT __declspec(dllimport) 
#endif

#ifdef _DEBUG
#pragma comment (lib, "Funciones_d.lib")
#pragma comment(lib, "ws2_32.lib")
#else
#pragma comment (lib, "Funciones.lib")
#pragma comment(lib, "ws2_32.lib")
#endif



#include <Windows.h>
#include <string>
using namespace std;

class Socket {
public:
	
	virtual void Listen(string IP, int Port) = 0;
	virtual void Connect(std::string IP, int Port) = 0;
	virtual void Disconnect() = 0;
	virtual void Send(string Data) = 0;
	virtual int  Get_State() = 0;
	virtual void Event_Status(void(*Function)(int State, string Text)) = 0;
	virtual void Event_Input(void(*Function)(string Data_out)) = 0;
};

//extern "C" DLLIMPORT Socket * New_Socket();
extern DLLIMPORT Socket* New_Socket();