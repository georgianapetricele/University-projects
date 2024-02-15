from random import *
from UndirectedGraph import *


def generate_random_graph(num_vertices, num_edges):
    graph = UndirectedGraph(num_vertices, num_edges)
    vertices = list(range(num_vertices))
    for vertex in vertices:
        graph.add_vertex(vertex)
    shuffle(vertices)
    num_edges_added = 0
    while num_edges_added < num_edges:
        u, v = sample(vertices, 2)
        already_added= False
        if (u,v) not in graph.edges_costs.keys():
            graph.add_edge(u, v, randint(-1000, 1000))
            num_edges_added +=1
    return graph


def read_from_file(file_name):
    fin = open(file_name,"r")
    line_content = []
    counter = 0
    nr_vertices, nr_edges = fin.readline().split()
    graph = UndirectedGraph(int(nr_vertices), int(nr_edges))
    lines = fin.readlines()
    vertices = list(range(int(nr_vertices)))
    for vertex in vertices:
        graph.add_vertex(vertex)
    for line in lines:
        line_content = line.split()
        vertex1= int(line_content[0])
        vertex2 = int(line_content[1])
        edge_weight = int(line_content[2])
        counter += 1
        if counter % 10000 == 0:
            print(counter," lines processed...\n")
        graph.add_edge(vertex1,vertex2,edge_weight)
    return graph


def write_in_file(file_name,given_graph):
    fout= open(file_name,"w")
    if len(given_graph.edges_costs) == 0:
        fout.write("Graph can't be generated!")
    else:
        fout.write(str(given_graph))
    fout.close()

def dfs(given_graph, visited, x, component):
    """
    Executes a DFS traversal of the undirected graph G.
    :param given_graph: UndirectedGraph object
    :param visited: dictionary of booleans
    :param x: the source node for the current DFS traversal
    :param component: the connected component resulted (UndirectedGraph object)
    :return: UndirectedGraph object that represents the connected component
    """
    visited[x] = True
    component.add_vertex(x)
    for y in given_graph.neighbours[x]:
        # add edge from start to y
        if not visited[y]:
            component.add_vertex(y)
            component.set_nr_vertices(component.get_number_of_vertices+1)

        if given_graph.find_if_edge_exists(x, y):
            cost = given_graph.get_edge_cost(x, y)
            component.add_edge(x, y, cost)
            component.set_nr_edges(component.get_number_of_edges + 1)

        if not visited[y]:
            visited[y] = True
            dfs(given_graph,visited,y,component)
def dfs_connected_components(given_graph):
    """
    Function that returns a list of the connected components of an undirected graph as UndirectedGraph objects. It uses
    Depth-First Search traversal.
    :param given_graph:
    :return: list of UndirectedGraph objects (list of the connected components)
    """
    list_connected_components = []
    visited={}
    for node in given_graph.parse_vertices():
        visited[node] = False
    for node in given_graph.parse_vertices():
        if visited[node] == False:
            connected_component = UndirectedGraph()
            dfs(given_graph,visited,node,connected_component)
            connected_component.set_nr_vertices(connected_component.get_number_of_vertices)
            connected_component.set_nr_edges(connected_component.get_number_of_edges//2)
            list_connected_components.append(connected_component)
    return list_connected_components


