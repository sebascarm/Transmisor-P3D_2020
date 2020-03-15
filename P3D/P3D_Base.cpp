#include "P3D_Base.h"
#include "Recepcion_PMDG.h"
#include "Archivo.h"
#include "Estructuras.h"	// Para Grupo
#include "Funciones.h"		// Para cambiar de string a integer
#include <thread>			//Para hilos (multiproceso)


//----------------------------------------------//
//-- CONSTRUCTOR CARGA DE PARAMETROS			//
//----------------------------------------------//

P3D_Base::P3D_Base() {
	this->Cargar();
}

//----------------------------------------------//
//-- CONEXION									//
//----------------------------------------------//
bool P3D_Base::Connect() {
	
	// Intento de conexion			
	if (SUCCEEDED(SimConnect_Open(&hSimConnect, "PMDG NGX Client", NULL, 0, 0, 0))) {
		Conexion_P3D();		//P3D	
		Conexion_PMDG();	//PMDG	
		ScreenMessage("Conexi�n con Mediador Establecida");
		// Ejecutar Loops
		Status = true;
		thread th_Loop_envio([this] {Th_Loop_Envio_a_Placa(); });	// Loop de envio a placa
		thread th_Loop([this] {Th_loop_recepcion(); });				// Escuchar del simulador
		th_Loop_envio.detach();
		th_Loop.detach();
		return true;
	} else {
		//this->Status = false;
		return false;
	}
}

//----------------------------------------------//
//-- LOOP DE RECEPCION							//
//----------------------------------------------//
void P3D_Base::Th_loop_recepcion() {
	while (Status) {
		// receive and process the NGX data y P3D (Receptor debe ser estatico)
		SimConnect_CallDispatch(hSimConnect, Recep_Estatica, this);
		Sleep(1);
	}
}

//----------------------------------------------//
//-- CARGA DE PARAMETROS						//
//----------------------------------------------//
void P3D_Base::Cargar() {
	Archivo* ArchivoP3D = New_File();
	ArchivoP3D->Load("P3D.cfg");
	//Lectura de parametros	Envio a simulador (P3D)	
	EST_SIMU Est_aSimu;
	string Tipo, sID, dePlaca, aSimu;
	bool tes = false;
	while (ArchivoP3D->Read_Line(Tipo, sID, dePlaca, aSimu, "|")) {
		if (Tipo == "WRITE") {
			Est_aSimu.ID = Funciones::To_Integer(sID);
			Est_aSimu.a_Simulador = aSimu;
			this->Map_P3D_Write[dePlaca] = Est_aSimu;
		}
	}
	ArchivoP3D->Reset_LineParameter();
	// Lectura de READ P3D (Envio a Placa)			
	int ID = 0;
	string Evento, TipoDato, Respuesta, Decimales;
	DATO_COMPUESTO Param_Com;
	while (ArchivoP3D->Read_Line(Tipo, Evento, TipoDato, Respuesta, Decimales, "|")) {
		if (Tipo == "READ_P3D") {
			this->Map_P3D_Read[ID] = { Evento, TipoDato, Respuesta, Decimales };
			ID++;
		}
	}
	//Cargamos el arreglo en 0 para comparar cambios 
	Array_P3D = new double[(int)Map_P3D_Read.size()];
	for (int i = 0; i < Map_P3D_Read.size(); i++) {
		Array_P3D[i] = 0;
	}

	ArchivoP3D->Reset_LineParameter();
	// Lectura de READ PMDG (Envio a Placa)			
	string deSimu, aPlaca, decimales;
	while (ArchivoP3D->Read_Line(Tipo, deSimu, aPlaca, decimales, "|")) {
		if (Tipo == "READ_PMDG") {
			this->Map_PMDG_Read[deSimu] = aPlaca;
		}
	}

	// Cargar vector								
	Buscador_P3D_Write = Map_P3D_Write.begin();
	while (Buscador_P3D_Write != Map_P3D_Write.end()) {
		EST_BOARD_SIMU Bs;
		Bs.ID = Buscador_P3D_Write->second.ID;
		Bs.Board = Buscador_P3D_Write->first;
		Bs.Simu = Buscador_P3D_Write->second.a_Simulador;
		vBoardSimu.push_back(Bs);
		Buscador_P3D_Write++;
	}
	// Cargar vector READ PMDG						
	Buscador_PMDG_Read = Map_PMDG_Read.begin();
	while (Buscador_PMDG_Read != Map_PMDG_Read.end()) {
		EST_SIMU_BOARD Sb;
		Sb.Simu = Buscador_PMDG_Read->first;
		Sb.Board = Buscador_PMDG_Read->second;
		vSimuBoard.push_back(Sb);
		Buscador_PMDG_Read++;
	}
}

