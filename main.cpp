#include "includes.h"
#include "trim.h"
#include "consoleColor.h"


// programs (COSC 1336)
// contains the code for programs 8-15
// run the app, then select the program desired via keyboard input

// goto line 078 for program 8
// goto line 109 for program 9a
// goto line 136 for program 9b
// goto line 162 for program 10
// goto line 171 for program 11
// goto line 187 for program 12a
// goto line 206 for program 12b
// goto line 243 for program 13
// goto line 333 for program 14, line 45 for book print function
// goto line 501 for program 15, line 520 for 15f1, line 529 for 15f2, line 543 for 15f3


std::vector<uint32_t> bookIDManifest;

struct book {
public:
	uint32_t id;
	std::string title;
	std::string author;
	uint16_t occurences;

	book(std::string iTitle, std::string iAuthor, uint16_t iOccurences)
		: title(std::move(iTitle)), author(std::move(iAuthor)), occurences(std::move(iOccurences)) {

		if (bookIDManifest.size() != 0) { bookIDManifest.push_back(bookIDManifest.back() + 1); }
		else { bookIDManifest.push_back(0); }

		id = bookIDManifest.back();
		isValid = true;
	}
	// constructor
	// casts the input variables into the member variables, 
	// adds its ID to the ID manifest (i don't know why i did this, maybe it'll be faster to iterate through i guess?), 
	// then sets it's isValid variable to true

	void printInfo() {
		if (!isValid) { std::cout << "Object is not valid. Aborting the print.\n\n"; return; }
		for (uint16_t i = 0; i < occurences; i++) {
			std::cout << id << " : {" << title << "} by " << author << ", volume " << (i + 1) << " of " << occurences;
			std::cout << "\n";
		}
		std::cout << "\n\n";
	}
	// prints the member variables
	// prints an individual line for each occurrence
	// will not print through occurrences if the obeject is invalid

private:
	bool isValid = false;
};

std::vector<book> bookManifest;

class programList {
public:
	void all() {
		programEight();
		programNineA();
		programNineB();
		programTen();
		programEleven();
		programTwelveA();
		programTwelveB();
		programThirteen();
		programFourteen();
		programFifteen();
	}
	
	void programEight() {
		std::cout << "\n\nProgram Eight\n\n";
		
		double inputOne, inputTwo;
		bool stopValue = true;
		std::string stopInput;
		// declarations

		while(stopValue) {
			std::cout << "Input the first number: ";
			std::cin >> inputOne;

			std::cout << "Input the second number: ";
			std::cin >> inputTwo;
			// take input variables

			std::cout << "\n";

			if (inputOne == inputTwo) {std::cout << "Numbers are equal" << std::endl;}
			else if (inputOne > inputTwo) {std::cout << "First is larger" << std::endl;}
			else {std::cout << "Second is larger" << std::endl;}

			std::cout << "Continue (y/n)? ";
			std::cin >> stopInput;

			if (stopInput == "n") {stopValue = false;}
		}
		// if-else chain for logic, to decide which is larger, or, if they're both equal, and a while loop to allow for continuation
	}
	// input 2 numbers, prints the size relationship

	void programNineA() {
		std::cout << "\n\nProgram Nine-A\n\n";

		uint32_t employeeID;
		uint16_t itemsSold;
		uint64_t totalValueOfItemsSold;

		std::cout << "Input employee ID: ";
		std::cin >> employeeID;

		std::cout << "Input number of items sold by employee in the last month: ";
		std::cin >> itemsSold;

		std::cout << "Input total value of items sold by employee: ";
		std::cin >> totalValueOfItemsSold;

		std::cout << "\n";

		if (itemsSold > 200) {
			std::cout << "Employee " << std::to_string(employeeID) << " is a high performer. " << std::endl;
			std::cout << "Number of items sold: " << std::to_string(itemsSold) << std::endl;
			std::cout << "Total value of sold items: " << std::to_string(totalValueOfItemsSold) << std::endl;
		}
	}
	// takes in an employee ID, an amount of items sold by said employee in the last month, and the total value of the items sold,
	// and outputs a data message only if the amount of items sold is greater than 200

