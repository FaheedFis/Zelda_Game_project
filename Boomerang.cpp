//Name: Boomerang.cpp
//Project: CMSC 202 Project 4, Fall 2023
//Author:  Faheed Sadique
//Date:    11/4/23
//Desc: This file contains code details for the Boomerang.cpp

#include "Weapon.h"
#include <iostream>

using namespace std;

void Boomerang(int damage){

}
string m_name; //Name of the Sword
int m_damage;

int specialAttack() {
  cout << m_name << " throws and returns for " << m_damage << " damage. " << endl;
  int specialDamage = m_damage * 2;
  cout << m_name << " launches a Boomerang specail attack. " << endl;
  if (m_damage > 1){
  }
  return m_damage;
}
int main(){
  return 0;
}
