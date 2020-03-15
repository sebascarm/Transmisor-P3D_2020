//######################################################//
// MultiLine v1.1										//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 15/03/2020                                           //
// Correcion en resize									//
// Creacion                                             //
//######################################################//

#pragma once
#include "C_Objeto.h"
#include <queue> 

class C_MultiLine :public Win_MultiLine, public C_Objeto  {
protected:
	// Para proceso interno	
	queue<string> Cola_Texto;
	void Th_Add_Line();
public:
	void	Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto);
	// Propiedades			
	int		Get_Pos_X() { return C_Objeto::Get_Pos_X(); }
	int		Get_Pos_Y() { return C_Objeto::Get_Pos_Y(); }
	// Metodos
	void	Set_Pos(int x, int y, int ancho, int alto) { C_Objeto::Set_Pos(x, y, ancho, alto); }
	void	Set_Enable() { C_Objeto::Set_Enable(); }
	void	Set_Disable() { C_Objeto::Set_Disable(); }
	void	Add_Line(string Texto);
};