	void programNineB() {
		std::cout << "\n\nProgram Nine-B\n\n";

		uint32_t employeeID;
		uint16_t itemsSold;
		uint64_t totalValueOfItemsSold;

		std::cout << "Input employee ID: ";
		std::cin >> employeeID;

		std::cout << "Input number of items sold by employee in the last month: ";
		std::cin >> itemsSold;

		std::cout << "Input total value of items sold by employee: ";
		std::cin >> totalValueOfItemsSold;

		std::cout << "\n";

		if (itemsSold > 200 && totalValueOfItemsSold >= 1000) {
			std::cout << "Employee " << std::to_string(employeeID) << " is a high performer. " << std::endl;
			std::cout << "Number of items sold: " << std::to_string(itemsSold) << std::endl;
			std::cout << "Total value of sold items: $" << std::to_string(totalValueOfItemsSold) << std::endl;
		}
	}
	// same as above (programNineA), except in addition to the items sold, a minimum value of 1000 is required in order to display the data message

	void programTen() {
		std::cout << "\n\nProgram Ten\n\n";

		for (uint8_t outputNumber = 1; outputNumber <= 200; outputNumber++) {
			if (outputNumber % 2 == 0) std::cout << std::to_string(outputNumber) << std::endl;
		}
	}
	// prints every even number between 1 and 200

	void programEleven() {
		std::cout << "\n\nProgram Eleven\n\n";

		uint64_t inputNumber, outputNumber = 0;

		std::cout << "Input a number: ";
		std::cin >> inputNumber;

		for (uint64_t i = 0; i <= inputNumber; i++) {
			outputNumber += i;
		}

		std::cout << outputNumber;
	}
	// prints the sum of all numbers less than or equal to the input

	void programTwelveA() {
		std::cout << "\n\nProgram Twelve-A\n\n";

		int classNumber; std::string input;

		std::string classes[6] = { "", "Yoga 1", "Yoga 2", "Children's Yoga", "Prenatal Yoga", "Senior Yoga" };
		std::cout << "Input a class number: ";
		std::cin >> input;

		classNumber = std::stoi(input);

		std::cout << "\n";

		std::cout << "Class is: " << classes[classNumber] << std::endl;
	}
	// prints a class name based on a given class number 
	// (i used a small trick for the class array, making index zero a null value, so I could directly use the input)
	// gosh i wish i could've used a map for this

	void programTwelveB() {
		std::cout << "\n\nProgram Twelve-B\n\n";

		uint8_t classNumber; // max value 255, set to 0 to exit program
		std::string input;

		std::string classes[6] = { "", "Yoga 1", "Yoga 2", "Children's Yoga", "Prenatal Yoga", "Senior Yoga" };
		uint64_t classRequests[6] = { 0, 0, 0, 0, 0, 0 }; // 1.8e19 max value

			do {
				std::cout << "Input a class number (or 0 to exit): ";
				std::cin >> input;
				
				
				try {
					classNumber = std::stoi(input);
				}
				catch (...) {
					std::cout << "non-integer character in input\n";
					std::cout << "input: {" << input << "}\n";
					std::cout << "re-starting\n\n";
					continue;
				}
				std::cout << "\n";

				if (classNumber > 5) { std::cout << "Class doesn't exist. Re-starting...\n\n"; continue; }

				if (classNumber != 0 && classNumber <= 6) { std::cout << "Class is: " << classes[classNumber] << "\n\n"; }
				classRequests[classNumber]++;
			} while (classNumber != 0);

			for (uint8_t i = 1; i < 6; i++) {
				std::cout << i << " : " << classes[i] << " : " << classRequests[i] << " request(s)" << std::endl;
			}
	}
	// same as above (programTwelveA) except allows user to input a sentinel value (255) to exit

