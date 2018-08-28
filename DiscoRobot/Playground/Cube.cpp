#include "Cube.h"



Cube::Cube()
{
}

const void* Cube::getVerticesArrayStart()
{
	return cubeVerts;
}

const size_t Cube::getVerticesSize()
{
	return sizeof(cubeVerts);
}

const int Cube::getTrianglesCount()
{
	return 36;
}

const void * Cube::getNormalsArrayStart()
{
	return cubeNorms;
}

const size_t Cube::getNormalsSize()
{
	return sizeof(cubeNorms);
}

const void * Cube::getIndicesArrayStart()
{
	return cubeIndices;
}

const size_t Cube::getIndicesSize()
{
	return sizeof(cubeIndices);
}

const unsigned int Cube::getIndicesCount()
{
	return sizeof(cubeIndices) / sizeof(GLuint);
}

Cube::~Cube()
{
}