//------------------------------------------------//
//--     CONEXION CON P3D (RECEPCION DE SIM)	  //
//------------------------------------------------//
void P3D_Base::Conexion_P3D() {
	// LECTURA DE DATOS (EVENTOS) - RECEPCION DEL SIMULADOR										    
	// *********************************************************************************************
	Buscador_P3D_Read = Map_P3D_Read.begin();
	// Agregar Cada Evento y Tipo de dato al ID de definicion (READ EN ARCHIVO CFG)
	while (Buscador_P3D_Read != Map_P3D_Read.end()) {
		this->hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_P3D, Buscador_P3D_Read->second.A_Evento.c_str(), Buscador_P3D_Read->second.B_TipoDato.c_str());
		Buscador_P3D_Read++;}
	//Asociar el ID de definicion al ID de Requerimiento	
	this->hr = SimConnect_RequestDataOnSimObject(
		hSimConnect, REQUEST_P3D, DEFINITION_P3D, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SIM_FRAME, SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);
	// ESCRITURA DE DATOS (EVENTOS) - ENVIO AL SIMULADOR (TODOS LOS QUE SE ENCUENTREN MAPEADOS)	    
	// *********************************************************************************************
	Buscador_P3D_Write = Map_P3D_Write.begin();
	// Asociamos cada Comando al  ID (WRITE EN ARCHIVO CFG)							
	while (Buscador_P3D_Write != Map_P3D_Write.end()) {
		// Asociacion de Comando a ID	
		this->hr = SimConnect_MapClientEventToSimEvent(hSimConnect, Buscador_P3D_Write->second.ID, Buscador_P3D_Write->second.a_Simulador.c_str());
		// Asociamos ID a Grupo			
		this->hr = SimConnect_AddClientEventToNotificationGroup(hSimConnect, GROUP0, Buscador_P3D_Write->second.ID);
		Buscador_P3D_Write++;
	}
	// Asignamos prioridad del Grupo	
	this->hr = SimConnect_SetNotificationGroupPriority(hSimConnect, GROUP0, SIMCONNECT_GROUP_PRIORITY_HIGHEST);
}

//------------------------------------------------//
//--     CONEXION CON PMDG						  //
//------------------------------------------------//
void P3D_Base::Conexion_PMDG() {
	Sleep(100);
	// LECTURA DE DATOS (EVENTOS) - RECEPCION DEL SIMULADOR				
	this->hr = SimConnect_MapClientDataNameToID(hSimConnect, PMDG_NG3_DATA_NAME, PMDG_NG3_DATA_ID); 
	this->hr = SimConnect_AddToClientDataDefinition(hSimConnect, PMDG_NG3_DATA_DEFINITION, 0, sizeof(PMDG_NG3_Data), 0, 0);
	this->hr = SimConnect_RequestClientData(hSimConnect, PMDG_NG3_DATA_ID, DATA_REQUEST, PMDG_NG3_DATA_DEFINITION,
		SIMCONNECT_CLIENT_DATA_PERIOD_ON_SET, SIMCONNECT_CLIENT_DATA_REQUEST_FLAG_CHANGED, 0, 0, 0);	
	// ESCRITURA DE DATOS (EVENTOS)										
	Control.Event		= 0;	//Puesta a 0
	Control.Parameter	= 0;	//Puesta a 0
	this->hr = SimConnect_MapClientDataNameToID(hSimConnect, PMDG_NG3_CONTROL_NAME, PMDG_NG3_CONTROL_ID);
	this->hr = SimConnect_AddToClientDataDefinition(hSimConnect, PMDG_NG3_CONTROL_DEFINITION, 0, sizeof(PMDG_NG3_Control), 0, 0);
	this->hr = SimConnect_RequestClientData(hSimConnect, PMDG_NG3_CONTROL_ID, CONTROL_REQUEST, PMDG_NG3_CONTROL_DEFINITION,	
		SIMCONNECT_CLIENT_DATA_PERIOD_ON_SET, SIMCONNECT_CLIENT_DATA_REQUEST_FLAG_CHANGED, 0, 0, 0);
}

//------------------------------------------------//
//--     MENSAJES A PANTALLA DEL SIMULADOR		  //
//------------------------------------------------//
void P3D_Base::ScreenMessage(std::string Message) {
	char Message1[] = "Conexion con mediador establecida";
	SimConnect_Text(hSimConnect, SIMCONNECT_TEXT_TYPE_PRINT_WHITE, 8, 2, sizeof(Message1), (void*)Message1);
}

