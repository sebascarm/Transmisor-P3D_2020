//******************************************************************************************************************//
// CONFIGURACION APLICADA																							//
//******************************************************************************************************************//
// All Configuration // All Platform (La base es un Empty Proyect)													//
//																													//
// General	>	Dir Salida		> $(SolutionDir)Bin\																//
//			>	Dir Intermed	> $(SolutionDir)Tmp\																//
//			>	Nomb Destino	> $(ProjectName)		- (Release / 64 Bits)										//
//			>	Nomb Destino	> $(ProjectName)_d		- (Debug   / 64 Bits)										//
//			>	Nomb Destino	> $(ProjectName)_32		- (Release / 32 Bits)										//
//			>	Nomb Destino	> $(ProjectName)_32d	- (Debug   / 32 Bits)										//
//																													//
// Advanced >	Juego de caract	> Multibyte																			//
// C/C++	>	General			> Multi-Proc Compilation	> YES													//
//				Optimization	> Favor Size or Speed		> FAVOR FAST CODE										//
//				Preprocessor	> Prepr Definitions			> ....; NDEBUG(Solo en Release)							//
//				Code Generation > Runtime Library			> Multi - threaded(/ MT)  - Estatico(Solo en Release)	//
//								> Runtime Library			> DLL Multi - threaded(/ MTd) - Dinamico(Debug)	******	//
//								> Floating Point Model		> FAST													//
//			Languaje			> C++ Lang Standard			> LAST COMPILER											//
//																													//
// Linker	>	System			> SubSystem					> Windows												//
//******************************************************************************************************************//
// Plantilla con la configuración minima necesaria recomendada por chilli, se incuyen los directores de salida,		//
// especial para crear proyectos C++																				//
//******************************************************************************************************************//

//######################################################//
// TRANSMISOR V 2.0										//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 01/03/2020                                           //
// Creacion                                             //
//######################################################//


#include <Windows.h>	//Obligatorio para DLL

//#include "WinApi.h"
#include "Frame.h"
#include "P3D.h"
#include "Funciones.h"

#ifdef _DEBUG
#pragma comment (lib, "WinApi_d.lib")
#pragma comment (lib, "P3D_d.lib")
#pragma comment (lib, "Funciones_d.lib")
#else
#pragma comment (lib, "WinApi.lib")
#pragma comment (lib, "P3D.lib")
#pragma comment (lib, "Funciones.lib")
#endif



void Click() {
	OutputDebugString("EVENTO CLICK");
	for (int i = 0; i < 500; i++) {
		Text_Enviar->Set_Text(to_string(i));
		MultiLineGeneral->Add_Line("Texto: " + to_string(i));
		//Sleep(0.1);
	}
}

void Call_Resize() {
	//OutputDebugString("CALL FRAME RESIZE\n");
	int Alto = Frame1->Get_Height() - 220;
	int Ancho = Frame1->Get_Width() - 15;
	int Ancho1 = (int)(Ancho * 4 / 12);
	int Ancho2 = (int)(Ancho * 2.5 / 12);
	int Ancho3 = (int)(Ancho * 2.5 / 12);
	int Ancho4 = (int)(Ancho * 3 / 12);
	int X1 = 10;
	int X2 = X1 + Ancho1;
	int X3 = X2 + Ancho2;
	int X4 = X3 + Ancho3;
	MultiLineGeneral->Set_Pos(X1, 210, Ancho1, Alto);
	MultiLineSerie1->Set_Pos(X2, 210, Ancho2, Alto);
	MultiLineSerie2->Set_Pos(X3, 210, Ancho3, Alto);
	MultiLineSimu->Set_Pos(X4, 210, Ancho4, Alto);
}

P3D* Prep3d = New_P3D();

void Call_Conexion() {
	if (Prep3d->Connect()) {
		MultiLineGeneral->Add_Line("Conexion establecida");
	} else {
		MultiLineGeneral->Add_Line("Conexion no establecida");
	}


	
	

}

void Call_Desconexion() {
	Prep3d->Disconnect();
}

void Call_List() {
	//string text;
	//text = List->Get_Text();
	//OutputDebugString(text.c_str());
	OutputDebugString("\n");
}

int CALLBACK WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpszCmdParam,
	_In_ int nCmdShow)
{
	CrearObjetos(hInstance);
	Boton_AServidor->Assign_Event_Click(Click);
	Frame1->Assign_Event_Resize(Call_Resize);
	Boton_Sim_Conect->Assign_Event_Click(Call_Conexion);
	Boton_Serie_Desc->Assign_Event_Click(Call_Desconexion);
	
	ListBoardSimu->Set_Font("Courier new");
	ListSimuBoard->Set_Font("Courier new");

	
	WinApi->Draw();
	//List->Add_Line("hola1");
	// Loop del programa
	
	//List->Assign_Event_ChangeCell(Call_List);

	std::vector <EST_BOARD_SIMU> vBs;
	vBs = Prep3d->Get_Board_Simu();
	for (int i = 0; i < vBs.size(); i++) {
		string ID = to_string(vBs[i].ID);
		string Board = vBs[i].Board;
		string Simu = vBs[i].Simu;
		ListBoardSimu->Add_Line(ID + " - " + Board + " -> " + Simu);
	}

	std::vector <EST_SIMU_BOARD> vSb;
	vSb = Prep3d->Get_Simu_Board();
	for (int i = 0; i < vSb.size(); i++) {
		string Simu = vSb[i].Simu;
		string Board = vSb[i].Board;
		Funciones::RedimSTR(Simu, 30);
		ListSimuBoard->Add_Line(Simu + " -> " + Board);
	}

	
	WinApi->Loop();

}

