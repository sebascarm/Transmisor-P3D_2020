//######################################################//
// P3D V 3.0											//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 21/03/2020                                           //
// Envio completo										//
// Uso de decimales										//
// Mejoras de lectura de archivo y evento de recepcion	//
// Enviar datos al simulador							//
// Recepcion y activacion de eventos					//
// Obtener vectores										//
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
#include <vector>
using namespace std;	


struct ST_BOARD_SIMU {
	int ID;
	string Board;
	string Simu;
};

struct ST_SIMU_BOARD {
	string Simu;
	string Board;
};



class P3D {
public:
	virtual bool Connect() = 0;								// return true if conect ok
	virtual void Disconnect() = 0;
	virtual void ScreenMessage(std::string Message) = 0;	// to send message to the P3D Screen
	// Use value "UP" for mouse weel UP, and "DOWN" for mouse weel down
	virtual void Send(string Comando, string Valor) = 0;	// Enviar datos al simu
	// Metodos											
	virtual void Activate_After_Overhead() = 0;
	virtual void Activate_Fordward_Overhead() = 0;
	virtual void Activate_Glareshield() = 0;
	virtual void Activate_Fordward_Panel() = 0;
	virtual void Activate_Low_Fordward_Panel() = 0;
	virtual void Activate_Control_Stand() = 0;
	virtual void Deactivate_After_Overhead() = 0;
	virtual void Deactivate_Fordward_Overhead() = 0;
	virtual void Deactivate_Glareshield() = 0;
	virtual void Deactivate_Fordward_Panel() = 0;
	virtual void Deactivate_Low_Fordward_Panel() = 0;
	virtual void Deactivate_Control_Stand() = 0;
	// return list of elemento from board to simulator	
	virtual std::vector <ST_BOARD_SIMU> Get_Board_Simu() = 0;
	virtual std::vector <ST_SIMU_BOARD> Get_Simu_Board() = 0;
	virtual	void Assign_Event_Reception(void(*Function)(string Comando, string aPlaca, string Valor_Comando, string Valor_aPlaca)) = 0;
	virtual void Assign_Event_Send(void(*Function)(string Comando, string Definicion, string Valor)) = 0;

};

extern DLLIMPORT P3D* New_P3D();