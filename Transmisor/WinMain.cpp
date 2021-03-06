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
// TRANSMISOR V 2.2										//
//######################################################//
// ULTIMA MODIFICACION DOCUMENTADA                      //
// 17/03/2020                                           //
// Usando Rich Text										//
// Eventos por separado                                 //
// Creacion                                             //
//######################################################//


#include <Windows.h>	//Obligatorio para DLL

//#include "WinApi.h"
#include "Frame.h"
#include "P3D.h"
#include "Socket.h"
#include "Funciones.h"
#include "Eventos.h"


#ifdef _DEBUG
#pragma comment (lib, "WinApi_d.lib")
#pragma comment (lib, "P3D_d.lib")
#pragma comment (lib, "Funciones_d.lib")
#pragma comment (lib, "Socket_d.lib")
#else
#pragma comment (lib, "WinApi.lib")
#pragma comment (lib, "P3D.lib")
#pragma comment (lib, "Funciones.lib")
#pragma comment (lib, "Socket.lib")
#endif


P3D* Prep3d = New_P3D();
Socket* Sock = New_Socket();

int CALLBACK WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpszCmdParam,
	_In_ int nCmdShow)
{
	
	int a = Sock->Get_State();

	CrearObjetos(hInstance);
	WinApi->Draw();
	
	Configurar_objetos();
	Eventos();


	WinApi->Loop();

}

