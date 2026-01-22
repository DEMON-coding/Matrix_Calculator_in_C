#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	double** mat;
	int row;
	int col;
} Matrix;

//声明函数
void menu();//菜单
void InitialMatrix(Matrix* T, int row, int col); //只分配空间不初始化；
void InitialMatrixZero(Matrix* T, int row, int col); //初始化为 0
void InitialMatrixRand(Matrix* T, int row, int col); //初始化为 50 以内随机正整数
void InputMatrix(Matrix* T, int row, int col); //键盘输入矩阵
void DestroyMatrix(Matrix* T); //释放矩阵空间
int AddMatrix(Matrix* A, Matrix* B, Matrix* C, int row, int col); //矩阵加
int MinusMatrix(Matrix* A, Matrix* B, Matrix* C, int row, int col); //矩阵减
int MultiMatrix(Matrix* A, Matrix* B, Matrix* C); //矩阵乘法
void PrintMatrix(Matrix* T, int row, int col); //矩阵输出
double MaxMatrix(Matrix* T, int row, int col); //矩阵元素最大值
int ReverseMatrix(Matrix* A, Matrix* B, int row, int col); //B 是 A 的逆矩阵
int ABS(double a);//求绝对值

int main()
{
	// 初始化随机数生成器
	srand((unsigned)time(NULL));

	//开始交互
	printf("您好，欢迎使用矩阵计算器！\n");
	menu();
	printf("请输入数字以使用对应功能：");
	int ROW = 0, COL = 0, input = -2;

	while (1)
	{
		scanf_s("%d", &input);
		switch (input)
		{
		case -1://重新查看菜单
		{
			menu();
			break;
		}
		case 0:
		{
			printf("感谢使用！");
			system("pause");
			system("cls");
			break;
		}
		case 1:
		{
			printf("请输入矩阵行数：");
			scanf_s("%d", &ROW);
			printf("请输入矩阵列数：");
			scanf_s("%d", &COL);
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}

			Matrix A;
			InitialMatrix(&A, ROW, COL);
			//初始化完毕

			InitialMatrixZero(&A, ROW, COL);

			//键盘输入
			printf("请输入矩阵\n");
			InputMatrix(&A, ROW, COL);

			int i = 0, j = 0;
			double sum = 0;
			for (i = 0; i < ROW; i++)
			{
				for (j = 0; j < COL; j++) sum += A.mat[i][j];
			}

			printf("矩阵的均值为：%f\n", sum / (i * j));

			DestroyMatrix(&A);
			break;
		}
		case 2:
		{
			printf("请输入矩阵行数：");
			scanf_s("%d", &ROW);
			printf("请输入矩阵列数：");
			scanf_s("%d", &COL);
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}

			Matrix A;
			InitialMatrix(&A, ROW, COL);
			//初始化完毕				

			//随机生成
			InitialMatrixRand(&A, ROW, COL);
			printf("随机生成矩阵成功！\n");

			int i = 0, j = 0;
			double sum = 0;
			for (i = 0; i < ROW; i++)
			{
				for (j = 0; j < COL; j++) sum += A.mat[i][j];
			}

			printf("产生的矩阵为：\n");
			PrintMatrix(&A, ROW, COL);
			printf("矩阵的均值为：%f", sum / (i * j));

			DestroyMatrix(&A);
			break;
		}
		case 3:
		case 6:
		{
			Matrix A, B, C;
			printf("请输入矩阵行数：");
			scanf_s("%d", &ROW);
			printf("请输入矩阵列数：");
			scanf_s("%d", &COL);
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}
			InitialMatrix(&A, ROW, COL);
			InitialMatrix(&B, ROW, COL);
			InitialMatrix(&C, ROW, COL);
			InitialMatrixZero(&C, ROW, COL);

			if (input == 3)
			{
				InitialMatrixZero(&A, ROW, COL);
				InitialMatrixZero(&B, ROW, COL);

				printf("请输入第一个矩阵：\n");
				InputMatrix(&A, ROW, COL);
				printf("请输入第二个矩阵：\n");
				InputMatrix(&B, ROW, COL);
				//初始化完毕				
			}
			else
			{
				InitialMatrixRand(&A, ROW, COL);
				InitialMatrixRand(&B, ROW, COL);
				printf("随机生成矩阵成功！\n");
				printf("产生的矩阵1为：\n");
				PrintMatrix(&A, ROW, COL);
				printf("产生的矩阵2为：\n");
				PrintMatrix(&B, ROW, COL);
				//初始化完毕	
			}

			int check = AddMatrix(&A, &B, &C, ROW, COL);
			if (check == -1)
			{
				printf("获取矩阵地址失败！\n");
				input = -2;
				break;
			}
			printf("矩阵和为：\n");
			PrintMatrix(&C, ROW, COL);

			DestroyMatrix(&A);
			DestroyMatrix(&B);
			DestroyMatrix(&C);
			break;
		}
		case 4:
		case 7:
		{
			Matrix A, B, C;
			printf("请输入矩阵行数：");
			scanf_s("%d", &ROW);
			printf("请输入矩阵列数：");
			scanf_s("%d", &COL);
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}
			InitialMatrix(&A, ROW, COL);
			InitialMatrix(&B, ROW, COL);
			InitialMatrix(&C, ROW, COL);
			InitialMatrixZero(&C, ROW, COL);

			if (input == 4)
			{
				InitialMatrixZero(&A, ROW, COL);
				InitialMatrixZero(&B, ROW, COL);

				printf("请输入第一个矩阵：\n");
				InputMatrix(&A, ROW, COL);
				printf("请输入第二个矩阵：\n");
				InputMatrix(&B, ROW, COL);
				//初始化完毕				
			}
			else
			{
				InitialMatrixRand(&A, ROW, COL);
				InitialMatrixRand(&B, ROW, COL);
				printf("随机生成矩阵成功！\n");
				printf("产生的矩阵1为：\n");
				PrintMatrix(&A, ROW, COL);
				printf("产生的矩阵2为：\n");
				PrintMatrix(&B, ROW, COL);
				//初始化完毕	
			}

			int check = MinusMatrix(&A, &B, &C, ROW, COL);
			if (check == -1)
			{
				printf("获取矩阵地址失败！\n");
				input = -2;
				break;
			}
			printf("矩阵差为：\n");
			PrintMatrix(&C, ROW, COL);

			DestroyMatrix(&A);
			DestroyMatrix(&B);
			DestroyMatrix(&C);
			break;
		}
		case 5:
		case 8:
		{
			Matrix A, B, C;
			printf("请输入矩阵1行数：");
			scanf_s("%d", &A.row);
			printf("请输入矩阵1列数(即矩阵2行数)：");
			scanf_s("%d", &A.col);
			printf("请输入矩阵2列数：");
			scanf_s("%d", &B.col);
			if (A.row <= 0 || A.col <= 0 || B.col <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}
			InitialMatrix(&A, A.row, A.col);
			InitialMatrix(&B, A.col, B.col);
			InitialMatrix(&C, A.row, B.col);
			InitialMatrixZero(&C, A.row, B.col);

			if (input == 5)
			{
				InitialMatrixZero(&A, A.row, A.col);
				InitialMatrixZero(&B, A.col, B.col);

				printf("请输入第一个矩阵：\n");
				InputMatrix(&A, A.row, A.col);
				printf("请输入第二个矩阵：\n");
				InputMatrix(&B, A.col, B.col);
				//初始化完毕				
			}
			else
			{
				InitialMatrixRand(&A, A.row, A.col);
				InitialMatrixRand(&B, A.col, B.col);
				printf("随机生成矩阵成功！\n");
				printf("产生的矩阵1为：\n");
				PrintMatrix(&A, A.row, A.col);
				printf("产生的矩阵2为：\n");
				PrintMatrix(&B, A.col, B.col);
				//初始化完毕	
			}

			int check = MultiMatrix(&A, &B, &C);
			if (check == -1)
			{
				printf("获取矩阵地址失败！\n");
				input = -2;
				break;
			}

			printf("矩阵积为：\n");
			PrintMatrix(&C, A.row, B.col);

			DestroyMatrix(&A);
			DestroyMatrix(&B);
			DestroyMatrix(&C);
			break;
		}
		case 9:
		{
			printf("请输入矩阵行数：");
			scanf_s("%d", &ROW);
			printf("请输入矩阵列数：");
			scanf_s("%d", &COL);
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}

			Matrix A;
			int BeginRow, BeginCol, EndCol, EndRow;
			InitialMatrix(&A, ROW, COL);
			printf("请输入矩阵\n");
			InputMatrix(&A, ROW, COL);
			printf("请依次输入 起始行 起始列 结束行 结束列：\n");
			scanf_s("%d%d%d%d", &BeginRow, &BeginCol, &EndRow, &EndCol);

			if (BeginRow < 0 || BeginCol < 0 || EndRow < 0 || EndCol < 0 || BeginRow > EndRow || BeginCol > EndCol || BeginRow >= ROW || BeginCol >= COL || EndRow >= ROW || EndCol >= COL) printf("不正确的输入！\n");
			printf("子矩阵为：\n");
			int i = 0, j = 0;
			for (i = 0; i < (EndRow - BeginRow + 1); i++)
			{
				for (j = 0; j < (EndCol - BeginCol + 1); j++) printf("%f ", A.mat[i + BeginRow][j + BeginCol]);
				printf("\n");
			}

			DestroyMatrix(&A);
			break;
		}
		case 10:
		case 11:
		{
			printf("请输入矩阵行数：");
			scanf_s("%d", &ROW);
			printf("请输入矩阵列数：");
			scanf_s("%d", &COL);
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}

			Matrix A;
			InitialMatrix(&A, ROW, COL);
			//初始化完毕

			if (input == 10)
			{
				InitialMatrixZero(&A, ROW, COL);

				printf("请输入矩阵\n");
				InputMatrix(&A, ROW, COL);
			}
			else
			{
				InitialMatrixRand(&A, ROW, COL);
				printf("随机生成矩阵成功！\n");

				printf("产生的矩阵为：\n");
				PrintMatrix(&A, ROW, COL);
			}

			double max = MaxMatrix(&A, ROW, COL);
			printf("矩阵的最大值为：%f", max);
			DestroyMatrix(&A);
			break;
		}
		case 12:
		case 13:
		{
			printf("请输入矩阵行数：");
			scanf_s("%d", &ROW);
			printf("请输入矩阵列数：");
			scanf_s("%d", &COL);
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}

			Matrix A;
			InitialMatrix(&A, ROW, COL);
			//初始化完毕

			if (input == 12)
			{
				InitialMatrixZero(&A, ROW, COL);

				printf("请输入矩阵\n");
				InputMatrix(&A, ROW, COL);
			}
			else
			{
				InitialMatrixRand(&A, ROW, COL);
				printf("随机生成矩阵成功！\n");

				printf("产生的矩阵为：\n");
				PrintMatrix(&A, ROW, COL);
			}

			printf("矩阵的转置为：\n");
			int i = 0, j = 0;
			for (i = 0; i < COL; i++)
			{
				for (j = 0; j < ROW; j++) printf("%f ", A.mat[j][i]);
				printf("\n");
			}

			DestroyMatrix(&A);
			break;
		}
		case 14:
		case 15:
		{
			printf("请输入矩阵行数：");
			scanf_s("%d", &ROW);
			printf("请输入矩阵列数：");
			scanf_s("%d", &COL);
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}

			Matrix A;
			InitialMatrix(&A, ROW, COL);
			//初始化完毕

			if (input == 14)
			{
				InitialMatrixZero(&A, ROW, COL);

				printf("请输入矩阵\n");
				InputMatrix(&A, ROW, COL);
			}
			else
			{
				InitialMatrixRand(&A, ROW, COL);
				printf("随机生成矩阵成功！\n");

				printf("产生的矩阵为：\n");
				PrintMatrix(&A, ROW, COL);
			}

			double max = 0;
			int i = 0, j = 0;
			for (i = 0; i < ROW; i++)
			{
				if (ABS(max) < ABS(A.mat[i][j]))  max = A.mat[i][j];
			}
			if (max == 0)
			{
				printf("零矩阵无法归一化\n");
				break;
			}
			printf("矩阵的最大值归一化为：\n");
			for (i = 0; i < ROW; i++)
			{
				for (j = 0; j < COL; j++) printf("%f ", (A.mat[i][j]) / max);
				printf("\n");
			}

			DestroyMatrix(&A);
			break;
		}
		case 16:
		case 17:
		{
			printf("请输入方阵阶数：");
			scanf_s("%d", &ROW);
			COL = ROW;
			if (ROW <= 0 || COL <= 0)
			{
				printf("不正确的输入！\n");
				input = -2;
				break;
			}

			Matrix A, B;
			InitialMatrix(&A, ROW, COL);
			InitialMatrix(&B, ROW, COL);
			InitialMatrixZero(&B, ROW, COL);
			//初始化完毕

			if (input == 16)
			{
				InitialMatrixZero(&A, ROW, COL);

				//键盘输入
				printf("请输入矩阵\n");
				InputMatrix(&A, ROW, COL);
			}
			else
			{
				InitialMatrixRand(&A, ROW, COL);
				printf("随机生成矩阵成功！\n");

				printf("产生的矩阵为：\n");
				PrintMatrix(&A, ROW, COL);
			}

			int flag = ReverseMatrix(&A, &B, ROW, COL);
			if (flag == -1) break;
			printf("矩阵的逆为：\n");

			PrintMatrix(&B, ROW, COL);
			DestroyMatrix(&A);
			DestroyMatrix(&B);
			break;
		}
		default:
		{
			printf("不正确的输入！\n");
			input = -2;
			break;
		}
		}
		if (input == 0) break;
		if (input == -2) continue;
		printf("输出完毕！\n");
		printf("您可以继续使用或退出，输入 -1 呼出菜单：");
	}

	return 0;
}

