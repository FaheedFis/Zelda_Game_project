//Name: Weapon.cpp
//Project: CMSC 202 Project 4, Fall 2023
//Author:  Faheed Sadique
//Date:    11/4/23
//Desc: This file contains code details for the Weapon.cpp

#include "Weapon.h"
#include <iostream>
using namespace std;

//Overloaded constructor
Weapon::Weapon(string name,int damage) : m_name(name), m_damage(damage){
}

//Virtual Destructor
Weapon::~Weapon(){
}
string m_name; //Name for Weapon
int m_damage; //Damage that the base attack does

//Describes attack statements for weapon and Returns damage
int Weapon::Attack(){
  cout << m_name << " attack enemy for " << m_damage << endl;
  if(m_damage > 1){
  }
  return m_damage;
}

//  Returns the damage
int Weapon::GetDamage(){
  return m_damage;
}

// Increases m_damage of the weapon by the value passed
void Weapon::ImproveWeapon(int value){
  m_damage += value;

}

int main (){
  return 0;
}
