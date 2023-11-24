from src.domain.domain import *


class RepositoryException(Exception):
    pass


class Repository(object):
    def __init__(self):
        self.__repo = []

    def find_entity(self, new_entity):
        for entity in self.__repo:
            if entity == new_entity:
                return True
        return False

    def get_all(self):
        return self.__repo

    def add_entity_repo(self, new_entity):
        if self.find_entity(new_entity):
            raise RepositoryException("Duplicate entity!")
        else:
            self.__repo.append(new_entity)

    def delete_entity_repo(self, entity):
        if self.find_entity(entity):
            self.__repo.remove(entity)
        else:
            raise RepositoryException("The entity doesn't exit!")

    def update_entity(self, old_entity, new_entity):
        if old_entity is None:
            raise RepositoryException("The entity doesn't exist!")
        else:
            self.delete_entity_repo(old_entity)
            self.add_entity_repo(new_entity)

    def __str__(self):
        list_of_str = ""
        for current_entity in self.__repo:
            list_of_str += str(current_entity) + "\n"
        return str(list_of_str)

    def __len__(self):
        return len(self.__repo)

    def get_first_element(self):
        return self.__repo[0]
