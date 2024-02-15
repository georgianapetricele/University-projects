import copy
from Validators import *


class VertexException(Exception):
    pass


class EdgeException(Exception):
    pass


class DirectedGraph:
    def __init__(self, number_of_vertices=0, number_of_edges=0):
        self._nr_vertices = number_of_vertices
        self._nr_edges = number_of_edges
        self.inbound_vertices = {}
        self.outbound_vertices = {}
        self.edges_costs = {}
        for index in range(number_of_vertices):
            self.inbound_vertices[index] = []
            self.outbound_vertices[index] = []

    def __str__(self):
        string = ""
        string += str(self._nr_vertices) + ' ' + str(self._nr_edges) + '\n'
        for edge in self.edges_costs.keys():
            string+= str(edge[0]) +' ' + str(edge[1]) +' ' + str(self.edges_costs[edge]) + '\n'
        return string

    @property
    def get_edges_costs(self):
        return self.edges_costs

    @property
    def get_inbound_vertices(self):
        return self.inbound_vertices

    @property
    def get_outbound_vertices(self):
        return self.outbound_vertices

    @property
    def get_number_of_vertices(self):
        return self._nr_vertices

    @property
    def get_number_of_edges(self):
        return self._nr_edges

    def add_vertex(self, vertex_to_add):
        if vertex_to_add in self.inbound_vertices.keys() and vertex_to_add in self.outbound_vertices.keys():
            return False
        self.inbound_vertices[vertex_to_add] = []
        self.outbound_vertices[vertex_to_add] = []
        self._nr_vertices += 1
        return True

    def remove_vertex(self, vertex_to_remove):
        if vertex_to_remove not in self.inbound_vertices.keys() and vertex_to_remove not in self.outbound_vertices.keys():
            return False
        self.inbound_vertices.pop(vertex_to_remove)
        self.outbound_vertices.pop(vertex_to_remove)
        for key in self.inbound_vertices.keys():
            if vertex_to_remove in self.inbound_vertices[key]:
                self.inbound_vertices[key].remove(vertex_to_remove)
            elif vertex_to_remove in self.outbound_vertices[key]:
                self.outbound_vertices[key].remove(vertex_to_remove)
        keys = list(self.edges_costs.keys())
        for key in keys:
            start_vertex = key[0]
            dest_vertex = key[1]
            if start_vertex == vertex_to_remove or dest_vertex == vertex_to_remove:
                self.edges_costs.pop(key)
                self._nr_edges -= 1
        self._nr_vertices -= 1
        return True

    def add_edge(self, vertex1, vertex2, cost):
        if vertex1 not in self.inbound_vertices[vertex2]:
            if vertex2 not in self.outbound_vertices[vertex1]:
                if (vertex1, vertex2) not in self.edges_costs.keys():
                    self.inbound_vertices[vertex2].append(vertex1)
                    self.outbound_vertices[vertex1].append(vertex2)
                    self.edges_costs[(vertex1, vertex2)] = cost
                    return True
        return False

    def remove_edge(self, vertex1, vertex2):
        if vertex1 not in self.inbound_vertices.keys() or vertex2 not in self.inbound_vertices.keys() or vertex1 not in self.outbound_vertices.keys() or vertex2 not in self.outbound_vertices.keys():
            return False
        if vertex1 not in self.inbound_vertices[vertex2]:
            return False
        elif vertex2 not in self.outbound_vertices[vertex1]:
            return False
        elif (vertex1, vertex2) not in self.edges_costs.keys():
            return False
        self.inbound_vertices[vertex2].remove(vertex1)
        self.outbound_vertices[vertex1].remove(vertex2)
        self.edges_costs.pop((vertex1, vertex2))
        self._nr_edges -= 1
        return True

    def update_edge_cost(self, vertex1, vertex2, cost):
        if (vertex1, vertex2) not in self.edges_costs.keys():
            return False
        self.edges_costs[(vertex1, vertex2)] = cost
        return True

    def parse_vertices(self):
        vertices = list(self.inbound_vertices.keys())
        for v in vertices:
            yield v

    def parse_inbound_vertices(self, x):
        for y in self.inbound_vertices[x]:
            yield y

    def parse_outbound_vertices(self, x):
        for y in self.outbound_vertices[x]:
            yield y

    def parse_edges(self):
        keys = list(self.edges_costs.keys())
        for key in keys:
            yield key


    def get_in_degree(self, vertex):
        if vertex not in self.inbound_vertices.keys():
            return -1
        return len(self.inbound_vertices[vertex])

    def get_out_degree(self, vertex):
        if vertex not in self.outbound_vertices.keys():
            return -1
        return len(self.outbound_vertices[vertex])

    def find_if_edge_exists(self, vertex1, vertex2):
        if vertex1 in self.inbound_vertices[vertex2]:
            return self.edges_costs[(vertex1, vertex2)]
        elif vertex2 in self.outbound_vertices[vertex1]:
            return self.edges_costs[(vertex1, vertex2)]
        return False

    def find_if_vertex_exists(self,vertex):
        for edge in list(self.edges_costs.keys()):
            if edge[0] == vertex or edge[1] == vertex:
                return True
        return False

    def make_copy_of_current_graph(self):
        return copy.deepcopy(self)
