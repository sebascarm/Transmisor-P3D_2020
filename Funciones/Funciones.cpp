#include "Funciones.h"

#include <algorithm>	//Para Replace de string y trim
#include <windows.h>	//Para MultiByte
#include <vector>

#include <math.h>       /* pow */
#include <cctype>		//Para trim isspace(ch);
#include <sstream>		//Para string to integer
#include <iostream>		//Para COUT

#ifdef _DEBUG
bool DEBUG = true;
#else
bool DEBUG = false;
#endif // _DEBUG

namespace Funciones {
	void RemplazarSTR(string& Texto, string Caracter, string NuevoCaracter) {
		char _Caracter;
		char _NuevoCaracter;
		_Caracter = Caracter[0];
		_NuevoCaracter = NuevoCaracter[0];
		replace(Texto.begin(), Texto.end(), _Caracter, _NuevoCaracter);
	}
	// inline: se copia el codigo donde se usa la funcion para acelerar el programa(puede generar un programa mas largo)
	// static en una funcion se usa para enlace interno
	// trim from start (in place)
	void Ltrim(string& Texto) {
		Texto.erase(Texto.begin(), std::find_if(Texto.begin(), Texto.end(), [](int ch) {
			return !std::isspace(ch);
			}));
	}
	// trim from end (in place)						
	void Rtrim(string& Texto) {
		Texto.erase(std::find_if(Texto.rbegin(), Texto.rend(), [](int ch) {
			return !std::isspace(ch);
			}).base(), Texto.end());
	}
	// trim from both ends (in place)				
	void Trim(string& Texto) {
		Ltrim(Texto);
		Rtrim(Texto);
	}
	// Redimencionar texto, completando con espacios
	void RedimSTR(std::string& Texto, int size){
		int largo = Texto.length();
		if (largo > size) {
			Texto =  Texto.substr(0, size);
		} else if (largo < size) {
			Texto = Texto + string((size-largo), ' ');
		}
	}



