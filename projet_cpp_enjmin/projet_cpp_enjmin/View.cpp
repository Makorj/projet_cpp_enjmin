#include "View.h"
#include <string>
#include <ctime>
#include "InputManager.h"
#include "Data.h"

const std::string florent_str =
"         :::::::::: :::        ::::::::  :::::::::  :::::::::: ::::    ::: :::::::::::\
         :+:        :+:       :+:    :+: :+:    :+: :+:        :+:+:   :+:     :+:    \
        +:+        +:+       +:+    +:+ +:+    +:+ +:+        :+:+:+  +:+     +:+     \
       :#::+::#   +#+       +#+    +:+ +#++:++#:  +#++:++#   +#+ +:+ +#+     +#+      \
      +#+        +#+       +#+    +#+ +#+    +#+ +#+        +#+  +#+#+#     +#+       \
     #+#        #+#       #+#    #+# #+#    #+# #+#        #+#   #+#+#     #+#        \
    ###        ########## ########  ###    ### ########## ###    ####     ###         ";


View::View()
	: _entities(new GraphicalEntity[MAX_GRAPHICAL_ENTITIES]),
	_nbEntities(0)
{
	std::string tile1 = Data::LoadSpriteFromSpriteSheet(1);
	std::string tile2 = Data::LoadSpriteFromSpriteSheet(2);

	for (int i = 0; i < 10; i++)
	{
		GraphicalEntity tmp(i % 2 == 0 ? tile1 : tile2, 5, 5);
		_entities[i] = tmp;
		_nbEntities++;
	}
}


View::~View()
{
	delete[] _entities;
}

volatile int posX = 50;
volatile int posY = 50;

void View::Update()
{
	if (InputManager::getInstance().getKbInfos().KEY_RIGHT)
		VirtualScreen::debug("KEY RIGHT");
	if (InputManager::getInstance().getKbInfos().KEY_LEFT)
		VirtualScreen::debug("KEY LEFT");

	if (InputManager::getInstance().getKbInfos().KEY_UP)
		VirtualScreen::debug("KEY UP");
	if (InputManager::getInstance().getKbInfos().KEY_DOWN)
		VirtualScreen::debug("KEY DOWN");
}

void View::Render()
{
	_screen.clear();

	GraphicalEntity* a;
	for (char i = 0; i < _nbEntities; ++i)
	{
		a = &(_entities[i]);
		_screen.draw(*a, i*5, 10);//_entityMap[a]->getPosX(),_entityMap[a]->getPosY());
	}

	_screen.draw(florent_str.c_str(), 86, 7, posX, posY);

#ifdef _DEBUG
	_screen.draw(VirtualScreen::debug_stream.c_str(), VirtualScreen::debug_stream.size(), 1, 0, 1);
#endif // DEBUG

	_screen.flip();
}
