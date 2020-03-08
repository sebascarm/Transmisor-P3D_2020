//######################################################//
// WIN API v2.1											//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 08/03/2020                                           //
// ListBox v2.0											//
// Creacion                                             //
//######################################################//

#pragma once

#ifdef BUILDING_DLL
#define DLLIMPORT __declspec(dllexport) 
#else
#define DLLIMPORT __declspec(dllimport) 
#endif


#include "Windows.h"
#include <string>
#include "General.h"
#include <vector> // Para los menus

using namespace std;

//GENERAL
class Win_Api {
public:
	virtual void Create(HINSTANCE h_Instancia) = 0;
	virtual void Draw() = 0;
	virtual int  Loop()  = 0;
	virtual void Exit()  = 0;
	// Metodos
	virtual HINSTANCE Get_Instance() = 0;
	virtual string    GetClass()     = 0;
};

//FRAME			
class Win_Frame {
public:
	virtual void Create(Win_Api* MFrame, string Titulo, int x, int y, int ancho, int alto, bool Resize = false) = 0;
	//Metodos (propiedades)
	virtual HWND& Get_hWnd()	= 0;
	virtual int   Get_Height()	= 0;
	virtual int   Get_Width()	= 0;
	virtual bool  Get_Visible() = 0;
	// Asignacion de eventos
	virtual void Assign_Event_Resize(void(*Function)()) = 0;
};
//BUTTON			
class Win_Button {
public:
	virtual void	Create(Win_Frame* _Frame, string Text, int x, int y, int ancho = 60, int alto = 20) = 0;
	virtual string	Get_Text()  = 0;
	virtual int		Get_Pos_X() = 0;
	virtual int		Get_Pos_Y() = 0;
	virtual void	Set_Text(string Text) = 0;
	virtual void	Set_Pos(int x = -1, int y = -1, int ancho = -1, int alto = -1) = 0; //El -1 mantiene el tamaño actual
	// Asignacion de eventos
	virtual void	Assign_Event_Click(void(*Function)()) = 0;
};
// LABEL			
class Win_Label {
public:
	virtual void Create(Win_Frame* _Frame, string Text, int x, int y, int ancho = 60, int alto = 20, W_Align Align = W_Align::A_IZQ) = 0;
	virtual string	Get_Text()  = 0;
	virtual int		Get_Pos_X() = 0;
	virtual int		Get_Pos_Y() = 0;
	virtual void	Set_Text(string Text) = 0;
	virtual void	Set_Pos(int x = -1, int y = -1, int ancho = -1, int alto = -1) = 0;
};
// GROUPBOX			
class Win_GroupBox {
public:
	virtual void Create(Win_Frame* _Frame, string Text, int x, int y, int ancho = 100, int alto = 100) = 0;
	virtual string	Get_Text()  = 0;
	virtual int		Get_Pos_X() = 0;
	virtual int		Get_Pos_Y() = 0;
	virtual void	Set_Text(string Text) = 0;
	virtual void	Set_Pos(int x = -1, int y = -1, int ancho = -1, int alto = -1) = 0;
};
// TEXTBOX			
class Win_TextBox {
public:
	virtual void	Create(Win_Frame* _Frame, string Text, int x, int y, int ancho = 60, int alto = 20) = 0;
	virtual string	Get_Text()  = 0;
	virtual int		Get_Pos_X() = 0;
	virtual int		Get_Pos_Y() = 0;
	virtual void	Set_Text(string Text) = 0;
	virtual void	Set_Pos(int x = -1, int y = -1, int ancho = -1, int alto = -1) = 0;
};
// MENU				
class Win_Menu {
public:
	virtual void Create(Win_Frame* _Frame, string Titulo, std::vector <std::string> MenuText) = 0;
	// Asignacion de eventos
	virtual void Assign_Event_Click(void(*Function)(), int Menu_Item) = 0;
};
// MULTILINE		
class Win_MultiLine {
public:
	virtual void	Create(Win_Frame* _Frame, string Text, int x, int y, int ancho = 100, int alto = 100) = 0;
	virtual int		Get_Pos_X() = 0;
	virtual int		Get_Pos_Y() = 0;
	virtual void	Set_Pos(int x = -1, int y = -1, int ancho = -1, int alto = -1) = 0;
	virtual void	Add_Line(string Texto) = 0;
};
// MESSAGE BOX		
class Win_MessageBox {
public:
	virtual int Create(string Titulo, string Message, M_Message Tipo = M_Message::M_OK) = 0;
};
// LIST BOX			
class Win_ListBox {
public:
	virtual void	Create(Win_Frame* _Frame, int x, int y, int ancho = 60, int alto = 20) = 0;
	virtual string	Get_Text() = 0;
	virtual int		Get_Pos_X() = 0;
	virtual int		Get_Pos_Y() = 0;
	virtual int		Get_Row()	= 0;
	virtual void	Set_Font(string Fuente) = 0;
	virtual void	Set_Pos(int x = -1, int y = -1, int ancho = -1, int alto = -1) = 0;
	virtual void	Add_Line(string Texto) = 0;
	// Asignacion de evento				
	virtual void	Assign_Event_ChangeCell(void(*Function)()) = 0;
};

extern DLLIMPORT Win_Api* New_Api();
extern DLLIMPORT Win_Frame* New_Frame();
extern DLLIMPORT Win_Button* New_Button();
extern DLLIMPORT Win_Label* New_Label();
extern DLLIMPORT Win_GroupBox* New_GroupBox();
extern DLLIMPORT Win_TextBox* New_TextBox();
extern DLLIMPORT Win_Menu* New_Menu();
extern DLLIMPORT Win_MultiLine* New_MultiLine();
extern DLLIMPORT Win_MessageBox* New_MessageBox();
extern DLLIMPORT Win_ListBox* New_ListBox();