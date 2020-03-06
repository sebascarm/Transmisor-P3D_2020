#pragma once
#include "C_Objeto.h"

class C_ListBox:public Win_ListBox, public C_Objeto {

public:
	void Create(Win_Frame* pFrame, int x, int y, int ancho, int alto);
	// Metodos			
	void Add_Line(string Texto);
};

