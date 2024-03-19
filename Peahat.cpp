//Name: Peahat.cpp
//Project: CMSC 202 Project 4, Fall 2023
//Author:  Faheed Sadique
//Date:    11/4/23
//Desc: This file contains code details for the Peahat.cpp

#include "Enemy.h"

using namespace std;

void Peahat(string name, int health, int damage, string desc) {

}
string m_name; //Name of the enemy
int m_health; //Total health for this enemy
int m_damage; //Max damage for this enemy
string m_desc; //Description of the enemy

int specialAttack() {
  int specialDamage = m_damage * 3;
  cout << m_name << " launches a specail attack for " << specialDamage << " damage " << endl;
  if (m_damage > 1){
  }
  return m_damage;
}
int main(){
  return 0;
}
