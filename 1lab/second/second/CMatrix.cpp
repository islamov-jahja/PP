#include "stdafx.h"
#include "CMatrix.h"


CMatrix::CMatrix(string nameOfFile, int countOfFlows) :_nameOfFile(nameOfFile), _countOfFlows(countOfFlows)
{
	InicializateMatrix();
	CalculateCountOfFlows();
}


CMatrix::~CMatrix()
{
}

int CMatrix::GetRank()
{
	int rank = 0;
	HANDLE hThread = new HANDLE[_countOfFlows] ;

	for (size_t i = 0; i < _countOfLines - 1; i++)
	{
		if (_Matrix[i][i] != 0)
		{
			ResetColumn(i);
		}
		{
			ChangeAndProcessLine(i);
		}
	}

	for (size_t i = 0; i < _countOfLines; i++)
	{
		if (_Matrix[i][i] != 0)
			rank++;
	}

	return rank;
}

vector<double> CMatrix::GetDevidedSeniorLine(int seniorLine)
{
	int numberToDevide = _Matrix[seniorLine][seniorLine];
	int numberToMultiplication = _Matrix[_indexOfProcessedLine][seniorLine];
	for (size_t i = seniorLine; i < _countOfColumns; i++)
	{
		_Matrix[seniorLine][i] = _Matrix[seniorLine][i] / numberToDevide;
		_Matrix[seniorLine][i] = _Matrix[seniorLine][i] * numberToMultiplication;
	}
	return _Matrix[seniorLine];
}

void CMatrix::ChangeAndProcessLine(int column)
{
	for (int j = column + 1; j < _countOfLines; j++)
	{
		if (_Matrix[j][column] != 0)
		{
			RowExchange(column, j);
			ResetColumn(column);
		}
	}
}

void CMatrix::RowExchange(int i, int j)
{
	int temp;

	for (int k = 0; k < _countOfColumns; k++)
	{
		temp = _Matrix[i][k];
		_Matrix[i][k] = _Matrix[j][k];
		_Matrix[j][k] = temp;
	}
}

void CMatrix::ResetColumn(int column)
{
	HANDLE* hThreads = new HANDLE[_countOfFlows];
	PointerWithColumn pwc;
	pwc.matrix = this;
	pwc.seniorLine = column;
	_indexOfProcessedLine = column + 1;
	if (_indexOfProcessedLine == _Matrix.size())
		return;

	for (int i = 0; i < _countOfFlows; i++)
	{	
		hThreads[i] = CreateThread(NULL, 2048, &CalculateProcessedLine, (PVOID)&pwc, 0, NULL);
	}

	WaitForMultipleObjects(_countOfFlows, hThreads, true, INFINITE);
}

DWORD WINAPI CMatrix::CalculateProcessedLine(LPVOID lpParam)
{
	PointerWithColumn* pwc = (PointerWithColumn*)lpParam;
	CMatrix* matrix = pwc->matrix;
	vector<double> seniorLineArray;
	int seniorLine = pwc->seniorLine;

	while (matrix->_indexOfProcessedLine != matrix->_Matrix.size())
	{
		matrix->_mutex.lock();
		if (matrix->_indexOfProcessedLine == matrix->_Matrix.size()) {
			matrix->_mutex.unlock();
			break;
		}

		int indexOfProcessedLine = matrix->_indexOfProcessedLine;

		if (matrix->_Matrix[indexOfProcessedLine][seniorLine] == 0)
		{
			matrix->_indexOfProcessedLine++;
			matrix->_mutex.unlock();
			continue;
		}

		seniorLineArray = matrix->GetDevidedSeniorLine(seniorLine);
		matrix->_indexOfProcessedLine++;
		matrix->_mutex.unlock();
		matrix->ToProcessLineOfMatrix(seniorLine, indexOfProcessedLine, seniorLineArray);
	}

	ExitThread(0);
}

void CMatrix::ToProcessLineOfMatrix(int seniorLine, int processedString, vector<double> lineToSub)
{
	for (size_t i = seniorLine; i < _countOfColumns; i++)
	{
		_Matrix[processedString][i] = _Matrix[processedString][i] - lineToSub[i];
	}
}

void CMatrix::CalculateCountOfFlows()
{
	if (_countOfFlows < 1 || _countOfFlows > 16)
		_countOfFlows = DEFAULT_COUNT;
}

void CMatrix::InicializateMatrix()
{
	_inFile.open(_nameOfFile);

	if (!_inFile.is_open())
		throw runtime_error("file not found");

	_inFile >> _countOfLines;
	_inFile >> _countOfColumns;

	vector<vector<double>> matrix(_countOfLines, vector<double>(_countOfColumns, 0));

	_Matrix = matrix;

	for (size_t i = 0; i < _countOfLines; i++) {
		for (size_t j = 0; j < _countOfColumns; j++) {
			_inFile >> _Matrix[i][j];
		}
	}

	_inFile.close();
}
