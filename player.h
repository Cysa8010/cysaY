#ifndef PLAYER_H_
#define PLAYER_H_

class Player:public Object
{
private:

public:
	Player();
	~Player();
	void Finalize();
	void Update();
	void Draw();
};

#endif // !PLAYER_H_
