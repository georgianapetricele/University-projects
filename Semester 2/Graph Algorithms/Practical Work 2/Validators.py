
class WrongVertexException(Exception):
    pass


class DuplicateVertexException(Exception):
    pass


def valid_num_vertices(num_vertices):
    if num_vertices.isdigit():
        if int(num_vertices) > 1000000:
            return False
        return True
    return False


def valid_num_edges(num_edges,num_vertices):
    if num_edges.isdigit():
        if int(num_edges) > (num_vertices * (num_vertices - 1))//2:
            return False
        return True
    return False


def valid(input_string):
    if not input_string.isdigit():
        return False
    else:
        return True