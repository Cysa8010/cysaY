#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
private:
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

	Object() :m_Destroy(false) {}
	virtual ~Object() {}
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
	}
};

#endif // !OBJECT_H_
