#pragma once
#include "Player.h"
#include "Team.h"
#include "Match.h"
class General : public Team , public Player , public Match
{
public:
	General();
	void Display_3_Frist_Teams();
	~General();
};

