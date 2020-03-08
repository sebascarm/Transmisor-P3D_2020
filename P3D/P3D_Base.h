#pragma once

#include "P3D.h"

#include "SimConnect.h"
#include "PMDG_NG3_SDK.h"

#include <Windows.h>			// HANDLE	
#include <map>					//Para Mapeo
#include <vector>		

#include <string>				// string	
using namespace std;			// string	

struct DATO_COMPUESTO {
	string A_Evento;
	string B_TipoDato;
	string C_Respuesta;
	string D_Decimales;
};

struct EST_SIMU {
	int		ID;
	string  a_Simulador;
};

//struct EST_BOARD_SIMU {
//	int ID;
//	string bard;
//	string simu;
//};

class P3D_Base :public P3D {
protected:
	HRESULT hr = NULL;			// resultados de conexion		
	HANDLE  hSimConnect = NULL;	// handle de simconnect			
	PMDG_NG3_Control Control;	// Estructura con Event y Parameter (unsigned int cada uno) SDK
	PMDG_NG3_Data Est_PMDG;		// Estructura local de datos
	// Conexiones INTERNAS			
	void Cargar();				// Carga de parametros			
	void Conexion_P3D();
	void Conexion_PMDG();
	//Mapeo de elementos para P3D (ID, [Evento, TipoDato, Respuesta, Decimales])
	map<int, DATO_COMPUESTO>::iterator Buscador_P3D_Read;	// desde Sim
	map<int, DATO_COMPUESTO> Map_P3D_Read;					// desde Sim
	// PMDG
	map<string, string>::iterator Buscador_PMDG_Read;	// desde Sim
	map<string, string> Map_PMDG_Read;					// desde Sim

	//Mapeo de elementos para P3D (de placa, id , a Simu)								
	map<string, EST_SIMU>::iterator Buscador_P3D_Write;		// hacia Sim
	map<string, EST_SIMU> Map_P3D_Write;					// hacia Sim
	
	//Posiblemente dejar en desuso la estructura Est_P3D
	//double* Array_P3D = NULL;	//Array dinamico(determinar su uso)	
	std::vector <EST_BOARD_SIMU> vBoardSimu;
	std::vector <EST_SIMU_BOARD> vSimuBoard;

	bool Status = false;		// Estado de conexion			

	void Recepcion_PMDG(PMDG_NG3_Data* pS);
	// Modulos habilitados
	bool AFT_OVERHEAD;
	bool FORWARD_OVERHEAD;
	bool GLARESHIEL;
	bool FORWARD_PANEL;
	bool LOWER_FORWARD_PANEL;
	bool CONTROL_STAND;
	// Etapa de control segun tipo de datos
	//Unificador de tipo de datos para envio (control)
	void Controlar(bool& DatoSimu, bool& DatoLocal, const char* Comando);
	void Controlar(int& DatoSimu, int& DatoLocal, const char* Comando);
	void Controlar(unsigned int& DatoSimu, unsigned int& DatoLocal, const char* Comando);
	void Controlar(char& DatoSimu, char& DatoLocal, const char* Comando);
	void Controlar(unsigned char& DatoSimu, unsigned char& DatoLocal, const char* Comando);
	void Controlar(short& DatoSimu, short& DatoLocal, const char* Comando);
	void Controlar(unsigned short& DatoSimu, unsigned short& DatoLocal, const char* Comando);
	void Controlar(float& DatoSimu, float& DatoLocal, const char* Comando);
	void Controlar(double& DatoSimu, double& DatoLocal, const char* Comando);
	// Coontr
	void EstructuraModificada(string Comando, string Valor);
	

public:
	P3D_Base();					// Constructor
	~P3D_Base();				// Destructor
	bool Connect();				// return true if conect ok		
	void Disconnect();			// Disconect
	void Send(string, unsigned int);			// Enviar datos al simu
	void ScreenMessage(std::string Message);	// to send message to the P3D Screen
	std::vector <EST_BOARD_SIMU> Get_Board_Simu();
	std::vector <EST_SIMU_BOARD> Get_Simu_Board();
};

