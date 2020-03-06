#pragma once

#include "General.h"

#include <Windows.h>

class C_Frame;		/* Forward declaration de Child; */
class C_Button;		/* Forward declaration de Child; */
class C_Label;		/* Forward declaration de Child; */
class C_GroupBox;	/* Forward declaration de Child; */
class C_TextBox;	/* Forward declaration de Child; */
class C_Menu;		/* Forward declaration de Child; */
class C_MultiLine;  /* Forward declaration de Child; */
class C_ListBox;	/* Forward declaration de Child; */

class Contenedor {
private:
	void Agregar();

public:
	static int Elementos;
	int Element_ID;
	void New_Object(C_Frame& _Objeto);
	void New_Object(C_Button& _Objeto);
	void New_Object(C_Label& _Objeto);
	void New_Object(C_GroupBox& _Objeto);
	void New_Object(C_TextBox& _Objeto);
	void New_Object(C_Menu& _Objeto);
	void New_Object(C_MultiLine& _Objeto);
	void New_Object(C_ListBox& _Objeto);
	//envios
	void	Draw();		// Dibujo (para todos los elementos							
	void	Show();		// Show (para frame)										
	HWND	Get_hWnd(); //Get hWnd (para frame)
	int		Get_ID();	// Get ID de los elementos (solo botones por el momento)	
	
	HBRUSH ColorEdit(WPARAM wParam);	//Edicion de color (para label transparente) - devuelve el pincel modificado
	
	TipoObjeto		Tipo;
	//Punteros
	C_Frame*		pFrame;
	C_Button*		pButton;
	C_Label*		pLabel;
	C_GroupBox*		pGroupBox;
	C_TextBox*		pTextBox;
	C_Menu*			pMenu;
	C_MultiLine*	pMultiLine;
	C_ListBox*		pListBox;
	
};

