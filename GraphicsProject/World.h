#pragma once
#include "Entity.h"
#include "Camera.h"
#include "Shader.h"
#include <list>
#include "Camera.h"
#include "Quad.h"
#include "glm/mat4x4.hpp"

class World
{
public:
	World() {}
	~World() {}

	void start();
	void update(float deltaTime);
	void draw();
	void end();

	virtual void onStart() {}
	virtual void onUpdate(float deltaTime) {}
	virtual void onDraw() {}
	virtual void onEnd() {}

	void add(Entity* entity);
	void remove(Entity* entity);
	void destroy(Entity* entity);

	Camera* getCamera() { return m_camera; }
	void setCamera(Camera* camera) { m_camera = camera; }

private:
	Camera* m_camera = nullptr;

	std::list<Entity*> entities;
	std::list<Entity*> addList;
	std::list<Entity*> removeList;
	std::list<Entity*> destroyList;

	bool m_started = false;
	Quad m_quad = Quad(glm::vec4(0.2f, 0.8f, 0.6f, 1.0f));
	Camera m_camera = Camera();
	glm::mat4 m_projectionMatrix = glm::mat4(1.0f);
};