	void programThirteen() {
		std::cout << "\n\nProgram Thirteen\n\n";

		std::string employeeName;
		double hrlyWage;
		int hrsWorked;
		std::string input;

		float witholding;

		double grossPay, wthldTax, netPay;

		double totals[4] = {0, 0, 0, 0}; // i0: hrs worked, i1: gross payroll, i2: witholding, i3: net payroll

		while (true) {
			employeeName = "";
			hrlyWage = 0.00;
			hrsWorked = 0;
			grossPay = 0.00, witholding = 0.00, wthldTax = 0.00, netPay = 0.00;
			
			
			std::cout << "Input an employee name (or 'EXIT' to exit): ";
			std::cin >> input;

			std::cout << "\n\n";

			if (input == "EXIT") { break; }

			employeeName = input;
			input.clear();

			std::cout << "Input their hourly wage: ";
			std::cin >> input;

			std::cout << "\n\n";

			hrlyWage = std::stof(input);
			input.clear();

			std::cout << "Input their hours worked: ";
			std::cin >> input;

			std::cout << "\n\n";

			hrsWorked = std::stoi(input);
			input.clear();

			grossPay = hrlyWage * hrsWorked;

			if (grossPay > 800.01) { witholding = 0.2; }
			else if (grossPay > 550.01) { witholding = 0.16; }
			else if (grossPay > 300.01) { witholding = 0.13; }
			else if (grossPay > 0.00) { witholding = 0.1; }

			wthldTax = grossPay * witholding;
			netPay = grossPay - wthldTax;

			std::cout << employeeName << ":\n";
			std::cout << "Hours worked: " << hrsWorked << " | Hourly rate: $" << hrlyWage << "/hr\n";
			std::cout << "Gross pay: $" << grossPay << " | Witholding Percentage: "
				<< std::to_string((witholding * 100)) << "% | Witheld amount: $" << wthldTax << "\n";
			std::cout << "Net pay: $" << netPay << "\n";

			totals[0] += hrsWorked; totals[1] += grossPay; totals[2] += wthldTax; totals[3] += netPay;

			std::cout << "\n\n";
			
		}

		std::cout << "Total amounts:\n";
		std::cout << "Hours worked by all employees: " << totals[0] << "\n";
		std::cout << "Gross payroll: $" << totals[1] << "\n";
		std::cout << "Total witholding: $" << totals[2] << "\n";
		std::cout << "Total net payroll: $" << totals[3] << "\n";

		/*
		wkly gross pay|witholding %
		0.00-300.00    10
		300.01-550.00  13
		550.01-800.00  16
		> 800.01       20

		grossPay = hrsWorked * hrlyWage
		witholding tax percentage in table above

		*/

	}
	// payroll one

