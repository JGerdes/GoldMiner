#ifndef CONTROL_H_
#define CONTROL_H_

#include <vector>

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
