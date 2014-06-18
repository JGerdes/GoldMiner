#ifndef CONTROL_H_
#define CONTROL_H_

#include <vector>


class Ground{
	public:
	Ground(int x, int y){};
	int getHp(){};
};

class Player {
public:
	Player(){};
	~Player(){};
	void setPos(int x, int y){};
};

class World {
public:
	World();
	~World(){};
	std::vector<Ground> createMap();
	void update();
	void testBlockLife();
	void testCollision();
private:
	Player player;
	std::vector<Ground> map;
	bool collisonRight, collisionLeft, collisionDown, collisionUp;
};






#endif /* CONTROL_H_ */
