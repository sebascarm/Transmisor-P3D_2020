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

int C_ListBox::Get_Row() {
	return SendMessage(hWnd, LB_GETCURSEL, 0, 0);
}

string C_ListBox::Get_Text() {
	//string text;
	char* text;
	int length;
	int row = this->Get_Row();
	
	length = SendMessage(hWnd, LB_GETTEXTLEN, (WPARAM)row, 0);
	text = new char[length + 1];
	SendMessage(hWnd, LB_GETTEXT, (WPARAM)row, (LPARAM)text);
	//SendMessage(hWnd, LB_GETTEXT, row, (LPARAM)text);
	return text;
}

void C_ListBox::Add_Line(string Texto) {
	SendMessage(hWnd, LB_ADDSTRING, 0, (LPARAM)Texto.c_str());
}

//*********************************************
//*** ASIGNACION DE EVENTO					***
//*********************************************
void C_ListBox::Assign_Event_ChangeCell(void(*Function)()) {
	Function_ChangeCell = Function;
}
void C_ListBox::Assign_Event_DobleClick(void(*Function)()) {
	Function_DobleClick = Function;
}


//*********************************************
//*** EVENTO	 (El loop debe llamarlo)	***
//*** No se activa solo						***
//*********************************************
void C_ListBox::Event_ChangeCell() {
	Function_ChangeCell();
}
void C_ListBox::Event_DobleClick() {
	Function_DobleClick();
}




//std::thread Th_ChangeCell([this, row, text] {Function_ChangeCell(row, text);});
//Th_ChangeCell.detach();