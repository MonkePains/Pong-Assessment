
#ifndef WHACKAMOLESFML_VECTOR_H
#define WHACKAMOLESFML_VECTOR_H

class Vector
{
 public:
	 Vector()
	 {
		 x = 0.2, y = -3;
     } 
	 Vector(float newX, float newY)
	 {
		 x = newX, y = newY;
	 }
	 Vector normalise() 
	 { 
		 float magnitude = sqrt(x * x + y * y);
         float newX      = x / magnitude;
         float newY      = y / magnitude;
	 }
	 Vector operator*(float scalar)
	 { 
		 return Vector(x * scalar, y * scalar);
	 }
	 float x, y;
};
























#endif // WHACKAMOLESFML_VECTOR_H