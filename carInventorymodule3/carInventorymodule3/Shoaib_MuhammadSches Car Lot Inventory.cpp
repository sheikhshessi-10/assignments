/*
    Project: Car Lot Inventory
    Programmer: Muhammad Sches Shoaib
    Date: 28 september
    Description: This program loads car inventory data from a file
                 allows the user to search for a car by inventory number
                 and displays the car's details.gives user the option to do so using binary search or linear search
*/

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>

using namespace std;

// Function declarations
void getData(string[], string[], int[], double[], int&);
void processUserSelections(string[], string[], int[], double[], int);
void displayResults(string[], string[], int[], double[], int);
int linearSearch(string[], int, string);

int main() {
    system("color f0");  // Set the console background and text color

    const int size = 40;  // The file contains data for 40 cars could be something else as well just needed to declare array
    string inventoryNumber[size];
    string description[size];
    int mileage[size];
    double listPrice[size];
    int totalCars = 0;

    //reading and stroing in parallel arrays
    getData(inventoryNumber, description, mileage, listPrice, totalCars);

    // Process user selections and calls linear search
    processUserSelections(inventoryNumber, description, mileage, listPrice, totalCars);

    return 0;
}

// Function to load car data by opening the file and then storing into parallel arrays
void getData(string inventoryNumber[], string description[], int mileage[], double listPrice[], int& totalCars) {
    ifstream inputFile("inventory.txt");  // Open the file 

    if (inputFile.fail()) {  // Check to see file opened correctly
        cout << "Error reading the file!" << endl;
        system("pause");
        return;
    }

    string line;
    int index = 0;
    while (getline(inputFile, inventoryNumber[index])) {  // read inventory numbe
        getline(inputFile, description[index]);  //Read descrption
        getline(inputFile, line);
        mileage[index] = atoi(line.c_str());  // convert string to int for mileage
        getline(inputFile, line);
        listPrice[index] = atof(line.c_str());  //convert string to double for price
        index++;
    }
    totalCars = index;  //Update total car after readng
    inputFile.close();  //Closing the file
}

// Function to handle user input and call linear search
void processUserSelections(string inventoryNumber[], string description[], int mileage[], double listPrice[], int totalCars) {
    string inventory_number;  // Variable to store user input 

    do {
        system("cls");  // Clear the screen using cls
        cout << "Enter the inventory number (or q to quit): ";  // ask the user
        getline(cin, inventory_number);

        // If the user enters 'q' or 'Q', exit the loop
        if (inventory_number != "q" && inventory_number != "Q") {
            int position = linearSearch(inventoryNumber, totalCars, inventory_number);  // Perform linear search 

            if (position >= 0) {
                displayResults(inventoryNumber, description, mileage, listPrice, position);  // Display car details
            }
            else {
                cout << "Inventory number not found!" << endl;  // If inventory numberis not found
            }
        }

    } while (inventory_number != "q" && inventory_number != "Q");  // Continue until Q or q
}

// Function to display car details
void displayResults(string inventoryNumber[], string description[], int mileage[], double listPrice[], int position) {
    // Format output to display the price as in the doc
    cout << setprecision(2) << fixed;
    cout << "\nInventory Number:  " << inventoryNumber[position] << endl
        << "Description:       " << description[position] << endl
        << "Mileage:           " << mileage[position] << " miles" << endl
        << "List Price:        $" << listPrice[position] << endl;
}

// Linear search function to find inventory number
int linearSearch(string array[], int size, string value) {
    for (int index = 0; index < size; index++) {
        if (array[index] == value) {  // Return index if inventory num  found
            return index;
        }
    }
    return -1;  // 
}