void PrintMatrix(Matrix* T, int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) printf("%f ", T->mat[i][j]);
		printf("\n");
	}
}

void InitialMatrix(Matrix* T, int row, int col)
{
	// 检查指针是否为空
	if (T == NULL)
	{
		printf("获取矩阵地址失败！\n");
		return;
	}

	T->row = row;
	T->col = col;

	//分配内存
	T->mat = (double**)malloc(row * sizeof(double*));//创建列

	if (T->mat == NULL)
	{
		printf("内存分配失败！\n");
		return;
	}

	int i = 0, j = 0;
	for (i = 0; i < row; i++) //创建行
	{
		T->mat[i] = (double*)malloc(col * sizeof(double));
		if (T->mat[i] == NULL)
		{
			printf("内存分配失败！\n");

			// 释放之前已分配的内存
			for (j = 0; j < i; j++) free(T->mat[j]);
			free(T->mat);
			return;
		}
	}
}

void InitialMatrixZero(Matrix* T, int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) T->mat[i][j] = 0;
	}
}

void InitialMatrixRand(Matrix* T, int row, int col)
{
	int i = 0, j = 0;

	//创建 0 到 50 之间的随机数
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) T->mat[i][j] = rand() / (double)RAND_MAX * 50;
	}

}

void InputMatrix(Matrix* T, int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) scanf_s("%lf", &(T->mat[i][j]));
	}
}

