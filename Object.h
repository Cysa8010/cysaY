#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
private:
protected:
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scaling;

	bool m_Destroy = false;
public:
	D3DXVECTOR3 GetPosition() { return m_Position; }
	D3DXVECTOR3 GetRotation() { return m_Rotation; }
	D3DXVECTOR3 GetScaling() { return m_Scaling; }

	void SetPosition(D3DXVECTOR3 Position) { m_Position = Position; }
	void SetRotation(D3DXVECTOR3 Rotation) { m_Rotation = Rotation; }
	void SetScaling(D3DXVECTOR3 Scaling) { m_Scaling = Scaling; }

	Object() :m_Destroy(false),	m_Position(D3DXVECTOR3(0.f,0.f,0.f)),
		m_Rotation(D3DXVECTOR3(0.f, 0.f, 0.f)),	m_Scaling(D3DXVECTOR3(1.f, 1.f, 1.f)) {}
	virtual ~Object() {}
	virtual void Initialize(){}
	virtual void Finalize(){}
	virtual void Update(){}
	virtual void Draw(){}
	void SetDestroy() { m_Destroy = true; }
	bool Destroy()
	{
		if (m_Destroy)
		{
			Finalize();
			delete this;
		}
		else
			return false;
		return false;
	}
};

#endif // !OBJECT_H_
