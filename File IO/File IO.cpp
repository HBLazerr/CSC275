// File I/O
//Daniel Chavez

// Libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    string line;
    ifstream infile("Operators_List.txt");
    ofstream outfile("outputdocument.txt");
    system("pause");

    if (infile.is_open())
    {
        if (outfile.is_open())
        {
            while (getline(infile, line))
            {
                cout << line << endl;
                outfile << line << "\n";
            }
            infile.close();
            outfile.close();
        } //end of if outfile
        else cout << "Unable to open output file." << endl;

    } //end of if infile
    else cout << "Unable to open input file." << endl;
    system("pause");
    
    return 0;
}