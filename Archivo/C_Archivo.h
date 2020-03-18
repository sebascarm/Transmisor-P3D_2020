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
	
public:
	bool	Load(std::string File);		// Devuleve false si no puede abrir el archivo
	string	Read_Parameter(std::string Parameter);
	void	Change_Parameter(std::string Parameter, std::string Value);
	void	Save(std::string File);		//Incompleto // Realizar
	~C_Archivo();						// Cierre
	// Lectura secuencial en vector - el ultimo vector se retorna en vacion '' para saber que es el ultimo
	bool Read_LineVec(std::vector<std::string>& Vector_Resul, char Separador);
	void Reset_LineParameter();
};

