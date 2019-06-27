#ifndef SCENE_H_
#define SCENE_H_

// インクルードファイル
#include <list>
#include <vector>
#include <typeinfo>
#include "texture.h"
#include "polygon.h"
#include "Object.h"
#include "player.h"
#include "enemy.h"

class Scene
{
private:
//protected://←参考programが何故かこれになってる(シーンの拡張性?)
	/* 0:BG 1:BackEffect 2:chara 3:FrontEffect 4:UI  */
	std::list<Object*> m_GameObjects[5];

public:
	Scene(){}
	virtual ~Scene() {}

	virtual void Initialize()
	{
		AddGameObject<Player>(2);
		AddGameObject<Enemy>(2);
		AddGameObject<Enemy>(2);
		AddGameObject<Enemy>(2);
		AddGameObject<Enemy>(2);
		AddGameObject<Enemy>(2);

		std::vector<Enemy*> enemys = GetGameObjects<Enemy>(2);
		int cnt = 0;
		for (Enemy* enemy : enemys)
		{
			enemy->SetPosition(D3DXVECTOR3(700.f, 50.f + (cnt * 100), 0.f));
			cnt++;
			
		}
	}
	virtual void Finalize()
	{
		for (int i = 0; i < 5; i++)
		{
			for (Object* object : m_GameObjects[i])
			{
				object->Finalize();
				delete object;
			}
			m_GameObjects[i].clear();
		}
	}
	virtual void Update()
	{
		for (int i = 0; i < 5; i++)
		{
			for (Object* object : m_GameObjects[i])
			{
				object->Update();
			}
			m_GameObjects[i].remove_if(
				[](Object* object) {return object->Destroy(); }
			);
		}
	}
	virtual void Draw()
	{
		for (int i = 0; i < 5; i++)
		{
			for (Object* object : m_GameObjects[i])
			{
				object->Draw();
			}
		}
	}

	void DestroyGameObject(Object* gameObject)
	{
		gameObject->SetDestroy();
	}

	template <typename T> T* AddGameObject(int Layer)
	{
		T* object = new T();
		object->Initialize();
		m_GameObjects[Layer].push_back(object);

		return object;
	}

	template <typename T> T* GetGameObject(int Layer)
	{
		for (Object* object : m_GameObjects[Layer])
		{
			if (typeid(*object) == typeid(T))
			{
				return (T*)object;
			}
		}
		return (T*)nullptr;
	}

	template <typename T> std::vector<T*> GetGameObjects(int Layer)
	{
		std::vector<T*> objects;
		for (Object* object : m_GameObjects[Layer])
		{
			if (typeid(*object) == typeid(T))
			{
				objects.push_back((T*)object);
			}
		}
		return objects;
	}

	

};

#endif // !SCENE_H_
