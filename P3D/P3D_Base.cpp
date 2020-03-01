#include "P3D_Base.h"


void P3D_Base::Connect() {
	if (SUCCEEDED(SimConnect_Open(&hSimConnect, "PMDG NGX Client", NULL, 0, 0, 0))) {
		Conexion_P3D();		//P3D
	}
}

//------------------------------------------------//
//--     CONEXION CON P3D (RECEPCION DE SIM)	  //
//------------------------------------------------//
void P3D_Base::Conexion_P3D() {
	
}