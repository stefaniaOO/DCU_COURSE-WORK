import math

class Dot3D(object):
	def __init__(self, x, y, z,label = None):
		self.x = x;
		self.y = y;
		self.z = z;
		self.label = label;

	def distance_to(self,other):
		distance = math.sqrt((other.x - self.x) ** 2 + (other.y - self.y) ** 2 + (other.z - self.z) ** 2)
		return distance;

	def add_vector(self, other):
		new_x = self.x + other.x;
		new_y = self.y + other.y;
		new_z = self.z + other.z;
		new_label = self.label + "+"+other.label;
		return Dot3D(new_x, new_y, new_z, new_label);


class Triangle3D(object):
	def __init__(self, Dot1 = None, Dot2 = None, Dot3 = None):
		if Dot1 == None:
		    self.Dot1 = Dot3D();
		else:
			self.Dot1 = Dot1;

		if Dot2 == None:
		    self.Dot2 = Dot3D();

		else:
			self.Dot2 = Dot2;

		if Dot3 == None:
		    self.Dot3 = Dot3D();
		else:
			self.Dot3 = Dot3;


	def calculate_perimeter(self):
		edge1 = self.Dot1.distance_to(self.Dot2)
		edge2 = self.Dot2.distance_to(self.Dot3)
		edge3 = self.Dot3.distance_to(self.Dot1)

		perimeter = edge1 + edge2 + edge3
		return perimeter;

		
	def calculate_area(self):
		s_p = self.calculate_perimeter() / 2
		edge1 = self.Dot1.distance_to(self.Dot2)
		edge2 = self.Dot2.distance_to(self.Dot3)
		edge3 = self.Dot3.distance_to(self.Dot1)
		Area = math.sqrt(s_p * (s_p - edge1) * (s_p - edge2) * (s_p - edge3))

		return Area;

		"""
		A 3D triangle is defined by three vertices (dots) in a three-dimensional space. The triangle is represented by connecting the vertices with straight edges.

Perimeter: The sum of the lengths of the triangle’s edges. It is calculated as: ` perimeter = edge1 + edge2 + edge3 ` where edge1, edge2, and edge3 are the distances between the triangle’s vertices.

Area: Calculated using Heron’s formula, which requires the semi-perimeter (s) and the edge lengths:

  s = (edge1 + edge2 + edge3) / 2
  area = √(s * (s - edge1) * (s - edge2) * (s - edge3))
Requirements
Create a class called Triangle3D.

The class should take three Dot3D objects as parameters, representing the triangle’s vertices.

Implement the following methods:

calculate_perimeter(self): Compute and return the perimeter of the triangle.

calculate_area(self): Compute and return the area of the triangle using Heron’s formula.


Here is an example of how the Triangle3D class might be used:

from Triangle3D import *

dot1 = Dot3D(0, 0, 0)
dot2 = Dot3D(3, 0, 0)
dot3 = Dot3D(0, 4, 0)

triangle = Triangle3D(dot1, dot2, dot3)

# Calculate perimeter
perimeter = triangle.calculate_perimeter()
print(perimeter)  # Expected: 12.0

# Calculate area
area = triangle.calculate_area()
print(area)  # Expected: 6.0


"""