#include "View.h"
#include <string>
#include <ctime>

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

void View::Update()
{
	//chopper les données dans data
	//mettre a jour les positions des entitées
}

void View::Render()
{
	_screen.clear();

	for (char i = 0; i < _nbEntities; ++i)
	{
		_screen.draw(_entities[i],0,0);
	}

	_screen.draw(florent_str.c_str(), 86, 7, 0, 0);
	_screen.flip();
}
