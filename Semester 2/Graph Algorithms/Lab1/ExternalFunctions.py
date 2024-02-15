from random import *
from DirectedGraph import *


def generate_random_graph(num_vertices, num_edges):
    graph = DirectedGraph(num_vertices,num_edges)
    vertices = list(range(num_vertices))
    shuffle(vertices)
    num_edges_added = 0
    while num_edges_added < num_edges:
        u, v = sample(vertices, 2)
        already_added= False
        if (u,v) not in graph.edges_costs.keys():
            graph.add_vertex(u)
            graph.add_vertex(v)
            graph.add_edge(u, v, randint(-1000, 1000))
            num_edges_added +=1
    return graph


def read_from_file(file_name):
    fin = open(file_name,"r")
    line_content = []
    counter = 0
    nr_vertices, nr_edges = fin.readline().split()
    graph = DirectedGraph(int(nr_vertices),int(nr_edges))
    lines = fin.readlines()
    for line in lines:
        line_content = line.split()
        vertex1= int(line_content[0])
        graph.add_vertex(vertex1)
        vertex2 = int(line_content[1])
        graph.add_vertex(vertex2)
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