	// Convert a wide Unicode string to an UTF8 string
	string utf8_encode(const wstring& wstr) {
		if (wstr.empty()) return string();
		int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
		string strTo(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
		return strTo;
	}

	// Convert an UTF8 string to a wide Unicode String
	wstring utf8_decode(const string& str) {
		if (str.empty()) return wstring();
		int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
		wstring wstrTo(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
		return wstrTo;
	}

	// Convert an UTF8 string to a wide Unicode String
	wstring ANSI_to_WideString(const string& str) {
		if (str.empty()) return wstring();
		int size_needed = MultiByteToWideChar(CP_ACP, 0, &str[0], (int)str.size(), NULL, 0);
		wstring wstrTo(size_needed, 0);
		MultiByteToWideChar(CP_ACP, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
		return wstrTo;
	}

	// Convert an ANSI string to a UTF8 string
	string UnicodeString(string Origen) {
		wstring WideString;
		string Resultado;
		WideString = ANSI_to_WideString(Origen);
		Resultado = utf8_encode(WideString);
		return Resultado;
	}
	bool Is_Number(string& Texto) {
		string TexNumero;
		int Numero = atoi(Texto.c_str());
		TexNumero = to_string(Numero);
		if (TexNumero == Texto) { return true; }
		else { return false; }
	}

	int To_Integer(string& Texto) {
		int Resultado = 0;
		istringstream myStream(Texto);
		myStream >> Resultado;
		return Resultado;
	}

	unsigned int To_UInteger(string& Texto) {
		unsigned int Resultado = 0;
		istringstream myStream(Texto);
		myStream >> Resultado;
		return Resultado;
	}

	double To_Double(string& Texto) {
		double Resultado = 0;
		istringstream myStream(Texto);
		myStream >> Resultado;
		return Resultado;
	}

	void Sum_String(string& Data) {
		unsigned __int64 PosIni, PosFin;
		string Texto1, Texto2;
		int Valor1, Valor2, Resul;
		PosIni = Data.find("+");
		if (PosIni >= 0) {
			PosFin = Data.find("\n", PosIni);
			if (PosFin == -1) { PosFin = Data.size(); }  // No hay enter, ultima linea
			Texto1 = Data.substr(0, PosIni);
			Texto2 = Data.substr(PosIni + 1);
			//Convertimos en int
			Valor1 = To_Integer(Texto1);
			Valor2 = To_Integer(Texto2);
			Resul = Valor1 + Valor2;
			Data = to_string(Resul);
		}
	}

	//Conversion para WINAPI
	wstring String_to_WS(const string& str) {
		//Exactamente igual a ANSI_to_WideString (solo para mantener 2 nombres de funciones)
		if (str.empty()) return wstring();
		int size_needed = MultiByteToWideChar(CP_ACP, 0, &str[0], (int)str.size(), NULL, 0);
		wstring wstrTo(size_needed, 0);
		MultiByteToWideChar(CP_ACP, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
		return wstrTo;
	}

	//Redondear a x decimales
	double Redondear(double Numero, int Decimales) {
		return ((float)((int)(Numero * pow(10, Decimales) + 0.5))) / pow(10, Decimales);
	}
	string a_String_red(double Numero, int Decimales) {
		double Valor = ((float)((int)(Numero * pow(10, Decimales) + 0.5))) / pow(10, Decimales);
		string S_Valor = to_string(Valor);
		unsigned __int64 pos = S_Valor.find(".");
		if (Decimales == 0) {
			return S_Valor.substr(0, pos);
		}
		else {
			return S_Valor.substr(0, pos + Decimales + 1);
		}
	}
	//Revisa se la cadena de texto contiene solo espacios o enter sin texto
	bool Texto_vacio(string Data) {
		if (size(Data) == 0) {
			return true;
		}
		else {
			Trim(Data);
			if (Data == "") { return true; }
			else { return false; }
		}
	}
	//******************************************************
	//**** DELETE COMENT (V1.1 - Correccion)			****
	//******************************************************
	string Delete_Comment(string Data) {
		int PosIni, PosFin;
		string Texto1, Texto2;
		PosIni = Data.find("//");
		while (PosIni >= 0) {
			PosFin = Data.find("\n", PosIni);
			if (PosFin == -1) { PosFin = Data.size() - 1; }  // No hay enter, ultima linea
			Texto1 = Data.substr(0, PosIni);
			//Texto2 = Data.substr(PosFin + 1);
			Texto2 = Data.substr(PosFin);					// No borro el enter v1.1
			Data = Texto1 + Texto2;
			//Buscamos una nueva ocurrencia
			PosIni = Data.find("//");
		}
		//Borramos llaves
		PosIni = Data.find("{");
		while (PosIni >= 0) {
			PosFin = Data.find("}", PosIni);
			if (PosFin == -1) { PosFin = Data.size(); }  // No hay enter, ultima linea
			Texto1 = Data.substr(0, PosIni);
			//Texto2 = Data.substr(PosFin + 1);
			Texto2 = Data.substr(PosFin);					// No borro el enter v1.1
			Data = Texto1 + Texto2;
			//Buscamos una nueva ocurrencia
			PosIni = Data.find("{");
		}
		return Data;
	}
	
	//******************************************************
	//**** DIVIDIR CADENA (MEJORADO)					****
	//******************************************************
	std::vector<std::string> Split_String(const std::string& Cadena, char Divisor) {
		std::vector<std::string> vec_text;
		std::string texto;
		std::istringstream Cadena_Stream(Cadena);
		while (std::getline(Cadena_Stream, texto, Divisor)){
			Clear_Text(texto);
			vec_text.push_back(texto);
		}
		return vec_text;
	}
	std::string Split_String(const std::string& Cadena, char Divisor, int Elemento) {
		std::vector<std::string> vec_text;
		vec_text = Split_String(Cadena, Divisor);
		if (vec_text.size() > Elemento) {
			return vec_text[Elemento];
		} else {
			return "";
		}
	}
	

	//******************************************************
	//**** Limpia basura (TAB y Espacios)				****
	//******************************************************
	void Clear_Text(string& Data) {
		RemplazarSTR(Data, "\t", " ");
		Trim(Data);
	}

	//******************************************************
	//**** MAPEO DE VALORES								****
	//******************************************************
	int Mapeo(int Value, int Min1, int Max1, int Min2, int Max2) {
		int Resul = ((Value - Min1) * (Max2 - Min2) / (Max1 - Min1)) + Min2;
		return Resul;
	}
	double Mapeo(double Value, int Min1, int Max1, int Min2, int Max2) {
		double Resul = ((Value - Min1) * (Max2 - Min2) / (Max1 - Min1)) + Min2;
		return Resul;
	}
	double Mapeo(double Value, double Min1, double Max1, int Min2, int Max2) {
		double Resul = ((Value - Min1) * (Max2 - Min2) / (Max1 - Min1)) + Min2;
		return Resul;
	}

	//******************************************************
	//**** FUNCION PARA DEBUG Y LOG						****
	//******************************************************
	void Log(string Datos, string Datos2, string Datos3, string Datos4, string Datos5) {
		std::string Mensaje = "LOG: " + Datos + Datos2 + Datos3 + Datos4 + Datos5 + "\n";
		OutputDebugString(Mensaje.c_str());
	}
	void Logl(string Datos, string Datos2, string Datos3, string Datos4, string Datos5) {
		std::string Mensaje = "LOG: " + Datos + Datos2 + Datos3 + Datos4 + Datos5;
		OutputDebugString(Mensaje.c_str());
	}
	void Debug(string Datos, string Datos2, string Datos3, string Datos4, string Datos5) {
		if (DEBUG) {
			std::string Mensaje = "DEBUG: " + Datos + Datos2 + Datos3 + Datos4 + Datos5 + "\n";
			OutputDebugString(Mensaje.c_str());
		}
	}
	void Debugl(string Datos, string Datos2, string Datos3, string Datos4, string Datos5) {
		if (DEBUG) {
			std::string Mensaje = "DEBUG: " + Datos + Datos2 + Datos3 + Datos4 + Datos5;
			OutputDebugString(Mensaje.c_str());
		}
	}
	//******************************************************
	//**** EVENTOS SIN ACCION							****
	//******************************************************
	void FuncionTest() {
		OutputDebugString("FUNCION TEST\n");
	}
}
