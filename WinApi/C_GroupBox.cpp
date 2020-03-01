#include "C_GroupBox.h"

void C_GroupBox::Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto) {
	// Crear y contener
	C_Objeto::Create(pFrame, Text, x, y, ancho, alto);
	C_Objeto::Contener(*this);
	// Detalles del objeto
	Tipo = "BUTTON";
	Estilo = BS_GROUPBOX | WS_CHILD | WS_VISIBLE | WS_GROUP | BS_FLAT;
}
