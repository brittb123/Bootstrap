#include "World.h"

void World::start()
{
	onStart();
	m_started = true;
<<<<<<< HEAD
=======
}

void World::update(float deltaTime)
{
	if (!m_started) {
		start();
	}

	//Create camera transforms
	//m_camera.setTransform(glm::lookAt(
	//	glm::vec3(1.0f, 1.0f, 1.0f),
	//	glm::vec3(0.0f),
	//	glm::vec3(0.0f, 1.0f, 0.0f)
	//));
	m_camera.setPosition(glm::vec3(1.0f, 1.0f, 1.0f));
	m_camera.setYaw(-135.0f);
	m_camera.setPitch(-35.0f);
	m_projectionMatrix = glm::perspective(
		m_camera.getFieldOfView() * glm::pi<float>() / 180.0f,
		(float)m_width / (float)m_height,
		m_camera.getNearClip(),
		m_camera.getFarClip()
	);
>>>>>>> main
}
	onUpdate(deltaTime);

	//Update the list of entities
	for (Entity* entity : addList) {
		entities.push_back(entity);
	}
	addList.clear();
	entities.unique();
	for (Entity* entity : removeList) {
		entities.remove(entity);
	}
	removeList.clear();
	for (Entity* entity : destroyList) {
		entities.remove(entity);
		delete entity;
	}
	destroyList.clear();

	//Update the entities
	for (Entity* entity : entities) {
		entity->update(deltaTime);
	}
}

void World::draw()
{
	onDraw();

	for (Entity* entity : entities) {
		entity->draw();
	}
}

void World::end()
{
	onEnd();
}

void World::add(Entity* entity)
{
	return m_projectionMatrix * m_camera.getViewMatrix() * m_quad.getTransform();
	removeList.remove(entity);
	addList.push_back(entity);
}

void World::remove(Entity* entity)
{
	addList.remove(entity);
	removeList.push_back(entity);
}

void World::destroy(Entity* entity)
{
	addList.remove(entity);
	removeList.remove(entity);
	destroyList.push_back(entity);
}
