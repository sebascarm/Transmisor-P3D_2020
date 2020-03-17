#include "C_RichText.h"

//#include <windows.h>
//#include <commctrl.h>

void C_RichText::Create(Win_Frame* pFrame, std::string Text, int x, int y, int ancho, int alto) {
	//Cargar libreria especial
	LoadLibrary(TEXT("Riched32.dll"));   
	// Crear y contener
	C_Objeto::Create(pFrame, Text, x, y, ancho, alto);
	C_Objeto::Contener(*this);
	//Detalles del objeto
	Tipo = "RICHEDIT";
	Estilo = WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_MULTILINE | ES_WANTRETURN | WS_VSCROLL | ES_DISABLENOSCROLL;
    // Especificaciones de fuente
    Formato.cbSize = sizeof(Formato);
    Formato.dwMask = CFM_COLOR;        // change color
    Formato.dwEffects = 0;             // add this line
}

CHARFORMAT C_RichText::Get_Format() {
    DWORD range = SCF_DEFAULT;
    CHARFORMAT Formato;
    SendMessage(this->hWnd, EM_GETCHARFORMAT, range, (LPARAM)&Formato);
    return Formato;
}
void C_RichText::Set_Format(const CHARFORMAT& Formato) {
    DWORD range = SCF_SELECTION;
    SendMessage(this->hWnd, EM_SETCHARFORMAT, range, (LPARAM)&Formato);
}

void C_RichText::Cursor_Bottom() {
    SendMessage(this->hWnd , EM_SETSEL, -2, -1);
}

void C_RichText::Scroll(DWORD pos) {
    SendMessage(this->hWnd, WM_VSCROLL, pos, 0);
}
void C_RichText::Scroll_Bottom() {
    Scroll(SB_BOTTOM);
}

void C_RichText::Replace_Sel(const char* str) {
    SendMessage(this->hWnd, EM_REPLACESEL, 0, (LPARAM)str);
}


void C_RichText::ChangeColor(COLORREF Color) {
    Cursor_Bottom();                // move cursor to bottom
    Formato.crTextColor = Color;    // Color                
    Set_Format(Formato);            // set default char format
    //Scroll_Bottom();              // scroll to bottom
}

void C_RichText::TextLine(string Texto) {
    Texto = Texto + "\r\n";
    Replace_Sel(Texto.c_str());
    Scroll_Bottom();
}

void C_RichText::ColorText(string Texto, COLORREF Color) {
    Cursor_Bottom();
    Formato.crTextColor = Color;
    Set_Format(Formato);
    Replace_Sel(Texto.c_str());            
    //Scroll_Bottom();
}
void C_RichText::ColorTextEnd(string Texto, COLORREF Color) {
    Cursor_Bottom();
    Formato.crTextColor = Color;
    Set_Format(Formato);
    Texto = Texto + "\r\n";
    Replace_Sel(Texto.c_str());
    Scroll_Bottom();
}

