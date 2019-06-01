// FILE: stattest.cpp
//Write your test code in this file


#include <cctype>    // Provides toupper
#include <iostream>  // Provides cout, cin
#include <cstdlib>   // Provides EXIT_SUCCESS
#include "stats.h"

using namespace std;
int main( )
{
	statistician mark;
    mark.next(2.54);
    mark.next(6.1);
    mark.next(1);
    mark.next(9);
    mark.next(100);

    statistician jenny;
    jenny.next(2.1);
    jenny.next(3.0);
    jenny.next(10.8);
    jenny.next(56);
    jenny.next(7.9);
    jenny.next(234);

    statistician alex;
    alex.next(2.54);
    alex.next(6.1);
    alex.next(1);
    alex.next(9);
    alex.next(100);

    statistician markJenny;
    markJenny.next(2.54);
    markJenny.next(6.1);
    markJenny.next(1);
    markJenny.next(9);
    markJenny.next(100);
    markJenny.next(2.1);
    markJenny.next(3.0);
    markJenny.next(10.8);
    markJenny.next(56);
    markJenny.next(7.9);
    markJenny.next(234);

   

    cout << "TEST SUM()" << endl;
    if(mark.sum()== 118.64){
        cout << "mark.sum(): PASSED" << endl;
    }else
        cout << "mark.sum(): FAILED" << endl;

    if (jenny.sum() == 313.8){
        cout << "jenny.sum(): PASSED" << endl;
    }else
        cout << "jenny.sum(): FAILED" << endl;



    cout << "TEST LENGTH()" << endl;
    if (mark.length() == 5){
        cout << "mark.sum(): PASSED" << endl;
    }else
        cout << "mark.sum(): FAILED" << endl;

    if (jenny.length() == 6){
        cout << "jenny.sum(): PASSED" << endl;
    }else
        cout << "jenny.sum(): FAILED" << endl;



    cout << "TEST MEAN" << endl;
    if (mark.mean() == 23.728){
        cout << "mark.mean(): PASSED" << endl;
    }else
        cout << "mark.mean(): FAILED" << endl;

    if (jenny.mean() == 52.3){
        cout << "jenny.mean(): PASSED" << endl;
    }else
        cout << "jenny.mean(): FAILED" << endl;

    cout << "TEST MINIMIM" << endl;
    if (mark.minimum() == 1){
        cout << "mark.minimum(): PASSED" << endl;
    }else
        cout << "mark.minimum(): FAILED" << endl;

    if (jenny.minimum() == 2.1){
        cout << "jenny.minimum(): PASSED" << endl;
    }else
        cout << "jenny.minimum(): FAILED" << endl;



    cout << " TEST MAXIMUM" << endl;
    if (mark.maximum() == 100){
        cout << "mark.maximum(): PASSED" << endl;
    }else
        cout << "mark.maximum(): FAILED" << endl;

    if (jenny.maximum() == 234){
        cout << "jenny.maximum(): PASSED" << endl;
    }else
        cout << "jenny.maximum(): FAILED" << endl;


    cout << "TEST OPERATOR +" << endl;
    
    statistician temp;
    temp = mark + jenny;
    if (temp == markJenny){
            cout << "operator + : PASSED" << endl;
    }else
        cout << "operator + : FAILED" << endl;


    cout << "TEST OPERATOR *" << endl;
    temp.reset();
    temp = 2*mark;
    double tempSum = 2*118.64;
    double tempMin = 2*1;
    double tempMax = 2*100;
    double tempMean = 2*23.728;

    if ((temp.sum() == tempSum) && (temp.minimum() == tempMin) &&
        (temp.maximum() == tempMax) && (temp.mean() == tempMean)){
            cout << "operator * : PASSED" << endl;
    }else
        cout << "operator * : FAILED" << endl;



    cout << "TEST OPERATOR ==" << endl;
    if (mark == alex){
        cout << "operator == : PASSED" << endl;
    }else
        cout << "operator == :FALIED" << endl;


    return 0;

}


