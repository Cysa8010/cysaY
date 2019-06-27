#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy :public Object
{
private:
	Texture* m_Tex;
	CPolygon* m_Polygon;

public:
	Enemy();
	~Enemy()override;
	void Initialize()override;
	void Finalize()override;
	void Update()override;
	void Draw()override;

};

#endif // !ENEMY_H_
