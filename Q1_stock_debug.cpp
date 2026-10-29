/*
 * Name       : Ayesha Qaisar
 * Reg No     : L1S26BSCS0110
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
#include <fstream> // FIX 1:<fstream> was missing, so ifstream and ofstream were unknown.
using namespace std;

int main() {
    ifstream inFile("stock.txt");
    if (!inFile)// FIX 2: Added ! because we need to check if the file did not open.
     {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

ofstream reorder("reorder.txt", ios::app); // FIX 3: Used ios::app so the old data in the file is not deleted.

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    double total = 0;// FIX 4: Used double because the total can contain decimal values.


inFile.ignore(100, '\n');// FIX 5: The first line is a heading, so it must be skipped.

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            reorder << code << " " << qty<<endl; // FIX 6: Added endl so each item is written on a new line.
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}
