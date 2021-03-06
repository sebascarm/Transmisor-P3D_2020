#pragma once

#include "P3D.h"

#include "SimConnect.h"
#include "PMDG_NG3_SDK.h"

#include <Windows.h>			// HANDLE	
#include <map>					//Para Mapeo
#include <vector>		
#include <queue>				//Colas

#include <string>				// string	
using namespace std;			// string	

struct ST_A_PLACA_P3D {
	string A_Evento;
	string B_TipoDato;
	string C_Respuesta;
	string D_Decimales;
	bool   E_Mapeo;
	double F_Min_In;
	double G_Max_In;
	int	   H_Min_Out;
	int	   I_Max_Out;
};

struct ST_A_PLACA_PMDG {
	string A_Respuesta;
	string B_Decimales;
};

struct ST_A_SIMU_P3D {
	int		A_ID;
	string  B_aSimulador;
	bool	C_Mapeo;
	int		D_Min_In;
	int		E_Max_In;
	int		F_Min_Out;
	int		G_Max_Out;
};

struct ST_A_SIMU_PMDG {
	string A_Definicion;
	unsigned int B_Comando;
};

#define _UP      0x00004000
#define _DOWN    0x00002000

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
	double* Array_P3D = NULL;	// Array dinamico (Simular a la est local PMDG

	// Conexiones INTERNAS			
	void Cargar();				// Carga de parametros			
	void Conexion_P3D();
	void Conexion_PMDG();
	//Mapeo de elementos para P3D (ID, [Evento, TipoDato, Respuesta, Decimales])
	map<int, ST_A_PLACA_P3D>::iterator Buscador_P3D_Read;	// desde Sim
	map<int, ST_A_PLACA_P3D> Map_P3D_Read;					// desde Sim
	// PMDG	(de simu - a placa, decimales) 
	map<string, ST_A_PLACA_PMDG>::iterator Buscador_PMDG_Read;	// desde Sim
	map<string, ST_A_PLACA_PMDG> Map_PMDG_Read;					// desde Sim
	// P3D	
	//Mapeo (de placa - id, a Simu)										
	map<string, ST_A_SIMU_P3D>::iterator Buscador_P3D_Write;		// hacia Sim
	map<string, ST_A_SIMU_P3D> Map_P3D_Write;					// hacia Sim
	// PMDG	
	//Mapeo (de placa - Definicion, Comando)							
	map<string, ST_A_SIMU_PMDG>::iterator Buscador_PMDG_Write;		// hacia Sim
	map<string, ST_A_SIMU_PMDG> Map_PMDG_Write;			// hacia Sim


	//Posiblemente dejar en desuso la estructura Est_P3D
	//double* Array_P3D = NULL;	//Array dinamico(determinar su uso)	
	std::vector <ST_BOARD_SIMU> vBoardSimu;
	std::vector <ST_SIMU_BOARD> vSimuBoard;

	bool Status = false;		// Estado de conexion			

	//Proceso de recepcion (desde el simulador)
	static void Recep_Estatica(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext);
	void Recep_Dinamica(SIMCONNECT_RECV* pData, DWORD cbData);

	void Recepcion_P3D (double* DATA);
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
	void Controlar_P3D(double& DatoSimu, double& DatoLocal, int Id_Comando); // Lo utiliza P3D
	// Coontr
	void Th_loop_recepcion();
	void Th_Loop_Envio_a_Placa();
	
	void Th_Loop_Envio_a_Sim_P3D();
	void Th_Loop_Envio_a_Sim_PMDG();
	// Valores a enviar a placa P3D Y PMDG	
	queue<string> Co_Comando;
	queue<string> Co_aPlaca;
	queue<string> Co_Valor_Comando;
	queue<string> Co_Valor_aPlaca;
	queue<bool>	  Co_Mapeo_aPlaca;
	queue<int>	  Co_Min_In_aPlaca;
	queue<int>	  Co_Max_In_aPlaca;
	queue<int>	  Co_Min_Out_aPlaca;
	queue<int>	  Co_Max_Out_aPlaca;
	// Valores para envio al simu P3D		
	queue<int>		Co_Comando_aSim_P3D;
	queue<string>	Co_Definicion_aSim_P3D;
	queue<double>	Co_Valor_aSim_P3D;
	queue<bool>		Co_Mapeo_aSim_P3D;
	queue<int>		Co_Min_In_aSim_P3D;
	queue<int>		Co_Max_In_aSim_P3D;
	queue<int>		Co_Min_Out_aSim_P3D;
	queue<int>		Co_Max_Out_aSim_P3D;
	// Valores para envio al simu PMDG		
	queue<int>		Co_Comando_aSim_PMDG;
	queue<string>	Co_Definicion_aSim_PMDG;
	queue<int>		Co_Valor_aSim_PMDG;


	// Evento
	static void Function_Empty(string Comando, string Definicion, string Valor);
	static void Function_Empty(string Comando, string aPlaca, string Valor_Comando, string Valor_aPlaca);
	void (*Function_Reception)(string Comando, string aPlaca, string Valor_Comando, string Valor_aPlaca) = Function_Empty;		// A un puntero de funcion solo se puede asignar una funcion estatica
	void (*Function_Send)(string Comando, string Definicion, string Valor) = Function_Empty;		// A un puntero de funcion solo se puede asignar una funcion estatica

public:
	P3D_Base();					// Constructor
	~P3D_Base();				// Destructor
	bool Connect();				// return true if conect ok		
	void Disconnect();			// Disconect
	void Send(string Comando, string Valor);	// Enviar datos al simu
	void ScreenMessage(std::string Message);	// to send message to the P3D Screen
	std::vector <ST_BOARD_SIMU> Get_Board_Simu();
	std::vector <ST_SIMU_BOARD> Get_Simu_Board();
	// Metodos				
	void Activate_After_Overhead();
	void Activate_Fordward_Overhead();
	void Activate_Glareshield();
	void Activate_Fordward_Panel();
	void Activate_Low_Fordward_Panel();
	void Activate_Control_Stand();
	void Deactivate_After_Overhead();
	void Deactivate_Fordward_Overhead();
	void Deactivate_Glareshield();
	void Deactivate_Fordward_Panel();
	void Deactivate_Low_Fordward_Panel();
	void Deactivate_Control_Stand();
	// Asignar Eventos		
	void Assign_Event_Reception(void(*Function)(string Comando, string aPlaca, string Valor_Comando, string Valor_aPlaca));
	void Assign_Event_Send(void(*Function)(string Comando, string Definicion, string Valor));
	// Evento				
	void Event_Reception_P3D(int Id, string Valor);
	void Event_Reception_PMDG(string Comando, string Valor);
	//void Event_Send(string Comando, string Definicion, string Valor);

};

