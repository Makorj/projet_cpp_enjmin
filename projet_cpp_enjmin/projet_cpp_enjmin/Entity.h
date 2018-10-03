#pragma once
class Entity 
{
//CLASSE ABSTRAITE POUR LES OBJETS SUR LA MAP 
//LES TUILES CONTIENNENT DES ENTITY 

	public:
		Entity();
		Entity(int x, int y);
		virtual ~Entity()=0;

		int & getPosX();
		int & getPosY();

	protected: 
		int _posX;
		int _posY;
};

