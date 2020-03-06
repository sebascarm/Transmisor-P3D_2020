#include "Contenedor.h"
#include "General.h"

#include "C_Frame.h"
#include "C_Button.h"
#include "C_Label.h"
#include "C_GroupBox.h"
#include "C_TextBox.h"
#include "C_Menu.h"
#include "C_MultiLine.h"
#include "C_ListBox.h"

int Contenedor::Elementos = 100;

void Contenedor::Agregar() {
	++Elementos;
	Element_ID = Elementos;
}

//CREACION DE ELEMENTOS										
void Contenedor::New_Object(C_Frame& _Objeto) {
	Agregar();
	pFrame = &_Objeto;
	this->Tipo = TipoObjeto::T_FRAME;
}
void Contenedor::New_Object(C_Button& _Objeto) {
	Agregar();
	pButton = &_Objeto;
	this->Tipo = TipoObjeto::T_BUTTON;
}
void Contenedor::New_Object(C_Label& _Objeto) {
	Agregar();
	pLabel = &_Objeto;
	this->Tipo = TipoObjeto::T_LABEL;
}
void Contenedor::New_Object(C_GroupBox& _Objeto) {
	Agregar();
	pGroupBox = &_Objeto;
	this->Tipo = TipoObjeto::T_GROUPBOX;
}
void Contenedor::New_Object(C_TextBox& _Objeto) {
	Agregar();
	pTextBox = &_Objeto;
	this->Tipo = TipoObjeto::T_TEXTBOX;
}
void Contenedor::New_Object(C_Menu& _Objeto) {
	Agregar();
	pMenu = &_Objeto;
	this->Tipo = TipoObjeto::T_MENU;
}
void Contenedor::New_Object(C_MultiLine& _Objeto) {
	Agregar();
	pMultiLine = &_Objeto;
	this->Tipo = TipoObjeto::T_MULTILINE;
}
void Contenedor::New_Object(C_ListBox& _Objeto) {
	Agregar();
	pListBox = &_Objeto;
	this->Tipo = TipoObjeto::T_LISTBOX;
}


//Show Frame													
void Contenedor::Show() {
	switch (Tipo) {
	case  TipoObjeto::T_FRAME:
		pFrame->Show();
		break;
	}
}

// GET ID (Solo Frame lo usa									
HWND Contenedor::Get_hWnd() {
	switch (Tipo) {
	case TipoObjeto::T_FRAME:
		return pFrame->hWnd;
		break;
	default:
		return 0;
	}

}

//Cambiar color (para label tranparente)						
HBRUSH Contenedor::ColorEdit(WPARAM wParam) {
	switch (Tipo) {
	case TipoObjeto::T_LABEL:
		return pLabel->ColorEdit(wParam);
		break;
	default:
		return (HBRUSH)wParam;
	}
}

//Dibujar														
void Contenedor::Draw() {
	switch (Tipo) {
	case  TipoObjeto::T_FRAME:
		pFrame->Draw();
		break;
	case TipoObjeto::T_BUTTON:
		pButton->Draw();
		break;
	case TipoObjeto::T_LABEL:
		pLabel->Draw();
		break;
	case TipoObjeto::T_GROUPBOX:
		pGroupBox->Draw();
		break;
	case TipoObjeto::T_TEXTBOX:
		pTextBox->Draw();
		break;
	case TipoObjeto::T_MENU:
		pMenu->Draw();
		break;
	case TipoObjeto::T_MULTILINE:
		pMultiLine->Draw();
		break;
	case TipoObjeto::T_LISTBOX:
		pListBox->Draw();
		break;
	}
}

int Contenedor::Get_ID() {
	switch (Tipo) {
	case TipoObjeto::T_BUTTON:
		return pButton->ID;
		break;
	case TipoObjeto::T_MENU:
		return pMenu->ID;
		break;
	case TipoObjeto::T_LISTBOX:
		return pListBox->ID;
		break;
	default:
		return 0;
	}
}