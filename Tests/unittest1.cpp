#include "stdafx.h"
#include "CppUnitTest.h"
#include ".\..\DiscoRobot\Playground\Transform.h"
#include ".\..\DiscoRobot\Playground\Transform.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(Transformations)
	{
		void AssertMat4Equal(glm::mat4 expected, glm::mat4 actual) 
		{
			Assert::AreEqual((double)expected[0][0], (double)actual[0][0], expected[0][0]/1000.0);
			Assert::AreEqual((double)expected[0][1], (double)actual[0][1], expected[0][1]/1000.0);
			Assert::AreEqual((double)expected[0][2], (double)actual[0][2], expected[0][2]/1000.0);
			Assert::AreEqual((double)expected[0][3], (double)actual[0][3], expected[0][3]/1000.0);
			Assert::AreEqual((double)expected[1][0], (double)actual[1][0], expected[1][0]/1000.0);
			Assert::AreEqual((double)expected[1][1], (double)actual[1][1], expected[1][1]/1000.0);
			Assert::AreEqual((double)expected[1][2], (double)actual[1][2], expected[1][2]/1000.0);
			Assert::AreEqual((double)expected[1][3], (double)actual[1][3], expected[1][3]/1000.0);
			Assert::AreEqual((double)expected[2][0], (double)actual[2][0], expected[2][0]/1000.0);
			Assert::AreEqual((double)expected[2][1], (double)actual[2][1], expected[2][1]/1000.0);
			Assert::AreEqual((double)expected[2][2], (double)actual[2][2], expected[2][2]/1000.0);
			Assert::AreEqual((double)expected[2][3], (double)actual[2][3], expected[2][3]/1000.0);
			Assert::AreEqual((double)expected[3][0], (double)actual[3][0], expected[3][0]/1000.0);
			Assert::AreEqual((double)expected[3][1], (double)actual[3][1], expected[3][1]/1000.0);
			Assert::AreEqual((double)expected[3][2], (double)actual[3][2], expected[3][2]/1000.0);
			Assert::AreEqual((double)expected[3][3], (double)actual[3][3], expected[3][3]/1000.0);

		}
	public:
		
		TEST_METHOD(LookAt1)
		{
			glm::mat4 expected = glm::lookAt(
				glm::vec3(0, 0, -1),
				glm::vec3(0, 0, 0),
				glm::vec3(0, 1, 0)
			);
			glm::mat4 actual = Transform::lookAt(
				glm::vec3(0, 0, -1),
				glm::vec3(0, 0, 0),
				glm::vec3(0, 1, 0)
			);
			AssertMat4Equal(expected, actual);
		}

		TEST_METHOD(LookAt2)
		{
			glm::mat4 expected = glm::lookAt(
				glm::vec3(10, 0, -1),
				glm::vec3(0, 20, 0),
				glm::vec3(0, 1, 0)
			);
			glm::mat4 actual = Transform::lookAt(
				glm::vec3(10, 0, -1),
				glm::vec3(0, 20, 0),
				glm::vec3(0, 1, 0)
			);
			AssertMat4Equal(expected, actual);
		}
		TEST_METHOD(Perspective)
		{
			float fov = (float)(M_PI/2);
			float aspectRatio = 1024/868.;
			float zNear = 0.1f;
			float zFar = 100.0f;
			glm::mat4 expected = glm::perspective(
				fov,
				aspectRatio,
				zNear,
				zFar
			);
			glm::mat4 actual = Transform::perspective(
				fov,
				aspectRatio,
				zNear,
				zFar
			);
			AssertMat4Equal(expected, actual);
		}

		TEST_METHOD(Rotate)
		{
			glm::vec3 rotationAxis(1, 1, 0);
			float angle = (float)(45.0f*M_PI/180);
			glm::mat4 ident = glm::mat4(1.0);
			glm::mat4 expected = glm::rotate(
				ident,
				angle,
				rotationAxis
			);
			glm::mat4 actual = Transform::rotate(
				angle,
				rotationAxis
			);
			glm:mat4 result = glm::mat4(1.0) * actual;
			AssertMat4Equal(expected, result);
		}
	};
}