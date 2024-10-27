#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;

int main()
{
	system("color f0");


    int count = 1;
    while (count <= 10) {
        cout << count << endl;
        count = count + 1;
    }
    cout << "That's all!\n\n";

    // display sqrt and sin values
    count = 1;
    while (count <= 100) {
        cout << count << " " << sqrt(count) << " " << sin(count) << endl;
        count = count + 1;
    }
    cout << endl;

    // input validation
    double number;
    cout << "Enter a non-negative number: ";
    cin >> number;
    while (number < 0) {
        cout << "Invalid input. Enter a non-negative number: ";
        cin >> number;
    }
    cout << "The square root of " << number << " is " << sqrt(number) << endl;
    cout << endl;

    // Read three numbers from the keyboard and calculate the sum.
    double sum = 0; // sum is called an accumulator variable
    int count = 1;
    while (count <= 3) {
        cout << "Enter a number: ";
        cin >> number;
        sum = sum + number;
        count++;
    }
    cout << "The sum is " << sum << "\n\n";

    // The do-while loop
    
    int count = 1;
    do {
        cout << count << endl;
        count++;
    } while (count <= 10);

    cout << "That's all!\n\n";

    // display sqrt and sin values

    count = 1;
    do {
        cout << count << " " << sqrt(count) << " " << sin(count) << endl;
        count++;
    } while (count <= 100);

    cout << endl;


    // CREATING A MENU

    const double TAX_RATE = 0.07;
    double subtotal, total;
    int choice;

    system("cls");

    cout << "\nRacoon Mountain Campground\n"
        << "1. Primitive Camping ($15 per night)\n"
        << "2. RV Composite ($35 per night)\n"
        << "3. Cabin ($50 per night)\n"
        << "4. Quit the Program\n\n"
        << "Enter your choice: ";

    cin >> choice;

    // validate the menu selection
    while (choice < 1 || choice > 4) {
        cout << "Invalid menu choice. Please enter a valid menu choice: ";
        cin >> choice;
    }

    // validate the menu selection
   /* while (choice < 1 || choice > 4) {
        cout << "Invalid menu choice. Please enter a valid menu choice: ";
        cin >> choice;
    }
    */
    do {
        cout << "Enter your choice: ";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    switch (choice) {
    case 1:
        subtotal = 15;
        break;
    case 2:
        subtotal = 35;
        break;
    case 3:
        subtotal = 90;
        break;
    case 4:
        cout << "\nGoodbye!!!\n";
        break;
    }

    if (choice != 4) {
        total = subtotal + TAX_RATE * subtotal;
        cout << setprecision(2) << fixed << "\nTotal = $" << total << endl;
    }
    
    // THE FOR LOOP

    int c;

    for (c = 10; c >= 0; c--) {
        cout << c << endl;
    }

    for (c = 1; c <= 100; c++) {
        cout << c << " " << sqrt(c) << " " << sin(c) << endl;
    }

    // use a nested for loop to display the following
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4

    cout << endl;

    for (int row = 1; row <= 3; row++) {
        for (int col = 1; col <= 4; col++) {
            cout << setw(4) << col;
        }
        cout << endl;
    }


    //TEST scores 
    double score, sum;
    int num_students, num_tests;

    cout << "Enter the number of students: ";
    cin >> num_students;

    cout << "Enter the number of tests: ";
    cin >> num_tests;

    cout << setprecision(1) << fixed;

    for (int student = 1; student <= num_students; student++) {
        cout << "\nStudent " << student << endl;
        cout << "Enter the score for the following test:\n";

        sum = 0;
        for (int test = 1; test <= num_tests; test++) {
            cout << "Test " << test << ": ";
            cin >> score;

            sum += score;
        }

        cout << "The average for student " << student << " is " << sum / num_tests << endl;
    }




    // Writing to a Text File

    ofstream outputFile;
    outputFile.open("data.txt");

    outputFile << "John Henry Taylor\n";
    outputFile << "123 Main St.\n";
    outputFile << "Columbus, OH 21358\n\n";

    outputFile << "Susan J. Williams\n";
    outputFile << "459 Oakdale Lane\n";
    outputFile << "Memphis, TN 54124\n";

    outputFile.close();

    // Reading from a Text File

    ifstream infile;
    infile.open("data.txt");

    string name, address, city_state_zip, blank_line;

    while (getline(infile, name)) {
        getline(infile, address);
        getline(infile, city_state_zip);
        getline(infile, blank_line);

        cout << name << endl
            << address << endl
            << city_state_zip << endl << endl;
    }

    infile.close();

    return 0;
}