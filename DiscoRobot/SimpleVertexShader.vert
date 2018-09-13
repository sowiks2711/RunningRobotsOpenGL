#version 330 core

layout(location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

smooth out vec3 fragNormal;
out vec4 fragPosition;
out vec4 reflectorPosition;
out vec4 spotlightFocusSpot;

void main(){

	mat4 VM =  V * M;
    gl_Position = P * VM * vec4(position, 1.0f); 
	fragNormal = mat3(transpose(inverse(VM)))*normal;
	reflectorPosition = V * vec4(5,15,5,1);
	spotlightFocusSpot = V * vec4(15,0,15,1);
	fragPosition = VM * vec4(position, 1.0f);
}

