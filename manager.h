#ifndef MANAGER_H_
#define MANAGER_H_

class Manager
{
public:
	static void Initialize();
	static void Finalize();
	static void Update();
	static void Draw();
	//static Scene* GetScene();
};

#endif // !MANAGER_H_
