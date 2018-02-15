#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdio>

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::string;
using std::ifstream;
using std::ofstream;

const float RATE_INCREASE = .025;
// Function prototypes
void adjustSalary(ifstream &, ofstream &);
bool readFile(ifstream &);
bool writeFile(ofstream &, float &);
bool isValid(const string &);
void errorHandler(string, int, string, ifstream &, ofstream &);      // we can't pass by reference b/c we're using literals

int main()
{
  ifstream salaryFile;                       // create file input object
  ofstream newSalaryFile;                    // create file output object
  // notice we open the files and connect them to the names here, in the caller (main), as recommended
  salaryFile.open("salaries.txt");           // open the file and make the function's parameter an ifstream
  newSalaryFile.open("newsalaries.txt");     // open the file and make the function's parameter an ofstream
  if(readFile(salaryFile))
  {
    adjustSalary(salaryFile, newSalaryFile); // adjust salary will process the entire salary file
  }
  else
  {
    // PLACE ERROR HANDLING HERE (status TWO)
    string inputOffense = ("Corrupted File");
    int status = 2;
    string message = ("File Open Failure");
    errorHandler(inputOffense, status, message, salaryFile, newSalaryFile);
    return 0;

  }
  salaryFile.close();
  newSalaryFile.close();
  return 0;
}
//Precondition: valid open file with salary amount
//Postcondition: cost of living adjusted amount
//will be written to new salaries file
void adjustSalary(ifstream &salaryFile, ofstream &newSalaryFile)
{
  int validCount = 0;
  string stringAmount = " ";
  // notice that we are reading the file into a string, and not a float. You could read into a float, our variable amount.
  // the reason why we did this is because we can only see the invalid characters if it is a string, and we want them for
  // our error handling output (so the user knows what exactly was bad). ??? Ask about any of this anytime in class.
  while (!(salaryFile >> stringAmount).eof())        // avoids the isolated eof test from failure (as explained in our lectures)
  {
    float amount = 0.00;
    stringstream stringStreamAmount(stringAmount);  // The stringstream class: uses stream insertion operator
    stringStreamAmount >> amount;                   // stream string stream into the amount and convert the streamed string into a float

    if (!isValid(stringAmount))                     // is there an invalid value (non-numeric data) (status one)
    {
      string inputOffense = ("Invalid Input");
      int status = 1;
      string message = ("Non-numeric data entry");
      errorHandler(inputOffense, status, message, salaryFile, newSalaryFile);

    }
    else if (salaryFile.fail() && !salaryFile.eof())
    {
      // if fail bit was triggered here it may be more severe than invalid data
      // so we check the bad bit. If on, it's not a data issue and the stream should be considered unusable.
      if (salaryFile.bad())
      {
        string inputOffense = ("Corrupted File");
        int status = 2;
        string message = ("Corrupted File Stream: Now closing down for maintenance");
        errorHandler(inputOffense, status, message, salaryFile, newSalaryFile);
        return;
      }
      else
      {
        // handle the error, and need to clear the buffer and reset the flags (status ONE)
        string inputOffense = ("Invalid File Data");
        int status = 1;
        string message = ("Could not read input/fail bit failure. Recommencing sequence");
        errorHandler(inputOffense, status, message, salaryFile, newSalaryFile);

      }
    }
    else if (amount <= 0)                          // invalid amount error of zero or less (status ONE)
    {
        string inputOffense = ("Invalid Input");
        int status = 1;
        string message = ("Calculator not programmed for stable/decreasing salaries");
        errorHandler(inputOffense, status, message, salaryFile, newSalaryFile);
    }
    else if (amount > 999999.99)                   // invalid amount error over a million (status ONE)
    {
        string inputOffense = ("Invalid Input");
        int status = 1;
        string message = ("Salary increase of $1,000,000 or more is prohibited");
        errorHandler(inputOffense, status, message, salaryFile, newSalaryFile);
    }
    else                                           // trailing else ... everything was valid.
    {
      amount = amount + (amount * RATE_INCREASE);
      if (writeFile(newSalaryFile, amount))
      {
        cout << "New rate: " << std::right << std::setw(15) << std::fixed << std::setprecision(2) << amount << endl;
      }
      else  // write error to file (status TWO)
      {
         string inputOffense = ("Error to File");
         int status = 2;
         string message = ("Info could not be programmed to file");
         errorHandler(inputOffense, status, message, salaryFile, newSalaryFile);
         return;
      }
      validCount++;
    }
  }
  cout << "The number of valid salary adjustments made was: " << validCount << endl;
}
//***************************************************
// the read file function                           *
//***************************************************
//Precondition: opened file object is passed into this function
//Postcondition: The status of the file's disposition will be returned
bool readFile(ifstream &salaryFile)
{
  if (!salaryFile.is_open())
  {
    return false;
  }
  return true;
}
//***************************************************
// the write file function                           *
//***************************************************
//Precondition: opened file object is passed into this function and written to
//Postcondition: The status of the file's disposition will be returned
bool writeFile(ofstream &newSalaryFile, float &newAmt)
{
  newSalaryFile << newAmt << endl;  // writing to the output file
  if (!newSalaryFile.is_open())
  {
    return false;
  }
  return true;
}
//***************************************************
// the is valid function                           *
//***************************************************
//Precondition: a float or double is passed and converted to a string value
//Postcondition: The status of the float or double will be returned
// as bool (true or false), is it a numeric item or not
// this reads the string as an array and looks at each character, one by one
bool isValid(const string &str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if(!isdigit(str[i]) && str[i] != '.')
     {
       return false;
     }
   }
   return true;
}
//***************************************************
// the error handler function                       *
//***************************************************
//Precondition: an error message and an error status code
//Postcondition: The message will display to standard error
// the status code will determine if the program ends or returns
// The parameters are:
// 1) dataInfo is the data that caused the problem
//       - for amounts, use the stringAmount variable
//       - for files, use the name of the file
// 2) status is 1 or 2
// 3) message is a formatted, informative message
// 4) file is the input file for the program
// 5) outputFile is the output file for the program
void errorHandler(string dataInfo, int status, string message, ifstream& file, ofstream& outputFile)
{
   if (status == 1)
   {
        if (dataInfo == "Invalid Input")
        {
            std::cerr << message << endl;
            return;
        }
        else if (dataInfo == "Invalid Data Input")
        {
            std::cerr << message << endl;
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
   }
   else if (status == 2)
   {
       if (dataInfo == "Corrupted File")
       {
           std::cerr << message << endl;
           file.close();
           outputFile.close();
           return;
        }
        else if (dataInfo == "Error to File")
        {
            std::cerr << message << endl;
            file.close();
            outputFile.close();
            return;
        }
    }
}
