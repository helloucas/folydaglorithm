#ifndef FLOY_H
#define FLOY_H
#include<vector>
#include<Eigen\Dense>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<iostream>
using namespace std;
using Eigen::MatrixXd;


vector<int>split(string str, char delimiter)
{
	vector<int>temp;
	stringstream ss(str);                       // Turn the string into a stream.
	string  tok;
	while (getline(ss, tok, delimiter)) {
		int p = atoi(tok.c_str());           // c_str()一个将string转换为 const* char的函数。
		temp.push_back(p);
	}
	return temp;
}


void floy(string  filename, MatrixXd &m)
{
	ifstream  infile;
	infile.open(filename, ios::in);
	if (!infile)
	{
		cerr << "sorry , the file is not open or not exist" << endl;
		exit(1);
	}

	string  str;
	for (int i = 0; i < m.rows(); i++)
	{
		getline(infile, str);
		vector<int>temp = split(str, ',');
		for (int j = 0; j < m.cols(); j++)
		{
			m(i, j) = temp[j];
		}
	}
	//-------------------以上全部的代码只是对矩阵的读取到matrixxd对象当中--------------------//


	/*int i, j, k;
     for (k = 1; k <= n; k++)
		        for (i = 1; i <= n; i++)
		            for (j = 1; j <= n; j++)
	                if (dist[i][k] + dist[k][j]<dist[i][j])
		                   dist[i][j] = dist[i][k] + dist[k][j];
*/
	for (int k = 0; k< m.cols(); k++)
		for (int j = 0; j < m.cols(); j++)
			for (int i = 0; i < m.cols(); i++)
			{
				if (m(i, k) + m(k, j) < m(i, j))
					m(i, j) = m(i, k) + m(k, j);
			}
	/*for (int i = m.cols()-1; i >=0; i--)
		for (int j =m.cols()-1; j >=0; j--)
			for (int k = m.cols()-1; k >=0; k--)
			{
				if (m(i, k) + m(k, j) < m(i, j))
					m(i, j) = m(i, k) + m(k, j);
			}*/


}



#endif