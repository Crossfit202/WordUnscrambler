# Overview

This software is a C++ program that allows the user to specify a grouping of letters and seraches a group of CSV files that contain words based on their length. It then returns all of the words that can be made with those letters contained in the CSV files. This was my first program using the C++ language syntax. 

My purpose for writing this software is to further my learning as a software engineer and to gain more experience with the C++ programming language. This project allowed me to learn about C++ file I/O, string manipulation, and working with CSV files. I have always wanted to make this program to help me when I play WordScapes with my wife. It provided a great opportunity to discover another programming language that I was unfamiliar with.

[Software Demo Video](https://youtu.be/dSLM-TPXMI8)

# Development Environment

This software was developed using Visual Studio Code as the code editor. I used the C++ programming language and the following libraries:

iostream
fstream
string
vector
algorithm
csv-parser (third-party library)

# Useful Websites

A list of websites that I found helpful are as follows:

- [Word List CSV](https://www-personal.umich.edu/~jlawler/wordlist.html) 
This is where I downloaded my list of words. It was nearly 70,000 lines long and I was having issues with speed, so I wrote a program in Python to create files based on length and place the words in their respective files. 

- [Python Program](https://github.com/Crossfit202/WordUnscrambler/blob/master/listCreator.py)

- [W3Schools](https://www.w3schools.com/cpp/default.asp)

- [C++ Reference](https://en.cppreference.com/w/)



# Future Work

There are several improvements and features that I would like to add to this program in the future:

- Find a more comprehensive list of words and combine them with the lists I already have.
- Add error handling. (example; case-sensitive issues).
- Implement a graphical user interface to make the program more user-friendly.
- Reduce runtime. When you get up near 7 letters, it takes a while to process the list. I want to find a way to improve the speed of the program
- Add the functionatity of searching a dictionary CSV to get a word defined if you would like