void menu()
{
	printf("***************************************************\n");
	printf("1:输入一个矩阵，求矩阵均值\n");
	printf("2:产生一个随机数矩阵，求矩阵均值\n");
	printf("3:输入两个矩阵，求矩阵和 \n");
	printf("4:输入两个矩阵，求矩阵差 \n");
	printf("5:输入两个矩阵，求矩阵积\n");
	printf("6:产生两个随机数矩阵，求矩阵和\n");
	printf("7:产生两个随机数矩阵，求矩阵差\n");
	printf("8:产生两个个随机数矩阵，求矩阵积\n");
	printf("9:输入一个矩阵，求矩阵的子阵\n");
	printf("10:输入一个矩阵，求矩阵元素的最大值\n");
	printf("11:产生一个随机数矩阵，求矩阵元素的最大值\n");
	printf("12:输入一个矩阵，求矩阵转置\n");
	printf("13:产生一个随机数矩阵，求矩阵转置\n");
	printf("14:输入一个矩阵，对矩阵最大值归一化\n");
	printf("15:产生一个随机数矩阵，对矩阵最大值归一化\n");
	printf("16:输入一个矩阵（方阵），求矩阵的逆\n");
	printf("17:产生一个随机数矩阵（方阵），求矩阵的逆\n");
	printf("0:结束!\n");
	printf("***************************************************\n");
}

