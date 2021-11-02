#include "Light.h"
#include "gl_core_4_4.h"

Light::Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular) : Light()
{
	setDirection(direction);
	m_ambient = ambient;
	m_diffuse = diffuse;
	m_specular = specular;
}

void Light::onDraw()
{
	if(m_index < 0)
	{
		printf("First Index failed");
	}
	else if (m_index > 1)
	{
		printf("Passed the index border");
	}

	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1) {
		printf("No shader bound!\n");
		return;
	}

	int lightDirection = 0;
	int lightAmbient = 0;
	int lightSpecular = 0;
	int lightDiffuse = 0;

	std::string str = ("iDirection" + std::to_string(m_index));
	lightDirection = glGetUniformLocation(program, str.c_str());

	str = ("iAmbient" + std::to_string(m_index));
	lightAmbient = glGetUniformLocation(program, str.c_str());

	str = ("iDiffuse" + std::to_string(m_index));
	lightDiffuse = glGetUniformLocation(program, str.c_str());

	str = ("iSpecular" + std::to_string(m_index));
	lightSpecular = glGetUniformLocation(program, str.c_str());


	if (lightDirection >= 0) 
	{
		glm::vec3 direction = getDirection();
		glUniform3f(lightDirection, direction.x, direction.y, direction.z);
	}
	if (lightAmbient >= 0)
	{
		glUniform3f(lightAmbient, m_ambient.x, m_ambient.y, m_ambient.z);
	}
	if (lightDiffuse >= 0) 
	{
		glUniform3f(lightDiffuse, m_diffuse.x, m_diffuse.y, m_diffuse.z);
	}
	if (lightSpecular >= 0) 
	{
		glUniform3f(lightSpecular, m_specular.x, m_specular.y, m_specular.z);
	}
}

glm::vec3 Light::getDirection()
{
	return getTransform()->getForward();
}

void Light::setDirection(glm::vec3 direction)
{
	getTransform()->setForward(direction);
}
