//######################################################//
// ARCHIVO V 1.1										//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 18/03/2020                                           //
// Read_lineVec (lectura de linea en vector)			//
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
#else
#pragma comment (lib, "Funciones.lib")
#endif

#include <string>		// Para el uso de string
#include <vector>		// Para el use de vector
//using namespace std;	// Para std


class Archivo {
public:
	virtual bool Load(std::string File) = 0;	//Devuleve false si no puede abrir el archivo
	virtual std::string Read_Parameter(std::string Parameter) = 0;
	virtual void Change_Parameter(std::string Parameter, std::string Value) = 0;
	virtual void Save(std::string File) = 0;	//Incompleto // Realizar
	// Lectura secuencial en vector - el ultimo vector se retorna en vacion '' para saber que es el ultimo
	virtual bool Read_LineVec(std::vector<std::string>& Vector_Resul, char Separador)=0;
	virtual void Reset_LineParameter() = 0;
};

extern "C" DLLIMPORT Archivo * New_File();
