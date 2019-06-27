#ifndef PLAYER_H_
#define PLAYER_H_

class Player:public Object
{
private:
	Texture* tex;
	CPolygon* m_Polygon;
public:
	Player();
	~Player()override;
	void Initialize()override;
	void Finalize()override;
	void Update()override;
	void Draw()override;
};

#endif // !PLAYER_H_
