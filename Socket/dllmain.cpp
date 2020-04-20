
//******************************************************************************************************************//
// CONFIGURACION APLICADA V1.2																    					//
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
//				Preprocessor	> Prepr Definitions			> BUILDING_DLL;....; - MAS					            //
//				Preprocessor	> Prepr Definitions			> ....; NDEBUG(Solo en Release)	- MAS					//
//				Code Generation > Runtime Library			> DLL Multi - threaded(/ MD)  - Dinamic(Solo en Release)//
//								> Runtime Library			> DLL Multi - threaded(/ MDd) - Dinamic(Solo en Debug)  //
//								> Floating Point Model		> FAST													//
//			Languaje			> C++ Lang Standard			> LAST COMPILER											//
//																													//
// Linker	>	System			> SubSystem					> Windows												//
// 												                                                                    //
// Agregar Manualmente 	                    										                                //
// 												                                                                    //
// C/C++	  >	Encabezado Precomp  > Encab Precomp	        > No Utilizar	                	                    //
// 												                                                                    //
// Agregar Manualmente (Al agregar una libreria de uso)	                    										//
// 												                                                                    //
// Vinculador >	General			    > Dire Bibl Adicional   > $(SolutionDir)Bin\                                    //
// C/C++	  >	General			    > Directorio Adicional	> ..\(Directorio de Libreria)\		                    //
// En codigo:                                                                                                       //
// pragmas comments (lib, "Funciones_d.lib")  - Ejemplo                                                               //
//******************************************************************************************************************//
// Plantilla con la configuración minima necesaria recomendada por chilli, se incuyen los directores de salida,		//
// especial para crear proyectos C++																				//
//******************************************************************************************************************//

// usrdll
// encabezado precomp
// archivo manifesto

//------------------------------------------------//
//--     MAIN GENERAL (xxxxx)					  //
//------------------------------------------------//

#include <Windows.h>	//Obligatorio para DLL
//#include "Socket.h"     // Llamada al encabezado principal

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

