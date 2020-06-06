#include "Global.h"
#include <memory>
#include "Box2DEngine.h"
#include "Player.h"

class Rope
{
public:
	Rope(int x, int y, float length, int nb_links, Box2DEngine* gameController);
	float getLength() const { return length; }
	int	getNb_links() const { return nb_links; }
	std::vector<b2Body*> getElements() const { return elements; }
	void linkPlayers(Player* player1, Player* player2, b2World* world);
private:
	float length;
	int nb_links;
	Box2DEngine* gameController;
	std::vector<b2Body*> elements;


};
