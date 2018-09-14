#include "sfere.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace glm;

void Sfere::initialize(float radius, int stacks, int slices)
{
	_vertices.clear();
	_normals.clear();
	float fstacks = (float)stacks;
	float fslices = (float)slices;
	for (int i = 0; i < slices; i++) {
		for (int j = 0; j < stacks; j++) {
			// Top left
			_vertices.push_back(vec3(
				radius * -cos(2.0f * M_PI * i / fstacks) * sin(M_PI * (j + 1.0f) / fslices),
				radius * -cos(M_PI * (j + 1.0f) / fslices),
				radius * sin(2.0f * M_PI * i / fstacks) * sin(M_PI * (j + 1.0f) / fslices)));
			_normals.push_back(glm::normalize(vec3(
				-cos(2.0f * M_PI * i / fstacks) * sin(M_PI * (j + 1.0f) / fslices),
				-cos(M_PI * (j + 1.0f) / fslices),
				sin(2.0f * M_PI * i / fstacks) * sin(M_PI * (j + 1.0f) / fslices))));
			// Top right
			_vertices.push_back(vec3(
				radius * -cos(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * (j + 1.0) / fslices),
				radius * -cos(M_PI * (j + 1.0) / fslices),
				radius * sin(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * (j + 1.0) / fslices)));
			_normals.push_back(glm::normalize(vec3(
				-cos(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * (j + 1.0) / fslices),
				-cos(M_PI * (j + 1.0) / fslices),
				sin(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * (j + 1.0) / fslices))));
			// Bottom right
			_vertices.push_back(vec3(
				radius * -cos(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * j / fslices),
				radius * -cos(M_PI * j / fslices),
				radius * sin(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * j / fslices)));
			_normals.push_back(glm::normalize(vec3(
				-cos(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * j / fslices),
				-cos(M_PI * j / fslices),
				sin(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * j / fslices))));

			// Need to repeat 2 of the vertices since we can only draw triangles. Eliminates the confusion
			// of array indices.
			// Top left
			_vertices.push_back(vec3(
				radius * -cos(2.0f * M_PI * i / fstacks) * sin(M_PI * (j + 1.0f) / fslices),
				radius * -cos(M_PI * (j + 1.0f) / fslices),
				radius * sin(2.0f * M_PI * i / fstacks) * sin(M_PI * (j + 1.0f) / fslices)));
			_normals.push_back(glm::normalize(vec3(
				-cos(2.0f * M_PI * i / fstacks) * sin(M_PI * (j + 1.0f) / fslices),
				-cos(M_PI * (j + 1.0f) / fslices),
				sin(2.0f * M_PI * i / fstacks) * sin(M_PI * (j + 1.0f) / fslices))));
			// Bottom right
			_vertices.push_back(vec3(
				radius * -cos(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * j / fslices),
				radius * -cos(M_PI * j / fslices),
				radius * sin(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * j / fslices)));
			_normals.push_back(glm::normalize(vec3(
				-cos(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * j / fslices),
				-cos(M_PI * j / fslices),
				sin(2.0f * M_PI * (i + 1.0) / fstacks) * sin(M_PI * j / fslices))));
			// Bottom left
			_vertices.push_back(vec3(
				radius * -cos(2.0f * M_PI * i / fstacks) * sin(M_PI * j / fslices),
				radius * -cos(M_PI * j / fslices),
				radius * sin(2.0f * M_PI * i / fstacks) * sin(M_PI * j / fslices)));
			_normals.push_back(glm::normalize(vec3(
				-cos(2.0f * M_PI * i / fstacks) * sin(M_PI * j / fslices),
				-cos(M_PI * j / fslices),
				sin(2.0f * M_PI * i / fstacks) * sin(M_PI * j / fslices))));

		}
	}


}
Sfere::Sfere()
{
	initialize(20, 20, 20);
}

Sfere::Sfere(float radius, int stacks, int slices)
{
	initialize(radius, stacks, slices);
}

const void* Sfere::getVerticesArrayStart()
{
	return &_vertices[0];
}

const size_t Sfere::getVerticesSize()
{
	return sizeof(glm::vec3)*_vertices.size();
}

const int Sfere::getTrianglesCount()
{
	return _vertices.size();
}

const void* Sfere::getNormalsArrayStart()
{
	return &_normals[0];
}

const size_t Sfere::getNormalsSize()
{
	return sizeof(glm::vec3)*_normals.size();
}

const void* Sfere::getIndicesArrayStart()
{
	return nullptr;
}

const size_t Sfere::getIndicesSize()
{
	return size_t();
}

Sfere::~Sfere()
{
}
