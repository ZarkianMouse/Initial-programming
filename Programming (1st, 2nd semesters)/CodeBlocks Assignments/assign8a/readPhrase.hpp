#ifndef READPHRASE_HPP_INCLUDED
#define READPHRASE_HPP_INCLUDED

// readPhrase function reads lines of text from
// input file to phrase string
// precondition: is passed input file and string
//               for phrase storage by reference
// postcondition: reads text into string
//                returns nothing
void readPhrase(std::ifstream& input, std::string& phrase)
{
    getline(input, phrase);
    std::cout << "English: " << phrase << std::endl;
    return;
}

#endif // READPHRASE_HPP_INCLUDED
