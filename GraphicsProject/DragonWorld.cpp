#include "DragonWorld.h"
#include "glm/ext.hpp"
#include "gl_core_4_4.h"

void DragonWorld::onStart()
{
	
	if (!m_Texture.load("earth_diffuse.jpg"))
	{
		printf("Failed to load texture");
	}
	m_quad.getTransform();
	m_quad.start();
	m_quad.getTransform()->setScale(glm::vec3(2.0f, 2.0f, 2.0f));
	
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	m_light = new Light(
		{ -1.0f, 0.0f, -1.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f });
	m_light->setIndex(0);
	add(m_light);

	m_leftLight = new Light(
		{ 1.0f, 0.0f, 1.0f },
		{ 0.5f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f}
	);
	m_leftLight->setIndex(1);
	add(m_leftLight);


	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->getTransform();
	m_dragon->load("Dragon.obj");
	m_dragon->getTransform()->setPosition(glm::vec3(0.0f, -2.0f, 0.0f));
	m_dragon->getTransform()->setScale(0.1f, 0.1f, 0.1f);
	add(m_dragon);

}



void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_dragon);

}

void DragonWorld::onDraw()
{
   
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("Failed to load shader");

	int diffuseTextureAmbient = glGetUniformLocation(program, "fTexture");
	if (diffuseTextureAmbient >= 0)
		glUniform1i(diffuseTextureAmbient, 0);

	glActiveTexture(GL_TEXTURE);
	glBindTexture(GL_TEXTURE_2D, m_Texture.getHandle());

	m_quad.draw();
}
