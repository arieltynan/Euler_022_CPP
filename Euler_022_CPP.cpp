// Euler_022_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// What is the total of all the name scores in the file?

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

using namespace std;

int biSearch(string* arr, int arrSize, string target)
{
    int first = 0;
    int last = arrSize - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;
        string midValue = arr[mid];

        if (target == midValue)
            return mid;
        else if (target < midValue)
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

vector<string> Sort(vector<string> vect, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (vect[j] < vect[min])
                min = j;
            //cout << min << " ";
        }
        //cout << vect[i] << " ";
        iter_swap(vect.begin() + i, vect.begin() + min);
        //cout << vect[i] << endl << endl;
    }
    return vect;
} //end sort

int main()
{
    ifstream fin;
    string fileName = "p022_names.txt";
    fin.open(fileName.c_str());

    //if file is not found, print error statement
    if (!fin)
    {
        cout << "Cannot open " << fileName << endl;
        exit(1);
    }
    else
        cout << "File is open" << endl;

    string oneString;
    int i = 0;
    while (fin)
    {
        string x;
        fin >> oneString;
        //oneString.push_back(x);
        //cout << oneString << endl; //prints names
    }
    vector<string> vectList;
    stringstream ss(oneString);
    int count = 0;
    while (ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        substr.erase(remove(substr.begin(), substr.end(), '\"'), substr.end());
        vectList.push_back(substr);
        count++;
    }

    int vectSize = count; //size of array
    vector<string> vectSorted = Sort(vectList, vectSize);
    int pointTot = 0;

    for (int i = 0; i < vectSize; ++i)
    {
        int wordpt = 0;
        for (int j = 0; j < vectSorted[i].length(); j++) //vectSorted[i].length()
        {
            wordpt = (i + 1) * (vectSorted[i][j] - 64) + wordpt;
            //cout << vectSorted[i][j];
        }
        pointTot = wordpt + pointTot;
        //cout << vectSorted[i] << " " << pointTot;
    }
    //cout << vectSize << endl;
    cout << pointTot;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
