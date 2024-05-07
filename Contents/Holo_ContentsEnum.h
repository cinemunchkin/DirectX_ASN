#pragma once

enum class ERenderOrder
{
	Holo_Back,
	MonsterUp,
	Attack,
	Player,
	MonsterDown,
	Weapon,
	Pointer,

};

enum class ECollisionOrder
{
	Player,
	Monster,
	Attack,
};

enum class EDir
{
	Left,
	Right,
};

enum class Atk_State
{
	None,
	Atk_Animation,
	Atk_Animation_End,
};



enum class EPlayerDir
{
	None,
	Up,
	UpRight,
	Right,
	DownRight,
	Down,
	DownLeft,
	Left,
	UpLeft,
};


enum class EPointerDir
{
	None,
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