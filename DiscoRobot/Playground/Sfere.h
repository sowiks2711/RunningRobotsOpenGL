#pragma once
#include "Cube.h"
#include <glm/glm.hpp>
class Sfere:
	public AbstractGeometry
{	
	std::vector<glm::vec3> _vertices;
	std::vector<glm::vec3> _normals;
	void initialize(float radius, int stacks, int slices);
public:
	Sfere();
	Sfere(float radius, int stacks, int slices);
	const void* getVerticesArrayStart();
	const size_t getVerticesSize();
	const int getTrianglesCount();
	const void* getNormalsArrayStart();
	const size_t getNormalsSize();
	const void* getIndicesArrayStart();
	const size_t getIndicesSize();
	~Sfere();
};

