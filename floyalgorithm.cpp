// floyalgorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include"Eigen/Dense"
#include"floy.h"

using Eigen::MatrixXd;

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	MatrixXd m(MAX, MAX);

	floy("matrix.txt", m);
	cout << m << endl;
	return 0;
}

