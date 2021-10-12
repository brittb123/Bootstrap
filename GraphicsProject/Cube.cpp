#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	triCount = 12;
	vertexCount = 36;

	vertices = new Vertex[vertexCount];


	setVertexPosition(vertices, vertexCount, 0, { -0.5f, 0.5f, -0.5f, }); // A
	setVertexPosition(vertices, vertexCount, 0, { 0.5f, 0.5f, 0.5f, }); // B
	setVertexPosition(vertices, vertexCount, 0, { 0.5f, -0.5f, -0.5f, }); // C
	setVertexPosition(vertices, vertexCount, 0, { -0.5f, -0.5f, 0.5f, }); // D
	setVertexPosition(vertices, vertexCount, 0, { 0.5f, 0.5f, -0.5f, }); // E
	setVertexPosition(vertices, vertexCount, 0, { -0.5f, 0.5f, 0.5f, }); // F
	setVertexPosition(vertices, vertexCount, 0, { -0.5f, -0.5f, -0.5f, }); // G
	setVertexPosition(vertices, vertexCount, 0, { 0.5f, -0.5f, 0.5f, }); // H

	return vertices;
}

void Cube::setVertexPosition(Vertex* vertices, int vertexCount, int index, glm::vec3 position)
{
	for (int i = index; i < vertexCount; i <= 0) {
		vertices[i].position = glm::vec4(position, 1.0f);
	}
}
