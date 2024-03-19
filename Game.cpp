//Name: Weapon.cpp
//Project: CMSC 202 Project 4, Fall 2023
//Author:  Faheed Sadique
//Date:    11/4/23
//Desc: This file contains code details for the Weapon.cpp

//Includes of required classes
#include "Area.h"
#include "Hero.h"
#include "Enemy.h"
#include "Armos.h"
#include "Moblin.h"
#include "Peahat.h"
#include "Weapon.h"
#include "Sword.h"
#include "Bomb.h"
#include "Boomerang.h"
#include <iostream>

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


// Overloaded Constructor
Game::Game(string filename) : m_filename(filename){
  m_myHero(nullptr);
  m_curEnemy(nullptr);
  m_curArea(nullptr);
  m_startingArea = START_AREA;
}

// Destructor
Game::~Game() {
  // Deallocate anything dynamically allocated in Game
  delete m_myHero;
  delete m_curEnemy;

  // Deallocate areas in the map
  for (Area* area : m_myMap) {
    delete area;
  }
}

vector<Area*> m_myMap; // Vector for holding all areas in game
Hero* m_myHero; // Hero pointer for Hero (Player)
int m_curArea; // Current area that player (Hero) is in
Enemy* m_curEnemy; // Current enemy loaded for current area
string m_filename; //Name of the input file for the map (holds area objects)

void Game::LoadMap() {
  ifstream inputFile(m_filename);

}

string line;
while (getline(inputFile, line)) {
  istringstream iss(line);
  int id, north, east, south, west;
  string name, desc;

  if (!(iss >> id >> name >> desc >> north >> east >> south >> west)) {
    cerr << "Error: Invalid format in input file." << endl;
    exit(EXIT_FAILURE);
  }
  m_myMap.push_back(new Area(id, name, desc, north, east, south, west));
 }

void Game::Look() {
  // Check if the current area is valid
  if (m_curArea != nullptr) {
    // Display the current area's description
    cout << "Current Area: " << GetName() << endl;
    cout << "Description: " << GetDesc() << endl;

    // Check if there is a current enemy
    if (m_curEnemy != nullptr) {
      // Display the current enemy's description
      cout << "Current Enemy: " << GetName << endl;
      cout << "Enemy Description: " << GetDesc << endl;
    } else {
      // No enemy in the current area
      cout << "It is peaceful here." << endl;
    }

    void Game::StartGame() {
      // Welcome the player to the game
      cout << "Welcome to Zelda! " << endl;
      cout << " Hero Name: " << endl;
      cin >> m_name;
      // Call LoadMap to populate the game map
    ifstream inputFile(proj4_map1.txt);
    

    void Game::Action() {
      char choice;

      do {
	// Display the menu
	cout << " Game Menu " << endl;
	cout << "1. Look\n2. Move\n 3. Attack\n 4. Improve Weapon\n 5. Stats\n 6. Quit\n";
	cout << "Enter your choice (1-6): ";
	cin >> choice;

	// Validate user input
	while (choice < '1' || choice > '6') {
	  cout << "Invalid choice. Please enter a number between 1 and 6: ";
	  cin >> choice;
	}

	// Perform the chosen action
	switch (choice) {
	case '1':
	  Look();
	  break;
	case '2':
	  Move();
	  break;
	case '3':
	  if (m_curEnemy != nullptr) {
	    Attack();
	  } else {
	    cout << "There is no enemy to attack in this area." << endl;
	  }
	  break;
	case '4':
	  ImproveWeapon();
	  break;
	case '5':
	  Stats();
	  break;
	case '6':
	  // Quit the game
	  cout << "Thanks for playing! Goodbye." << endl;
	  break;
	default:
	 
	  break;
	}
      } while (choice != '6' && m_myHero != nullptr && m_myHero->GetHealth() > 0);
    }
      void Game::RandomEnemy(){
      switch (randomEnemyType) {
      case 0:
	m_curEnemy = new Armos();   
	  break;
      case 1:
	m_curEnemy = new Moblin();  
	break;
      case 2:
	m_curEnemy = new Peahat();  
	break;
      default:
	
	break;
      }
      void Game::Move(){
      currentArea->Move(direction);
      }

      void Game::Attack(){
	if (m_curEnemy == nullptr) {
	  cout << "There is no enemy to attack in this area." << endl;
	  return;
	}

	// Display the current enemy's information
	cout << "Current Enemy: " << GetName << endl;
	cout << "Enemy Health: " << GetHealth << endl;

	// Player and enemy attack in turns until one or both have <= 0 health
	while (m_myHero->GetHealth() > 0 && m_curEnemy->GetHealth() > 0) {
	  char attackChoice;

	  // Ask the user if they want to use a normal or special attack
	  cout << "Choose attack type: (N)ormal or (S)pecial: ";
	  cin >> attackChoice;

	  // Validate user input
	  while (attackChoice != 'N' && attackChoice != 'S') {
	    cout << "Invalid choice. Please enter 'N' for Normal or 'S' for Special: ";
	    cin >> attackChoice;
	  }

	  // Perform the chosen attack
	  int heroDamage = 0;
	  int enemyDamage = 0;

	  if (attackChoice == 'N') {
	    // Normal attack
	    heroDamage = m_myHero->Attack();
	    enemyDamage = m_curEnemy->Attack();
	  } else {
	    // Special attack
	    heroDamage = m_myHero->SpecialAttack();
	    enemyDamage = m_curEnemy->SpecialAttack();
	  }

	  // Update health based on the damage dealt
	  m_myHero->SetHealth(m_myHero->GetHealth() - enemyDamage);
	  m_curEnemy->SetHealth(m_curEnemy->GetHealth() - heroDamage);

	  // Update health based on the damage dealt
	  cout << "Hero dealt " << enemyDamage << " damage to the enemy." << endl;
	  cout << "Enemy dealt " << heroDamage << " damage to the hero." << endl;
	  cout << "Hero Health: " << m_myHero->GetHealth() << endl;
	  cout << "Enemy Health: " << m_curEnemy->GetHealth() << endl;
	}

       	ProcessBattle(m_curEnemy->GetHealth() <= 0, m_myHero->GetHealth() <= 0);
      }

      void Stats(){
	if (m_myHero != nullptr) {
	  // Display hero information
	  cout << " Hero Stats " << endl;
	  cout << "Name: " << GetName << endl;
	  cout << "Health: " << m_myHero->GetHealth() << endl;
	  cout << "Rupees: " << m_myHero->GetRupee() << endl;
	  cout << " " << endl;
	}

      }

      void ProcessvBattle(bool enemyAlive, bool alive){
	if (!enemyAlive && alive) {
	  // Hero wins
	  cout << "Congratulations! You defeated the enemy!" << endl;

	  // Give RUPEES_WIN to the hero and reset health to starting value
	  m_myHero->SetRupee(m_myHero->GetRupee() + RUPEES_WIN);
	  m_myHero->SetHealth(STARTING_HEALTH);

	  cout << "You earned " << RUPEES_WIN << " rupees and your health is restored." << endl;
	} else if (enemyAlive && !alive) {
	  // Enemy wins
	  cout << " The enemy defeat you." << endl;
	} else {
	  // Mutual destruction
	  cout << "It's a draw! Both the hero and the enemy are defeated." << endl;
	}

	// Deallocate the enemy to prevent memory leaks
	delete m_curEnemy;
	m_curEnemy = nullptr;
      }

      }
      int main(){
	return 0;
      }
    }
  }
}

