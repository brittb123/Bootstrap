#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "OBJMesh.h"
#include "Cube.h"

class DragonWorld : public World
{
public:
	void onStart() override;
	void onEnd() override;
	void onDraw() override;

private:
	PlayerCamera* m_camera = nullptr;
	aie::Texture m_Texture;
	Light* m_light = nullptr;
	OBJMesh* m_dragon = nullptr;
	Cube* m_cube;
};

