// first.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CMatrix.h"


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "incorrect count of arguments. You need to enter name of File with Data for matrix";
		return 1;
	}

	CMatrix matrix;
	matrix.InicializateMatrix(argv[1]);
	matrix.ShowMatrix();

	system("pause");

    return 0;
}

