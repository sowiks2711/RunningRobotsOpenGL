#version 330 core

// Ouput data
out vec4 fragcolor;

in vec3 fragNormal;
in vec4 fragPosition;

uniform vec4 _emission;
uniform vec4 _diffuse;
uniform vec4 _specular;
uniform float _shininess;
const int lightsCapacity = 20;
uniform int _lightsUsed;
uniform vec4 _lightsPositions[lightsCapacity];
uniform vec4 _lightsColors[lightsCapacity];

vec4 ComputeLight(const in vec3 direction, const in vec4 lightcolor, const in vec3 normal, const in vec3 halfvec, const in vec4 mydiffuse, const in vec4 myspecular, const in float myshininess) {

        float nDotL = dot(normal, direction)  ;         
        vec4 lambert = mydiffuse * lightcolor * max (nDotL, 0.0) ;  

        float nDotH = dot(normal, halfvec) ; 
        vec4 phong = myspecular * lightcolor * pow (max(nDotH, 0.0), myshininess) ; 

        vec4 retval = lambert + phong ; 
        return retval ;            
}    
void main()
{
	vec4 color = vec4(0,0,0,0); 
	vec4 diffuse = _diffuse; 
	vec4 specular = _specular;
	float shininess = _shininess;
	vec4 ambient = vec4(0.2, 0.2, 0.2, 1);
	const vec3 eyepos = vec3(0,0,0);

	vec3 mypos = fragPosition.xyz / fragPosition.w ; // Dehomogenize current location 
	vec3 eyedirn = normalize(eyepos - mypos) ; 

	for (int i = 0; i < _lightsUsed; i++ )
	{
		vec4 lightposn = _lightsPositions[i];
		vec4 lightcolor = _lightsColors[i]; 
		vec3 position = lightposn.xyz/lightposn.w;
		vec3 direction = normalize (position - mypos); // no attenuation 
		vec3 half1 = normalize (direction + eyedirn) ;  
		color = color + ComputeLight(direction, lightcolor, normalize(fragNormal), half1, diffuse, specular, shininess);
	}

	color = color + ambient; 
	color = color + _emission;
	fragcolor = color;
}