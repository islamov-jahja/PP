#pragma once

class CMatrix
{
public:
	CMatrix();
	void InicializateMatrix(string nameOfFileWithMatrix);
	int GetRankOfMatrix();
	void ShowMatrix();
	~CMatrix();
private:
	vector<vector<double>> m_Matrix;
	int m_countOfColumns;
	int m_countOfLines;
};