void DestroyMatrix(Matrix* T)
{
	if (T == NULL) return;
	for (int i = 0; i < T->row; i++) free(T->mat[i]); // 释放每一行的内存
	free(T->mat); // 释放存储行指针的内存
}

int AddMatrix(Matrix* A, Matrix* B, Matrix* C, int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) C->mat[i][j] = A->mat[i][j] + B->mat[i][j];
	}
	return 0;
}

int MinusMatrix(Matrix* A, Matrix* B, Matrix* C, int row, int col)
{
	if (A == NULL || B == NULL || C == NULL) return -1;
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) B->mat[i][j] = 0 - B->mat[i][j];
	}
	int check = AddMatrix(A, B, C, row, col);
	return check;
}

int MultiMatrix(Matrix* A, Matrix* B, Matrix* C)
{
	if (A == NULL || B == NULL || C == NULL) return -1;
	int i = 0, j = 0, k = 0;
	for (i = 0; i < A->row; i++)
	{
		for (j = 0; j < B->col; j++)
		{
			C->mat[i][j] = 0;
			for (k = 0; k < A->col; k++) C->mat[i][j] = C->mat[i][j] + (A->mat[i][k] * B->mat[k][j]);
		}
	}
	return 0;
}

double MaxMatrix(Matrix* T, int row, int col)
{
	int i = 0, j = 0;
	double max = T->mat[0][0];
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (max < T->mat[i][j]) max = T->mat[i][j];
		}
	}
	return max;
}

