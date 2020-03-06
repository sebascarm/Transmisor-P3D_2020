#include "C_ListBox.h"

void C_ListBox::Create(Win_Frame* pFrame, int x, int y, int ancho, int alto) {
	// Crear y contener
	C_Objeto::Create(pFrame, "", x, y, ancho, alto);
	C_Objeto::Contener(*this);
	// Detalles del objeto
	Tipo = "LISTBOX";
	// Estilo
	Estilo = WS_CHILD | WS_VISIBLE | LBS_STANDARD | LBS_NOTIFY;
}

void C_ListBox::Add_Line(string Texto) {
	SendMessage(hWnd, LB_ADDSTRING, 0, (LPARAM)Texto.c_str());
}

