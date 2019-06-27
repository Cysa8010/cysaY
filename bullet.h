#ifndef BULLET_H_
#define BULLET_H_

class Bullet :public Object
{
private:
	Texture* m_Tex;
	CPolygon* m_Polygon;

public:
	Bullet();
	~Bullet()override;
	void Initialize()override;
	void Finalize()override;
	void Update()override;
	void Draw()override;

};

#endif // !BULLET_H_
