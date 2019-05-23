#pragma once

const int MAX_THREADS = 4;

class CMatrix
{
public:
	CMatrix(string nameOfFile);
	int GetRankOfMatrixConsistently();
	void ShowMatrix();
	~CMatrix();
private:
	int m_CountOfThreads;
	void ResetColumn(int column);
	void ToProcessLineOfMatrix(int seniorLine, int processedString);
	void RowExchange(int i, int j);
	void ChangeAndProcessLine(int column);
	void InicializateMatrixConsistently(string nameOfFileWithMatrix);
	string m_NameOfFile;
	vector<vector<double>> m_Matrix;
	int m_countOfColumns;
	int m_countOfLines;
};

