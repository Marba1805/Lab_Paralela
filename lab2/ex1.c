#include <iostream>

int exe1 ()
{
	int mat[10][10];
    int i, j, row, col, small, big, mencol;
	
	big = mat[0][0];
    small = mat[0][0];
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(mat[i][j] < small)
            small = mat[i][j];
            mencol = j;
            
            if(mat[i][j] > big)
            big = mat[i][j];
        }
    }
    
	std::cout << "a linha com o menor elemento:" << mencol;
	return 0;
	
}

int main(void)
{
    return 0;
}
