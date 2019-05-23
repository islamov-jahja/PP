#include "stdafx.h"
#include "CMatrix.h"

CMatrix::CMatrix(string nameOfFile):m_NameOfFile(nameOfFile)
{
}


void CMatrix::InicializateMatrixConsistently(string nameOfFileWithMatrix)
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

	fileWithDataForMatrix.close();
}


int CMatrix::GetRankOfMatrixConsistently()
{
	InicializateMatrixConsistently(m_NameOfFile);
	int rangOfMatrix = 0;

	for (size_t i = 0; i < m_countOfLines - 1; i++)
	{
		if (m_Matrix[i][i] != 0)
		{
			ResetColumn(i);
		}
		{
			ChangeAndProcessLine(i);
		}
	}

	for (size_t i = 0; i < m_countOfLines; i++)
	{
		if (m_Matrix[i][i] != 0)
			rangOfMatrix++;
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

void CMatrix::ChangeAndProcessLine(int column)
{
	for (int j = column + 1; j < m_countOfLines; j++)
	{
		if (m_Matrix[j][column] != 0)
		{
			RowExchange(column, j);
			ResetColumn(column);
		}
	}
}

void CMatrix::ResetColumn(int column)
{
	for (size_t i = column + 1; i < m_countOfLines; i++)
	{
		if (m_Matrix[i][column] == 0)
			continue;

		ToProcessLineOfMatrix(column, i);
	}
}

void CMatrix::ToProcessLineOfMatrix(int seniorLine, int processedString)
{
	int numberToDevide = m_Matrix[seniorLine][seniorLine];
	int numberToMultiplication = m_Matrix[processedString][seniorLine];

	for (size_t i = seniorLine; i < m_countOfColumns; i++)
	{
		m_Matrix[seniorLine][i] = m_Matrix[seniorLine][i] / numberToDevide;
		m_Matrix[seniorLine][i] = m_Matrix[seniorLine][i] * numberToMultiplication;
		m_Matrix[processedString][i] = m_Matrix[processedString][i] - m_Matrix[seniorLine][i];
	}
}

void CMatrix::RowExchange(int i, int j)
{
	int temp;

	for (int k = 0; k < m_countOfColumns; k++)
	{
		temp = m_Matrix[i][k];
		m_Matrix[i][k] = m_Matrix[j][k];
		m_Matrix[j][k] = temp;
	}
}

CMatrix::~CMatrix()
{
}
