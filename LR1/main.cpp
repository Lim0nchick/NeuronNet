#include <iostream>
#include <cmath> 

using namespace std;

bool Check(int *T, int* Y)	// Функция проверки необходимости завершения обучения
{
	for (auto i=0; i<16; i++)
	{
		if ((T[i]-Y[i])!=0)
			return false;
	}
	return true;
}

int main()
{
	int  E=8; 	// Ошибка
	double n=0.3; 	// Норма обучения 
	double* W = new double[5]; 	// Массив, хранящий весовые коэффициенты
	for (auto i=0; i<5; i++)
		W[i]=0;
	int X[16][5] = 	// Матрица, хранящая значения входных наборов
	{	 
		{ 1, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 0, 1, 0 },
		{ 1, 0, 0, 1, 1 },
		{ 1, 0, 1, 0, 0 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 0 },
		{ 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0 },
		{ 1, 1, 0, 0, 1 },
		{ 1, 1, 0, 1, 0 },
		{ 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 0 },
		{ 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1 },
	};
	
	int* Y = new int[16]; 	// Массив, хранящий выходной вектор значений (реальный выход НС)
	for (auto i=0; i<16; i++)
		Y[i]=1;
	double net=0; 	// Сетевой (комбинированный) вход
	int k=0;	// Счетчик эпох
	bool exit = false; 	// Флаг завершения обучения

	int d = 0; 	// Дельта-ошибка
	int T[16] = {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1}; 	// Массив, храняший целевой выход
	do
	{
		k++;
		cout << "Age " << k << endl; 
		for (auto i=0; i<16; i++)
		{
			for (auto j=0; j<5; j++)
				net += W[j]*X[i][j];
			if  (net>=0) Y[i]=1;
			else Y[i]=0;
			cout << "Y[" << i << "] = " << Y[i] << "  ";
		}
		cout << endl << endl;
		exit = Check(T, Y);
		if (exit==false)
		{
			for (auto l=0; l<16; l++)
			{
				d = T[l]-Y[l];
				E += abs(d);
				double dw=0; 	// коррекция веса на l-м шаге
				//double tanh = (exp(2*net)-1)/(exp(2*net)+1); 
				
				for (auto j=0; j<5; j++)
				{
					dw = n*d*/*(1-2*tanh*tanh)**/X[l][j];
					W[j]+=dw;
				}
			}
			cout << "Weights: ";
			for (auto j=0; j<5; j++)
				cout << W[j] << "\t";
		}
		else 
			cout << "mission completed" << endl;
		getchar();
	} while(exit == false);
	return 0;
}