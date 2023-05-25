/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2022 Ali Alwan <aalwan99@aalwan99-XPS-15-9570>
 * 
 * wordle is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * wordle is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <sstream>  
#include <list>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	string wordsArray[367]; //You need to specify the type of array
	string wordsArray2[12845];
	ifstream legalWords;
	legalWords.open("testlist.txt");
	if (!legalWords) //test if file is open
	{
		cout << "error opening words file." << endl;
                //no need for a break here, after the program prints, it will leave these brackets.
	}

	int index = 0; //counter

	while (getline(legalWords, wordsArray[index]))
	{
		getline(legalWords, wordsArray[index]);
		//cout << wordsArray[index]<<endl;
	    index++; 
                //if you put index++ before the print, you are trying to print the non-existent
                // next word that you have not stored yet.
	}
	legalWords.close();//close the file



	int x = 0;
	string word = "";
	string line = wordsArray[0];
	for(int j = 0; j < 12479*6-6; j++)
	{
		if(line[j] == ' ')
		{
			wordsArray2[x] = word;
			word = "";
			x++;
		}
		else
		{
			word += line[j];
		}
	}
	wordsArray2[x] = word;


	list<string> myList = list<string>(begin(wordsArray2),end(wordsArray2));

	string guess = "";
	
	cout << "Enter the guessed word:" << endl;
	cin >> guess;

	if(guess.length() != 5 && guess != "exit")
	{
		while(guess.length() != 5)
		{
			cout << "Invalid entry. Try again." << endl;
			cout << "Enter the guessed word:" << endl;
			cin >> guess;
		}
	}

	while(guess != "exit")
	{

		string status[5];
		string color = "";
		cout << "\nWhat is the color for the letter " << guess[0] << ": ";
		cin >> color;
		status[0] = color;

		cout << "What is the color for the letter " << guess[1] << ": ";
		cin >> color;
		status[1] = color;

		cout << "What is the color for the letter " << guess[2] << ": ";
		cin >> color;
		status[2] = color;

		cout << "What is the color for the letter " << guess[3] << ": ";
		cin >> color;
		status[3] = color;

		cout << "What is the color for the letter " << guess[4] << ": ";
		cin >> color;
		status[4] = color;

		                     
		
		for(int i = 0; i < 5; i++)
		{
			if(status[i] == "gray")
			{
				for(int j = 0; j < 12478; j++)
				{
					if(wordsArray2[j].at(0) == guess[i] || wordsArray2[j].at(1) == guess[i] || wordsArray2[j].at(2) == guess[i] || wordsArray2[j].at(3) == guess[i] || wordsArray2[j].at(4) == guess[i])  
					{
						myList.remove(wordsArray2[j]);
					}
				}
			}
			if(status[i] == "yellow")
			{
				for(int j = 0; j < 12478; j++)
				{
					if(wordsArray2[j].at(0) != guess[i] && wordsArray2[j].at(1) != guess[i] && wordsArray2[j].at(2) != guess[i] && wordsArray2[j].at(3) != guess[i] && wordsArray2[j].at(4) != guess[i] || wordsArray2[j].at(i) == guess[i])  
					{
						myList.remove(wordsArray2[j]);
					}
				}
			}
			if(status[i] == "green")
			{
				for(int j = 0; j < 12478; j++)
				{
					if(wordsArray2[j].at(i) != guess[i])  
					{
						myList.remove(wordsArray2[j]);
					}
				}
			}
		}

		for(int i=0;i<368;i++)
			myList.remove("");

		for (auto v : myList)
		    cout << v << "\n";

		cout << "\n\nEnter the guessed word:" << endl;
		cin >> guess;

		if(guess.length() != 5 && guess != "exit")
		{
			while(guess.length() != 5)
			{
				cout << "Invalid entry. Try again." << endl;
				cout << "Enter the guessed word:" << endl;
				cin >> guess;
			}
		}
	}
	
	return 0;
}

