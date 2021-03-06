#pragma once

#include "..\Headers\State.h"
#include "..\Headers\City.h"
#include "..\Headers\Town.h"
#include "..\Headers\Button.h"
#include "..\Headers\Player.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
class CityState :
	public State
{
public:
	CityState(RenderWindow* window, Font _font, stack<State*>* _states, City& city, int gold, Player * player);

	~CityState();

	void update();
	void render(RenderTarget* target = nullptr);
	void end();

private:
	bool mouseHeld;

	//t?o
	RectangleShape background;
	Texture texture;
	//Czcionka
	Font font;
	//Przyciski
	map<string, Button*>buttons;

	void initButtons();
	void updateButtons();
	void renderButtons(RenderTarget* target);
	//Wy?wietlanie i update ekranu*/

	//Inicjacja t?a
	void initBackground(sf::RenderWindow* window);
	//Inicjalizacja tekstu i przycisk?w
	void initText(Font font, City& city);

	//Nazwa miasta
	Text greeting;
	//Informacje o mie?cie
	RectangleShape infoShape;
	void initInfo();
	void updateInfo();
	Text info;
	//Miasto
	City* city;
	//Tekst do pokazywania b??d?w
	Text error;
	int timeToSeeAlert;
	//Ile zlota ma wlasciciel
	int ownerGold;
	//Obiekt gracz
	Player* player;
	//Ukrywanie przycisk?w i pokazywanie g?ownych przycisk?w
	void hidingMainButtons();
	void showingMainButtons();
	// Sprawdzenie czy g?owne klawisze s? ukryte
	bool hiddenMainbuttons;
	//ilo?? jednostek do wytrenowania - wy?wietlanie
	Text newKnightsText;
	Text newHorsesText;
	Text newArchersText;
	//ilo?? jednostek do wytrenowania
	unsigned int newKnight;
	unsigned int newHorse;
	unsigned int newArcher;
	//Tekst jakie jednostki si? dodaje
	Text knightsText;
	Text horsesText;
	Text archersText;
};