//------------------------------------------------//
//--     DESCONEXION							  //
//------------------------------------------------//
void P3D_Base::Disconnect() {
	if (this->Status) {
		this->Status = false;
		Sleep(10);
		hr = SimConnect_Close(hSimConnect);
	}
	
}
// Liberar la libreria		
P3D_Base::~P3D_Base() {
	Disconnect();
}

//------------------------------------------------//
//--     ESCRITURA DE DATOS EN P3D Y PMDG		  //
//------------------------------------------------//
void P3D_Base::Send(string Comando, unsigned int Valor) {
	// Comando es valor proveniente de la placa
	//Solo un proceso a la vez puede encolar datos
	//Bloqueo.lock();
	
	//Funciones::Divide_Data(Data, Parametro, Valor, "=");
	
	//Buscamos el Evento y Obtenemos el ID
	Buscador_P3D_Write = Map_P3D_Write.find(Comando);
	if (Buscador_P3D_Write != Map_P3D_Write.end()) {
		//Co_Evento.push(Buscador_P3D_Write->second.ID); // Envia el ID /// continuar aca
		//Co_Parametro.push(Valor);
	}
}

//------------------------------------------------//
//--     OBTENER LISTADO DE BOARD SIMULADOR		  //
//------------------------------------------------//
std::vector <EST_BOARD_SIMU> P3D_Base::Get_Board_Simu() {
	return vBoardSimu;
}
//------------------------------------------------//
//--     OBTENER LISTADO DE SIMULADOR BOAR		  //
//------------------------------------------------//
std::vector <EST_SIMU_BOARD> P3D_Base::Get_Simu_Board() {
	return vSimuBoard;
}
//------------------------------------------------//
//--     RECEPCION DE P3D + PMDG (SIM)			  //
//------------------------------------------------//
void CALLBACK P3D_Base::Recep_Estatica(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext) {
	//Obtenemos el puntero This (Para poder llamar a la instancia del metodo dinamico)
	P3D_Base* pThis = reinterpret_cast<P3D_Base*>(pContext);
	pThis->Recep_Dinamica(pData, cbData);
}
//------------------------------------------------//
//--     RECEPCION DE P3D + PMDG (DINAMICA)		  //
//------------------------------------------------//
void P3D_Base::Recep_Dinamica(SIMCONNECT_RECV* pData, DWORD cbData) {
	switch (pData->dwID) {
		// RECEPCION SOLO PMDG (Recepcion de datos del PMDG)
	case SIMCONNECT_RECV_ID_CLIENT_DATA: {
		SIMCONNECT_RECV_CLIENT_DATA* pObjData = (SIMCONNECT_RECV_CLIENT_DATA*)pData;
		switch (pObjData->dwRequestID) {
			// ARRIBO DE DATOS DEL SIMULADOR (PMDG)
		case  DATA_REQUEST: {
			PMDG_NG3_Data* pS = (PMDG_NG3_Data*)&pObjData->dwData;
			//Proceso de arribo de datos (PMDG)
			Recepcion_PMDG(pS);
			break; }
						  // ESCRITURA DE DATOS EN SIMULADOR (PMDG)
		case  CONTROL_REQUEST: {
			PMDG_NG3_Control* pS = (PMDG_NG3_Control*)&pObjData->dwData; // keep the present state of Control area to know if the server had received and reset the command
			Control = *pS;
			break; }
		}
		break;
	}
									   //RECEPCION SOLO DE P3D (VARIABLES)					
	case SIMCONNECT_RECV_ID_SIMOBJECT_DATA: {
		SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;
		switch (pObjData->dwRequestID) {
		case REQUEST_P3D: {
			double* Arr = (double*)&pObjData->dwData;
			Recepcion_P3D(Arr);  //Procesar Recepcion P3D
			break; }
		}
	}
	}                            
}


//----------------------------------------------//
//-- EXPORT										//
//----------------------------------------------//

P3D* New_P3D() {
	return new P3D_Base();
}

//------------------------------------------------//
//--     PROCESAR RECEPCION DE P3D (SIM)		  //
//------------------------------------------------//
void P3D_Base::Recepcion_P3D(double* DATA) {
	for (int i = 0; i < Map_P3D_Read.size(); i++) {
		//cout << DATA[i] << " " << Map_P3D_Read.at(i).A_Evento << " " << Map_P3D_Read.at(i).B_TipoDato <<  endl;
		//OutputDebugString(to_string(DATA[i]).c_str());
		//OutputDebugString(" ");
		//OutputDebugString(Map_P3D_Read.at(i).A_Evento.c_str());
		//OutputDebugString("\n");
		Controlar_P3D(DATA[i], Array_P3D[i], Map_P3D_Read.at(i).A_Evento.c_str());
	}
}

