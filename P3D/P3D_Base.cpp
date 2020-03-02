#include "P3D_Base.h"
#include "Archivo.h"
#include "Estructuras.h"	// Para Grupo

#include "Funciones.h"		// Para cambiar de string a integer


bool P3D_Base::Connect() {
	// Caragar parametros			
	this->Cargar();
	// Intento de conexion			
	if (SUCCEEDED(SimConnect_Open(&hSimConnect, "PMDG NGX Client", NULL, 0, 0, 0))) {
		Conexion_P3D();		//P3D	
		Conexion_PMDG();	//PMDG	
		ScreenMessage("Conexión con Mediador Establecida");
		// no se
		return true;
	} else {
		//this->Status = false;
		return false;
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
	//Cargamos el arreglo en 0 para comparar cambios luego	
	//Array_P3D = new double[Map_P3D_Read.size()];
	//for (int i = 0; i < Map_P3D_Read.size(); i++) {
		//Array_P3D[i] = 0;
	//}
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
	// LECTURA DE DATOS (EVENTOS) - RECEPCION DEL SIMULADOR				
	// *****************************************************************
	// Asociar NOMBRE de la estructura de datos con ID (Valor definido)	
	this->hr = SimConnect_MapClientDataNameToID(hSimConnect, PMDG_NG3_DATA_NAME, PMDG_NG3_DATA_ID); 
	// Definir el Area de Datos											
	this->hr = SimConnect_AddToClientDataDefinition(hSimConnect, PMDG_NG3_DATA_DEFINITION, 0, sizeof(PMDG_NG3_Data), 0, 0);
	// Iniciar la notificacion del control de cambios					
	// SIMCONNECT_CLIENT_DATA_REQUEST_FLAG_CHANGED flag asks for the data to be sent only when some of the data is changed.
	this->hr = SimConnect_RequestClientData(hSimConnect, PMDG_NG3_DATA_ID, DATA_REQUEST, 
		PMDG_NG3_DATA_DEFINITION,	
		SIMCONNECT_CLIENT_DATA_PERIOD_ON_SET, 
		SIMCONNECT_CLIENT_DATA_REQUEST_FLAG_CHANGED, 
		0, 0, 0);	
	// ESCRITURA DE DATOS (EVENTOS)										
	// *****************************************************************
	Control.Event		= 0;	//Puesta a 0
	Control.Parameter	= 0;	//Puesta a 0
	// Asociar NOMBRE de la estructura de datos con ID (Valor definido)	
	this->hr = SimConnect_MapClientDataNameToID(hSimConnect, PMDG_NG3_CONTROL_NAME, PMDG_NG3_CONTROL_ID);
	// Definir el Area de Datos											
	this->hr = SimConnect_AddToClientDataDefinition(hSimConnect, PMDG_NG3_CONTROL_DEFINITION, 0, sizeof(PMDG_NG3_Control), 0, 0);
	// Iniciar la notificacion del control de cambios					
	this->hr = SimConnect_RequestClientData(hSimConnect, PMDG_NG3_CONTROL_ID, CONTROL_REQUEST, 
		PMDG_NG3_CONTROL_DEFINITION,	
		SIMCONNECT_CLIENT_DATA_PERIOD_ON_SET, 
		SIMCONNECT_CLIENT_DATA_REQUEST_FLAG_CHANGED, 
		0, 0, 0);
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
	this->Status = false;
	hr = SimConnect_Close(hSimConnect);
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


//----------------------------------------------//
//-- EXPORT										//
//----------------------------------------------//

P3D* New_P3D() {
	return new P3D_Base();
}

