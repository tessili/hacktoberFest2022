/**************************************************************
Author Name     : MUHAMMED AYIMEN ABDUL LATHEEF
Register Number : 20419055
Roll no         : 08
Batch           : IT-B
Date            : 22-03-2021
Experiment      : Write a program to reverse a sentence using
                  recursion.
****************************************************************/
#include <iostream>
using namespace std;
void rev_sentence(char *s)
{
    if (*s != '\0')
    {
        rev_sentence(s + 1);
        cout << *s;
    }
    else
        return;
}
int main()
{
    cout << "****************************************************************";
    cout << "\nAuthor Name     : MUHAMMED AYIMEN ABDUL LATHEEF";
    cout << "\nRegister Number : 20419055";
    cout << "\nRoll no         : 08";
    cout << "\nBatch           : IT-B";
    cout << "\nDate            : 22-03-2021  ";
    cout << "\nExperiment      : Write a program to reverse a sentence using  ";
    cout << "\n                  recursion.";
    cout << "\n****************************************************************";
    char s[100];
    cout << "\nEnter the sentence: ";
    gets(s);
    cout << "\nReversed sentence: ";
    rev_sentence(s);
    return 0;
}