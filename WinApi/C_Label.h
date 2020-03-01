#pragma once
#include "C_Objeto.h"


class C_Label :public Win_Label, public C_Objeto {
protected:
	//Valores propios	
	W_Align Align = W_Align::A_IZQ;
public:
	void Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto, W_Align Align);
	// Propiedades		
	string	Get_Text() { return C_Objeto::Get_Text(); }
	int		Get_Pos_X() { return C_Objeto::Get_Pos_X(); }
	int		Get_Pos_Y() { return C_Objeto::Get_Pos_Y(); }
	// Metodos			
	void	Set_Text(string Text) { C_Objeto::Set_Text(Text); }
	void	Set_Pos(int x, int y, int ancho, int alto) { C_Objeto::Set_Pos(x, y, ancho, alto); }

};

