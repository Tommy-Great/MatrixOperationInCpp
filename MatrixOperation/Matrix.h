/*
 * Matrix.h
 *
 *  Created on: 2021��11��1��
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
	//lapack.h,lapacke.h�����ƺ�����һЩ����һЩ���߼�������
	//ldaҪ��Ҫ���أ�
	//enum row major��ôд��
	//�������ʵ�֣��е�������֧����

public:
	//��ʼ������
	Matrix(int m,int n):M(m),N(n),lda(M){
		data=new DataType[M*N];
	}
	//Ĭ������Ϊ��ģʽ
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
	//������Ϣ
	struct Size size(){
		return {M,N};
	}
	int
	//��������
	DataType operator()(int i,int j){
		//�쳣����i��jҪ�ں��ʷ�Χ
		return data[i*lda+j];
	}
	friend Matrix<DataType> operator+(const Matrix<DataType>& A,const Matrix<DataType>& B){
		//�쳣��������Ҫ
	}

};







#endif /* MATRIX_H_ */
