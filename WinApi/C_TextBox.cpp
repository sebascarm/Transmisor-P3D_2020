#include "C_TextBox.h"

void C_TextBox::Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto) {
	// Crear y contener
	C_Objeto::Create(pFrame, Text, x, y, ancho, alto);
	C_Objeto::Contener(*this);
	// Valores propios
	Tipo = "EDIT";
	Estilo = WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL | WS_BORDER | BS_FLAT;
}