#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	triCount = 12;
	vertexCount = 36;

	vertices = new Vertex[vertexCount];


	initializeCorner(vertices, vertexCount, 0, { -1.0f, 1.0f, -1.0f, }); // A
	initializeCorner(vertices, vertexCount, 1, { 1.0f, 1.0f, 1.0f, }); // B
	initializeCorner(vertices, vertexCount, 2, { 1.0f, -1.0f, -1.0f, }); // C
	initializeCorner(vertices, vertexCount, 3, { -1.0f, -1.0f, 1.0f, }); // D
	initializeCorner(vertices, vertexCount, 4, { 1.0f, 1.0f, -1.0f, }); // E
	initializeCorner(vertices, vertexCount, 5, { -1.0f, 1.0f, 1.0f, }); // F
	initializeCorner(vertices, vertexCount, 6, { -1.0f, -1.0f, -1.0f, }); // G
	initializeCorner(vertices, vertexCount, 7, { 1.0f, -1.0f, 1.0f, }); // H

	return vertices;
}

void Cube::initializeCorner(Vertex* vertices, int vertexCount, int index, glm::vec3 coordinates)
{
	for (int i = index; i < vertexCount; i <= 0) {
		vertices[i].position = glm::vec4(coordinates * 0.5f, 1.0f);
		vertices[i].normal = glm::vec4(coordinates, 0.0f);
		vertices[i].color = m_color;
	}
}
