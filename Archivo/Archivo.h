//######################################################//
// ARCHIVO V 1.0 (sin cambios grandes con win2019)      //
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
#pragma comment (lib, "Funciones_d.lib")
#else
#pragma comment (lib, "Funciones.lib")
#endif

#include <string>		//Para el uso de string
//using namespace std;	//Manejo de archivos


class Archivo {
public:
	virtual bool Load(std::string File) = 0;	//Devuleve false si no puede abrir el archivo
	virtual std::string Read_Parameter(std::string Parameter) = 0;
	virtual void Change_Parameter(std::string Parameter, std::string Value) = 0;
	virtual void Save(std::string File) = 0;	//Incompleto // Realizar
	
	//Lectura secuencial de linea (Devuelve de 1 a 5 valores) - Devuelve False si no hay mas datos (fin de linea)
	virtual bool Read_Line(std::string& Resul) = 0;
	virtual bool Read_Line(std::string& Resul, std::string& Resul2, std::string Divisor) = 0;
	virtual bool Read_Line(std::string& Resul,std::string& Resul2,std::string& Resul3,std::string Divisor) = 0;
	virtual bool Read_Line(std::string& Resul,std::string& Resul2,std::string& Resul3,std::string& Resul4,std::string Divisor) = 0;
	virtual bool Read_Line(std::string& Resul,std::string& Resul2,std::string& Resul3,std::string& Resul4,std::string& Resul5,std::string Divisor) = 0;
	virtual void Reset_LineParameter() = 0;
};

extern "C" DLLIMPORT Archivo * New_File();
