#pragma once

enum class ERenderOrder
{
	Holo_Back,
	MonsterUp,
	Player,
	MonsterDown,
	Weapon,
	Cursor,
};

enum class EDir
{
	Left,
	Right,
};

enum class EPlayerDir
{
	N,
	NE,
	E,
	SE,
	S,
	SW,
	W,
	NW,
};

enum class EMonsterMoveType
{
	Follow,
	StraightToPlayer,
	StraightToUp,
	StraightToDown,
	StraightToRight,
	StraightToLeft,
	Stop,
};