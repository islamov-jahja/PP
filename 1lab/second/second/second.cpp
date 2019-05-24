// second.cpp: определяет точку входа для консольного приложения.
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

	cout << argv[1] << ' ' << argv[2] << endl;

	CMatrix matrix(argv[1], atoi(argv[2]));
	GetLocalTime(&st);
	printf("%d-%02d-%02d %02d:%02d:%02d.%03d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	cout << endl << "rank: " << matrix.GetRank() << endl;
	
	GetLocalTime(&st);
	printf("%d-%02d-%02d %02d:%02d:%02d.%03d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	system("pause");

    return 0;
}