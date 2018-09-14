#include "AbstractGeometry.h"

AbstractGeometry::AbstractGeometry()
{
}
const void * AbstractGeometry::getVerticesArrayStart()
{
	return nullptr;
}
const size_t AbstractGeometry::getVerticesSize()
{
	return size_t();
}
const int AbstractGeometry::getTrianglesCount()
{
	return 0;
}
const void * AbstractGeometry::getNormalsArrayStart()
{
	return nullptr;
}
const size_t AbstractGeometry::getNormalsSize()
{
	return size_t();
}
const void * AbstractGeometry::getIndicesArrayStart()
{
	return nullptr;
}
const size_t AbstractGeometry::getIndicesSize()
{
	return size_t();
}
AbstractGeometry::~AbstractGeometry()
{
}

