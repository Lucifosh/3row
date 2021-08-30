#pragma once
enum class AnimState
{
	Down, Up, Left, Right, None
};
class Anim
{
private:
	AnimState state = AnimState::None;
public:
	AnimState getState() { return state; };
	void setState(AnimState s) { state = s; };
};

