#include "C_Button.h"
#include <thread>			//Para hilos (multiproceso)

void C_Button::Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto) {
	// Crear y contener
	C_Objeto::Create(pFrame, Text, x, y, ancho, alto);
	C_Objeto::Contener(*this);
	//Detalles del objeto
	Tipo = "BUTTON";
	Estilo = BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_FLAT;
}


//*********************************************
//*** ASIGNACION DE EVENTO					***
//*********************************************
void C_Button::Assign_Event_Click(void(*Function)()) {
	Funcion_Click = Function;
}


//*********************************************
//*** EVENTO CLICK (El loop debe llamarlo)	***
//*** No se activa solo						***
//*********************************************
void C_Button::Event_Click() {
	std::thread Th_Click([this] {Funcion_Click(); });
	Th_Click.detach();
}

