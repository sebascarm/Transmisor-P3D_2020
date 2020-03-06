#include "C_Objeto.h"
#include "C_Button.h"
#include "C_Label.h"
#include "C_GroupBox.h"
#include "C_TextBox.h"
#include "C_Menu.h"
#include "C_MultiLine.h"
#include "C_ListBox.h"

#include <vector>
#include "Contenedor.h"

extern std::vector <Contenedor> CONTENEDOR;

void C_Objeto::Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto) {
	//Elementos
	hWnd_Padre = &pFrame->Get_hWnd();	// Obtengo un puntero el padre
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->Texto = Text;
	
}

//Contenedor (Agregar clase en contenedor.h)
void C_Objeto::Contener(C_Button & Objeto) {
	Elemento = CONTENEDOR.size();
	CONTENEDOR.resize(Elemento + 1);
	CONTENEDOR[Elemento].New_Object(Objeto);
	ID = CONTENEDOR[Elemento].Element_ID;
}
void C_Objeto::Contener(C_Label& Objeto) {
	Elemento = CONTENEDOR.size();
	CONTENEDOR.resize(Elemento + 1);
	CONTENEDOR[Elemento].New_Object(Objeto);
	ID = CONTENEDOR[Elemento].Element_ID;
}
void C_Objeto::Contener(C_GroupBox& Objeto) {
	Elemento = CONTENEDOR.size();
	CONTENEDOR.resize(Elemento + 1);
	CONTENEDOR[Elemento].New_Object(Objeto);
	ID = CONTENEDOR[Elemento].Element_ID;
}
void C_Objeto::Contener(C_TextBox& Objeto) {
	unsigned __int64 Elemento = CONTENEDOR.size();
	CONTENEDOR.resize(Elemento + 1);
	CONTENEDOR[Elemento].New_Object(Objeto);
	ID = CONTENEDOR[Elemento].Element_ID;
}
void C_Objeto::Contener(C_MultiLine& Objeto) {
	Elemento = CONTENEDOR.size();
	CONTENEDOR.resize(Elemento + 1);
	CONTENEDOR[Elemento].New_Object(Objeto);
	ID = CONTENEDOR[Elemento].Element_ID;
}
void C_Objeto::Contener(C_ListBox& Objeto) {
	Elemento = CONTENEDOR.size();
	CONTENEDOR.resize(Elemento + 1);
	CONTENEDOR[Elemento].New_Object(Objeto);
	ID = CONTENEDOR[Elemento].Element_ID;
}

// Solo el menu difiere
void C_Objeto::Contener(C_Menu& Objeto, int Elementos) {
	Elemento = CONTENEDOR.size();
	CONTENEDOR.resize(Elemento + 1);
	CONTENEDOR[Elemento].New_Object(Objeto);
	ID = CONTENEDOR[Elemento].Element_ID;
}



void C_Objeto::Draw() {
	// CREACION DE OBJETO
	hWnd = CreateWindowEx(
		0,
		(LPSTR)this->Tipo.c_str(),	/* Nombre de la clase */
		(LPSTR)Texto.c_str(),		/* Texto */
		this->Estilo,				/* Estilo */
		x, y,						/* Posición */
		ancho, alto,				/* Tamaño */
		*hWnd_Padre,				/* Ventana padre */
		(HMENU)(UINT_PTR)ID,		/* Identificador del control */
		NULL,						/* hInstance,	/* Instancia */
		NULL);						/* Sin datos de creación de ventana */

	SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));
}

//Color de fondo
HBRUSH C_Objeto::ColorEdit(WPARAM& wParam) {
	//Fondo del texto
	static HBRUSH pincel;
	pincel = CreateSolidBrush(RGB(250, 250, 250));	// Es un color especifico, se debe modificar por el que queremos usar
	SetBkColor((HDC)wParam, RGB(250, 250, 250));	// Es un color especifico, se debe modificar por el que queremos usar
	return pincel;

}

//*********************************************
//*** PROPIEDADES COMUNES					***
//*********************************************
std::string C_Objeto::Get_Text() {
	string Resul;
	int len = GetWindowTextLength(hWnd) + 1;
	std::string Text;
	Text.reserve(len);
	GetWindowText(hWnd, const_cast<char*>(Text.c_str()), len);
	return Text.c_str();	//Devemos convertir sino devolvmos string con contenido pero de size 0
}
int C_Objeto::Get_Pos_X() {
	return x;
}
int C_Objeto::Get_Pos_Y() {
	return y;
}

//*********************************************
//*** METODOS COMUNES						***
//*********************************************
void C_Objeto::Set_Text(string Text) {
	SetWindowText(hWnd, (LPCSTR)Text.c_str());
}

void C_Objeto::Set_Pos(int x, int y, int ancho, int alto) {
	if (x == -1) { x = Get_Pos_X(); }
	if (y == -1) { y = Get_Pos_Y(); }
	if (ancho == -1) { ancho = this->ancho; }
	if (alto == -1) { alto = this->alto; }
	SetWindowPos(hWnd, 0, x, y, ancho, alto, 0);
}


//*********************************************
//*** FUNCION POR DEFECTO SIN DEFINIR		***
//*********************************************
void C_Objeto::Function_Empty() {
	//Debug de mensajes
	OutputDebugString("EVENT NOT DEFINED\n");
}

//*********************************************
//*** Export								***
//*********************************************
Win_Button* New_Button() {
	return new C_Button();
}
Win_Label* New_Label() {
	return new C_Label();
}
Win_GroupBox* New_GroupBox() {
	return new C_GroupBox();
}
Win_TextBox* New_TextBox() {
	return new C_TextBox();
}
Win_Menu* New_Menu() {
	return new C_Menu();
}
Win_MultiLine* New_MultiLine() {
	return new C_MultiLine();
}
Win_ListBox* New_ListBox() {
	return new C_ListBox();
}
