#include <Events.h>
#include "myMain.h"

void HookEvents(sf::Window* window, Box2DEngine* gameController, b2Body* player) {
	sf::Event event;
	float impulse = player->GetMass() * 10;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window->close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			float MouseX = sf::Mouse::getPosition(*window).x;
			float MouseY = sf::Mouse::getPosition(*window).y;
			gameController->addDynamicBox(MouseX, MouseY, 1.0f * RATIO, 1.0f * RATIO, Material::WOOD);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			float MouseX = sf::Mouse::getPosition(*window).x;
			float MouseY = sf::Mouse::getPosition(*window).y;
			gameController->addStaticBox(MouseX, MouseY, 8.0f * RATIO, 1.0f * RATIO);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			actionplayerLeftKey(player);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			actionplayerRightKey(player);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			actionplayerDownKey(player);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			actionplayerUpKey(player);
		}
	}
}


void actionplayerRightKey(b2Body* player)
{
	int footcount;
	int handcount;
	int jumptimout;
	getvalue(player, &footcount, &handcount, &jumptimout);

	if (footcount < 1 && handcount < 1 && jumptimout > 0) { //enlair 
		if (player->GetLinearVelocity().x >= 5) {
			player->SetLinearVelocity(b2Vec2(10, player->GetLinearVelocity().y));
		}
		else
		{
			player->ApplyLinearImpulseToCenter(b2Vec2(10, 0), true);
		}

	}else{
		if (player->GetLinearVelocity().x >= 10) {
			player->SetLinearVelocity(b2Vec2(20, player->GetLinearVelocity().y));
		}
		else
		{
			player->ApplyLinearImpulseToCenter(b2Vec2(20, 0), true);
		}
	}
}

void actionplayerLeftKey(b2Body* player)
{
	int footcount;
	int handcount;
	int jumptimout;
	getvalue(player, &footcount, &handcount, &jumptimout);

	PlayerData* playerdata = (PlayerData*)player->GetUserData();
	if (footcount < 1 && handcount < 1 && jumptimout > 0) { //enlair
		if (player->GetLinearVelocity().x <= -5) {
			player->SetLinearVelocity(b2Vec2(-10, player->GetLinearVelocity().y));
		}
		else
		{
			player->ApplyLinearImpulseToCenter(b2Vec2(-10, 0), true);
		}

	}
	else {
		if (player->GetLinearVelocity().x <= -10) {
			player->SetLinearVelocity(b2Vec2(-20, player->GetLinearVelocity().y));
		}
		else
		{
			player->ApplyLinearImpulseToCenter(b2Vec2(-20, 0), true);
		}
	}
}

void actionplayerDownKey(b2Body* player)
{
	//nothingtodo
}

void actionplayerUpKey(b2Body* player)
{
	int footcount;
	int handcount;
	int jumptimout;
	getvalue(player, &footcount, &handcount, &jumptimout);
	PlayerData* playerdata = (PlayerData*)player->GetFixtureList()->GetUserData();
	if (footcount < 1 ) {
		return;
	}
	if (jumptimout > 0) return;
	player->ApplyLinearImpulseToCenter(b2Vec2(0, -player->GetMass() * 10), true);
	playerdata->SetJumpTimeout(30);
}
