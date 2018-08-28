#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 MV;
uniform mat4 P;

smooth out vec3 fragNormal;
out vec4 fragPosition;

void main(){

    gl_Position = P * MV * vec4(position, 1.0f); 
	// Forward these vectors to the fragment shader
	fragNormal = mat3(transpose(inverse(MV)))*normal;
	fragPosition = MV * vec4(position, 1.0f);
}

