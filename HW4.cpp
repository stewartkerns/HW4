#include <iostream>

int* sort(int *, int);
void merge(int*, int*, int*, int, int, int);
void printArray(int*, int);

int main() {
    std::cout << "Hello, World!" << std::endl;

    int * firstArray = new int[4] {1, 17, 4, 2};
    printArray(firstArray, 4);
    sort(firstArray, 4);
    printArray(firstArray, 4);


    return 0;
}

int* sort(int * intArray, int size){
    if (size > 1){
//change things to safe pointers, this shit is sketch
        int leftSize = size/2;
        int rightSize = (size/2) + (size % 2);
        int * intArrLeft = new int[leftSize];
        int * intArrRight = new int[rightSize];
        int count = 0;
        for (int i = 0; i < leftSize; i++){
            intArrLeft[count++] = intArray[i];
        }
        count = 0;
        for (int i = leftSize; i < size; i++){
            intArrRight[count++] = intArray[i];
        }
        sort(intArrLeft, leftSize);
        sort(intArrRight, rightSize);

        merge(intArray, intArrLeft, intArrRight, size, leftSize, rightSize);

        delete [] intArrLeft;
        delete [] intArrRight;
    }
}

void merge(int* intArray, int* intArrLeft, int* intArrRight, int size, int
leftSize, int rightSize){

    int countLeft = 0;
    int countRight = 0;
    for (int i = 0; i < size; i++){
        if (countLeft < leftSize && countRight < rightSize){
            if (intArrLeft[countLeft] >= intArrRight[countRight]){
                intArray[i] = intArrLeft[countLeft++];
            }
            else{
                intArray[i] = intArrRight[countRight++];
            }
        }
        else if (countLeft < leftSize){
            intArray[i] = intArrLeft[countLeft++];
        }
        else{
            intArray[i] = intArrRight[countRight++];
        }
    }
}
void printArray(int* intArray, int size){
    std::cout << "The array is as follows: ";
    for (int i = 0; i < size; i++){
        std::cout << intArray[i] << ", ";
    }
    std::cout << std::endl;
}