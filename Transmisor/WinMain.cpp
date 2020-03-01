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


#include <Windows.h>	//Obligatorio para DLL

//#include "WinApi.h"
#include "Frame.h"

#ifdef _DEBUG
#pragma comment (lib, "WinApi_d.lib")
#else
#pragma comment (lib, "WinApi.lib")
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


int CALLBACK WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpszCmdParam,
	_In_ int nCmdShow)
{
	CrearObjetos(hInstance);
	Boton_AServidor->Assign_Event_Click(Click);
	Frame1->Assign_Event_Resize(Call_Resize);
	// Loop del programa
	WinApi->Loop();

}

