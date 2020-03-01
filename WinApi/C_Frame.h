#pragma once
#include "WinApi.h"

class C_Frame :public Win_Frame
{
protected:
	std::string		ClassN;
	std::string		Titulo;
	bool			Resize	= false;
	bool			Visible = false;
	int x = 0, y = 0, ancho = 0, alto = 0;
	static void Function_Empty();				// Funcion vacia
	void (*Funcion_Resize)() = &Function_Empty;	// Funcion de evento resize
	// Amigo
	//friend Contenedor;
public:
	HWND		hWnd = nullptr;
	HINSTANCE	hInstance = nullptr;
	void		Create(Win_Api* MFrame, string Titulo, int x, int y, int ancho, int alto, bool Resize = false);
	void		Draw();
	void		Show();
	//Propiedades (Metodos)	
	HWND&		Get_hWnd();
	int			Get_Height();
	int			Get_Width();
	bool		Get_Visible();
	// Asignar Eventos		
	void		Assign_Event_Resize(void(*Function)());
	// Eventos				
	void		Event_Resize(LPARAM lParam);

};

