#include "View.h"
#include <string>
#include <ctime>
#include "InputManager.h"
#include "Data.h"


#define NUMBER_OF_SPRITE 6
#define SPRITE_ID_DEFAULT 0
#define SPRITE_ID_WALL_FULL 1
#define SPRITE_ID_WALL_HALF 2
#define SPRITE_ID_GHOST 3
#define SPRITE_ID_PLAYER 4
#define SPRITE_ID_FRUIT 5

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
	std::string sprites[NUMBER_OF_SPRITE];

	for (int i = 0; i < NUMBER_OF_SPRITE; i++)
	{
		sprites[i] = Data::LoadSpriteFromSpriteSheet(i+1);
	}

	for (int i = 0; i < NUMBER_OF_SPRITE; i++)
	{
		GraphicalEntity tmp(sprites[i], 5, 5);
		_entities[i] = tmp;
		_nbEntities++;
	}

}


View::~View()
{
	delete[] _entities;
}

GraphicalEntity* View::getGraphicalEntities()
{
	return _entities;
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

	DrawMap();

	_screen.draw(florent_str.c_str(), 86, 7, posX, posY);

#ifdef _DEBUG
	_screen.draw(VirtualScreen::debug_stream.c_str(), VirtualScreen::debug_stream.size(), 1, 0, 1);
#endif // DEBUG

	_screen.flip();
}

void View::setData(Data* data)
{
	_data = data;
}

void View::DrawMap()
{
	if (_data->GetGameMap() == nullptr)
		printf("caca");

	MapTile* tmpTile;
	for (int i = 0; i < _data->GetGameMap()->NUMBER_TILES; i++)
	{
		for (int j = 0; j < _data->GetGameMap()->NUMBER_TILES; j++)
		{
			tmpTile = _data->GetGameMap()->GetTileAtPosition(&i, &j);

			if (tmpTile != nullptr)
			{
				if (tmpTile->GetRenderer() == nullptr)
					printf("caca");

				_screen.draw(tmpTile->GetRenderer(), i*5, j*5);
				tmpTile = nullptr;
			}
		}
	}
}
