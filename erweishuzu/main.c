#include <stdio.h>
#define rows 3
#define columns 3
#define elementNum rows * columns

typedef struct matrix{
    double data;//����
    int row;//��λ��
    int column;//��λ��
}Matrix;

// �������Ԫ��
void add( Matrix matrix[] );
// Ϊ�������������ֵ
void AddCowColumn( Matrix matrix[] );
// ����������
void SortMatrix( Matrix matrix[] );
// ������ת��
void matrixTranspose( Matrix matrix[], Matrix NewMatrix[] );
// ��ԭ������ת�þ���ĺ�
void matrixSum( Matrix matrix[], Matrix NewMatrix[], Matrix SumMatrix[] );
// ����þ����е����ֵ����������
void print_NumberMax_Row_Column( Matrix matrix[] );
// �������
void printMatrix( Matrix matrix[] );

int main(){
    // ����ά��������Ϊ���򴢴���һ���ṹ��������
    Matrix matrix[elementNum], NewMatrix[elementNum], NumMatrix[elementNum];
    add(matrix );
    printf("�þ���Ϊ��\n");
    printMatrix( matrix );
    printf("--------------------\n");
    matrixTranspose( matrix, NewMatrix );
    SortMatrix( NewMatrix );
    printf("ת�þ���Ϊ��\n");
    printMatrix( NewMatrix );
    printf("--------------------\n");
    matrixSum( matrix, NewMatrix, NumMatrix );
    printf("ԭ������ת�þ���ĺ�Ϊ��\n");
    printMatrix( NumMatrix );
    printf("--------------------\n");
    print_NumberMax_Row_Column( matrix );
    printf("--------------------\n");
}

void add( Matrix matrix[] ) {
    printf("�밴���������Ԫ�أ�");
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

// ������
void SortMatrix( Matrix matrix[] ) {
    int i, j;
    Matrix temp;
    for ( i = 0; i < elementNum - 1; i++ ) {
        for ( j = i + 1; j < elementNum; j++ ) {
            // ����Ϊ��������
            if ( matrix[i].row > matrix[j].row ||
            ( matrix[i].row == matrix[j].row && matrix[i].column > matrix[j].column )) {
                // ��������Ԫ��
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
    // ת��
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
    printf("�þ�������Ԫ����%f���ڵ�%d�У���%d�С�\n", NewMatrix[Position].data, NewMatrix[Position].row, NewMatrix[Position].column);
}

void printMatrix( Matrix matrix[] ) {
    for( int i = 0; i < elementNum; i++){
        printf("%f ",matrix[i].data);
        if(( i + 1 ) % rows == 0 ){
            printf("\n");
        }
    }
}
