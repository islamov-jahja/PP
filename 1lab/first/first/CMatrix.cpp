#include "stdafx.h"
#include "CMatrix.h"


CMatrix::CMatrix()
{

}

void CMatrix::InicializateMatrix(string nameOfFileWithMatrix)
{
	ifstream fileWithDataForMatrix(nameOfFileWithMatrix);
	if (!fileWithDataForMatrix.is_open())
		throw runtime_error("file not found");

	fileWithDataForMatrix >> m_countOfLines;
	fileWithDataForMatrix >> m_countOfColumns;

	vector<vector<double>> matrix(m_countOfLines, vector<double>(m_countOfColumns, 0));

	m_Matrix = matrix;

	for (size_t i = 0; i < m_countOfLines; i++) {
		for (size_t j = 0; j < m_countOfColumns; j++) {
			fileWithDataForMatrix >> m_Matrix[i][j];
		}
	}
}

int CMatrix::GetRankOfMatrix()
{
	int rangOfMatrix = 0;

	for (size_t i = 0; i < m_countOfLines; i++)
	{
		if (m_Matrix[i][i] != 0)
		{
			//каждый раз делим данную строку на высший разряд и умножаем на нижние разряды, после чего из остальных строк вычитаем его. func s(); 
		}
		{
			//делаем поиск строки, в котором этот разряд не равен нулю и меняем эти строки местами;
			//выполняем func s();
		}
	}

	return rangOfMatrix;
}

void CMatrix::ShowMatrix()
{
	for (size_t i = 0; i < m_countOfLines; i++)
	{
		for (size_t j = 0; j < m_countOfColumns; j++)
		{
			cout << m_Matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

CMatrix::~CMatrix()
{
}
