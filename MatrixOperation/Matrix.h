/*
 * Matrix.h
 *
 *  Created on: 2021年11月1日
 *      Author: windows
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include<string.h>

struct Size{
	int m;
	int n;
};

template<class DataType=float>
class Matrix{
	DataType *data;
	int M,N;
	int lda;
	//lapack.h,lapacke.h功能似乎更多一些，有一些更高级的运算
	//lda要不要加呢？
	//enum row major怎么写？
	//复数如何实现，有第三方库支持吗？

public:
	//初始化函数
	Matrix(int m,int n):M(m),N(n),lda(M){
		data=new DataType[M*N];
	}
	//默认数组为行模式
	Matrix(int m,int n, DataType *pArray){
		lda=M=m;
		N=n;
		data=new DataType[M*N];
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				data[i*lda+j]=pArray[j*M+i];
	}
	Matrix(int m,int n, DataType **pArray){
		lda=M=m;
		N=n;
		data=new DataType[M*N];
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				data[i*lda+j]=pArray[i][j];
	}
	Matrix(const Matrix<DataType>& A){
		lda=M=A.M;
		N=A.N;
		data=new DataType[M*N];
		memcpy(data,A.data,sizeof(DataType)*M*N);
	}
	//矩阵信息
	struct Size size(){
		return {M,N};
	}
	int
	//矩阵运算
	DataType operator()(int i,int j){
		//异常处理i，j要在合适范围
		return data[i*lda+j];
	}
	friend Matrix<DataType> operator+(const Matrix<DataType>& A,const Matrix<DataType>& B){
		//异常处理，二者要
	}

};







#endif /* MATRIX_H_ */
