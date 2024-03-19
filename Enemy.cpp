//Name: Enemy.cpp
//Project: CMSC 202 Project 4, Fall 2023
//Author:  Faheed Sadique
//Date:    11/4/23
//Desc: This file contains code details for the Enemy.cpp

#include "Enemy.h"

#include <iostream>

using namespace std;

// Name: Enemy(string name, int hp, int damage, string desc)
// Description: Used to populate variables in enemy
// Postconditions: Used to populate child class data
Enemy::Enemy(string name, int hp, int damage, string desc): m_name(name), m_health(m_health), m_damage(damage), m_desc(desc) {
  
}
string m_name; //Name of the enemy
int m_health; //Total health for this enemy
int m_damage; //Max damage for this enemy
string m_desc; //Description of the enemy

Enemy::~Enemy(){   //Virtual Destructor

}


// Name: Attack()
// Description: Describes attack statements for Enemy
// Postconditions: Returns damage
int Enemy::Attack(){
  cout << m_name << " attack for " << m_damage << endl;
  if(m_damage > 1){
  } //else {
      return m_damage;
     
}

/*void Enemy::specialAttack(){
  cout << "Enemy " << m_name << "performs a basic special attack." << endl;
  }*/

// Name: GetName()
string Enemy::GetName(){
  return m_name;
}

//GetHealth to  Returns enemy health (used for battle)
int Enemy::GetHealth(){
  return m_health;
}
// Name: SetHealth Used to update enemy health (used for battle)
void Enemy::SetHealth(int){
  m_health = m_health;
}
// GetDamage to Returns enemy damage (used for battle)

int Enemy::GetDamage(){
  return m_damage;
}
// Name: GetDesc to Returns the description of the enemy (used in Look)
string Enemy::GetDesc(){
  return m_desc;
}

int main (){
  return 0;
}
