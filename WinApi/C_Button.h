#pragma once
#include "C_Objeto.h"

class C_Button :public Win_Button, public C_Objeto{
protected:
	void	(*Funcion_Click)() = &Function_Empty;
public:
	void Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto);
	// Propiedades			
	string	Get_Text() { return C_Objeto::Get_Text();}
	int		Get_Pos_X() { return C_Objeto::Get_Pos_X(); }
	int		Get_Pos_Y() { return C_Objeto::Get_Pos_Y(); }
	// Metodos				
	void	Set_Text(string Text) {C_Objeto::Set_Text(Text);}
	void	Set_Pos(int x, int y, int ancho, int alto) { C_Objeto::Set_Pos(x, y, ancho, alto); }
	void	Set_Enable() { C_Objeto::Set_Enable(); }
	void	Set_Disable() { C_Objeto::Set_Disable(); }
	// Asignar Eventos		
	void	Assign_Event_Click(void(*Function)());
	// Evento				
	void	Event_Click();
	
};

