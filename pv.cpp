#include<iostream>

#include<cmath>

#include<iomanip>


using namespace std;

// Function declarations

double readFutureValue();

double readInterestRate();

int readNumberYears();

double presentValue(double futureValue, double interestRate, int numberYears);

// main function

int main()

{

    // Declaring variables

    double pValue, futureValue, interestRate;

    int numberYears;

    // calling the functions

    futureValue = readFutureValue();

    interestRate = readInterestRate();

    numberYears = readNumberYears();

    // calling the function by passing the result values of each function

    pValue = presentValue(futureValue, interestRate, numberYears);

    // Displaying the output

    cout << "\nPresent value: $" << std::setprecision(2) << std::fixed << pValue << endl;

    cout << "Future value: $" << std::setprecision(2) << std::fixed << futureValue << endl;

    cout << "Annual interest rate: " << std::setprecision(3) << std::fixed << interestRate << "%"

        <<
        endl;

    cout << "Years: " << numberYears << endl;

    return 0;

}

// This function will read the valid future value

double readFutureValue()

{

    double futureVal;

    while (true)

    {

        cout << "Enter future value" << endl;

        cin >> futureVal;

        if (futureVal <= 0)

        {

            cout << "The future value must be greater than zero" << endl;

            continue;

        } else

        {

            break;

        }

    }

    return futureVal;

}

// This function will read the valid annual interest rate

double readInterestRate()

{

    double interestRate;

    while (true)

    {

        cout << "Enter annual interest rate" << endl;

        cin >> interestRate;

        if (interestRate <= 0)

        {

            cout << "The annual interest rate must be greater than zero" << endl;

            continue;

        } else

        {

            break;

        }

    }

    return interestRate;

}

// This function will read the valid no of years

int readNumberYears()

{

    int years;

    while (true)

    {

        cout << "Enter number of years";

        cin >> years;

        if (years <= 0)

        {

            cout << "\nThe number of years must be greater than zero" << endl;

            continue;

        } else

        {

            break;

        }

    }

    return years;

}

// This function will calculate the present value

double presentValue(double futureValue, double interestRate, int numberYears)

{

    double r = (interestRate / 100);

    //finalVal

    return (futureValue) / double(pow((1 + r), numberYears));

}