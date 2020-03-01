#pragma once

#include "P3D.h"
#include "SimConnect.h"

class P3D_Base :public P3D {
protected:
	HANDLE  hSimConnect = NULL;	// handle de simconnect
	// Conexiones
	void Conexion_P3D();
public:
	void Connect();
	void Disconnect();
};

