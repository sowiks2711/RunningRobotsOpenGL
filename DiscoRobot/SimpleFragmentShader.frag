#version 330 core

// Ouput data
out vec4 fragcolor;

in vec3 fragNormal;
in vec4 fragPosition;
in vec4 reflectorPosition;
in vec4 spotlightFocusSpot;

uniform vec4 _emission;
uniform vec4 _diffuse;
uniform vec4 _specular;
uniform float _shininess;
const int lightsCapacity = 20;
uniform int _lightsUsed;
uniform vec4 _lightsPositions[lightsCapacity];
uniform vec4 _lightsColors[lightsCapacity];

vec4 spotLight(const in vec4 lightcolor, const in vec3 normal, const in vec3 eyedirn) {

		vec3 spotlightPosition = reflectorPosition.xyz/reflectorPosition.w;
		vec3 direction = normalize (spotlightPosition  - fragPosition.xyz / fragPosition.w); 
		vec3 surfaceToLight = spotlightPosition - fragPosition.xyz / fragPosition.w ;
		vec3 coneDirection = normalize(spotlightFocusSpot.xyz/spotlightFocusSpot.w-spotlightPosition);
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
	color = color + spotLight(vec4(1, 1, 1, 1), normalize(fragNormal), eyedirn);
	fragcolor = color;
}