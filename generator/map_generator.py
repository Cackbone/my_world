#!/bin/python

import sys

class Vertex:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def display(self):
        print("v {} {} {}".format(self.x, self.y, self.z))

class Face:

    def __init__(self, v1, v2, v3, v4, texture, rotation):
        self.vertices = [v1, v2, v3, v4]
        self.texture = texture
        self.rotation = rotation

    def display(self):
        print("f {} {} {} {} -r{}".format(self.vertices[0],
                                        self.vertices[1],
                                        self.vertices[2],
                                        self.vertices[3],
                                        self.rotation))
class Texture:

    def __init__(self, name, x, y, w, h):
        self.name = name
        self.rect = [x, y, w, h]

    def display(self):
        print("t {} {} {} {} {}".format(self.name,
                                        self.rect[0],
                                        self.rect[1],
                                        self.rect[2],
                                        self.rect[3]))

class Map:

    def __init__(self, xsize, ysize):
        self.xsize = xsize
        self.ysize = ysize
        self.vertices = []
        self.faces = []
        self.textures = []

    def generate(self):
        for y in range(0, self.ysize):
            for x in range(0, self.xsize):
                self.vertices.append(Vertex(x, y, 0))

    def display(self):
        for vertex in self.vertices:
            vertex.display()

    def get_vertex(self, x, y):
        i = 0
        for vertex in self.vertices:
            i += 1
            if (vertex.x == x and vertex.y == y):
                return i
        return -1

    def generateTextures(self):
        self.textures.append(Texture("grass", 0, 0, 32, 32))
        self.textures.append(Texture("water", 32, 32, 32, 32))
        self.textures.append(Texture("stone", 96, 32, 32, 32))
        self.textures.append(Texture("brick", 64, 32, 32, 32))
        self.textures.append(Texture("grass_w", 0, 32, 32, 32))
        self.textures.append(Texture("dirt", 32, 0, 32, 32))

    def generateFaces(self):
        for y in range(0, self.ysize - 2):
            for x in range(0, self.xsize - 2):
                v1 = self.get_vertex(x, y)
                v2 = self.get_vertex(x + 1, y)
                v3 = self.get_vertex(x + 1, y + 1)
                v4 = self.get_vertex(x, y + 1)
                face = Face(v1, v2, v3, v4, self.textures[0], 0)
                self.faces.append(face)

    def save(self):
        print("tm map.jpg\n")
        for vertex in self.vertices:
            vertex.display()
        print("")
        for tex in self.textures:
            tex.display()
        print("")
        for face in self.faces:
            face.display()

def main():
    size = [100, 100]
    if (len(sys.argv) == 3):
        size[0] = int(sys.argv[1])
        size[1] = int(sys.argv[2])
    world = Map(size[0], size[1])
    world.generate()
    world.generateTextures()
    world.generateFaces()
    world.save()

if __name__ == "__main__":
    main()
