#version 330 core

layout(location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;
uniform mat4 SPOT_LIGHT_ROTATION;

smooth out vec3 fragNormal;
out vec4 fragPosition;
out vec4 rotatingReflectorPosition;
out vec4 rotatingSpotlightFocusSpot;
out vec4 staticReflectorPosition;
out vec4 staticSpotlightFocusSpot;

void main(){

	mat4 VM =  V * M;
    gl_Position = P * VM * vec4(position, 1.0f); 
	fragNormal = mat3(transpose(inverse(VM)))*normal;
	rotatingReflectorPosition = V * vec4(5,15,5,1);
	rotatingSpotlightFocusSpot = V * SPOT_LIGHT_ROTATION * vec4(15,0,15,1);
	staticReflectorPosition = V * vec4(0,10,0,1);
	staticSpotlightFocusSpot = V * vec4(5,0,5,1);
	fragPosition = VM * vec4(position, 1.0f);
}

