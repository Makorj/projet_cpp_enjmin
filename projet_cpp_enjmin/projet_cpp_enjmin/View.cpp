#include "View.h"
#include <string>
#include <ctime>
#include "InputManager.h"

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
		posX++;
}

void View::Render()
{
	_screen.clear();

	GraphicalEntity* a;
	for (char i = 0; i < _nbEntities; ++i)
	{
		a = &_entities[i];
		_screen.draw(*a,_entityMap[a]->getPosX(),_entityMap[a]->getPosY());
	}

	_screen.draw(florent_str.c_str(), 86, 7, posX, posY);
	_screen.flip();
}
