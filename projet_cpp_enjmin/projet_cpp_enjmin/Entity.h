#pragma once
#include "GraphicalEntity.h"

class Entity 
{
//CLASSE ABSTRAITE POUR LES OBJETS SUR LA MAP 

	public:
		Entity();
		Entity(int &x, int &y);
	
		~Entity()=default;

		virtual void UpdateEntity()=0;

		int & getPosX();
		int & getPosY();

		void SetPosition(int x, int y)
		{
			_posX = x;
			_posY = y;
		}

		GraphicalEntity& GetRenderer();
		
	protected: 
		int _posX;
		int _posY;

		GraphicalEntity renderer;
};

