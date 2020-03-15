#include "C_MultiLine.h"

#include <thread>			//Para hilos (multiproceso)


void C_MultiLine::Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto) {
	// Crear y contener
	C_Objeto::Create(pFrame, Text, x, y, ancho, alto);
	C_Objeto::Contener(*this);
	// Valores propios
	Tipo = "EDIT";
	Estilo = WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_MULTILINE | ES_WANTRETURN | WS_VSCROLL | WS_BORDER | BS_FLAT;
	// Ejecutar proceso de lectura
	thread Th_Linea([this] {Th_Add_Line(); });
	Th_Linea.detach();

}

//*********************************************
//*** ASIGNACION DE METODO PROPIO			***
//*********************************************

void C_MultiLine::Add_Line(string Texto) {
	Cola_Texto.push(Texto);	//Se agrega a la cola
}

//*************************************************************
//*** Thread de lectura de linea para no bloquer procesos	***
//*************************************************************
void C_MultiLine::Th_Add_Line() {
	string Linea_Texto;
	bool Ejecutar = true;
	while (Ejecutar) {
		if (!Cola_Texto.empty()) {
			Linea_Texto = Cola_Texto.front();	//Leer cola
			Cola_Texto.pop();					//Limpiar cola
			// Procesar
			Linea_Texto = Linea_Texto + "\r\n";
			// Movemos el caret al final del texto			
			int Long_Texto = GetWindowTextLength(hWnd);
			SendMessage(hWnd, EM_SETSEL, Long_Texto, Long_Texto);
			//Insertamos el texto en la posicion del caret	
			SendMessage(hWnd, EM_REPLACESEL, TRUE, reinterpret_cast<LPARAM>(Linea_Texto.c_str()));
		}
		Sleep(1);
	}
}
