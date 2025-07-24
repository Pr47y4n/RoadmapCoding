#include <iostream>

void print(int* arr, int sze){
    for(int i = 0; i < sze; ++i){



	    std::cout << arr[i] << " ";
    }
}

//Square Array with Dynamic Allocation
void squareArr(int num){
    int* arr = new int[num];
    for(int i = 0; i < num; ++i){
        arr[i] = i*i;
    }

    print(arr, num);
 
    delete[] arr;
}

//Dynamic 2D Array Allocation
void martix(int row, int col){
    int** mtx = new int*[row];

    for(int i = 0; i < row; ++i){
        mtx[i] = new int[col];
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            mtx[i][j] = i + j;
        }
    }

    for(int i = 0; i < row; ++i){
        print(mtx[i], col);
        std::cout << std::endl;
    }

    for(int i = 0; i < row; ++i){
        delete[] mtx[i];
    }

    delete[] mtx;
}

//Resize a Dynamic Array

// IMPORTANT "while testing, remember to delete the dynamic array to which this function returns to"
int* resizeDynArr(int* oldArr, int oldSze, int newSze){
    print(oldArr, oldSze);
    std::cout << "Old array" << std::endl;
    int* newArr = new int[newSze];
    for(int i = 0; i < oldSze; ++i){
        newArr[i] = oldArr[i];
    }
    delete[] oldArr;

    for(int i = newSze - oldSze; i < newSze; ++i){
        newArr[i] = i + oldSze;
    }
    print(newArr, newSze);
    std::cout << "New Array" << std::endl;
    return newArr;
}


// Reverse Dynamic array
void reverseDyn(int* arr, int sze){
    int tmpval = 0;
    print(arr, sze);
    std::cout << "Array befor reverse" << std::endl;
    for(int i = 0; i < sze/2; ++i){
        tmpval = arr[i];
        arr[i] = arr[sze - i - 1];
        arr[sze - i - 1] = tmpval;
    }
    print(arr, sze);
    std::cout << "Array after reverse" << std::endl;
}

//Diagonal sum of dymanic matrix
void martixDiag(int row, int col){
    if(row != col){
        std::cout << "Row and Column should be equal" << std::endl;
        return;
    }
    int sum = 0;
    int** mtx = new int*[row];

    for(int i = 0; i < row; ++i){
        mtx[i] = new int[col];
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            mtx[i][j] = i + j;
            if(i == j){
                sum += mtx[i][j];
            }
        }
    }

    for(int i = 0; i < row; ++i){
        print(mtx[i], col);
        std::cout << std::endl;
    }

    for(int i = 0; i < row; ++i){
        delete[] mtx[i];
    }

    delete[] mtx;
    std::cout << "The sum of diagonal matrix is " << sum << std::endl;
}

