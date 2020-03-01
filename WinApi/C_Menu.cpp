#include "C_Menu.h"
#include <thread>			//Para hilos (multiproceso)

extern std::vector <Contenedor> CONTENEDOR;

void C_Menu::Create(Win_Frame* pFrame, std::string Titulo, std::vector <std::string> MenuText) {
	// Variables propias
	Elementos = (int)MenuText.size();
	//Puntero a vector de funciones
	vFunction_Click.resize(Elementos);
	// Crear y contener
	C_Objeto::Create(pFrame, Titulo, 0, 0, 0, 0);
	C_Objeto::Contener(*this, Elementos);
	// Agregamos los ID al vector de ID
	for (int i = 0; i < Elementos; i++) {
		V_ID.push_back(ID + i);	//Asignamos el vector ID
	}
	CONTENEDOR[Elemento].Elementos = ID + Elementos - 1;	//Ampliamos el proximo ID del contenedor
	// Elementos
	this->MenuText = MenuText;
	this->Elementos = (int)MenuText.size();
	//Crea menu
	hMenubar = CreateMenu();
	hMenu = CreateMenu();
}

void C_Menu::Draw() {
	//Requiere que este el padre creado
	for (int i = 0; i < Elementos; i++) {
		if (MenuText[i] == "-") {
			//Separador
			AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
		} else {
			//Menu
			AppendMenu(hMenu, MF_STRING, (__int64)ID + i, (LPCSTR)MenuText[i].c_str());
		}
	}
	// Crea La barra general
	AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenu, (LPCSTR)this->Texto.c_str());
	SetMenu(*hWnd_Padre, hMenubar);
}

//*********************************************
//*** ASIGNACION DE EVENTO					***
//*********************************************
void C_Menu::Assign_Event_Click(void(*Function)(), int Menu_Item) {
	if (vFunction_Click.size() > Menu_Item)
		vFunction_Click.at(Menu_Item).Funcion = { Function };
}

//*********************************************
//*** EVENTO CLICK (El loop debe llamarlo)	***
//*** No se activa solo						***
//*********************************************
void C_Menu::Event_Click(WPARAM wParam) {
	int ID_Rec = LOWORD(wParam);
	ID_Funcion = ID_Rec - ID;
	if (vFunction_Click[ID_Funcion].Funcion) {
		std::thread Th_Click([this] {vFunction_Click[ID_Funcion].Funcion(); });
		Th_Click.detach();
	}
}