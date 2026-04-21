//Program Challenge 2-3 Chapter 9
// Madelyn Fawcett 
//April 21, 2026

#include <iostream>
using namespace std;

//function prototypes*******************************
void getArrayElements(double*, const int);
void displayArray(double*, const int);
void selectionSort(double*, const int);
double averageArrayElements(double*, const int);
void swap(double*, double*);
int inputValidate(int);
double inputValidate(double);


//Main function for program************************************************
int main()
{
    int number_of_test_scores = 0;
    int* ptr;
    double average;
    double* test_scores;


    cout << "This is a program that takes the test scores, drops the lowest and gives you the average." << endl;
    cout << "Enter the number of test scores: ";
    number_of_test_scores = inputValidate(number_of_test_scores);

    double* test_scores = new double[number_of_test_scores];
    
    cout << "Enter each test score: " << endl;
    getArrayElements(test_scores, number_of_test_scores);

    selectionSort(test_scores, number_of_test_scores);

    double average = averageArrayElements(test_scores, number_of_test_scores);

    cout << "\nSorted test scores:" << endl;
    displayArray(test_scores, number_of_test_scores);

    delete[] test_scores;
    test_scores = nullptr;

    cout << "\nAverage = " << average << endl;

    return 0;
}

// Function to validate number input*************************************
int inputValidate(int number)
{
    while (!(cin >> number))
    {
        cout << "Error. Enter a number: ";
        cin.clear();
        cin.ignore();
    }
    return number;
}

//Function to fill array*****************************************************
void getArrayElements(double* array, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "#" << (i + 1) << ": ";
        *(array + i) = inputValidate(*(array + i));
    }

}

//Function that uses a selection sort on test scores********************************
void selectionSort(double* array, const int SIZE)
{
    int start_index,
        minIndex,
        minValue;

    for (start_index = 0; start_index < (SIZE - 1); start_index++)
    {
        minIndex = start_index;
        minValue = *(array + start_index);

        for (int index = start_index + 1; index < SIZE; index++)
        {
            if (*(array + index) < minValue)
            {
                minValue = *(array + index);
                minIndex = index;
            }

        }
        swap(*(array + minIndex), *(array + start_index));
    }
}

//Function for integers to swap places during sorting***********************************
void swap(double* a, double* b)
{
    double* temp = a;
    a = b;
    b = temp;
}

//Function to get average from test scores and drop the lowest score*************************************
double averageArrayElements(double* array, const int SIZE)
{
    double lowest_value = *(array + 0),
    sum = lowest_value;

    for (int i = 1; i < SIZE; i++)
    {
        if (*(array + i) < lowest_value)
            lowest_value = *(array + i);

        sum += *(array + i);
    }

    sum -= lowest_value;

    return sum / (SIZE - 1);
}

//Function to display test scores after sorting**********************************
void displayArray(double* array, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << "#" << (i + 1) << ": " << *(array + i) << endl;

}

//function for double intergers*******************************************
double inputValidate(double number)
{
    while (!(cin >> number))
    {
        cout << "Error. Enter a number: ";
        cin.clear();
        cin.ignore();
    }
    return number;
}
