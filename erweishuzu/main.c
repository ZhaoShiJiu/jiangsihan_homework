#include <stdio.h>
#define rows 3
#define columns 3
#define elementNum rows * columns

typedef struct matrix{
    double data;//数据
    int row;//行位置
    int column;//列位置
}Matrix;

// 输入矩阵元素
void add( Matrix matrix[] );
// 为矩阵的行列数赋值
void AddCowColumn( Matrix matrix[] );
// 矩阵按行排序
void SortMatrix( Matrix matrix[] );
// 将矩阵转置
void matrixTranspose( Matrix matrix[], Matrix NewMatrix[] );
// 求原矩阵与转置矩阵的和
void matrixSum( Matrix matrix[], Matrix NewMatrix[], Matrix SumMatrix[] );
// 输出该矩阵中的最大值及其行列数
void print_NumberMax_Row_Column( Matrix matrix[] );
// 输出矩阵
void printMatrix( Matrix matrix[] );

int main(){
    // 将三维矩阵以行为主序储存在一个结构体数组中
    Matrix matrix[elementNum], NewMatrix[elementNum], NumMatrix[elementNum];
    add(matrix );
    printf("该矩阵为：\n");
    printMatrix( matrix );
    printf("--------------------\n");
    matrixTranspose( matrix, NewMatrix );
    SortMatrix( NewMatrix );
    printf("转置矩阵为：\n");
    printMatrix( NewMatrix );
    printf("--------------------\n");
    matrixSum( matrix, NewMatrix, NumMatrix );
    printf("原矩阵与转置矩阵的和为：\n");
    printMatrix( NumMatrix );
    printf("--------------------\n");
    print_NumberMax_Row_Column( matrix );
    printf("--------------------\n");
}

void add( Matrix matrix[] ) {
    printf("请按行输入矩阵元素：");
    for(int i = 0; i < elementNum; i++){
        scanf_s("%lf",&matrix[i].data);
    }
    AddCowColumn( matrix );
}

void AddCowColumn( Matrix matrix[] ){
    for(int i = 0; i < elementNum; i++){
        if ( i<=2 ) {
            matrix[i].row = 1;
            matrix[i].column = i%3+1;
        } else if( i<=5 ) {
            matrix[i].row = 2;
            matrix[i].column = i%3+1;
        }  else {
            matrix[i].row = 3;
            matrix[i].column = i%3+1;
        }
    }
}

// 排序函数
void SortMatrix( Matrix matrix[] ) {
    int i, j;
    Matrix temp;
    for ( i = 0; i < elementNum - 1; i++ ) {
        for ( j = i + 1; j < elementNum; j++ ) {
            // 按行为主序排序
            if ( matrix[i].row > matrix[j].row ||
            ( matrix[i].row == matrix[j].row && matrix[i].column > matrix[j].column )) {
                // 交换两个元素
                temp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = temp;
            }
        }
    }
}

void matrixTranspose(Matrix matrix[], Matrix NewMatrix[] ){
    for( int i = 0; i < elementNum; i++ ){
        NewMatrix[i].column = matrix[i].column;
        NewMatrix[i].row = matrix[i].row;
        NewMatrix[i].data = matrix[i].data;
    }
    // 转置
    for( int i = 0; i < elementNum; i++ ){
        int TemporaryData = NewMatrix[i].row;
        NewMatrix[i].row = NewMatrix[i].column;
        NewMatrix[i].column = TemporaryData;
    }
}

void matrixSum( Matrix matrix[], Matrix NewMatrix[], Matrix SumMatrix[] ){
    for( int i = 0; i < elementNum; i++ ){
        SumMatrix[i].data = matrix[i].data + NewMatrix[i].data;
    }
    AddCowColumn( SumMatrix );
}

void print_NumberMax_Row_Column( Matrix matrix[] ){
    Matrix NewMatrix[elementNum];
    for( int i = 0; i < elementNum; i++ ){
        NewMatrix[i] = matrix[i];
    }
    double NumberMax = NewMatrix[0].data;
    int Position = 0;
    for( int i = 1; i < elementNum; i++ ){
        if( NumberMax < NewMatrix[i].data ){
            NumberMax = NewMatrix[i].data;
            Position = i;
        }
    }
    printf("该矩阵的最大元素是%f，在第%d行，第%d列。\n", NewMatrix[Position].data, NewMatrix[Position].row, NewMatrix[Position].column);
}

void printMatrix( Matrix matrix[] ) {
    for( int i = 0; i < elementNum; i++){
        printf("%f ",matrix[i].data);
        if(( i + 1 ) % rows == 0 ){
            printf("\n");
        }
    }
}
