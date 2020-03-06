#pragma once
#include <Windows.h>
#include <string>
#include "WinApi.h"

#include "Contenedor.h"

class C_Objeto {
protected:
	int	 ID			 = NULL;
	unsigned __int64 Elemento;	// Numero de elemento - distinto al ID
	HWND hWnd		 = nullptr;
	HWND *hWnd_Padre = nullptr;
	int	 x = 0, y = 0, ancho = 0, alto = 0;
	std::string	Texto;
	// Detalles del objeto
	std::string Tipo;
	DWORD Estilo;
	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	// Funcion para los objetos
	void Contener(C_Button& Button);
	void Contener(C_Label& Label);
	void Contener(C_GroupBox& GroupBox);
	void Contener(C_TextBox& GroupBox);
	void Contener(C_Menu& Menu, int Elementos);
	void Contener(C_MultiLine& MultiLine);
	void Contener(C_ListBox& ListBox);
	//lo llama el contenedor
	void Draw();
	// Funcion vacia para callback
	static void Function_Empty();
	// Funciones especiales
	HBRUSH ColorEdit(WPARAM& wParam);	//Color de fondo
	//Clase Amiga
	friend Contenedor;

public:
	void Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto);
	// Propiedades comunues	
	string	Get_Text();
	int		Get_Pos_X();
	int		Get_Pos_Y();
	// Metodos comunes		
	void Set_Text(string Text);
	void Set_Pos(int x, int y, int ancho, int alto);
};

