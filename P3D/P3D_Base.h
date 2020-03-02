#pragma once

#include "P3D.h"

#include "SimConnect.h"
#include "PMDG_NG3_SDK.h"

#include <Windows.h>			// HANDLE
#include <map>					//Para Mapeo

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


class P3D_Base :public P3D {
protected:
	HRESULT hr = NULL;			// resultados de conexion		
	HANDLE  hSimConnect = NULL;	// handle de simconnect			
	PMDG_NG3_Control Control;	// Estructura con Event y Parameter (unsigned int cada uno) SDK
	// Conexiones INTERNAS			
	void Cargar();				// Carga de parametros			
	void Conexion_P3D();
	void Conexion_PMDG();
	//Mapeo de elementos para P3D (ID, [Evento, TipoDato, Respuesta, Decimales])
	map<int, DATO_COMPUESTO>::iterator Buscador_P3D_Read;	// desde Sim
	map<int, DATO_COMPUESTO> Map_P3D_Read;					// desde Sim
	//Mapeo de elementos para P3D (de placa, id , a Simu)								
	map<string, EST_SIMU>::iterator Buscador_P3D_Write;		// hacia Sim
	map<string, EST_SIMU> Map_P3D_Write;					// hacia Sim
	
	//Posiblemente dejar en desuso la estructura Est_P3D
	//double* Array_P3D = NULL;	//Array dinamico(determinar su uso)	


	bool Status = false;		// Estado de conexion			
public:
	~P3D_Base();				// Destructor
	bool Connect();				// return true if conect ok		
	void Disconnect();			// Disconect
	void Send(string, unsigned int);		// Enviar datos al simu
	void ScreenMessage(std::string Message);	// to send message to the P3D Screen
};

