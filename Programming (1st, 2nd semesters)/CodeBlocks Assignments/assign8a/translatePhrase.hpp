#ifndef TRANSLATEPHRASE_HPP_INCLUDED
#define TRANSLATEPHRASE_HPP_INCLUDED

// translatePhrase is used to update new phrase to its
// Pig Latin counterpart
// preconditions: is passed old phrase and new phrase variables
// postcondition: translates new phrase to Pig Latin
//                returns nothing
using std::string;
void translatePhrase(string oldPhrase, string& newPhrase)
{
    // variables for translation
    string phraseHold = oldPhrase;
    int position = 0;
    string word;
    int posHold = 0;
    string phrase;

    // loop for translating words one by one and updating
    // new phrase variable
    while (position != -1)
    {
        // for finding individual words
        position = phraseHold.find_first_of(' ');
        word = phraseHold.substr(posHold, position);
        // updates words to Pig Latin
        word = word.substr((posHold + 1), position) + word.substr(posHold, 1) + "ay";

        // for creating updated phrase
        if (phraseHold == oldPhrase)     // occurs at initial word translation
            newPhrase = newPhrase + word;
        else                             // occurs for all other words in phrase
            newPhrase = newPhrase + " " + word;

        // if there are no more words in phrase, function ends
        if (position == -1)
            return;

        // otherwise, the phrase needing to be translated is updated
        // and the process begins again
        else
        {
            posHold = position + 1;
            phrase = phraseHold.substr(posHold);
            phraseHold = phrase;
            posHold = 0;
        }
    }
}


#endif // TRANSLATEPHRASE_HPP_INCLUDED
