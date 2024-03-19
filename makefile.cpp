CXX = g++
  CXXFLAGS = -Wall
  
proj4: Enemy.o Armos.o Moblin.o Peahat.o Weapon.o Sword.o Bomb.o Boomerang.o Hero.o Area.o Game.o Proj4.cpp
  $(CXX) $(CXXFLAGS) Enemy.o Armos.o Moblin.o Peahat.o Weapon.o Sword.o Bomb.o Boomerang.o Hero.o Area.o Game.o Proj4.cpp -o proj4

Enemy.o: Armos.o Moblin.o Peahat.o Enemy.cpp Enemy.h
  $(CXX) $(CXXFLAGS) -c Enemy.cpp

Armos.o: Armos.h Armos.cpp Enemy.o
  $(CXX) $(CXXFLAGS) -c Armos.cpp
  
Moblin.o: Moblin.h Moblin.cpp Enemy.o
  $(CXX) $(CXXFLAGS) -c Moblin.cpp
  
Peahat.o: Peahat.h Peahat.cpp Enemy.o
  $(CXX) $(CXXFLAGS) -c Peahat.cpp

Weapon.o: Sword.o Bomb.o Boomerang.o Weapon.cpp Weapon.h
  $(CXX) $(CXXFLAGS) -c Weapon.cpp
  
Sword.o: Sword.h Sword.cpp Weapon.o
  $(CXX) $(CXXFLAGS) -c Sword.cpp
  
Bomb.o: Bomb.h Bomb.cpp Weapon.o
  $(CXX) $(CXXFLAGS) -c Bomb.cpp
  
Boomerang.o: Boomerang.o Boomerang.o Weapon.o
  $(CXX) $(CXXFLAGS) -c Boomerang.cpp

Hero.o: Sword.o Bomb.o Boomerang.o Weapon.o Hero.cpp Hero.h
  $(CXX) $(CXXFLAGS) -c Hero.cpp

Area.o: Area.o Area.cpp Area.h
  $(CXX) $(CXXFLAGS) -c Area.cpp

Game.o: Enemy.o Armos.o Moblin.o Peahat.o Weapon.o Sword.o Bomb.o Boomerang.o Hero.o Area.o Game.cpp Game.h
  $(CXX) $(CXXFLAGS) -c Game.cpp

clean:
        rm *.o
        rm *~

run:
         ./proj4
