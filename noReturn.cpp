// noReturn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// This is a text based game whatever you choose effects the player. Choose wisely...
// author: Victoria Guzman 

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
// defines 
#define WIN 0;
//protypes
//ints
int noReturnGame();
//voids
void printWelcome();
void goodbyeMessage();
void printRules();
void startTextBox();
void ChoiceOne();
void firstEffect(string);
void ChoiceTwo();
void finalChoice();
void secondEffectFlow(string);
void secondEffectGO(string);
void finalEffectZero(string);
void finalEffectOne(string);
void finalEffectTwo(string);
void finalEffectThree(string);
//bools
bool conformationCheck(string);
bool inputCheck(string);
// string 
string toLowerWord(string);
int main()
{
	// call to main gam function
	noReturnGame();
	return WIN;
}
int noReturnGame() {
	// varables 
	string welcomeAns,
		choiceOneAns,
		choiceTwoAns,
		finalAns;
	int lifeStat = 0;
	// calls welcome function
	printWelcome();
	cin >> welcomeAns;
	// checks the answer
	welcomeAns = toLowerWord(welcomeAns);
	// checks if it is other then yes...
	if (conformationCheck(welcomeAns) != true) {
		// if no present the goodbye
		goodbyeMessage();
	}
	// enters the loop
	while (conformationCheck(welcomeAns) == true) {
		printRules();// prints out rules
		startTextBox();// begins game
		
		ChoiceOne();
		cin >> choiceOneAns;
		// make the input all lowercase 
		choiceOneAns = toLowerWord(choiceOneAns);
		// checks if input is other than the choices
		while(inputCheck(choiceOneAns) != true) {
			cout << "PLease Re-enter: ";
			cin >> choiceOneAns;
			if (inputCheck(choiceOneAns) == true) {
				break;
			}
		}
		// takes in to present the correct text
		firstEffect(choiceOneAns);
		// sets the choices to a number of points 
		if (choiceOneAns == "flashlight"||choiceOneAns=="Flashlight") {
			lifeStat = 1;
			cout << "You gained: " << lifeStat << "  lifepoints.\n";
		}
		else if (choiceOneAns == "landline"||choiceOneAns=="Landline") {
			lifeStat = 0;
			cout << "You gained: " << lifeStat << " lifepoints. \n";
		}
		ChoiceTwo();
		cin >> choiceTwoAns;
		choiceTwoAns = toLowerWord(choiceTwoAns);
		// checks if input is other than the choices
		while(inputCheck(choiceTwoAns) != true) {
			cout << "Please Re-enter: ";
			cin >> choiceTwoAns;
			if (inputCheck(choiceTwoAns) == true) {
				break;
			}
		}
		// based on the lifepoints prints out the text box
		if (lifeStat <= 0) {
			secondEffectFlow(choiceTwoAns);
		}
		else if (lifeStat >= 1) {
			secondEffectGO(choiceTwoAns);
		}
		// sets the choices to a number of points 
		if (choiceTwoAns == "table") {
			lifeStat += 2;
			cout << "You gained: " << lifeStat << " lifepoints. \n";
		}
		else if (choiceTwoAns == "upstairs") {
			lifeStat += 0;
			cout << "You gained: " << lifeStat << " lifepoints. \n";
		}
		finalChoice();
		cin >> finalAns;
		finalAns = toLowerWord(finalAns);
		// checks if input is other than the choices
		while (inputCheck(finalAns) != true) {
			cout << "Please Re-enter: ";
			cin >> finalAns;
			if (inputCheck(finalAns) == true) {
				break;
			}
		}
		// based on the lifepoints prints out the text box
		if (lifeStat == 0) {
			finalEffectZero(finalAns);
		}
		else if (lifeStat == 1) {
			finalEffectOne(finalAns);
		}
		else if (lifeStat == 2) {
			finalEffectTwo(finalAns);
		}
		else if (lifeStat == 3) {
			finalEffectThree(finalAns);
		}
		// sets the choices to a number of points 
		if (finalAns == "fight") {
			lifeStat += 0;
		}
		else if (finalAns == "lamp") {
			lifeStat += 2;
		}
		// prints out the win or loss and prints the total lifepoints
		if (lifeStat > 0) {
			cout << "Congrats you have won the game.\n" << endl;
			cout << "You have " << lifeStat << " total lifepoints\n\n";
		}
		else if (lifeStat <= 0) {
			cout << "You have lost the game.\n" << endl;
			cout << "You have " << lifeStat << " total lifepoints\n\n";
		}
		// prints welcome again 
		printWelcome();
		cin >> welcomeAns;
		conformationCheck(welcomeAns);
		if (conformationCheck(welcomeAns) != true) {
			goodbyeMessage();
		}
	}
	return WIN;
}
string toLowerWord(string toConvert) {
	int i = 0;
	for ( char letter : toConvert) {
		toConvert[i] = tolower(toConvert[i]);
		i++;
	}
	return toConvert;
}

