#include "C_Archivo.h"
//#include <Windows.h>	# para el debug
//#include <iostream>  //Para cout
#include <sstream>		//Para split string

bool C_Archivo::Load(std::string File) {
	Nombre_Archivo = File;
	std::string Linea;
	std::string Total;
	Funciones::Debug("Opening File");
	Archivo.open(Nombre_Archivo, ios::in);
	//Revisaar si se pudo abrir el archivo
	if (Archivo.is_open()) {
		std::getline(Archivo, Linea);			//lee una linea gracias al include <std::string>
		Total = Linea;
		while (!Archivo.eof()) {				// Mientras se haya podido leer algo			
			getline(Archivo, Linea);
			Total = Total + "\n" + Linea;		// Agregar salto de linea						
		}
		Archivo.close();						// Finalmente, cierro							
		Contenido = Total;
		Contenido = Funciones::Delete_Comment(Contenido);
		Funciones::Debug("File Loaded");
		//Respuesta
		return true;
	}
	else {
		//No se pudo abrir el archivo
		Funciones::Log("No existe o no se pudo abrir el archivo: ", Nombre_Archivo.c_str());
		return false;
	}
	//Cerrar archivo
	Archivo.close();
	Funciones::Debug("Archivo Cerrado");
}


std::string C_Archivo::Read_Parameter(std::string Parameter) {
	int Posicion, PosIniVal, PosFinVal, Longitud;
	std::string Resultado = "";
	Parameter += ":";
	Posicion = (int)Contenido.find(Parameter);
	if (Posicion >= 0) {
		PosIniVal = Posicion + (int)Parameter.size();
		PosFinVal = (int)Contenido.find("\n", Posicion);
		if (PosFinVal == -1) { PosFinVal = (int)Contenido.size(); }
		Longitud = PosFinVal - PosIniVal;
		Resultado = Contenido.substr(PosIniVal, Longitud);
		Funciones::Trim(Resultado);	//sacamos los espacios
	}
	else {
		//Sin resultados
		Funciones::Log("Paramametro no encontrado: ", Parameter);
	}
	return Resultado;
}

void C_Archivo::Change_Parameter(std::string Parameter, std::string Value) {
	int Posicion, PosIniVal, PosFinVal;
	std::string Resultado = "";
	Parameter += ":";
	Posicion = (int)Contenido.find(Parameter);
	if (Posicion >= 0) {
		PosIniVal = Posicion + (int)Parameter.size();
		PosFinVal = (int)Contenido.find("\n", Posicion);
		if (PosFinVal == -1) { //Ultima linea
			PosFinVal = (int)Contenido.size();
		}
		//Rearmar cadena
		Resultado = Contenido.substr(0, PosIniVal);
		Resultado += " " + Value + Contenido.substr(PosFinVal);
		Contenido = Resultado;
	}
	else {
		//No se encontro el parametro
		Funciones::Log("Paramametro no encontrado: ", Parameter);
	}
}

void C_Archivo::Save(std::string File) {
	Archivo.open(Nombre_Archivo, ios::out);
	if (Archivo.is_open()) {
		Archivo << Contenido;
		Archivo.close();
		Funciones::Debug("Archivo Guardado");
	}
	else {
		Funciones::Log("No se encontro el Archivo para guardar");
	}
}

// Lectura secuencial en vector - el ultimo vector se retorna en vacion '' para saber que es el ultimo
bool C_Archivo::Read_LineVec(std::vector<std::string>& Vector_Resul, char Separador) {
	bool FindeLinea = false;
	Vector_Resul.clear();	// Vaciado del vector
	int PosFin, Longitud;
	std::string TextoLinea = "";
	//Obtener la linea
	PosFin = (int)Contenido.find("\n", PosParam);
	if (PosFin == -1)
		PosFin = (int)size(Contenido);	//Si no hay enter (ultima linea)
	Longitud = PosFin - PosParam;
	if (Longitud >= 0) {
		TextoLinea = Contenido.substr(PosParam, Longitud); // Resultado de linea
		PosParam = PosFin + 1;
	} else {
		TextoLinea = ""; // No hay mas lienas
		Funciones::Debug("Fin de Archivo");
		return false;
	}
	//Revisamos si hay datos en el texto
	if (Funciones::Texto_vacio(TextoLinea)) {
		Vector_Resul.push_back("");	//Ponemos el primer vector vacio
		return true;				//Para forzar a leer otra linea (revisar de devolver el vector vacio)
	}
	// Almacenamos en vector
	std::string texto;
	std::istringstream tokenStream(TextoLinea);
	while (std::getline(tokenStream, texto, Separador)) {
		Funciones::Clear_Text(texto);
		Vector_Resul.push_back(texto);
	}
	Vector_Resul.push_back("");
	return true;
}


void C_Archivo::Reset_LineParameter() {
	PosParam = 0;
}

C_Archivo::~C_Archivo() {
	Funciones::Debug("Destructor C_ARCHIVO");
}


//Export
Archivo* New_File() {
	return new C_Archivo();
}