#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

vector<string> answers;

// function to check if a word contains only the specified letters
bool containsOnlyLetters(const std::string &word, const std::string &letters)
{
    // sort the word and letters
    std::string sortedWord = word;
    std::sort(sortedWord.begin(), sortedWord.end());

    std::string sortedLetters = letters;
    std::sort(sortedLetters.begin(), sortedLetters.end());

    // compare the sorted word and letters
    return sortedWord == sortedLetters;
}

// function to find words in a CSV file that contain only the specified letters
void findWordsInCsv(const std::string &filename, const std::string &letters)
{
    // set to keep track of printed words
    std::set<std::string> printed;

    // open the file
    std::ifstream file(filename);
    if (!file.is_open())
    {
        // display an error message if the file cannot be opened
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    // read each line in the file
    std::string line;
    while (std::getline(file, line))
    {
        // split the line into words
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            // check if the word contains only the specified letters and has not been printed already
            if (containsOnlyLetters(word, letters) && std::find(answers.begin(), answers.end(), word) == answers.end())
            {
                // add the word to the answers vector and mark it as printed
                answers.push_back(word);
            }
        }
    }

    // close the file
    file.close();
}

// class to generate words from a given word
class WordGenerator
{
public:
    int _length;

    WordGenerator(int length)
    {
        _length = length;
    }

    // function to generate words from a given word
    std::vector<std::string> generateWords(std::string word, int length)
    {
        std::vector<std::string> result;
        std::sort(word.begin(), word.end());

        do
        {
            // add substrings of the given length to the result vector
            for (int i = 0; i <= length; i++)
            {
                result.push_back(word.substr(i, length));
            }
        } while (std::next_permutation(word.begin(), word.end()));

        return result;
    }
};

// function to append a word to a CSV file
void append_to_csv(const string &filename, string word)
{
    // open the file in append mode
    ofstream file;
    file.open(filename, ios_base::app);

    // display an error message if the file cannot be opened
    if (!file)
    {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    // write the word to the file
    file << word << endl;
    file.close();
    cout << "The word has been added to file and will appear next time!";
}

// function to remove a word from a CSV file
void remove_word(string filename, string word_to_remove)
{

    // open the input and output files
    ifstream infile(filename);
    ofstream outfile("temp.csv");

    // read each line from the input file
    string line;
    while (getline(infile, line))
    {
        // if the line *(stripped of the newline character)* does not match the word to remove, write it to the output file
        if (line.substr(0, line.size()-1) != word_to_remove)
        {
            outfile << line << endl;
        }
    }

    // close the input and output files
    infile.close();
    outfile.close();

    // delete the old file and rename the temporary file to the old file's name
    remove(filename.c_str());
    rename("temp.csv", filename.c_str());

    // print a message to indicate that the word has been removed
    cout << "The word has been removed from the list";
}

int main()
{
    // initialize some variables
    string input;
    string append;
    int length;

    // greet the user and ask for the length of the word they want to find
    cout << "Welcome to the Word Unscrambler!";
    cout << "\nHow long is the word you need to find? (3-7): ";
    cin >> length;

    // ask for the letters the user has and generate all possible words
    cout << "\nEnter the letters you need to unscramble: ";
    cin >> input;
    WordGenerator gen(length);
    vector<string> words = gen.generateWords(input, length);

    // loop through all generated words
    for (string word : words)
    {
        // search for the word in a CSV file that contains words of the same length
        if (word.length() == length)
        {
            int l = length;
            stringstream ss;
            ss << "lists/length_" << l << ".csv";
            string file = ss.str();
            findWordsInCsv(file, word);
        }
    }

    // print out all the answers
    for (string answer : answers)
    {
        cout << answer << endl;
    }

    // ask the user if they want to append a new word to the list
    cout << "Are there any words that you found that were not included in this list? (Y/N): ";
    cin >> append;
    append[0] = toupper(append[0]);

    // if the user wants to append, ask for the word and append it to the appropriate CSV file
    if (append == "Y")
    {
        string add;
        cout << "\nPlease enter the word you would like to add to the list: ";
        cin >> add;

        int l = add.length();
        stringstream ss;
        ss << "lists/length_" << l << ".csv";
        string file = ss.str();
        append_to_csv(file, add);
    }

    // ask the user if they want to remove a word from the list
    string removeWord;
    cout << "\nAre there any words that you don't believe will be helpful in the future? (Y/N): ";
    cin >> removeWord;
    removeWord[0] = toupper(removeWord[0]);

    // if the user wants to remove a word, ask for the word and remove it from the appropriate CSV file
    if (removeWord == "Y")
    {
        string badWord;
        cout << "\nPlease enter the word you would like to remove from the list: ";
        cin >> badWord;

        int l = badWord.length();
        stringstream ss;
        ss << "lists/length_" << l << ".csv";
        string file = ss.str();
        remove_word(file, badWord);
    }
}
