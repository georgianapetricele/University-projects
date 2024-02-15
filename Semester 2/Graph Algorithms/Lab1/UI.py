from DirectedGraph import *
from copy import *
from ExternalFunctions import *
from Validators import *
import os


class UI:
    def __init__(self):
        self.graph = DirectedGraph()
        self.copies = []

    def create_random_graph(self):
        print("Generate random graph:")
        num_vertices = input("Enter the number of vertices: ")
        while not valid_num_vertices(num_vertices):
            num_vertices = input("Enter the number of vertices: ")
        num_vertices = int(num_vertices)

        num_edges = input("Enter the number of edges: ")
        if valid_num_edges(num_edges, num_vertices):
            num_edges = int(num_edges)
            self.graph = generate_random_graph(num_vertices, num_edges)
        else:
            print("Number of edges > num_vertices * (num_vertices - 1)")

    def read_graph_from_a_file(self):
        file_name = input("Enter the file you want to read input from: ")
        if os.path.exists(file_name):
            self.graph = read_from_file(file_name)
        else:
            print("The file doesn't exist")

    def add_vertex(self):
        new_vertex = input("Enter the vertex you want to add: ")
        if valid(new_vertex):
            new_vertex = int(new_vertex)
            if self.graph.add_vertex(new_vertex):
                print("Vertex added with success!")
            else:
                print("Can't add vertex!")
        else:
            print("Enter valid input!")

    def remove_vertex(self):
        vertex_to_remove = input("Enter the vertex you want to remove: ")
        if valid(vertex_to_remove):
            vertex_to_remove = int(vertex_to_remove)
            if self.graph.remove_vertex(vertex_to_remove):
                print("Vertex removed with success!")
            else:
                print("Can't remove vertex!")
        else:
            print("Enter valid input!")

    def add_edge_to_graph(self):
        vertex1 = input("Enter the first vertex of the edge: ")
        vertex2 = input("Enter the second vertex of the edge: ")
        edge_cost = input("Enter the cost of the edge to add: ")
        if valid(vertex1) and valid(vertex2) and valid(edge_cost):
            vertex1 = int(vertex1)
            vertex2 = int(vertex2)
            edge_cost = int(edge_cost)
            if self.graph.add_edge(vertex1,vertex2,edge_cost):
                print("Edge added with success!")
            else:
                print("Can't add edge!")
        else:
            print("Enter valid input!")

    def remove_edge_from_graph(self):
        vertex1 = input("Enter the first vertex of the edge: ")
        vertex2 = input("Enter the second vertex of the edge: ")
        if valid(vertex1) and valid(vertex2):
            vertex1 = int(vertex1)
            vertex2 = int(vertex2)
            if self.graph.remove_edge(vertex1, vertex2):
                print("Edge removed with success!")
            else:
                print("Can't remove edge!")
        else:
            print("Enter valid input!")

    def update_the_cost_of_edge(self):
        vertex1 = input("Enter the first vertex of the edge: ")
        vertex2 = input("Enter the second vertex of the edge: ")
        new_edge_cost = input("Enter the cost of the edge: ")
        if valid(vertex1) and valid(vertex2) and valid(new_edge_cost):
            vertex1 = int(vertex1)
            vertex2 = int(vertex2)
            new_edge_cost = int(new_edge_cost)
            if self.graph.update_edge_cost(vertex1, vertex2,new_edge_cost):
                print("Edge cost updated with success!")
            else:
                print("Can't update edge cost!")
        else:
            print("Enter valid input!")

    def find_if_edge_exists(self):
        vertex1 = input("Enter the first vertex of the edge: ")
        vertex2 = input("Enter the second vertex of the edge: ")
        if valid(vertex1) and valid(vertex2):
            vertex1 = int(vertex1)
            vertex2 = int(vertex2)
            if self.graph.find_if_edge_exists(vertex1,vertex2):
                print("Edge exists!")
            else:
                print("Edge doesn't exist!")
        else:
            print("Enter valid input!")

    def write_graph_in_text_file(self):
        file_name = input("Enter the name of the file where you want to write the graph: ")
        write_in_file(file_name,self.graph)

    def display_current_graph_on_console(self):
        print(str(self.graph))

    def display_vertices(self):
        for vertex in self.graph.parse_vertices():
            print(vertex," ")

    def display_number_of_vertices(self):
        print("The number of vertices: ",self.graph.get_number_of_vertices)

    def display_in_degree_of_vertex(self):
        new_vertex = input("Enter the vertex for displaying its in degree: ")
        if valid(new_vertex):
            new_vertex = int(new_vertex)
            print("The in degree of ",new_vertex," is ",self.graph.get_in_degree(new_vertex))

    def display_out_degree_of_vertex(self):
        new_vertex = input("Enter the vertex for displaying its out degree: ")
        if valid(new_vertex):
            new_vertex = int(new_vertex)
            print("The out degree of ",new_vertex," is ",self.graph.get_out_degree(new_vertex))

    def display_in_bound_neighbors(self):
        new_vertex = input("Enter the vertex for displaying its in bound neighbors: ")
        if valid(new_vertex):
            new_vertex = int(new_vertex)
            string = ""
            print("The in bound neighbors of ",new_vertex," are: ")
            for vertex in self.graph.parse_inbound_vertices(new_vertex):
                string += str(vertex) + ' '
            print(string)

    def display_out_bound_neighbors(self):
        new_vertex = input("Enter the vertex for displaying its out bound neighbors: ")
        if valid(new_vertex):
            new_vertex = int(new_vertex)
            string = ""
            print("The out bound neighbors of ", new_vertex, " are: ")
            for vertex in self.graph.parse_outbound_vertices(new_vertex):
                string += str(vertex) + ' '
            print(string)

    def copy_current_graph(self):
        self.copies.append(self.graph.make_copy_of_current_graph())
        print(str(self.copies[-1]))

    @staticmethod
    def print_menu():
        print("""\nChoose one of the following operations:
        1. Generate a random graph with a given number of vertices and edges (and overwrite the current graph).
        2. Read a graph from a file (and overwrite the current graph).
        3. Add a vertex to the current graph.
        4. Remove a vertex from the current graph.
        5. Add an edge to the current graph.
        6. Remove an edge from the current graph.
        7. Update the cost of an edge of the current graph.
        8. Check if an edge between given vertices exists in the current graph.
        9. Write the representation of the current graph as a list of edges in graph_modif.txt.
        10. Display the current graph on the console.
        11. Display the number of vertices of the current graph.
        12. Display the vertices of the current graph.
        13. Display the in-degree of a vertex.
        14. Display the out-degree of a vertex.
        15. Display the inbound neighbors of a given vertex.
        16. Display the outbound neighbors of a given vertex
        17. Copy the graph.
        18. Exit.\n""")

    def start(self):
        commands = {"1": self.create_random_graph, "2": self.read_graph_from_a_file,"3":self.add_vertex,
                    "4":self.remove_vertex,"5":self.add_edge_to_graph,"6":self.remove_edge_from_graph,
                    "7":self.update_the_cost_of_edge,"8":self.find_if_edge_exists,"9":self.write_graph_in_text_file,
                    "10": self.display_current_graph_on_console,"11":self.display_number_of_vertices,"12": self.display_vertices,
                    "13":self.display_in_degree_of_vertex,"14":self.display_out_degree_of_vertex,"15":self.display_in_bound_neighbors,
                    "16":self.display_out_bound_neighbors,"17":self.copy_current_graph}
        while True:
            self.print_menu()
            option = input("Enter your option: ")
            if option in commands.keys():
                commands[option]()
            elif option == "18":
                break
            else:
                print("Enter a valid option!!!")


ui = UI()
ui.start()
