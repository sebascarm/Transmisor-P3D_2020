#pragma once
#include "C_Objeto.h"

#include <richedit.h>

class C_RichText :public Win_RichText, public C_Objeto {
private:
	void Cursor_Bottom();
	CHARFORMAT Get_Format();
	void Set_Format(const CHARFORMAT& cf);
	void Replace_Sel(const char* str);
	void Scroll(DWORD pos);
	void Scroll_Bottom();
	//
	CHARFORMAT Formato;
public:
	void Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto);
	// Propiedades comunes	
	int	Get_Pos_X() { return C_Objeto::Get_Pos_X(); }
	int	Get_Pos_Y() { return C_Objeto::Get_Pos_Y(); }
	// Metodos comunes		
	void Set_Font(string Fuente) { C_Objeto::Set_Font(Fuente); }
	void Set_Pos(int x, int y, int ancho, int alto) { C_Objeto::Set_Pos(x, y, ancho, alto); }
	void Set_Enable() { C_Objeto::Set_Enable(); }
	void Set_Disable() { C_Objeto::Set_Disable(); }
	// Metodos propios		
	void ChangeColor(COLORREF Color);
	void TextLine(string Texto);
	void ColorText(string Texto, COLORREF Color);
	void ColorTextEnd(string Texto, COLORREF Color);
};
