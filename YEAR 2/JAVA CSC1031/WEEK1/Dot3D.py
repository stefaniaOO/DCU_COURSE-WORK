import math

class Dot3D(object):
	def __init__(self, x, y, z, label):
		self.x = x
		self.y = y
		self.z = z
		self.label = label

	def distance_to(self,other):
		distance = math.sqrt((other.x - self.x) ** 2 + (other.y - self.y) ** 2 + (other.z - self.z) ** 2)
		return distance

	def add_vector(self, other):
		new_x = self.x + other.x
		new_y = self.y + other.y
		new_z = self.z + other.z
		new_label = self.label + "+"+other.label
		return Dot3D(new_x, new_y, new_z, new_label)


#task describtion:

"""
A dot in 3D space is represented by three coordinates (x, y, z) that define its position in a three-dimensional plane. For example, (3, 4, 5) represents a dot located at x-coordinate 3, y-coordinate 4, and z-coordinate 5.

A vector in 3D space is a mathematical object that has both direction and magnitude. It is often represented as a set of three components (vx, vy, vz), which describe how far and in which direction to move along each axis.

Adding two vectors involves adding their corresponding components. For example, adding (1, 2, 3) and (4, 5, 6) results in (5, 7, 9). This operation shifts one vector by the magnitude and direction of another.

The distance between two dots is the straight-line distance in 3D space, calculated using the Euclidean distance formula:

distance = √((x2 - x1)^2 + (y2 - y1)^2 + (z2 - z1)^2)
This measures the shortest path connecting the two dots.

Requirements
Create a class called Dot3D.

The class should take four inputs: x, y, z (coordinates), and label (optional, e.g., "x1").

Implement the following methods:

distance_to(self, other): Calculate the Euclidean distance between the current dot and another dot. Return the computed distance.

add_vector(self, other): Add the current dot’s coordinates to another dot’s coordinates (vector addition) and return a new Dot3D instance with the resulting coordinates and label containg both intial labels with + sign (for example, "A+B" where "A" and "B" - are the original labels).

Example Usage
After creating the class and implementing the methods, test it as follows:

class Dot3D:
    ...

dot1 = Dot3D(3, 4, 5, "x1")
dot2 = Dot3D(6, 8, 10, "x2")

distance = dot1.distance_to(dot2)
print(distance)  # 7.0710678118654755

resultant = dot1.add_vector(dot2)
print(resultant)  # returns Dot3D(9, 12, 15, label="x1+x2")

"""