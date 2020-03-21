//######################################################//
// FUNCIONES V 1.4							            //
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 21/03/2020                                           //
// Mapeo double											//
// Correcion en borrado de comentarios					//
// Funcion Split de texto en vector						//
// Funcion de Texto a Double							//
// Funcin RedimSTR                                      //
// Creacion                                             //
//######################################################//


//#pragma warning(disable:4190) //Warning por devolucion de datos string y wstring	
#pragma warning(disable:26451)	//Desbordamietno aritmetico: se usa valor de 4 bytes
#pragma warning(disable:4267)   //Conversion de datos con posibles perdidas			

#pragma once

#ifdef BUILDING_DLL
#define DLLIMPORT __declspec(dllexport) 
#else
#define DLLIMPORT __declspec(dllimport) 
#endif

#include <string>		// Para Tipo de datos string
#include <vector>		// Para slit de cadenas (nuevo)
#include <Windows.h>	// Tal vez para wstring

using namespace std;	//Para string

namespace Funciones {
	//utilizacion de cadenas string
	DLLIMPORT void RemplazarSTR(std::string& Texto, std::string Caracter, std::string NuevoCaracter);
	DLLIMPORT void Ltrim(std::string& Texto);
	DLLIMPORT void Rtrim(std::string& Texto);
	DLLIMPORT void Trim(std::string& Texto);
	DLLIMPORT void RedimSTR(std::string& Texto, int size);	// Redimenciona un string completando con espacios o truncando
	//Conversion de codificacion (sOLO FUNCIONA EN EL MISMO EJECUTABLE)
	DLLIMPORT std::string utf8_encode(const wstring& wstr);
	DLLIMPORT wstring utf8_decode(const std::string& str);
	DLLIMPORT std::string UnicodeString(std::string Origen);
	DLLIMPORT wstring String_to_WS(const std::string& str);
	//Devuelve true si es un numero
	DLLIMPORT bool Is_Number(std::string& Texto);
	// Conversion de datos					
	//Convierte un std::string en Integer	
	DLLIMPORT int To_Integer(std::string& Texto);
	DLLIMPORT unsigned int To_UInteger(std::string& Texto);
	DLLIMPORT double To_Double(std::string& Texto);
	//Redondear a x decimales				
	DLLIMPORT double Redondear(double Numero, int Decimales);
	DLLIMPORT std::string a_String_red(double Numero, int Decimales);
	//Para eventos sin accion test alguna (Solo Log en cout)
	DLLIMPORT void FuncionTest();
	//Borrar comentaris // y { }
	DLLIMPORT std::string Delete_Comment(std::string Data);
	//Limpia basura (TAB)
	DLLIMPORT void Clear_Text(std::string& Data);
	//Revisa se la cadena de texto contiene solo espacios o enter sin texto
	DLLIMPORT bool Texto_vacio(std::string Data);
	//Suma datos de cadenas (si hay numeros)
	DLLIMPORT void Sum_String(std::string& Data);
	//Divide datos entregando textos distintos (se omite el extern "c" para permitir sobrecarga (no se puede usar en C)
	//DLLIMPORT void Divide_Data(std::string Data, std::string& Text1, std::string& Text2, std::string Divisor);
	//DLLIMPORT void Divide_Data(std::string Data, std::string& Text1, std::string& Text2, std::string& Text3, std::string Divisor);
	//DLLIMPORT void Divide_Data(std::string Data, std::string& Text1, std::string& Text2, std::string& Text3, std::string& Text4, std::string Divisor);
	//DLLIMPORT void Divide_Data(std::string Data, std::string& Text1, std::string& Text2, std::string& Text3, std::string& Text4, std::string& Text5, std::string Divisor);
	// Divide Cadenas y entrega Vector
	DLLIMPORT std::vector<std::string> Split_String(const std::string& Cadena, char Divisor);
	//Mapeo de valores	
	DLLIMPORT int Mapeo(int Value, int Min1, int Max1, int Min2, int Max2);
	DLLIMPORT double Mapeo(double Value, int Min1, int Max1, int Min2, int Max2);
	//Logs y debug		
	DLLIMPORT void Log(std::string Datos, std::string Datos2 = "", std::string Datos3 = "", std::string Datos4 = "", std::string Datos5 = "");
	DLLIMPORT void Logl(std::string Datos, std::string Datos2 = "", std::string Datos3 = "", std::string Datos4 = "", std::string Datos5 = "");
	DLLIMPORT void Debug(std::string Datos, std::string Datos2 = "", std::string Datos3 = "", std::string Datos4 = "", std::string Datos5 = "");
	DLLIMPORT void Debugl(std::string Datos, std::string Datos2 = "", std::string Datos3 = "", std::string Datos4 = "", std::string Datos5 = "");
}
