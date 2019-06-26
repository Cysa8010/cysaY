#ifndef RENDERER_H_
#define RENDERER_H_

class Renderer
{
public:
	static void Initialize();
	static void Finalize();
	static void Begin();
	static void End();

	static void SetMatrix2D();


};

#endif // !RENDERER_H_