int ReverseMatrix(Matrix* A, Matrix* B, int row, int col)
{
	int i = 0, j = 0, k = 0, flag = -1;
	double tmp = 0.0;

	//B初始化为单位矩阵
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i == j) B->mat[i][j] = 1;
		}
	}

	//行初等变换为行阶梯型
	for (j = 0; j < col; j++)
	{
		//找开头非零的行
		for (i = j; i < row; i++)
		{
			if (A->mat[i][j] != 0) flag = i;
			break;
		}

		//找不到就不可逆
		if (flag == -1)
		{
			printf("矩阵不可逆！\n");
			return -1;
			break;
		}
		else if (flag == j) tmp = A->mat[j][j];
		//加到首行,首元化为1
		for (k = 0;k < col; k++)
		{
			if (j == flag)
			{
				A->mat[j][k] = (A->mat[j][k]) / tmp;
				B->mat[j][k] = (B->mat[j][k]) / tmp;
			}
			else
			{
				A->mat[j][k] = (A->mat[flag][k] + A->mat[j][k]) / (A->mat[flag][j]);
				B->mat[j][k] = (B->mat[flag][k] + B->mat[j][k]) / (A->mat[flag][j]);
			}
		}

		//其余行首元化为0
		for (i = flag + 1;i < row; i++)
		{
			tmp = (A->mat[i][j]);
			for (k = 0;k < col; k++)
			{
				A->mat[i][k] -= (A->mat[flag][k]) * tmp;
				B->mat[i][k] -= (B->mat[flag][k]) * tmp;
			}
		}
		//PrintMatrix(B ,row ,col);
	}

	//进一步将A化为单位矩阵
	for (j = col - 1; j >= 0; j--)
	{
		for (i = j - 1;i >= 0; i--)
		{
			tmp = (A->mat[i][j]);
			for (k = col - 1;k >= 0; k--)
			{
				A->mat[i][k] -= (A->mat[j][k]) * tmp;
				B->mat[i][k] -= (B->mat[j][k]) * tmp;
			}
		}
		//PrintMatrix(B ,row ,col);
	}

	//B为矩阵的逆
	return 0;
}

int ABS(double a)
{
	if (a >= 0) return a;
	else return (0 - a);
}