#ifndef INPUT_H_
#define INPUT_H_

class Input
{
private:
	static BYTE m_OldKeyState[256];
	static BYTE m_KeyState[256];

public:
	static void Initialize();
	static void Finalize();
	static void Update();

	static bool GetKeyPress(BYTE KeyCode);
	static bool GetKeyTrigger(BYTE KeyCode);

	//static XMFLOAT3& GetDirection();
};


#endif // !INPUT_H_
