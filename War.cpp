/*
  Created by: Wesley Springer
        Date: April 2016
 Description: WAR is a card game that pits two players against each other. The deck is shuffled and then each player 
              is given half the deck. On each turn, each player draws a card and faces them against each other.
	      The card with the higher value wins the round with ace being one, jack being 11, queen being 12 and king being 13.
	      The player that has the most rounds won, wins!
*/



#include <vector>
#include <algorithm> //needed for random_shuffle
#include <iostream>

typedef enum
{
	spades = 1, hearts, diamonds, clubs
} suits;

typedef enum
{
	ace = 1, jack = 11, queen = 12, king = 13
}royalty;

class Card {
public:
	int value;
	int suit; 
};

//forward declarations
void main_menu();
void play_game();
void init_pack();
void deal_cards();
void print_deck();

//global 
std::vector<Card> pack(52);
std::vector < std::vector<Card> > hand(2); //creates 2 hands

int main()
{
	printf("\n\n\t\t\t\tWelcome to WAR\n\n\n");
	printf("--------------------------------------------------------------------------------\n\n\n");
	main_menu();
	return 0;


}

//prints main menu
void main_menu()
{
	int response = 0;
	printf("\t\t\t\tMAIN MENU\n\nType in the number to the corresponding choice on the main menu\n\n");
	printf("1) Play WAR\n2) Rules for WAR\n3) How to play\n4) Quit\n");
	std::cin >> response;
	if (response > 4 || response < 1)
	{
		printf("\nSorry, that is not a number thhat input is not an option. Please try again.\n");
		system("pause");
		system("CLS");
		main_menu();
	}
	switch (response)
	{
	case 1:
		play_game();
		break;
	case 2: 
		printf("Welcome to WAR. The rules are simple. There are 2 hands, and each hand contains half a shuffled deck. \nThis game will automatically play the top card from each deck against each other."
			"\nIf one card has a higher value than the other card, then that player wins that round.\nIf both cards have the same value, then it is a tie.\nOnce both decks are empty, the player with the "
			"most amount of wins wins the game.\n");
		system("pause");
		system("CLS");
		main_menu();
		break;
	case 3:
		printf("Welcome to WAR. All you have to do is press play and the game will do the rest!\n");
		system("pause");
		system("CLS");
		main_menu();
		break;
	case 4:
		exit(0);
	default:
		exit(0);
	}
}

void play_game()
{
	int tie = 0, wins = 0, defeats = 0;
	init_pack();
	std::random_shuffle(pack.begin(), pack.end()); //shuffle the deck
	deal_cards();
	printf("This is your deck: \n");
	print_deck();
	printf("Good luck! (press ENTER to continue)\n\n\n");
	system("pause");
	for (int i = 0; i < 26; i++)
	{
		printf("\nYou play: \t\t\t\tYour opponent plays: \nCard value: %d, Card suit: %d\t\tCard value: %d, Card suit: %d\n\n", hand[0][i].value, hand[0][i].suit, hand[1][i].value, hand[1][i].suit);
		if (hand[0][i].value > hand[1][i].value)
		{
			printf("You won the round!\n\n");
			wins++;
		}
		else if (hand[0][i].value == hand[1][i].value)
		{
			printf("This round resulted in a tie.\n\n");
			tie++;
		}
		else
		{
			printf("You lost the round!\n\n");
			defeats++;
		}
		system("pause");
	}

	if (wins > defeats)
	{
		printf("Congratulations! You defeated your opponent! You had %d victories while they had %d. Press ENTER to return to the main menu.\n", wins, defeats);
	}
	else if (wins < defeats)
	{
		printf("Oh no! You were defeated by your opponent! You had %d victories while they had %d. Press ENTER to return to the main menu.\n", wins, defeats);
	}
	else
	{
		printf("WOAH! The result is a tie. This means you have the same number of victories as defeats. That sucks. Press ENTER to return to the main menu.");
	}
	system("pause");
	system("CLS");
	main_menu();

}

void init_pack()
{
	int j = 0;
	//initialize suit to spades and card values of ace - king
	for (int i = 0; i < 13; i++)
	{
		pack[i].suit = spades;
		pack[i].value = j + 1;
		j++;
	}
	
	j = 0;
	//initialize suit to hearts and card values of ace - king
	for (int i = 13; i < 26; i++)
	{
		pack[i].suit = hearts;
		pack[i].value = j + 1;
		j++;
	}

	j = 0;
	//initialize suit to diamonds and card values of ace - king
	for (int i = 26; i < 39; i++)
	{
		pack[i].suit = diamonds;
		pack[i].value = j + 1;
		j++;
	}

	j = 0;
	//initialize suit to clubs and card values of ace - king
	for (int i = 39; i < 52; i++)
	{
		pack[i].suit = clubs;
		pack[i].value = j + 1;
		j++;
	}
}

void deal_cards()
{
	//deals cards to the player's hands
	for (int i = 0; i < pack.size(); i++)
	{
		if (i < 26)
		{
			hand[0].push_back(pack[i]);
		}
		else if (i >= 26 && i < 52)
		{
			hand[1].push_back(pack[i]);

		}
	}
}

//prints deck to the player
void print_deck()
{
	for (int i = 0; i < hand[0].size(); i++)
	{
		printf("Card value: %d, Card suit: %d\n", hand[0][i].value, hand[0][i].suit);
	}
}

