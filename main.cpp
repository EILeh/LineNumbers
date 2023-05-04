/* Line Numbers
 *
 * Description
 *
 * Program reads a file and writes its' content to another file by adding a line
 * number in the beginning of every line. Program starts by asking the user to
 * give the name of the file that is read and then it ask the name of the file
 * where the text is written. If the input file can't be opened, the program
 * prints an error and program ends to a return value EXIT_FAILURE.
 *
 * Writer of the program
 *
 * Name: EILeh
 */


#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input_file = "";
    string output_file = "";

    cout << "Input file: ";
    getline(cin, input_file);

    cout << "Output file: ";
    getline(cin, output_file);

    ifstream file_object_i(input_file);


    if ( !file_object_i )
    {
        cout << "Error! The file " << input_file << " cannot be opened.";
        file_object_i.close();
        return EXIT_FAILURE;
    }

    else
    {
        ofstream file_object_o(output_file);
        string row;
        int row_number = 1;

        // Goes through every row in input file and writes the same line to the
        // output file but adds variable row_number before every line.
        while ( getline(file_object_i, row) )
        {
            file_object_o << row_number << " " << row << endl;
            row_number++;
        }


        file_object_i.close();
        file_object_o.close();
    }

    return EXIT_SUCCESS;
}
