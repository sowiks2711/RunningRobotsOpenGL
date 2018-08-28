#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <GLFW/glfw3.h>
class AbstractGeometry
{
public:
	AbstractGeometry();
	virtual const void* getVerticesArrayStart();
	virtual const size_t getVerticesSize();
	virtual const int getTrianglesCount();
	virtual const void* getNormalsArrayStart();
	virtual const size_t getNormalsSize();
	virtual const void* getIndicesArrayStart();
	virtual const size_t getIndicesSize();
	~AbstractGeometry();
};