	void programFourteen() {
		std::cout << "\n\nProgram Fourteen\n\n";
		int lineNumber = 0;
		// initializes the lineNumber iterator variable (i guess you would call it a sentinel?)

		std::ifstream inputFile("PendantPublishing.txt", std::ifstream::in);
		// opens the input file (in this case, PendantPublishing.txt)

		while (!inputFile.eof()) {
			
			std::string line, charList;
			std::string author, title = "";
			unsigned int occurences = 1; int section = 0; 
			// initializes the book member variable inputs

			std::getline(inputFile, line);
#ifdef _DEBUG
			outputColoredText("\nLine number: {" + std::to_string(lineNumber) + "}\n", "debug");
#endif
			// gets a line from the file

			for (unsigned int i = 0; i < line.size(); i++) {
#ifdef _DEBUG
				outputColoredText(std::to_string(lineNumber) + " : " + std::to_string(section) + " : " + std::to_string(i) + " : "+line[i]+" : DEBUG\n", "debug");
#endif
				// for debug only: displays the line number, section, index, and then character 

				if (line.at(i) == (',') || i == line.size() - 1) {
#ifdef _DEBUG
					outputColoredText(std::to_string(lineNumber) + " : " + std::to_string(section) + " : " + std::to_string(i) + " : encountered comma/newline, attempting to assign to variable...", "debug");
					outputColoredText(("\n" + std::to_string(lineNumber) + " : " + std::to_string(section) + " : " + std::to_string(i) + " : DEBUG: END OF LINE T?F : " + std::to_string((i == line.size() - 1))), "debug");
#endif
					std::cout << "\n\n";
					// for debug: displays when an end of section character is found

					if (i == line.size() - 1) { charList.push_back(line[i]); }
					// if the character is at the end of the line and not a comma, adds it to the charList string

					switch (section) {
					case 0:
					// case 0 means the current section is the first, or author, section.
					// this case casts the current charList string to the author variable

						try {
							if (section == 0) {
								author = trimCopy(charList);
#ifdef _DEBUG
								outputColoredText(std::to_string(lineNumber) + " : " + std::to_string(section) + " : " + std::to_string(i) + " : Author: "+author+"\n", "debug");
#endif
								if (author == "") { throw 200; }
								section++; 
								charList = "";
								continue;
							}
						}
						catch (...) {
							std::cout << lineNumber << " : " << section << " : " << i << " : author str=>str cast failed. " 
								<< "\nString to be cast: {" << charList << "}\n"
								<< lineNumber << " : " << section << " : " << i << " : Line: {" << line << "}\n\n";
						}
						// exception catch
						break;

					case 1:
					// case 1 means that the current section is the second, or title, section.
					// this case casts the current charList string to the title variable

						try {
							title = trimCopy(charList);
#ifdef _DEBUG
							outputColoredText(std::to_string(lineNumber) + " : " + std::to_string(section) + " : " + std::to_string(i) + " : Title: " + title + "\n", "debug");
#endif
							if (title == "") { throw 201; }
							section++; 
							charList = "";
							continue;
						}
						catch (...) {
							std::cout << lineNumber << " : " << section << " : " << i << " : title str=>str cast failed. ";
							std::cout << "String to be cast: {" << charList << "}\n";
							std::cout << lineNumber << " : " << section << " : " << i << " : Line: {" << line << "}\n\n";
						}
						break;

					case 2:
					// as you might be able to tell, i was having issues with this section...
					// case 2 means that the current section is the third, or occurence, section.
					// this case casts the current charList string to the occurences variabe, after some processing

					/* EDIT FOR ABOVE COMMENTS : Found possible solution to issue:
					* when the loop iterates, it checks to see if the current index is a comma, or the last char in the line
					* however, if the char is the last in the line, it would forgo pushing it to the back of the string, 
					* since that code is in the else statement that executes if the index isn't a comma or EOL.
					* noticing this using my debug cout statements, I added another push_back() that executes in the if statement
					* only if the index is the EOL. This was implemented while debugging the below trim loop, so I'm unsure of which 
					* fixed the issue. 
					*/ 
					// TODO: check and see if that fixed the issue

							try {
								while (charList.front() == ' ' || charList.back() == ' ') {
									if (charList.front() == ' ') {
										ltrim(charList);
									}
									if (charList.back() == ' ') {
										rtrim(charList);
									}
								}
								// issue was here. for some reason, my trim() function refused to properly trim the string, so i instead did... that

								occurences = std::stoi(charList);
#ifdef _DEBUG
								outputColoredText(std::to_string(lineNumber) + " : " + std::to_string(section) + " : " + std::to_string(i) + " : Occurences: " + std::to_string(occurences) + "\n", "debug");
#endif
								if (occurences == 0) { throw 202; }
								section++; 
								charList = "";
								continue;
							}
							catch (...) {
									std::cout << lineNumber << " : " << section << " : " << i << " : Occurrences str=>int conversion failed. ";
									std::cout << "String to be converted: {" << charList << "}\n";
									std::cout << lineNumber << " : " << section << " : " << i << " : Line: {" << line << "}\n\n";
							}
						
						break;

					default:

						std::cout << lineNumber << " : " << section << " : Section out of bounds. Skipping to next loop iteration.\n";
						continue;

						break;
					}
					// i was having issues with this switch statement, so I added if statements inside of it to verify the numbers
					// EDIT FOR ABOVE COMMENT: Found the issue. switch statements need break; at the end, or else they will iterate outside of their cases.
					// this switch statement contains cases that decide which variable to cast the current charList string to
				}
				else { charList.push_back(line[i]); }
				// adds the character to the charList
				
			}

			bookManifest.emplace_back(title, author, occurences);
			// instantiates a book object in the bookManifest vector with the information taken from the line

			section = 0;
			author = "";
			title = "";
			occurences = 0;
			// clears variables

			lineNumber++;
			// iterates lineNumber

		}

		std::cout << "\n\n";

		for (unsigned int i = 0; i < bookManifest.size(); i++) {
			bookManifest[i].printInfo();
		}
		// prints the info for every book type
		inputFile.close();
	}
	// uses the book struct, along with the bookManifest and bookIDManifest vectors to print information on books in a text file
	// allows for an arbitrary number of books (this took a lot of work)

