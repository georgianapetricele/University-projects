import copy
from Validators import *


class VertexException(Exception):
    pass


class EdgeException(Exception):
    pass


class UndirectedGraph:
    def __init__(self,number_of_vertices: int=0, number_of_edges: int=0):
        self._nr_vertices = number_of_vertices
        self._nr_edges = number_of_edges
        self.vertices = []
        self.neighbours = {}
        self.edges_costs = {}

    def __str__(self):
        string = ""
        string += str(self._nr_vertices) + ' ' + str(self._nr_edges) + '\n'
        valid = {}
        for edge in self.edges_costs.keys():
            valid[edge] = 0
        for edge in self.edges_costs.keys():
            if edge[0] > edge[1]:
                edge = (edge[1],edge[0])
            if valid[edge] == 0:
                valid[edge] = 1
                string+= str(edge[0]) +' ' + str(edge[1]) +' ' + str(self.edges_costs[edge]) + '\n'
        return string

    @property
    def get_edges_costs(self):
        return self.edges_costs

    @property
    def get_number_of_vertices(self):
        return self._nr_vertices

    def set_nr_vertices(self,new_number):
        self._nr_vertices = new_number

    def set_nr_edges(self,new_number):
        self._nr_edges = new_number

    @property
    def get_number_of_edges(self):
        return self._nr_edges

    def add_vertex(self, vertex_to_add):
        if vertex_to_add in self.parse_vertices():
            return False
        self.vertices.append(vertex_to_add)
        self.neighbours[vertex_to_add] = []
        return True

    def remove_vertex(self, vertex_to_remove):
        if vertex_to_remove not in self.parse_vertices():
            return False
        self._nr_vertices-=1
        for edge in self.parse_edges():
            if edge[0] == vertex_to_remove or edge[1] == vertex_to_remove:
                self.remove_edge(edge[0],edge[1])
        self._nr_edges-=1
        del self.neighbours[vertex_to_remove]
        return True

    def add_edge(self, vertex1, vertex2, cost):
        if vertex1 not in self.neighbours[vertex2]:
            if vertex2 not in self.neighbours[vertex1]:
                if (vertex1, vertex2) not in self.edges_costs.keys():
                    self.neighbours[vertex1].append(vertex2)
                    self.neighbours[vertex2].append(vertex1)
                    self.edges_costs[(vertex1, vertex2)] = cost
                    self.edges_costs[(vertex2, vertex1)] = cost
                    return True
        return False

    def remove_edge(self, vertex1, vertex2):
        if vertex1 not in self.parse_vertices() or vertex2 not in self.parse_vertices():
            return False
        if vertex1 not in self.neighbours[vertex2]:
            return False
        elif vertex2 not in self.neighbours[vertex1]:
            return False
        elif (vertex1, vertex2) not in self.edges_costs.keys():
            return False
        self.neighbours[vertex2].remove(vertex1)
        self.neighbours[vertex1].remove(vertex2)
        self.edges_costs.pop((vertex1, vertex2))
        self.edges_costs.pop((vertex2, vertex1))
        self._nr_edges -= 1
        return True

    def get_edge_cost(self,vertex1,vertex2):
        return self.edges_costs[(vertex1, vertex2)]

    def update_edge_cost(self, vertex1, vertex2, cost):
        if (vertex1, vertex2) not in self.edges_costs.keys():
            return False
        self.edges_costs[(vertex1, vertex2)] = cost
        return True

    def parse_vertices(self):
        for v in self.vertices:
            yield v

    def parse_neighbours_for_vertex(self, x):
        for y in self.neighbours[x]:
            yield y

    def parse_edges(self):
        keys = list(self.edges_costs.keys())
        for key in keys:
            yield key

    def get_vertex_degree(self, vertex):
        if vertex not in self.neighbours.keys():
            return -1
        return len(self.neighbours[vertex])

    def find_if_edge_exists(self, vertex1, vertex2):
        if vertex1 in self.neighbours[vertex2]:
            return True
        elif vertex2 in self.neighbours[vertex1]:
            return True
        return False

    def find_if_vertex_exists(self,vertex):
        for edge in list(self.edges_costs.keys()):
            if edge[0] == vertex or edge[1] == vertex:
                return True
        return False

    def make_copy_of_current_graph(self):
        return copy.deepcopy(self)
