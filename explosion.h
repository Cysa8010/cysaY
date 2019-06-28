#ifndef EXPLOSION_H_
#define EXPLOSION_H_

class Explosion:public Object
{
private:
	Texture* m_Tex;
	CPolygon* m_Polygon;

public:
	Explosion();
	~Explosion()override;
	void Initialize()override;
	void Finalize()override;
	void Update()override;
	void Draw()override;

};

#endif // !EXPLOSION_H_
