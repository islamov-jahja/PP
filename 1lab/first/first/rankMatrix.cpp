// first.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CMatrix.h"


int main(int argc, char *argv[])
{
	SYSTEMTIME st;

	if (argc != 3)
	{
		cout << "incorrect count of arguments. You need to enter name of File with Data for matrix and count of flows";
		return 1;
	}

	CMatrix matrix(argv[1]);
	GetLocalTime(&st);
	printf("%d-%02d-%02d %02d:%02d:%02d.%03d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	
	cout << "rank: " << matrix.GetRankOfMatrixConsistently() << endl;

	GetLocalTime(&st);
	printf("%d-%02d-%02d %02d:%02d:%02d.%03d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	
	system("pause");

    return 0;
}

