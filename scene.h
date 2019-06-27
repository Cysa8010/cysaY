#ifndef SCENE_H_
#define SCENE_H_

// �C���N���[�h�t�@�C��
#include <list>
#include "Object.h"
#include "player.h"
#include "enemy.h"

class Scene
{
private:
//protected://���Q�lprogram�����̂�����ɂȂ��Ă�(�V�[���̊g����?)
	std::list<Object*> m_GameObject;

public:
	Scene(){}
	virtual ~Scene() {}

	virtual void Initialize(){}
	virtual void Finalize(){}
	virtual void Update(){}
	virtual void Draw(){}

	void DestroyGameObject(Object* gameObject)
	{
		gameObject->SetDestroy();
	}

	template <typename T> T* AddGameObject(int Layer)
	{
		T* object = new T();
		object->Initialize();
		m_GameObject[Layer].push_back(object);

		return object;
	}

	template <typename T> T* GetGameObject(int Layer)
	{
		return (T*)nullptr;
	}

	

};

#endif // !SCENE_H_
