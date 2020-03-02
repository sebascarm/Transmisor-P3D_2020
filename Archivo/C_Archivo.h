#pragma once
#include "Archivo.h"

#include "Funciones.h"

#include <fstream>		//Manejo de archivos
#include <string>		//Para el getline

using namespace std;	//Manejo de archivos

class C_Archivo: public Archivo {
protected:
	std::string     Nombre_Archivo;
	std::fstream	Archivo;
	std::string		Contenido;		//std::string con el contenido del archivo				
	int				PosParam = 0;	// Linea de lectura de parametro secuencial			
	//Funcion interna para el read line // devuelve true cuando hay linea con datos	
	bool Read_Line_int(std::string& Resul, std::string& Resul2, std::string& Resul3, std::string& Resul4, std::string& Resul5, std::string Divisor, int Elementos);
public:
	bool	Load(std::string File);		// Devuleve false si no puede abrir el archivo
	string	Read_Parameter(std::string Parameter);
	void	Change_Parameter(std::string Parameter, std::string Value);
	void	Save(std::string File);		//Incompleto // Realizar
	~C_Archivo();						// Cierre

	//Lectura secuencial de linea (Devuelve de 1 a 3 valores)
	bool Read_Line(std::string& Resul);
	bool Read_Line(std::string& Resul, std::string& Resul2, std::string Seperador);
	bool Read_Line(std::string& Resul, std::string& Resul2, std::string& Resul3, std::string Seperador);
	bool Read_Line(std::string& Resul, std::string& Resul2, std::string& Resul3, std::string& Resul4, std::string Separador);
	bool Read_Line(std::string& Resul, std::string& Resul2, std::string& Resul3, std::string& Resul4, std::string& Resul5, std::string Separador);
	void Reset_LineParameter();
};

