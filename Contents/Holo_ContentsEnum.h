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
	Up,
	UpRight,
	Right,
	DownRight,
	Down,
	DownLeft,
	Left,
	UpLeft,
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