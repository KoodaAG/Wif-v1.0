#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <ShlObj.h> // Background Wallpaper Changing Header

// #pragma comment(lib, "Shell32.dll") // Bind Background Wallpaper Changing Library

void DisplayMenu();
void ChangeBackground();
void Calculate();
void Editor();

int main()
{
	DisplayMenu();

	return 0;
}

void DisplayMenu()
{
	short menuSwitch = 0;

	std::cout << "----------------------Main Menu-------------------------" << std::endl;
	std::cout << "-[1] Change Background                                 -" << std::endl;
	std::cout << "-[2] Calculate                                         -" << std::endl;
	std::cout << "-[3] Editor                                            -" << std::endl;
	std::cout << "-[4] Exit Program                                      -" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	while (menuSwitch <= 0 || menuSwitch > 4)
	{
		std::cout << "Your Choice: ";
		std::cin >> menuSwitch;
		std::cin.sync();
		std::cin.clear();
	}

	system("cls"); // Clear the screen

	switch (menuSwitch)
	{
	case 1: ChangeBackground(); break;
	case 2: Calculate();        break;
	case 3:	Editor();		    break;
	case 4:					    break;
	}
}

void ChangeBackground()
{
	char backgroundFileName[60];

	std::cout << "----------------------Background Wallpaper Changing-------------------------" << std::endl;
	std::cout << "-DON'T FORGET TO ADD THE ENDING OF YOUR FILE (FOR EXAMPLE (FILE.[JPG]))    -" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	system("ls");

	std::cout << "JPG/PNG FILE NAME: ";
	std::cin >> backgroundFileName;

	std::cin.sync();
	std::cin.clear();

	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (PVOID)&backgroundFileName, SPIF_SENDCHANGE);

	system("cls"); // Clear the screen
	DisplayMenu(); // Move back to Main Menu
}

void Calculate()
{
	int operationSum = 0;
	short menuSwitch = 0;
	int value1 = 0;
	int value2 = 0;

	std::cout << "--------------------Calculate-------------------" << std::endl;
	std::cout << "-[1]Add                                        -" << std::endl;
	std::cout << "-[2]Sub                                        -" << std::endl;
	std::cout << "-[3]Div                                        -" << std::endl;
	std::cout << "-[4]Mul                                        -" << std::endl;
	std::cout << "-[9]Exit                                       -" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	while (menuSwitch != 9)
	{
		std::cout << "Your Choice:";
		std::cin >> menuSwitch;
		std::cin.sync();
		std::cin.clear();

		if (menuSwitch != 9)
		{
			std::cout << "Value 1:";
			std::cin >> value1;
			std::cin.sync();
			std::cin.clear();
			std::cout << "Value 2:";
			std::cin >> value2;
			std::cin.sync();
			std::cin.clear();
		}

		switch (menuSwitch)
		{
		case 1: operationSum = (value1 + value2); break;
		case 2: operationSum = (value1 - value2); break;
		case 3: operationSum = (value1 * value2); break;
		case 4: operationSum = (value1 / value2); break;
		default: break;
		}

		if      (menuSwitch == 1) std::cout << "Operation Sum Value = " << operationSum << std::endl;
		else if (menuSwitch == 2) std::cout << "Operation Sub Value = " << operationSum << std::endl;
		else if (menuSwitch == 3) std::cout << "Operation Div Value = " << operationSum << std::endl;
		else if (menuSwitch == 4) std::cout << "Operation Mul Value = " << operationSum << std::endl;
	}

	system("cls"); // Clear the screen
	DisplayMenu(); // Move to Main Menu
}

void Editor()
{
	std::fstream editorFile("Editor.txt");

	if (!editorFile)
	{
		editorFile.clear();
		editorFile.close();

		std::ofstream editorFileCreate("Editor.txt");
		editorFileCreate.flush();
		editorFileCreate.close();
		editorFile.open("Editor.txt");
	}

	std::vector<std::string> editorLines;
	std::string editorText;

	std::cout << "---------------------------Editor---------------------------" << std::endl;
	std::cout << "-[1] Display Content                                       -" << std::endl;
	std::cout << "-[2] Write                                                 -" << std::endl;
	std::cout << "-[3] Exit                                                  -" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;

	int menuSwitch = 0;

	while (menuSwitch <= 0 || menuSwitch > 3)
	{
		std::cin.sync();
		std::cin.clear();
		std::cout << "Your choice:";
		std::cin >> menuSwitch;
	}

	system("cls");

	switch (menuSwitch)
	{
	case 1: // Display Content

		std::cout << "-------------------Display Content----------------------" << std::endl;

		while (std::getline(editorFile, editorText))
			editorLines.push_back(editorText);

		for (auto text : editorLines)
			std::cout << text << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "---------------NOTE-------------------" << std::endl;
		std::cout << "-PRESS A KEY TO LEAVE                -" << std::endl;
		std::cout << "--------------------------------------" << std::endl;

		std::cin.sync();	
		std::cin.ignore();
		std::cin.clear();
	
		std::cin.get();

		break;

	case 2: // Write
		
		std::cout << "-------------------Write-----------------------" << std::endl;
		std::cout << "-ENTER SOME INFORMATIONS                      -" << std::endl;
		std::cout << "-TYPE IN EXIT TO LEAVE                        -" << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;

		while (editorText != "EXIT")
		{
			std::cin.sync();
			std::cin.clear();
			std::cout << ":";
			std::getline(std::cin, editorText);
			editorLines.push_back(editorText);
		}

		for (auto text : editorLines)
			editorFile << text << std::endl;

		editorFile.flush();
		editorFile.close();

		break;
	case 3: break;
	}


	system("cls"); // Clear screen
	DisplayMenu(); // Move to Main Menu
}