//------------------------------------------------//
//--     ETAPA DE CONTROL SEGUN TIPO DE DATO	  //
//------------------------------------------------//

void P3D_Base::Controlar(bool& DatoSimu, bool& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		Event_Reception(Comando, S_DatoSimu);
	}
}
void P3D_Base::Controlar(int& DatoSimu, int& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		Event_Reception(Comando, S_DatoSimu);
	}
}
void P3D_Base::Controlar(unsigned int& DatoSimu, unsigned int& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		Event_Reception(Comando, S_DatoSimu);
	}
}
void P3D_Base::Controlar(char& DatoSimu, char& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		Event_Reception(Comando, S_DatoSimu);
	}
}
void P3D_Base::Controlar(unsigned char& DatoSimu, unsigned char& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		Event_Reception(Comando, S_DatoSimu);
	}
}
void P3D_Base::Controlar(short& DatoSimu, short& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		Event_Reception(Comando, S_DatoSimu);
	}
}
void P3D_Base::Controlar(unsigned short& DatoSimu, unsigned short& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		Event_Reception(Comando, S_DatoSimu);
	}
}
void P3D_Base::Controlar(float& DatoSimu, float& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		Event_Reception(Comando, S_DatoSimu);
	}
}
void P3D_Base::Controlar_P3D(double& DatoSimu, double& DatoLocal, const char* Comando) {
	if (DatoSimu != DatoLocal) {
		DatoLocal = DatoSimu;
		string S_DatoSimu = to_string(DatoSimu);
		// Encolamos directamente
		Co_Valor.push(to_string(DatoSimu));
		Co_Comando.push(Comando);
	}
}


//*********************************************
//*** ASIGNACION DE EVENTO					***
//*********************************************
void P3D_Base::Assign_Event_Reception(void(*Function)(string Comando, string Valor)) {
	Function_Reception = Function;
}

//*********************************************
//*** EVENTO	 							***
//*********************************************
void P3D_Base::Event_Reception(string Comando, string Valor) {
	//Buscamos el Comando para obtener el equivalente a enviar a la placa
	Buscador_PMDG_Read = Map_PMDG_Read.find(Comando);
	if (Buscador_PMDG_Read != Map_PMDG_Read.end()) {
		// Encontrado encolamos
		Co_Valor.push(Valor);
		Co_Comando.push(Comando);
	}
}

//*********************************************
//*** TH LOOP DE ENVIO A PLACA				***
//*********************************************
void P3D_Base::Th_Loop_Envio_a_Placa() {
	string Comando;
	string Valor;
	while (Status) {
		if (!Co_Comando.empty()) {
			Comando = Co_Comando.front();
			Valor = Co_Valor.front();
			// Enviamos
			Function_Reception(Comando, Valor);
			//Limpiamos cola
			Co_Comando.pop();
			Co_Valor.pop();
		}
		Sleep(1);
	}
}

//*********************************************
//***	METODOS								***
//*********************************************
void P3D_Base::Activate_After_Overhead() {
	AFT_OVERHEAD = true;
}
void P3D_Base::Activate_Fordward_Overhead() {
	FORWARD_OVERHEAD = true;
}
void P3D_Base::Activate_Glareshield() {
	GLARESHIEL = true;
}
void P3D_Base::Activate_Fordward_Panel() {
	FORWARD_PANEL = true;
}
void P3D_Base::Activate_Low_Fordward_Panel() {
	LOWER_FORWARD_PANEL = true;
}
void P3D_Base::Activate_Control_Stand() {
	CONTROL_STAND = true;
}
void P3D_Base::Deactivate_After_Overhead() {
	AFT_OVERHEAD = false;
}
void P3D_Base::Deactivate_Fordward_Overhead() {
	FORWARD_OVERHEAD = false;
}
void P3D_Base::Deactivate_Glareshield() {
	GLARESHIEL = false;
}
void P3D_Base::Deactivate_Fordward_Panel() {
	FORWARD_PANEL = false;
}
void P3D_Base::Deactivate_Low_Fordward_Panel() {
	LOWER_FORWARD_PANEL = false;
}
void P3D_Base::Deactivate_Control_Stand() {
	CONTROL_STAND = false;
}


//*********************************************
//*** Funcion vacia de EVENTO				***
//*********************************************
void P3D_Base::Function_Empty(string Comando, string Valor) {
	OutputDebugString(Comando.c_str());
	OutputDebugString(" ");
	OutputDebugString(Valor.c_str());
	OutputDebugString("\n");
}