	void programFifteen() {
		std::cout << "\n\nProgramFifteen\n\n";

		programFifteenFunctionsList functions;

		int input;

		std::cout << "Input a number: ";
		std::cin >> input;

		functions.displayAllNumbers(input);
		std::cout << functions.sumAllNumbers(input) << "\n\n";
		std::cout << functions.multiplyAllNumbers(input) << "\n\n";

	}
	// functions one

private:
	struct programFifteenFunctionsList {
		void displayAllNumbers(int input) {
			std::cout << "\n\nDisplay numbers < " << input << "\n\n";

			for (input; input > 0; input--) {
				std::cout << input << std::endl;
			}

			return;
		}
		int sumAllNumbers(int input) {
			std::cout << "\n\nCalculating sum of all numbers < " << input << "\n\n";

			int sum = 0;

			for (int i = 1; i <= input; i++) {
				sum += i;
#ifdef _DEBUG
				outputColoredText(("DEBUG: iteration "+std::to_string(i)+", current sum: "+std::to_string(sum)+"\n"), "debug");
#endif
			}

			return sum;
		}
		int multiplyAllNumbers(int input) {
			std::cout << "\n\nCalculating factorial of " << input << "\n\n";
			int output = 1;
			
			for (int i = 1; i <= input; i++) {
				output = output * i;
#ifdef _DEBUG
				outputColoredText(("DEBUG: iteration " + std::to_string(i) + ", current product: " + std::to_string(output) + "\n"), "debug");
#endif
			}
			

			return output;
		}
	};
};
// class containing all code for each program (besides the trim() function, that's in trim.h and trim.cpp)
// also the methods for the book struct are in the above struct declaration

programList programs;

int main() {
	int programChoice;
	std::string input;

	std::cout << "Choose a program (0 for all, 8-15 for individuals): ";
	std::cin >> input;

	programChoice = std::stoi(input);

	std::cout << "\n\n";

	switch (programChoice) {
		case 0:
			programs.all();
			break;

		case 8:
			programs.programEight();
			break;

		case 9: {
			char choiceAB;

			std::cout << "Which one (a/b)? ";
			std::cin >> choiceAB;
			std::cout << "\n";

			if (choiceAB == 'a') { programs.programNineA(); }
			else { programs.programNineA(); }
			break;
		}
		case 10:
			programs.programTen();
			break;

		case 11:
			programs.programEleven();
			break;

		case 12: {
			char choiceAB;

			std::cout << "Which one (a/b)? ";
			std::cin >> choiceAB;
			std::cout << "\n";

			if (choiceAB == 'a') { programs.programTwelveA(); }
			else { programs.programTwelveB(); }
			break;
		}
		case 13:
			programs.programThirteen();
			break;

		case 14:
			programs.programFourteen();
			break;

		case 15:
			programs.programFifteen();
			break;

		default:
			if (programChoice > 15) {
				std::cout << "\n\nprogram doesn't exist in this file.\n\n";
			}
			break;
	}

	std::cout << "\n\nCoded by Miles Leal\n\n" << std::endl;

	std::cout << "\n\nPress enter to exit.\n\n";
	std::cin >> input;
}