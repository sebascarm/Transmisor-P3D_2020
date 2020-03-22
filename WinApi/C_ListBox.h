//######################################################//
// List Box v2.1										//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 21/03/2020                                           //
// Doble click											//
// SetFont												//
// Creacion                                             //
//######################################################//

#pragma once
#include "C_Objeto.h"

class C_ListBox:public Win_ListBox, public C_Objeto {
protected:
	void (*Function_ChangeCell)() = Function_Empty;
	void (*Function_DobleClick)() = Function_Empty;
public:
	void Create(Win_Frame* pFrame, int x, int y, int ancho, int alto);
	// Propiedades			
	int		Get_Pos_X() { return C_Objeto::Get_Pos_X(); }
	int		Get_Pos_Y() { return C_Objeto::Get_Pos_Y(); }
	int		Get_Row();
	string	Get_Text();
	// Metodos				
	void	Set_Font(string Fuente) {C_Objeto::Set_Font(Fuente);}
	void	Set_Pos(int x, int y, int ancho, int alto) { C_Objeto::Set_Pos(x, y, ancho, alto); }
	void	Set_Enable() { C_Objeto::Set_Enable(); }
	void	Set_Disable() { C_Objeto::Set_Disable(); }
	void	Add_Line(string Texto);
	// Asignar Eventos		
	void	Assign_Event_ChangeCell(void(*Function)());
	void	Assign_Event_DobleClick(void(*Function)());
	// Evento				
	void	Event_ChangeCell();
	void	Event_DobleClick();
};








//protected:
	//static void Function_Empty(int row, string text);
	//void (*Function_ChangeCell)(int row, string text) = Function_Empty; // A un puntero de funcion solo se puede asignar una funcion estatica
//public:
	//void	Assign_Event_ChangeCell(void(*Function)(int row, string text));
