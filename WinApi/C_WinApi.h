#pragma once
#include "WinApi.h"
#include <vector>
#include "C_Frame.h"

class C_WinApi :public Win_Api
{
protected:
	WNDCLASSEX wc = { 0 };
	HINSTANCE hInstance;
	std::string NombreClase;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	// friends
	//friend C_Frame;

public:
	void Create(HINSTANCE hInstance);
	void Draw();
	int Loop();
	void Exit();
	// Metodos
	HINSTANCE Get_Instance();
	string GetClass();
};

