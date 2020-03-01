#include "C_Frame.h"
#include <vector>
#include "Contenedor.h"

extern std::vector <Contenedor> CONTENEDOR;

void C_Frame::Create(Win_Api* MFrame, string Titulo, int x, int y, int ancho, int alto, bool Resize) {
	this->hInstance = MFrame->Get_Instance();
	this->ClassN = MFrame->GetClass();
	this->Resize = Resize;
	this->Titulo = Titulo;
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	//Contenedor
	unsigned __int64 Elemento = CONTENEDOR.size();
	CONTENEDOR.resize(Elemento + 1);
	CONTENEDOR[Elemento].New_Object(*this);
	//ID  = CONTENEDOR[Elemento].Element_ID;
	
}

void C_Frame::Draw() {
	DWORD Estilo = WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;
	if (Resize) {
		Estilo = WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SIZEBOX | WS_SYSMENU;
	}
	hWnd = CreateWindowEx(
		0,
		(LPSTR)ClassN.c_str(),
		(LPSTR)Titulo.c_str(),
		Estilo,
		x, y,
		ancho + 16, alto + 59, //tamaños q roba la aplicacion
		nullptr,
		nullptr,
		hInstance,
		nullptr);
}

void C_Frame::Show() {
	ShowWindow(hWnd, SW_SHOW);
	this->Visible = true;
}

//METODOS
HWND& C_Frame::Get_hWnd() {
	return hWnd;
}
int C_Frame::Get_Height() {
	return alto;
}
int C_Frame::Get_Width() {
	return ancho;
}
bool C_Frame::Get_Visible() {
	return Visible;
}

//*********************************************
//*** ASIGNACION DE EVENTO					***
//*********************************************
void C_Frame::Assign_Event_Resize(void(*Function)()) {
	Funcion_Resize = Function;
}

//*********************************************
//*** EVENTO RESIZE (lo llama el loop)		***
//*********************************************
void C_Frame::Event_Resize(LPARAM lParam) {
	//Cambiamos las variables de tamaño
	this->ancho = LOWORD(lParam);
	this->alto = HIWORD(lParam);
	this->Funcion_Resize();
}

//*********************************************
//*** EVENTO VACIO							***
//*********************************************
void C_Frame::Function_Empty() {
	OutputDebugString("EVENT RESIZE NOT DEFINED\n");
}


//*********************************************
//*** Export								***
//*********************************************
Win_Frame* New_Frame() {
	return new C_Frame();
};
