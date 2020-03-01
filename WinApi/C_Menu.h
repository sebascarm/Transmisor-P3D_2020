#pragma once
#include "C_Objeto.h"

struct Funcion_Puntero {
	void(*Funcion)();
};

class C_Menu : public Win_Menu, public C_Objeto {
protected:
	std::vector<Funcion_Puntero> vFunction_Click;
	// Variables propias
	int Elementos;
	int ID_Funcion;			// Para llamar a la funcion adecuada
	std::vector <std::string> MenuText;
	HMENU hMenubar	= nullptr;
	HMENU hMenu		= nullptr;
	//lo llama el contenedor (Tiene un Draw Propio)
	void Draw();
	//Clase Amiga (porque Draw es independiente)
	friend Contenedor;
public:
	void Create(Win_Frame* pFrame, std::string Titulo, std::vector <std::string> MenuText);
	std::vector <int> V_ID;	//Vector de IDs que posee (
	// Asignar Eventos				
	void Assign_Event_Click(void(*Function)(), int Menu_Item);
	// Evento (lo llama el loop)	
	void Event_Click(WPARAM wParam);
};