// checks the choices if they are correct 
bool inputCheck(string input) {
	if (input == "flashlight") {
		return true;
	}
	else if (input == "landline") {
		return true;
	}
	else if (input == "table") {
		return true;
	}
	else if (input == "upstairs") {
		return true;
	}
	else if (input == "fight") {
		return true;
	}
	else if (input == "lamp") {
		return true;
	}
	else if (input == "end") {
		return true;
	}
	else {
		cout << "Choice is incorrect\n";
	}
	return false;
}
// checks welcome messages answer 
bool conformationCheck(string input) {
	if (input == "y") {
		return true;
	}
	else if (input == "yes") {
		return true;
	}
	
	return false;
}
// prints final if lifepoints are 3
void finalEffectThree(string finalAns) {
	if (finalAns == "fight") {
		cout << "\tJanice: TAKE THIS!!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice punches her attacker with the keys and beats with the flashlight*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*It was effective...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I DID It!! I have to get out of here.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Janice Kelly is alive.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Her attacker was found dead at the scene. Miss kelly’s story raises home safety concerns.*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (finalAns == "lamp") {
		cout << "\tJanice: TAKE THIS!!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice hits her attacker with the lamp, stabs with the keys, and beats with the flashlight.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*It was effective...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I DID It!! I have to get out of here.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Janice Kelly is alive.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Her attacker was found dead at the scene. Miss kelly’s story raises home safety concerns.*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (finalAns == "end") {
		goodbyeMessage();
	}
}
// prints final if lifepoints are 2
void finalEffectTwo(string finalAns) {
	if (finalAns == "fight") {
		cout << "\tJanice: TAKE THIS!!!\n\n ";
		system("pause");
		cout << "\n";
		cout << "\t*Janice stabs her attacker with the keys*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*It was effective...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I DID It!! I have to get out of here\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Janice Kelly is alive*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Her attacker is in the hospital recovering and will face multiple charges of robbery and attempted murder.*\n\n";
		system("pause"); 
		cout << "\n";
	}
	else if (finalAns == "lamp") {
		cout << "\tJanice: TAKE THIS!!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice hits her attacker with the lamp.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*It was effective...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I DID It!! I have to get out of here.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Janice Kelly is alive.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Her attacker is in the hospital recovering and will face multiple charges of robbery and attempted murder.*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (finalAns == "end" || finalAns == "End") {
		goodbyeMessage();
	}
}
// prints final if lifepoints is 1
void finalEffectOne(string finalAns) {
	if (finalAns == "fight") {
		cout << "\tJanice: TAKE THIS!!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice punchs her attacker with flashlight in hand* \n\n";
		system("pause");
		cout << "\n";
		cout << "\t*It was effective...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I DID It!! I have to get out of here.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Janice Kelly was found alive in the woods.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Police claim she was searching for help in a robbery gone wrong.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: She is recovering in a hospital with frostbite, and police have the suspect in custody.*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (finalAns == "lamp") {
		cout << "\tJanice: TAKE THIS!!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice hits her attacker with lamp* \n\n";
		system("pause");
		cout << "\n";
		cout << "\t*It was effective...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I DID It!! I have to get out of here.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Janice Kelly was found alive in the woods.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Police claim she was searching for help in a robbery gone wrong.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: She is recovering in a hospital with frostbite, and police have the suspect in custody.*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (finalAns == "end") {
		goodbyeMessage();
	}
}
// prints final if lifepoints is 0
void finalEffectZero(string finalAns) {
	if (finalAns == "fight") {
		cout << "\tJanice: TAKE THIS!!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Jancie throws a punch...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Punch was not effecttive...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Janice Kelly murdered*\n\n";
		system("pause");
		cout << "\n";
		cout << "\n*Breaking news: police say in what appears to be a robbery gone wrong.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: The murder is at large. Police have no leads*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: if you have information contact Police*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (finalAns == "lamp") {
		cout << "\tJanice: TAKE THIS!!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice hits the figure with the lamp...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*It was effective...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Janice Kelly was found dead in the woods*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: police claim Janice was searching for help in a robbery gone wrong.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Breaking news: Her death was an accident, and police have the suspect in custody.*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (finalAns == "end") {
		goodbyeMessage();
	}
}
// prints final choices 
void finalChoice() {
	cout << "\t*The shadow figure starts to choke her as she is pinned to the floor...*\n\n";
	system("pause");
	cout << "\n";
	cout << "\tJanice: HELP!!! I CAN FIGHT OR GRAB THIS LAMP NEARBY!!\n\n ";
	system("pause");
	cout << "\n";
	cout << "Enter your final choice (fight/lamp): ";

}
// prints choice one 
void ChoiceOne() {

	cout << "\tunknown number: I think there is a flashlight in the cupboard, but there is also the landline.\n\n";
	system("pause");
	cout << "\n";
	cout << "\tunknown number: What should I choose?? \n\n";
	cout << "Enter your choice (flashlight/ landline) : ";

}
// prints choice two
void ChoiceTwo() {
	cout << "\tJanice: We can head to the garage but I can't rememeber where I put my keys.\n\n";
	system("pause");
	cout << "\n";
	cout << "\tJanice: It is either in my bag which is upstairs. Or on the dinning room table. \n\n";
	system("pause");
	cout << "\n";
	cout << "\tJanice: What do you think?\n\n";
	cout << "Enter your choice (upstairs/ table): ";
}
// prints if lifepoints is 1
void secondEffectGO(string choiceTwoAns) {

	if (choiceTwoAns == "upstairs") {
		cout << "\tJanice: Good thing I have a flashlight!\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I Think I heard noise upstairs but I am sure it is nothing.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Jancie makes her way upstairs...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice locates her bag...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: OH NO!! THEY ARE NOT IN HERE!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*A shadow figure attacks Janice...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: HELP!!! I AM BEING ATTACKED!!\n\n";
		system("pause");
		cout << "\n";
	}
	else if (choiceTwoAns == "table") {
		cout << "\tJanice: Good idea, good thing I have this flashlight.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Jancie makes her way to the table.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice:OH MY GOSH!! I never felt so happy to see my keys.\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: Let's get out of here!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice enters the garage...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Suddenly rapid footsteps head toward Janice...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*A shadow figure attacks Janice...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: HELP!!! I AM BEING ATTACKED!!\n\n";
		system("pause");
		cout << "\n";
	}
	else if (choiceTwoAns == "end") {
		goodbyeMessage();
	}
}
// prints if lifepoints is 0
void secondEffectFlow(string choiceTwoAns) {

	if (choiceTwoAns == "upstairs" ) {
		cout << "\tJanice: Are you sure? It is really dark in here and I might fall down.\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: But Okay you know best. \n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice heads Upstairs...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Jancie locates her bag...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: OH NO!! They are not here!\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: Someone is coming this way!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*A shadow figure attacks Janice...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: Help I am being attacked !!! \n\n";
		system("pause");
		cout << "\n";
	}
	else if (choiceTwoAns == "table") {
		cout << "\tJanice: One problem I can't see anything.\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: They could be on the table. I will try to get over there.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice stumbles toward the table.* \n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I got to the table. I don't know if I will find my keys.\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I FOUND THEM!! let's get out of here.\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice heads toward the grage but accidently knocks down a vase.*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: OH NO!! Whoever is in here heard me!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\t*A shadow figure comes out and attacks Janice...*\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: HELP!! SOMEONE IS ATTACKING ME !!!!\n\n";
		system("pause");
		cout << "\n";
	}
	else if (choiceTwoAns == "end") {
		goodbyeMessage();
	}

}
// prints if choice is landline or flashlight
void firstEffect(string choiceOneAns) {
	if (choiceOneAns == "landline") {
		cout << "\tunknown number: Okay I don't know if it will work since the power is out but worth"
			<< " a try. \n\n";
		system("pause");
		cout << "\n";
		cout << "\tunknown number: So long story short it didn't work and why did i pick a house in the"
			<< " middle of nowhere!!\n\n";
		system("pause");
		cout << "\n";
		cout << "\tunknown number: Sorry I am just freaking out. oh I am Janice btw.\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I should have started with that. \n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice hears footsteps upstairs...*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (choiceOneAns == "flashlight") {
		cout << "\tunknnown number: Yeah that seems smart.\n\n";
		system("pause");
		cout << "\n";
		cout << "\tunknown number: Okay I got the flaslight, WOW! That makes a big difference.\n\n";
		system("pause");
		cout << "\n";
		cout << "\tunknown number: I should introduce myself, my name is Janice. thanks for helping me.\n\n";
		system("pause");
		cout << "\n";
		cout << "\tJanice: I wouldn't know what do without you helping me. \n\n";
		system("pause");
		cout << "\n";
		cout << "\t*Janice hears footsteps upstairs...*\n\n";
		system("pause");
		cout << "\n";
	}
	else if (choiceOneAns == "end") {
		goodbyeMessage();

	}

}
// prints the start text 
void startTextBox() {
	cout << "\t*You are at home. You receive an unknown text on your phone it reads:*\n\n";
	system("pause");
	cout << "\n";
	cout << "\tunknown number: Hello?? Is someone there??? \n\n";
	system("pause");
	cout << "\n";
	cout << "\tunkown number: I Need help!!!\n\n";
	system("pause");
	cout << "\n";
	cout << "\tunknown number: I answered the landline, and this creepy voice was talking so I hung up. \n\n";
	system("pause");
	cout << "\n";
	cout << "\tunknown number: and now the lights are out. Great...\n\n";
	system("pause");
	cout << "\n";
	cout << "\tunknown number: I keep hearing noises in my house. I can't reach the police.\n\n";
	system("pause");
	cout << "\n";
	cout << "\tunknown number: Your my only hope. Please. \n\n";
	system("pause");
	cout << "\n";
}
// prints the rules
void printRules() {
	cout << "Welcome, the rules of this game are simple. There is a total of three choices throughout the game.\n"
		<< "Each of the choices you are given two options to help the player surive.\n"
		<< "You can end the game at anytime. Simply type in end when it is time to choose. \n"
		<< " It is up to you to save them.\n" <<
		"Goodluck...\n\n";

	system("pause");
	cout << "\n";

}
// prints welcome
void printWelcome() {
	cout << "\t ----Point Of No Return----\n";
	cout << "Welcome to the Point of no return,"<<" Do you wish to play? (y/n): ";
}
// prints goodbye and exits the game
void goodbyeMessage() {
	cout << "You have choosen to end the game. Thank you for playing."<<endl;
	exit(0);
}
