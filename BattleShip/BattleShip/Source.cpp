#include <iostream>
#include <chrono>
#include<conio.h>
#include <thread>
#define FALL_DOWN std::cout<<"\n"  
using namespace std;
#pragma region Values
enum MOVEMENT
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};
char** boats = new  char* [4]{
new char[20]{ "--Destroyer" },
new char[20]{ "--Corvette" },
new char[20]{ "--Battleship" },
new char[20]{ "--Aircraft Carrier" }
};
char** mainMenu = new  char* [4]{
new char[] { "PLAYER VS PLAYER   " },
new char[] { "PLAYER VS ULTRA BOT" },
new char[] { "- - - - - - - - - -" },
new char[] { "o o o o o o o o o o" }
};
int** closed_place_xy = new int* [2]{
	new int[300]{},
	new int[300]{}
};
int main_c = 0;
int x_close = 0;
int y_close = 0;
int x_bot = 0;
int y_bot = 0;
int bot_x_cout = 0;
int bot_y_cout = 0;
int boat_size[4]{ 4,3,2,1 };
#pragma region Visual Value
char area = 250;
char boat_dest = 254;
char empty_b = 178;
char crusor = 204;
#pragma endregion
#pragma endregion
#pragma region Visual
void print_nick() {
	system("cls");
	std::cout << ".-=~=-.                                                                                                       .-=~=-.\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "(__  _)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-.-=-.-=-.-=-.-=-.-=-.-=-.-=-.-=-.-=-(__  _)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "( _ __)                                                                                                       ( _ __)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "( _ __) _|_|_|      _|_|    _|_|_|_|_|  _|_|_|_|_|  _|        _|_|_|_|    _|_|_|  _|    _|  _|_|_|  _|_|_|    ( _ __)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "( _ __) _|    _|  _|    _|      _|          _|      _|        _|        _|        _|    _|    _|    _|    _|  ( _ __)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "( _ __) _|_|_|    _|_|_|_|      _|          _|      _|        _|_|_|      _|_|    _|_|_|_|    _|    _|_|_|    ( _ __)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "( _ __) _|    _|  _|    _|      _|          _|      _|        _|              _|  _|    _|    _|    _|        ( _ __)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "( _ __) _|_|_|    _|    _|      _|          _|      _|_|_|_|  _|_|_|_|  _|_|_|    _|    _|  _|_|_|  _|        ( _ __)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "( _ __)                                                                                                       ( _ __)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "(_ ___)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-.-=-.-=-.-=-.-=-.-=-.-=-.-=-.-=-.-=-(_ ___)\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	std::cout << "'-._.-'                                                                                                       '-._.-'\n";
	this_thread::sleep_for(chrono::milliseconds(100));
	this_thread::sleep_for(chrono::milliseconds(700));
	system("cls");
}
void simple_word_animation(char word[]) {
	for (int i = 0; word[i] != '\0'; i++)
	{
		std::cout << word[i];
		this_thread::sleep_for(chrono::milliseconds(2));
	}
}
void print_board(char** table) {
	system("cls");
	std::cout << "  0 1 2 3 4 5 6 7 8 9\n";
	this_thread::sleep_for(chrono::milliseconds(1));

	std::cout << " +-------------------\n";
	this_thread::sleep_for(chrono::milliseconds(1));

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << "|";
		for (int j = 0; j < 10; j++)
		{
			std::cout << table[i][j] << " ";

		}
		std::cout << "\n";
	}
}
void print_board_bot(char** table, char** table_2) {
	std::cout << "  0 1 2 3 4 5 6 7 8 9              0 1 2 3 4 5 6 7 8 9\n";
	std::cout << " +-------------------             +-------------------\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << "|";
		for (int j = 0; j < 10; j++)
		{
			std::cout << table[i][j] << " ";

		}
		std::cout << "           ";
		std::cout << i << "|";

		for (int j = 0; j < 10; j++)
		{
			if (table_2[i][j] == boat_dest || table_2[i][j] == empty_b)
				std::cout << table_2[i][j] << " ";
			else
				std::cout << area << " ";
		}
		FALL_DOWN;
	}
}
void print_board_player(char** table, char** table_2) {
	std::cout << "  0 1 2 3 4 5 6 7 8 9              0 1 2 3 4 5 6 7 8 9\n";
	std::cout << " +-------------------             +-------------------\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << "|";
		for (int j = 0; j < 10; j++)
		{
			std::cout << table[i][j] << " ";
		}
		std::cout << "           ";
		std::cout << i << "|";

		for (int j = 0; j < 10; j++)
		{
			std::cout << table_2[i][j] << " ";
		}
		FALL_DOWN;
	}
}
void add_area(char**& table) {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			table[i][j] = area;
		}
	}
}
void print_boats_table(char** boats) {
	system("cls");
	std::cout << " ____________________________" << "\n";
	std::cout << "|  ________________________  |" << "\n";
	std::cout << "| |                        | |" << "\n";
	std::cout << "| |                        | |" << "\n";
	std::cout << "| |   <<-CHOOSE SHIP->>" << "    | |" << "\n";
	std::cout << "| |    " << boats[0] << "         | |" << "\n";
	std::cout << "| |    " << boats[1] << "          | |" << "\n";
	std::cout << "| |    " << boats[2] << "        | | " << "\n";
	std::cout << "| |    " << boats[3] << "  | |" << "\n";
	std::cout << "| |                        | |" << "\n";
	std::cout << "| |________________________| |" << "\n";
	std::cout << "|____________________________|" << "\n";
}
#pragma endregion
#pragma region Main menu
void main_ss() {
	system("cls");
	std::cout << " ____________________________" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "|  ________________________  |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |                        | |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |                        | |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |     <<-CHOOSE->>" << "      | |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |    " << boats[0] << "         | |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |    " << boats[1] << "          | |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |    " << boats[2] << "        | | " << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |    " << boats[3] << "  | |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |                        | |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "| |________________________| |" << "\n";
	this_thread::sleep_for(chrono::milliseconds(1));
	std::cout << "|____________________________|" << "\n";
}
void main_menu() {
	system("cls");
	int c_w = 0;
	if (main_c == 0) {
		c_w = 2;
	}
	else
		c_w = 3;
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  /\\       /\\  /\\       /\\  /\\       /\\  /\\       /\\  /\\       /\\  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o {o ><{ }>< o}{o ><{ }>< o}{o ><{ }>< o}{o ><{ }>< o}{o ><{ }>< o} o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  \\/       \\/  \\/       \\/  \\/       \\/  \\/       \\/  \\/       \\/  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  /\\    o o o o o o o o o o o o o o o o o o o o o o o o o o    /\\  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o {o ><{ o            _______________________              o }>< o} o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  \\/    o           /                       \\             o    \\/  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  /\\    o              " << mainMenu[c_w] << "                o    /\\  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o {o ><{ o              " << mainMenu[main_c] << "                o }>< o} o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  \\/    o              " << mainMenu[c_w] << "                o    \\/  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  /\\    o           \\_______________________/             o    /\\  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o {o ><{ o                                                 o }>< o} o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  \\/    o o o o o o o o o o o o o o o o o o o o o o o o o o    \\/  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  /\\       /\\  /\\       /\\  /\\       /\\  /\\       /\\  /\\       /\\  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o {o ><{ }>< o}{o ><{ }>< o}{o ><{ }>< o}{o ><{ }>< o}{o ><{ }>< o} o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o  \\/       \\/  \\/       \\/  \\/       \\/  \\/       \\/  \\/       \\/  o" << "\n";
	this_thread::sleep_for(chrono::milliseconds(20));
	std::cout << "o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o" << "\n";
}
void main_menu_choose() {
	int player_move = 0;
	while (player_move != 13)
	{
		main_menu();
		player_move = _getch();
		if (player_move == 224) {
			player_move = _getch();
			switch (player_move)
			{
			case LEFT:
				if (::main_c == 0) {
					::main_c = 1;
				}
				else
					::main_c = 0;
				break;
			case RIGHT:
				if (::main_c == 0) {
					::main_c = 1;
				}
				else
					::main_c = 0;
				break;
			default:
				break;
			}
		}
	}
}
#pragma endregion
#pragma region Add Ship Manual
void choose_boat(int& boat_s) {
	int crusor = 0;
	int player_move = 0;
whileStart:
	while (player_move != 13)
	{
		print_boats_table(boats);
		player_move = _getch();
		if (player_move == 224) {
			player_move = _getch();
			switch (player_move)
			{
			case UP:
				if (crusor > 0) {
					boats[crusor][1] = '-';
					boats[crusor][0] = '-';
					crusor--;
					boats[crusor][1] = '>';
					boats[crusor][0] = '>';
				}
				else if (crusor == 0) {
					boats[crusor][1] = '-';
					boats[crusor][0] = '-';
					crusor += 3;
					boats[crusor][1] = '>';
					boats[crusor][0] = '>';
				}
				break;
			case DOWN:
				if (crusor < 3) {
					boats[crusor][1] = '-';
					boats[crusor][0] = '-';
					crusor++;
					boats[crusor][1] = '>';
					boats[crusor][0] = '>';
				}
				else if (crusor == 3) {
					boats[crusor][1] = '-';
					boats[crusor][0] = '-';
					crusor -= 3;
					boats[crusor][1] = '>';
					boats[crusor][0] = '>';
				}
				break;
			default:
				break;
			}
		}
	}
	boats[crusor][1] = '-';
	boats[crusor][0] = '-';
	boat_size[crusor]--;
	for (int i = 0; i < 4; i++)
	{
		if (::boat_size[crusor] < 0) {
			player_move = 0;
			char dude[]{ "Dude, there's no more of this ship type in storage." };
			simple_word_animation(dude);
			FALL_DOWN;
			system("pause");
			goto whileStart;
		}
	}
	boat_s = crusor;
	system("cls");
}
void add_boat_table(char**& table, int xy[], int boat_s, char vh) {
	char DCBA[5]{ "DCBA" };
	if (vh == 'v') {
		for (int i = 0; i < boat_s + 1; i++)
		{
			table[xy[0] - i][xy[1]] = DCBA[boat_s];
		}
	}
	else if (vh == 'h') {
		for (int i = 0; i < boat_s + 1; i++)
		{
			table[xy[0]][xy[1] + i] = DCBA[boat_s];
		}
	}
}
int check_closed_place(int xy[], int boat_s, char vh) {
	if (vh == 'v') {
		for (int j = 0; j < boat_s + 1; j++)
		{
			for (int i = 0; i < x_close; i++)
				if (xy[0] - j == closed_place_xy[0][i] && xy[1] == closed_place_xy[1][i]) {
					return 0;
				}
		}
	}
	else if (vh == 'h') {
		for (int j = 0; j < boat_s + 1; j++)
		{
			for (int i = 0; i < x_close; i++)
				if (xy[0] == closed_place_xy[0][i] && xy[1] + j == closed_place_xy[1][i]) {
					return 0;
				}
		}
	}
	return 1;
}
void add_closed_place(int xy[], int boat_s, char vh) {
	if (vh == 'v') {
		int x_min = xy[0] - (boat_s + 1);
		int y_min = xy[1] - 1;
		for (int i = 0; i < boat_s + 3; i++)
		{
			closed_place_xy[0][x_close] = x_min + i;
			x_close++;
			closed_place_xy[0][x_close] = x_min + i;
			x_close++;
			closed_place_xy[0][x_close] = x_min + i;
			x_close++;
			closed_place_xy[1][y_close] = y_min;
			y_close++;
			closed_place_xy[1][y_close] = y_min + 1;
			y_close++;
			closed_place_xy[1][y_close] = y_min + 2;
			y_close++;
		}
	}
	else if (vh == 'h') {
		int y_min = xy[1] - 1;
		int x_min = xy[0] - 1;
		for (int i = 0; i < boat_s + 3; i++)
		{
			closed_place_xy[0][x_close] = x_min;
			x_close++;
			closed_place_xy[0][x_close] = x_min + 1;
			x_close++;
			closed_place_xy[0][x_close] = x_min + 2;
			x_close++;
			closed_place_xy[1][y_close] = y_min + i;
			y_close++;
			closed_place_xy[1][y_close] = y_min + i;
			y_close++;
			closed_place_xy[1][y_close] = y_min + i;
			y_close++;
		}
	}
}
int check_place(int xy[], char& vh, char** table, int boat_s) {
	int x = 0;
	int y = 0;
	if (boat_s == 1) {
		x = 0;
		y = 9;
	}
	else if (boat_s == 2) {
		x = 1;
		y = 8;
	}
	else if (boat_s == 3) {
		x = 2;
		y = 7;
	}
	if (boat_s != 0) {
		if (vh == 'v') {
			while (true)
			{
				if (xy[0] > x) {
					break;
				}
				print_board(table);
				char jesus[]{ "Jesus christ, i can't place the X Coordinate. TRY AGAIN! :" };
				simple_word_animation(jesus);
				std::cin >> xy[0];
				system("cls");
			}
		}
		else if (vh == 'h') {
			while (true)
			{
				if (xy[1] < y) {
					break;
				}
				print_board(table);
				char jesus[]{ "Jesus christ, i can't place the Y Coordinate. TRY AGAIN! :" };
				simple_word_animation(jesus);
				std::cin >> xy[1];
				system("cls");
			}
		}
	}
	return 1;
}
void boat_place_manual(char**& table) {
	int boat_s = 0;
	char vh = 0;
	int xy[2]{};
	while (true)
	{
	whileStart:
		int end = 0;
		for (int i = 0; i < 4; i++)
		{
			if (::boat_size[i] <= 0) {
				end++;
			}
		}
		if (end == 4) {
			boat_size[0] = 4;
			boat_size[1] = 3;
			boat_size[2] = 2;
			boat_size[3] = 1;
			::x_close = 0;
			::y_close = 0;
			return;
		}
		end = 0;
		choose_boat(boat_s);
		char jesus[]{ "Orientation Vertical/Horizontal (v/h) :" };
		simple_word_animation(jesus);
		std::cin >> vh;
		system("cls");
		if (vh != 'v' && vh != 'h') {
			while (true)
			{
				if (vh == 'v' || vh == 'h') {
					break;
				}
				char orienta[]{ "You can use only -> (v/h) :" };
				simple_word_animation(orienta);
				std::cin >> vh;
				system("cls");
			}
		}
		print_board(table);
		char include_x[]{ "include X Coordinate :" };
		simple_word_animation(include_x);
		std::cin >> xy[0];
		system("cls");
		print_board(table);
		char include_y[]{ "include Y Coordinate :" };
		simple_word_animation(include_y);
		std::cin >> xy[1];
		system("cls");
		if (check_place(xy, vh, table, boat_s) && check_closed_place(xy, boat_s, vh)) {
			add_closed_place(xy, boat_s, vh);
			add_boat_table(table, xy, boat_s, vh);
			print_board(table);
			system("pause");
		}
		else {
			system("cls");
			boat_size[boat_s]++;
			char minecraft[]{ "You can't put a ship on a ship Bro" };
			simple_word_animation(minecraft);
			FALL_DOWN;
			system("pause");
			goto whileStart;
		}
	}
}
#pragma endregion
#pragma region Boat Place Oto
int check_place_oto(int xy[], char& vh, char** table, int boat_s) {
	int x = 0;
	int y = 0;
	if (boat_s == 1) {
		x = 0;
		y = 9;
	}
	else if (boat_s == 2) {
		x = 1;
		y = 8;
	}
	else if (boat_s == 3) {
		x = 2;
		y = 7;
	}
whileStart:

	if (boat_s != 0) {
		if (vh == 'v') {
			int hotdog = 0;
			while (true)
			{
				if (xy[0] > x) {
					break;
				}
				if (hotdog > 10000) {
					hotdog = 0;
					goto whileStart;
				}
				hotdog++;
				xy[0] = x + rand() % (9 - x + 1);
			}
		}
		else if (vh == 'h') {
			int hotdog = 0;
			while (true)
			{
				if (xy[1] < y) {
					break;
				}
				if (hotdog > 10000) {
					hotdog = 0;
					goto whileStart;
				}
				hotdog++;
				xy[1] = 0 + rand() % (y - 0 + 1);
			}
		}
	}
	return 1;
}
void choose_boat_oto(int& boat_s) {
whileStart:
	int hotdog = 0;
	while (true)
	{
		int crusor = 0 + rand() % (3 - 0 + 1);
		for (int i = 0; i < 4; i++)
			if (::boat_size[crusor] != 0) {
				boat_size[crusor]--;
				boat_s = crusor;
				return;
			}
		hotdog++;
		if (hotdog > 10000) {
			hotdog = 0;
			goto whileStart;
		}
	}
}
void boat_place_oto(char**& table) {
	int boat_s = 0;
	char vh = 0;
	int xy[2]{};
	srand(time(0));
	while (true)
	{

		int end = 0;
		for (int i = 0; i < 4; i++)
		{
			if (::boat_size[i] == 0) {
				end++;
			}
		}
		if (end == 4) {
			boat_size[0] = 4;
			boat_size[1] = 3;
			boat_size[2] = 2;
			boat_size[3] = 1;
			::x_close = 0;
			::y_close = 0;
			return;
		}
		end = 0;
		xy[0] = 0 + rand() % (9 - 0 + 1);
		xy[1] = 0 + rand() % (9 - 0 + 1);
		choose_boat_oto(boat_s);
	whileStart:
		int random_vh = 1 + rand() % (2 - 1 + 1);
		if (random_vh == 1)
			vh = 'v';
		else if (random_vh == 2)
			vh = 'h';
		int hotdog = 0;
		if (check_place_oto(xy, vh, table, boat_s) && check_closed_place(xy, boat_s, vh)) {
			add_closed_place(xy, boat_s, vh);
			add_boat_table(table, xy, boat_s, vh);
		}
		else {
			while (true)
			{
				xy[0] = 0 + rand() % (9 - 0 + 1);
				xy[1] = 0 + rand() % (9 - 0 + 1);

				if (check_place_oto(xy, vh, table, boat_s) && check_closed_place(xy, boat_s, vh)) {
					goto whileStart;
				}
				if (hotdog > 1000) {
					hotdog = 0;
					goto whileStart;
				}
				hotdog++;
			}
		}
	}
}
#pragma endregion
#pragma region Battle - Player vs Player
void first_player(char**& table, char**& table_2, int first_xy[], int& gta_x, int& pubg_y, int**& player_xy, int& end_player) {
whileStart:
	char first_x[]{ "First Player, include X Coordinate :" };
	char first_y[]{ "First Player, include Y Coordinate :" };
	print_board_player(table, table_2);
	FALL_DOWN;
	simple_word_animation(first_x);
	std::cin >> first_xy[0];
	system("cls");
	print_board_player(table, table_2);
	FALL_DOWN;
	simple_word_animation(first_y);
	std::cin >> first_xy[1];
	system("cls");

	for (int i = 0; i < gta_x; i++)
	{
		if (player_xy[0][i] == first_xy[0] && player_xy[1][i] == first_xy[1]) {
			std::cout << "You can't include same place please try again!\n";
			system("pause");
			goto whileStart;

		}
	}
	player_xy[0][gta_x] = first_xy[0];
	gta_x++;
	player_xy[1][pubg_y] = first_xy[1];
	pubg_y++;
	if (table_2[first_xy[0]][first_xy[1]] == area) {
		table_2[first_xy[0]][first_xy[1]] = empty_b;
		return;
	}
	else
	{
		table_2[first_xy[0]][first_xy[1]] = boat_dest;
		end_player++;
		if (end_player == 20) {
			return;
		}
		goto whileStart;

	}
}
void second_player(char**& table, char**& table_2, int second_xy[], int& gta_x, int& pubg_y, int**& player_xy, int& player_2_end) {
whileStart:
	char second_x[]{ "Second Player, include X Coordinate :" };
	char second_y[]{ "Second Player, include Y Coordinate :" };
	print_board_player(table, table_2);
	FALL_DOWN;
	simple_word_animation(second_x);
	std::cin >> second_xy[0];
	system("cls");
	print_board_player(table, table_2);
	FALL_DOWN;
	simple_word_animation(second_y);
	std::cin >> second_xy[1];
	system("cls");

	for (int i = 0; i < gta_x; i++)
	{
		if (player_xy[0][i] == second_xy[0] && player_xy[1][i] == second_xy[1]) {
			std::cout << "You can't include same place please try again!\n";
			system("pause");
			goto whileStart;
		}
	}
	player_xy[0][gta_x] = second_xy[0];
	gta_x++;
	player_xy[1][pubg_y] = second_xy[1];
	pubg_y++;
	if (table[second_xy[0]][second_xy[1]] == area) {
		table[second_xy[0]][second_xy[1]] = empty_b;
		return;
	}
	else
	{
		table[second_xy[0]][second_xy[1]] = boat_dest;
		player_2_end++;
		if (player_2_end == 20) {
			return;
		}
		goto whileStart;

	}
}
void player_vs_player(char**& table, char**& table_2, int& end_player, int& player_2_end) {
	system("cls");

	int first_xy[2]{};
	int second_xy[2]{};
	char DCBA[5]{ "DCBA" };
	char dcba_one;
	int** player_xy = new int* [2]{
	new int[300]{},
	new int[300]{} };
	int** player_xy_2 = new int* [2]{
new int[300]{},
new int[300]{} };
	int gta_x = 0;
	int pubg_y = 0;
	int gta = 0;
	int pubg = 0;
	while (true)
	{
		first_player(table, table_2, first_xy, gta_x, pubg_y, player_xy, end_player);
		if (end_player == 20) {
			return;
		}

		second_player(table, table_2, second_xy, gta, pubg, player_xy, player_2_end);
		if (player_2_end == 20) {
			return;
		}
	}
}
#pragma endregion
#pragma region Battle - Player vs Bot
int bot_attack(int**& bot_xy, char**& table, int boats_xy[], char& dcba) {
whileStart:
	boats_xy[0] = 0 + rand() % (9 - 0 + 1);
	boats_xy[1] = 0 + rand() % (9 - 0 + 1);
	if (table[boats_xy[0]][boats_xy[1]] == boat_dest || table[boats_xy[0]][boats_xy[1]] == empty_b) {
		goto whileStart;
	}
	for (int i = 0; i < bot_x_cout; i++)
	{
		if (bot_xy[0][i] == boats_xy[0] && bot_xy[1][i] == boats_xy[1]) {
			goto whileStart;
		}
	}
	bot_xy[0][bot_x_cout] = boats_xy[0];
	bot_x_cout++;
	bot_xy[1][bot_y_cout] = boats_xy[1];
	bot_y_cout++;
	if (table[boats_xy[0]][boats_xy[1]] == area) {
		table[boats_xy[0]][boats_xy[1]] = empty_b;
		return 0;
	}
	else {
		dcba = table[boats_xy[0]][boats_xy[1]];
		table[boats_xy[0]][boats_xy[1]] = boat_dest;
		return 1;
	}
}
int bot_attack_again(int**& bot_xy, char**& table, int boats_xy[], char dcba, int& conti_x, int& conti_y) {

	if (dcba == 'D') {
		return 0;
	}
	else if (dcba == 'C') {
		if (table[boats_xy[0] + 1][boats_xy[1]] != empty_b && boats_xy[0] + 1 <= 9) {
			if (table[boats_xy[0] + 1][boats_xy[1]] == dcba) {
				table[boats_xy[0] + 1][boats_xy[1]] = boat_dest;
				boats_xy[0] = boats_xy[0] + 1;
				bot_xy[0][bot_x_cout] = boats_xy[0];
				bot_x_cout++;
				bot_xy[1][bot_y_cout] = boats_xy[1];
				bot_y_cout++;
				return 1;
			}
			else if (table[boats_xy[0] + 1][boats_xy[1]] != empty_b && table[boats_xy[0] + 1][boats_xy[1]] != boat_dest) {
				table[boats_xy[0] + 1][boats_xy[1]] = empty_b;
				boats_xy[0] = boats_xy[0] + 1;
				bot_xy[0][bot_x_cout] = boats_xy[0];
				bot_x_cout++;
				bot_xy[1][bot_y_cout] = boats_xy[1];
				bot_y_cout++;
				return 0;

			}
		}
		else if (table[boats_xy[0] - 1][boats_xy[1]] != empty_b && boats_xy[0] - 1 >= 0) {
			if (table[boats_xy[0] - 1][boats_xy[1]] == dcba) {
				table[boats_xy[0] - 1][boats_xy[1]] = boat_dest;
				boats_xy[0] = boats_xy[0] - 1;
				bot_xy[0][bot_x_cout] = boats_xy[0];
				bot_x_cout++;
				bot_xy[1][bot_y_cout] = boats_xy[1];
				bot_y_cout++;
				return 1;
			}
			else if (table[boats_xy[0] - 1][boats_xy[1]] != empty_b && table[boats_xy[0] - 1][boats_xy[1]] != boat_dest) {
				table[boats_xy[0] - 1][boats_xy[1]] = empty_b;
				boats_xy[0] = boats_xy[0] - 1;
				bot_xy[0][bot_x_cout] = boats_xy[0];
				bot_x_cout++;
				bot_xy[1][bot_y_cout] = boats_xy[1];
				bot_y_cout++;
				return 0;

			}
		}
		else if (table[boats_xy[0]][boats_xy[1] + 1] != empty_b && boats_xy[1] + 1 <= 9) {
			if (table[boats_xy[0]][boats_xy[1] + 1] == dcba) {
				table[boats_xy[0]][boats_xy[1] + 1] = boat_dest;
				boats_xy[1] = boats_xy[1] + 1;
				bot_xy[0][bot_x_cout] = boats_xy[0];
				bot_x_cout++;
				bot_xy[1][bot_y_cout] = boats_xy[1];
				bot_y_cout++;
				return 1;
			}
			else if (table[boats_xy[0]][boats_xy[1] + 1] != empty_b && table[boats_xy[0]][boats_xy[1] + 1] != boat_dest) {
				table[boats_xy[0]][boats_xy[1] + 1] = empty_b;
				boats_xy[0] = boats_xy[1] + 1;
				bot_xy[0][bot_x_cout] = boats_xy[0];
				bot_x_cout++;
				bot_xy[1][bot_y_cout] = boats_xy[1];
				bot_y_cout++;
				return 0;
			}
		}
		else if (table[boats_xy[0]][boats_xy[1] - 1] != empty_b && boats_xy[1] - 1 >= 0) {
			if (table[boats_xy[0]][boats_xy[1] - 1] == dcba) {
				table[boats_xy[0]][boats_xy[1] - 1] = boat_dest;
				boats_xy[1] = boats_xy[1] - 1;
				bot_xy[0][bot_x_cout] = boats_xy[0];
				bot_x_cout++;
				bot_xy[1][bot_y_cout] = boats_xy[1];
				bot_y_cout++;
				return 1;
			}
			else if (table[boats_xy[0]][boats_xy[1] - 1] != empty_b && table[boats_xy[0]][boats_xy[1] - 1] != boat_dest) {
				table[boats_xy[0]][boats_xy[1] - 1] = empty_b;
				boats_xy[0] = boats_xy[1] - 1;
				bot_xy[0][bot_x_cout] = boats_xy[0];
				bot_x_cout++;
				bot_xy[1][bot_y_cout] = boats_xy[1];
				bot_y_cout++;
				return 0;
			}
		}
	}
	else if (dcba == 'B') {
		if (table[boats_xy[0] + 1][boats_xy[1]] == dcba) {
			table[boats_xy[0] + 1][boats_xy[1]] = boat_dest;
			boats_xy[0] = boats_xy[0] + 1;
			bot_xy[0][bot_x_cout] = boats_xy[0];
			bot_x_cout++;
			bot_xy[1][bot_y_cout] = boats_xy[1];
			bot_y_cout++;
			return 1;
		}
		if (table[boats_xy[0] - 1][boats_xy[1]] == dcba) {
			table[boats_xy[0] - 1][boats_xy[1]] = boat_dest;
			boats_xy[0] = boats_xy[0] - 1;
			bot_xy[0][bot_x_cout] = boats_xy[0];
			bot_x_cout++;
			bot_xy[1][bot_y_cout] = boats_xy[1];
			bot_y_cout++;
			return 1;
		}
		if (table[boats_xy[0]][boats_xy[1] + 1] == dcba) {
			table[boats_xy[0]][boats_xy[1] + 1] = boat_dest;
			boats_xy[1] = boats_xy[1] + 1;
			bot_xy[0][bot_x_cout] = boats_xy[0];
			bot_x_cout++;
			bot_xy[1][bot_y_cout] = boats_xy[1];
			bot_y_cout++;
			return 1;
		}
		if (table[boats_xy[0]][boats_xy[1] - 1] == dcba) {
			table[boats_xy[0]][boats_xy[1] - 1] = boat_dest;
			boats_xy[1] = boats_xy[1] - 1;
			bot_xy[0][bot_x_cout] = boats_xy[0];
			bot_x_cout++;
			bot_xy[1][bot_y_cout] = boats_xy[1];
			bot_y_cout++;
			return 1;
		}
	}
	else if (dcba == 'A') {
		if (table[boats_xy[0] + 1][boats_xy[1]] == dcba) {
			table[boats_xy[0] + 1][boats_xy[1]] = boat_dest;
			boats_xy[0] = boats_xy[0] + 1;
			bot_xy[0][bot_x_cout] = boats_xy[0];
			bot_x_cout++;
			bot_xy[1][bot_y_cout] = boats_xy[1];
			bot_y_cout++;
			return 1;
		}
		if (table[boats_xy[0] - 1][boats_xy[1]] == dcba) {
			table[boats_xy[0] - 1][boats_xy[1]] = boat_dest;
			boats_xy[0] = boats_xy[0] - 1;
			bot_xy[0][bot_x_cout] = boats_xy[0];
			bot_x_cout++;
			bot_xy[1][bot_y_cout] = boats_xy[1];
			bot_y_cout++;
			return 1;
		}
		if (table[boats_xy[0]][boats_xy[1] + 1] == dcba) {
			table[boats_xy[0]][boats_xy[1] + 1] = boat_dest;
			boats_xy[1] = boats_xy[1] + 1;
			bot_xy[0][bot_x_cout] = boats_xy[0];
			bot_x_cout++;
			bot_xy[1][bot_y_cout] = boats_xy[1];
			bot_y_cout++;
			return 1;
		}
		if (table[boats_xy[0]][boats_xy[1] - 1] == dcba) {
			table[boats_xy[0]][boats_xy[1] - 1] = boat_dest;
			boats_xy[1] = boats_xy[1] - 1;
			bot_xy[0][bot_x_cout] = boats_xy[0];
			bot_x_cout++;
			bot_xy[1][bot_y_cout] = boats_xy[1];
			bot_y_cout++;
			return 1;
		}
	}
}
void player_vs_bot(char**& table, char**& table_2, int& end_player, int& end_bot) {
	system("cls");
	char first_x[]{ "Include X Coordinate :" };
	char first_y[]{ "Include Y Coordinate :" };
	int first_xy[2]{};
	char DCBA[5]{ "DCBA" };
	int conti_x = 0;
	int conti_y = 0;
	char dcba = '0';
	int** player_xy = new int* [2]{
	new int[300]{},
	new int[300]{}
	};
	int** bot_xy = new int* [2]{
	new int[300]{},
	new int[300]{}
	};
	int gta_x = 0;
	int c = 0;
	int pubg_y = 0;
	int boats_xy[2]{};
	int boats_u[20]{};
	while (true)
	{
		while (true)
		{
		whileStart:
			system("cls");
			print_board_bot(table, table_2);
			simple_word_animation(first_x);
			std::cin >> first_xy[0];
			system("cls");
			print_board_bot(table, table_2);
			simple_word_animation(first_y);
			std::cin >> first_xy[1];
			system("cls");
			for (int i = 0; i < gta_x; i++)
			{
				if (player_xy[0][i] == first_xy[0] && player_xy[1][i] == first_xy[1]) {
					std::cout << "You can't include same place please try again!\n";
					system("pause");
					goto whileStart;
				}
			}
			player_xy[0][gta_x] = first_xy[0];
			player_xy[1][pubg_y] = first_xy[1];
			pubg_y++;
			gta_x++;
			if (table_2[first_xy[0]][first_xy[1]] != area) {
				table_2[first_xy[0]][first_xy[1]] = boat_dest;
				end_player++;
				if (end_player == 20)
					return;
				goto whileStart;
			}
			else if (table_2[first_xy[0]][first_xy[1]] == area) {
				table_2[first_xy[0]][first_xy[1]] = empty_b;
			}
			if (c <= 0) {
				if (bot_attack(bot_xy, table, boats_xy, dcba)) {
					end_bot++;
					if (end_bot == 20)
						return;
					print_board_bot(table, table_2);
					conti_x = boats_xy[0];
					conti_y = boats_xy[1];
					for (int i = 0; DCBA[i] != '\0'; i++)
					{
						if (dcba == DCBA[i]) {
							c = i;
							break;
						}
					}
					goto whileStart;
				}
			}
			while (c > 0) {
				if (bot_attack_again(bot_xy, table, boats_xy, dcba, conti_x, conti_y)) {
					if (dcba == 'B') {
						system("cls");
						print_board_bot(table, table_2);
						system("pause");
						bot_attack_again(bot_xy, table, boats_xy, dcba, conti_x, conti_y);
						c--;
					}
					else if (dcba == 'A') {
						system("cls");
						print_board_bot(table, table_2);
						system("pause");
						bot_attack_again(bot_xy, table, boats_xy, dcba, conti_x, conti_y);
						system("cls");
						print_board_bot(table, table_2);
						system("pause");
						bot_attack_again(bot_xy, table, boats_xy, dcba, conti_x, conti_y);
						c--;
						c--;
					}
					c--;
					end_bot++;
					if (end_bot == 20)
						return;
				}
				else {
					boats_xy[0] = conti_x;
					boats_xy[1] = conti_y;
					break;
				}

			}
		}
	}
}
#pragma endregion
int main() {
	print_nick();
	char** table = new char* [10]{
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{}
	};
	char** table_2 = new char* [10]{
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{},
		new char[10]{}
	};
	add_area(table);
	add_area(table_2);
	main_menu_choose();
	system("cls");
	char manu_auto[]{ "First player, do you want to fill manually or automatically(m/a)? :" };
	char player_2[]{ "Second player, do you want to fill manually or automatically(m/a)? : " };
	// 2 nefer oynamagi ucun
	char manu_auto_bot[]{ "Do you want to fill manually or automatically(m/a)? :" };
	if (main_c == 0) {
		char choose;
		simple_word_animation(manu_auto);
		std::cin >> choose;
		system("cls");
		if (choose != 'a' && choose != 'm') {
			while (true)
			{
				if (choose == 'a' || choose == 'm') {
					break;
				}
				char mmm[]{ "You can use only -> (m/a) :" };
				simple_word_animation(mmm);
				std::cin >> choose;
				system("cls");
			}
		}
		if (choose == 'm')
			boat_place_manual(table);
		else if (choose == 'a')
			boat_place_oto(table);
		print_board(table);
		system("pause");
		system("cls");
		simple_word_animation(player_2);
		std::cin >> choose;
		system("cls");
		if (choose != 'a' && choose != 'm') {
			while (true)
			{
				if (choose == 'a' || choose == 'm') {
					break;
				}
				char mmm[]{ "You can use only -> (m/a) :" };
				simple_word_animation(mmm);
				std::cin >> choose;
				system("cls");
			}
		}
		if (choose == 'm')
			boat_place_manual(table_2);
		else if (choose == 'a') {
			boat_place_oto(table_2);
		}
		int end_player = 0;
		int end_player_2 = 0;
		print_board(table_2);
		system("pause");
		player_vs_player(table, table_2, end_player, end_player_2);
		if (end_player > end_player_2) {
			system("cls");
			print_board_player(table, table_2);
			std::cout << "\nWINNER IS FIRST";
			system("pause");
		}
		else {
			system("cls");
			print_board_player(table, table_2);
			std::cout << "\nWINNER IS SECOND";
			system("pause");
		}
	}
	// bota qarsi oynamaq ucun
	else if (main_c == 1)
	{
		char choose;
		simple_word_animation(manu_auto_bot);
		std::cin >> choose;
		system("cls");
		if (choose != 'a' && choose != 'm') {
			while (true)
			{
				if (choose == 'a' || choose == 'm') {
					break;
				}
				char mmm[]{ "You can use only -> (m/a) :" };
				simple_word_animation(mmm);
				std::cin >> choose;
				system("cls");
			}
		}
		int end_player = 0;
		int end_bot = 0;
		if (choose == 'm')
			boat_place_manual(table);
		else if (choose == 'a')
			boat_place_oto(table);
		boat_place_oto(table_2);
		player_vs_bot(table, table_2, end_player, end_bot);
		if (end_player > end_bot) {
			system("cls");
			print_board_player(table, table_2);
			std::cout << "\nWINNER IS PLAYER";
			system("pause");
		}
		else {
			system("cls");
			print_board_player(table, table_2);
			std::cout << "\nWINNER IS BOT";
			system("pause");
		}
	}
	return 0;
}