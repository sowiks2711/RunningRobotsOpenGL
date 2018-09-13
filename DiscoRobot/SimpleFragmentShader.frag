#version 330 core

// Ouput data
out vec4 fragcolor;

in vec3 fragNormal;
in vec4 fragPosition;
in vec4 rotatingReflectorPosition;
in vec4 rotatingSpotlightFocusSpot;
in vec4 staticReflectorPosition;
in vec4 staticSpotlightFocusSpot;

uniform vec4 _emission;
uniform vec4 _diffuse;
uniform vec4 _specular;
uniform float _shininess;
const int lightsCapacity = 20;
uniform int _lightsUsed;
uniform vec4 _lightsPositions[lightsCapacity];
uniform vec4 _lightsColors[lightsCapacity];

vec4 spotLight(const in vec4 lightcolor, const in vec3 normal, const in vec3 eyedirn, in vec3 reflectorPosition, in vec3 spotlightFocusPosition) {

		vec3 direction = normalize (reflectorPosition  - fragPosition.xyz / fragPosition.w); 
		vec3 surfaceToLight = reflectorPosition - fragPosition.xyz / fragPosition.w ;
		vec3 coneDirection = normalize(spotlightFocusPosition-reflectorPosition);
		vec3 rayDirection = normalize(-surfaceToLight);
		float lightToSurfaceAngle = degrees(acos(dot(rayDirection, coneDirection)));

		vec3 halfvec = normalize (direction + eyedirn) ;  
        float nDotL = dot(normal, direction)  ;         
        vec4 lambert = _diffuse * lightcolor * max (nDotL, 0.0) ;  

        float nDotH = dot(normal, halfvec) ; 
        vec4 phong = _specular * lightcolor * pow (max(nDotH, 0.0), _shininess) ; 

        vec4 retval = lambert + phong ; 
		if (lightToSurfaceAngle > 20)
			retval = vec4(0,0,0,0);

        return retval ;            
}    

vec4 ComputeLight(const in vec3 direction, const in vec4 lightcolor, const in vec3 normal, const in vec3 eyedirn) {

		vec3 halfvec = normalize (direction + eyedirn) ;  
        float nDotL = dot(normal, direction)  ;         
        vec4 lambert = _diffuse * lightcolor * max (nDotL, 0.0) ;  

        float nDotH = dot(normal, halfvec) ; 
        vec4 phong = _specular * lightcolor * pow (max(nDotH, 0.0), _shininess) ; 

        vec4 retval = lambert + phong ; 

        return retval ;            
}    
void main()
{
	vec4 color = vec4(0,0,0,0); 
	vec4 ambient = vec4(0.2, 0.2, 0.2, 1);
	const vec3 eyepos = vec3(0,0,0);

	vec3 mypos = fragPosition.xyz / fragPosition.w ; 
	vec3 eyedirn = normalize(eyepos - mypos) ; 

	for (int i = 0; i < _lightsUsed; i++ )
	{
		vec4 lightposn = _lightsPositions[i];
		vec4 lightcolor = _lightsColors[i]; 
		vec3 position = lightposn.xyz/lightposn.w;
		vec3 direction = normalize (position - mypos); 
		color = color + ComputeLight(direction, lightcolor, normalize(fragNormal), eyedirn);
	}

	color = color + ambient; 
	color = color + _emission;
	color = color + spotLight(vec4(1, 1, 1, 1), normalize(fragNormal), eyedirn, rotatingReflectorPosition.xyz/rotatingReflectorPosition.w, rotatingSpotlightFocusSpot.xyz/rotatingSpotlightFocusSpot.w);
	color = color + spotLight(vec4(0, 1, 0, 1), normalize(fragNormal), eyedirn, staticReflectorPosition.xyz/staticReflectorPosition.w, staticSpotlightFocusSpot.xyz/staticSpotlightFocusSpot.w);
	fragcolor = color;
}