//Name: Hero.cpp
//Project: CMSC 202 Project 4, Fall 2023
//Author:  Faheed Sadique
//Date:    11/4/23
//Desc: This file contains code details for the Hero.cpp

#include "Hero.h"
#include "Weapon.h"
#include "Sword.h" // Include the weapon headers
#include "Bomb.h"
#include "Boomerang.h"
#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For srand() function

using namespace std;

Hero::Hero(string name, int health) : m_name(name), m_health(health), m_rupees(m_rupees) {
  // Initialize hero with a random weapon
  RandomWeapon();
}

string m_name; //Name of the hero
int m_damage;
int m_health; //Total health for this hero
int m_rupees; //Money held by the hero
Weapon* m_weapon; //Weapon that the hero is wielding (used for damage)

Hero::~Hero() {
  // Deallocate dynamically allocated resources
  delete m_weapon;
}

//Calls the weapon's attack and Returns damage
int Hero::Attack(){
 
 if(m_weapon != nullptr) {
   return m_weapon->Attack();
  }
 return 0;
}

//Returns the current name
string Hero::GetName(){
  return m_name;
}

//Updates m_name with a new name
void Hero::SetName(string){
  m_name = m_name;
}
//Returns the health of the hero
int GetHealth(){
  return m_health;
}

//Updates m_health of the hero
void SetHealth(int){
  m_health = m_health;
}

//Returns the rupee of the hero
int Hero::GetRupee(){
  return m_rupees;
}

//Updates m_rupee of the hero
void SetRupee(int){
  m_rupees = m_rupees;
}

void Hero::RandomWeapon() {
  delete m_weapon;
  // Randomly assign a weapon to the hero
  int randomWeapnType = rand() % 3;

  switch (randomWeapnType) {
  case 0:
    m_weapon = Sword;
    break;
  case 1:
    m_weapon = Bomb;
    break;
  case 2:
    m_weapon = Boomerang;
    break;
  default:
   
    break;
  }

}

//Improve Weapon to Increases m_weapon and decreases m_rupees
void Hero::ImproveWeapon(int value){
  if (m_weapon != nullptr) {
    // Improve the weapon by spending rupees
    m_weapon->ImproveWeapon(m_rupees);

    // Decrease the hero's rupees
  m_rupees -= m_rupees;
  }
}
 

//Used to attack an enemy using the weapon's special attack
int SpecialAttack(){
 if(m_weapon != nullptr){
   return m_weapon->SpecialAttack();
    //return m_weapon->GetDamage();
  cout << m_name << " launches an attack on the enemy using the weapon's "
       << SpecialAttack << endl;
}
return 0;
}

int main(){
  return 0;
}
