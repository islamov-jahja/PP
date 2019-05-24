#pragma once
class CMatrix
{
public:
	CMatrix(string nameOfFile, int countOfFlows);
	int GetRank();
	~CMatrix();
private:
	vector<double> GetDevidedSeniorLine(int seniorLine);
	void CMatrix::ChangeAndProcessLine(int column);
	void RowExchange(int i, int j);
	void ResetColumn(int column);
	static DWORD WINAPI CalculateProcessedLine(LPVOID lpParam);
	void ToProcessLineOfMatrix(int seniorLine, int processedString, vector<double> lineToSub);
	void CalculateCountOfFlows();
	void InicializateMatrix();
	mutex _mutex;
	vector<vector<double>> _Matrix;
	string _nameOfFile;
	int _countOfFlows;
	int _countOfLines;
	int _countOfColumns;
	int _indexOfProcessedLine;
	ifstream _inFile;
};

struct PointerWithColumn
{
	CMatrix* matrix;
	int seniorLine;
};

